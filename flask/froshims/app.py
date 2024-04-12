from cs50 import SQL
from flask import Flask, render_template, request, redirect

app = Flask(__name__)

db = SQL("sqlite:///froshims.db")

#REGISTRANTS = {} # empty dictionary

SPORTS = ["Basketball", "Soccer", "Ultimate Frisbee"] # use this list to generate the client side form

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS) # pass named parameter placeholder sports with the list of SPORTS

@app.route("/register", methods=["POST"]) # create new route
def register(): # define new function register

#    if not request.form.get("name") or request.form.get("sport") not in SPORTS:
#        return render_template("failure.html")
#    return render_template("success.html")


    # Validatw name
    name = request.form.get("name")
    if not name:
        return render_template("error.html", message="Missing name")

    # Validate sport
    sport = request.form.get("sport")
    if not sport:
        return render_template("error.html", message="Missing Sport")
    if sport not in SPORTS:
        return render_template("error.html", message="Invalid Sport")

    # Remember registrant
 #   REGISTRANTS[name] = sport # assigning key: value. key(name) -> sport

    # Confirm registration
    return redirect("/registrants")

@app.route("/registrants")
def registrants():
    return render_template("registrants.html", registrants=REGISTRANTS)
