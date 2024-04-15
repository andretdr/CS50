from flask import Flask, redirect, render_template, request, session # session variable imported here

app = Flask(__name__)

app.config["SESSION_PERMANENT"] = False # make it a session cookie, deleted when quit browser
app.config["SESSION_TYPE"] = "filesystem" # contents of shopping cart stored in server side, not cookie
Session(app) # activate session

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/login")
def login():
    if request.method == "POST":
        session     # imported the session variable from above, a dictionary
    return render_template("login.html")





