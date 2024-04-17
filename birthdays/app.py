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

def validatename(strname):
    try:
        result = bool(strname)
    except ValueError:
        result = False
    return result

def returnmonth(strdate):
    format = "%Y-%m-%d"
    try:
        date = datetime.strptime(strdate, format)
        month = date.strftime("%m")
        result = month
    except ValueError:
        result = 0
    return result


def returnday(strdate):
    format = "%Y-%m-%d"
    try:
        date = datetime.strptime(strdate, format)
        day = date.strftime("%d")
        result = day
    except ValueError:
        result = 0
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

        if validatedate(record['date']) and validatename(record['name']):
            # enter into database how to auto increment the id?
            db.execute("INSERT INTO birthdays (name, month, day) VALUES(?, ?, ?);", record['name'], returnmonth(record['date']), returnday(record['date']))
            response = 'Successful entry'
        else:
            response = 'Invalid entry'

        return render_template("index.html", response=response)

    else:

        return render_template("index.html")

@app.route("/return")
def returnlist():

    birthdays = db.execute("SELECT * FROM birthdays SORT BY month day DESC")

    return jsonify(birthdays)


