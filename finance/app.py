import os
import re

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, jsonify
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd, validatename, validatepassword, validatesymbol, addrecord, getbalance
from helpers import strictlydigits, returnsymbol, update_transaction, update_portfolio, update_balance, fetch_portfolio, return_usershares, check_suffshares


# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
@login_required
def index():

    if request.method == "POST":
        rows = fetch_portfolio(session['user_id'], db)

        return jsonify(rows)

    else:
        return render_template("index.html")




@app.route("/buy", methods=["GET", "POST"])
@login_required

def buy():
    if request.method == "POST" :
        record = request.get_json()

        shares = record['shares']
        if strictlydigits(shares):

            balance = getbalance(session['user_id'], db)
            unitprice = lookup(record['symbol'])

            if float(unitprice['price'])*float(shares) <= balance:
                # make the transaction

                returnsymbol(record['symbol'], db) # check and add symbol into database if not present

                update_transaction(1, session['user_id'], record['symbol'], shares, db) # update DB transactions, buy
                update_portfolio(1, session['user_id'], record['symbol'], shares, db) # update portfolio, buy

                amt = float(unitprice['price']) * float(shares)
                update_balance(1, session['user_id'], amt, db) # update balance

                return jsonify({"status":"0"})
            else:
                return jsonify({"status":"Insufficient Funds"})
        return jsonify({"status":"Invalid Input"})

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():

    session.clear()

    if request.method == "POST":
        record = request.get_json()

        # validation

        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", record['username']
            )

        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], record['password']
            ):
            status = {'status':'invalid username and/or password'}
            return jsonify(status)

        session["user_id"] = rows[0]["id"]

        status = {'status':'redirect'}
        return jsonify(status)

    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")

@app.route("/checktotal")
@login_required
def checktotal():
    sessionid = session['user_id']
    result = {"balance":getbalance(sessionid, db)}

    return jsonify(result)


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "POST" :

        record = request.get_json()
        if validatesymbol(record['symbol']) == 1:
            return jsonify({"status":"Symbol must be alphanumeric"})

        result = lookup(record['symbol'])
        return jsonify(result)

    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():

    session.clear()

    if request.method == "POST":
        record = request.get_json()
        print(f"Our Json get {record}")

        statuscheck = validatename(record['username'], db)

        if statuscheck != 3:
            statuslist = ['Please fill in yr username', 'Username is used', 'Username needs to be alphanumeric']
            status = {'status':statuslist[statuscheck]}
            return jsonify(status) #(status[statuscheck]) how to pas back the message dynamically? fetch as post?

        statuscheck = validatepassword(record['password'], record['confirmation'])

        if statuscheck != 2:
            statuslist = ['Please fill in your password', 'Passwords do not match']
            status = {'status':statuslist[statuscheck]}
            return jsonify(status) #'password and comfirmation do not match'

        pwhash = generate_password_hash(record['password'], method='scrypt', salt_length=16)

        addrecord(record['username'], pwhash, db)
        id = db.execute('SELECT id FROM users WHERE username = ?;', record['username'])

        session['user_id'] = id[0]['id']

        status = {'status':'redirect'}
        return jsonify(status)

    else:
        return render_template("register.html")


@app.route("/sellcheck", methods=["POST"])
@login_required

def sellcheck():

    record = request.get_json()
    if validatesymbol(record['symbol']) == 1:
        return jsonify({"status":"Symbol must be alphanumeric"})

    result = return_usershares(session['user_id'], record['symbol'], db)

    if result != None:
        lookupdata = lookup(record['symbol'])
        currprice = lookupdata['price']
        result['price'] = currprice

    return jsonify(result)

@app.route("/sell", methods=["GET", "POST"])
@login_required

def sell():
    if request.method == 'POST':
        clientdata = request.get_json()
        clientshares = clientdata['shares']
        clientsymbol = clientdata['symbol']
        currentid = session['user_id']

        if (not strictlydigits(clientshares)) and (not validatesymbol(clientsymbol)) :
            return jsonify({"status":"Invalid input"})

        if (not check_suffshares(clientshares, clientsymbol, currentid, db)): #if not ok
            return jsonify({"status":"Insufficient shares"})

        update_transaction(0, currentid, clientsymbol, clientshares, db)
        update_portfolio(0, currentid, clientsymbol, clientshares, db)

        lookupdata = lookup(clientsymbol)
        currentprice = lookupdata['price']
        amt = float(currentprice) * float(clientshares)

        update_balance(0, currentid, amt, db)

        return jsonify({"status":"0"})

    else:
        return render_template("sell.html")
