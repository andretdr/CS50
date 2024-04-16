import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session
from datetime import datetime

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

def validatedate(strdate):
    format = "%Y-%m-%d"
    try:
        result = bool(datetime.strptime(strdate, format))
    except ValueError:
        result = False
    return result

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    response = ''

    if request.method == "POST":
        record = {}
        record['name'] = request.form.get('name')
        record['date'] = request.form.get('date')
        if validatedate(record['date']):
            # enter into database
            db.execute("INSERT into )
            response = 'Successful entry'

        else:
            response = 'Invalid date'

        return render_template("index.html", response=response)

    else:

        return render_template("index.html")

@app.route("/return")
def returnlist():

    birthdays = db.execute("SELECT * FROM birthdays")

    return jsonify(birthdays)


