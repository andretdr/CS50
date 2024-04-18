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

def validateid(id):
    try:
        result = bool(db.execute("SELECT * FROM birthdays WHERE id = ?", id))
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

status = ''

@app.route("/", methods=["GET", "POST"])
def index():

    return render_template("index.html")


@app.route("/add")
def add():

    record = {}
    record['name'] = request.args.get('name')
    record['date'] = request.args.get('date')

    if validatedate(record['date']) and validatename(record['name']):
        db.execute("INSERT INTO birthdays (name, month, day) VALUES(?, ?, ?);", record['name'], returnmonth(record['date']), returnday(record['date']))
        status = ''
    else:
        status = 'Invalid entry'

    return status


@app.route("/delete")
def delete():

    record = {};
    record['id'] = request.args.get('id')
    if validateid(record['id']):
        db.execute("DELETE FROM birthdays WHERE id = ?;", record['id'])
        status = ''
    else:
        status = 'Record not found'

    return status


@app.route("/update")
def update():

    idedit = request.args.get('id')
    nameedit = request.args.get('name')
    dateedit = request.args.get('date')

    if (validateid(idedit) and validatename(nameedit) and validatedate(dateedit)):
        db.execute("UPDATE birthdays SET name = ? date = ? WHERE id = ?", nameedit, dateedit, idedit)
        status = ''
    else:
        status = 'Invalid Entry'

    return status


@app.route("/returnlist")
def returnlist():

    birthdays = db.execute("SELECT * FROM birthdays ORDER BY month, day ASC")

    return jsonify(birthdays)


