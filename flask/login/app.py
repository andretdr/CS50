from flask import Flask, redirect, render_template, request, session # session variable imported here a dictionary that is unique to your current session

app = Flask(__name__)

app.config["SESSION_PERMANENT"] = False # make it a session cookie, deleted when quit browser
app.config["SESSION_TYPE"] = "filesystem" # contents of shopping cart stored in server side, not cookie
Session(app) # activate session

@app.route("/")
def index():
    return render_template("index.html", name = session.get("name")) # cannot just have ( "index.thml", session.get("name")), yyou need the placeholder , NAME = session.get("name)

@app.route("/login")
def login():
    if request.method == "POST":
        session["name"] = request.form.get("name")    # imported the session variable from above, a dictionary that is unique to your current session
        return redirect("/")
    return render_template("login.html")





