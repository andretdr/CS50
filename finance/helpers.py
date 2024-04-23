import csv
import datetime
import pytz
import requests
import urllib
import uuid
import re

from flask import redirect, render_template, request, session
from functools import wraps
from datetime import date, datetime


def apology(message, code=400):
    """Render message as an apology to user."""

    def escape(s):
        """
        Escape special characters.

        https://github.com/jacebrowning/memegen#special-characters
        """
        for old, new in [
            ("-", "--"),
            (" ", "-"),
            ("_", "__"),
            ("?", "~q"),
            ("%", "~p"),
            ("#", "~h"),
            ("/", "~s"),
            ('"', "''"),
        ]:
            s = s.replace(old, new) # creates and replaces special escape characters
        return s

    return render_template("apology.html", top=code, bottom=escape(message)), code


def login_required(f):
    """
    Decorate routes to require login.

    https://flask.palletsprojects.com/en/latest/patterns/viewdecorators/
    """

    @wraps(f)
    def decorated_function(*args, **kwargs):
        if session.get("user_id") is None:
            return redirect("/login")
        return f(*args, **kwargs)

    return decorated_function


def lookup(symbol):
    """Look up quote for symbol."""

    # Prepare API request
    symbol = symbol.upper()
    end = datetime.datetime.now(pytz.timezone("US/Eastern"))
    start = end - datetime.timedelta(days=7)

    # Yahoo Finance API
    url = (
        f"https://query1.finance.yahoo.com/v7/finance/download/{urllib.parse.quote_plus(symbol)}"
        f"?period1={int(start.timestamp())}"
        f"&period2={int(end.timestamp())}"
        f"&interval=1d&events=history&includeAdjustedClose=true"
    )

    # Query API
    try:
        response = requests.get(
            url,
            cookies={"session": str(uuid.uuid4())},
            headers={"Accept": "*/*", "User-Agent": request.headers.get("User-Agent")},
        )
        response.raise_for_status()

        # CSV header: Date,Open,High,Low,Close,Adj Close,Volume
        quotes = list(csv.DictReader(response.content.decode("utf-8").splitlines()))
        price = round(float(quotes[-1]["Adj Close"]), 2)
        return {"price": price, "symbol": symbol}
    except (KeyError, IndexError, requests.RequestException, ValueError):
        return None


def usd(value):
    """Format value as USD."""
    return f"${value:,.2f}"


def validatename(name, db): # returns 3 if ok, 0 if invalid, 1 if username is already being used, 2 if using special letters
    if name == '':
        return 0
    if not (re.match('^[a-zA-Z0-9]+$', name)): #regex check
        return 2
    row = db.execute("SELECT username FROM users WHERE username = ?;", name)
    if len(row) == 0:
        return 3
    return 1

def validatepassword(pw, pwconfirm):
    if pw == '' or pwconfirm == '':
        return 0
    if pw != pwconfirm:
        return 1
    return 2

def validatesymbol(symbol): # 0 is good, 1 is not
    if not (re.match('^[a-zA-Z0-9]+$', symbol)): #regex check
        return 1
    return 0

def addrecord(name, pwhash, db):
    db.execute("INSERT INTO users (username, hash) VALUES(?, ?);", name, pwhash)

def getbalance(id, db): # return the balance in this account, assume its valid
    row = db.execute("SELECT cash FROM users WHERE id = ?;", id)
    return row[0]['cash']

def strictlydigits(n):
    return re.match("^\\d+$", n)

def returnsymbol(symbol, db): #returns symbol ID, if new entry will add into db
    symbol = symbol.upper()
    row = db.execute("SELECT id from SYMBOL WHERE symbol = ?;", symbol)
    if len(row) == 0: #if new entry
        return db.execute("INSERT INTO symbol (symbol) VALUES(?);", symbol)
    return row[0]['id']

def update_transaction(buycode, id, symbol, shares, db):
    date = date.today()
    datef = date.strftime("%Y-%m-%d")
    time = datetime.now()
    timef = time.strftime("%H:%M:%S")

    lookupdata = lookup(symbol)
    price = lookupdata

    if (buycode == 'buy'):
        db.execute("INSERT INTO transactions (userid, symbol, price, shares, date, time, buycode) VALUES (?, ?, ?, ?, ?, ?, ?);", id, symbol, , shares, datef, timef, buycode)
