from flask import Flask, render_template, request

app = Flask(__name__)

SPORTS = ["Basketball", "Soccer", "Ultimate Frisbee"] # use this list to generate the client side form

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/register", methods=["POST"]) # create new route
def register(): # define new function register
    if not request.form.get("name") or not request.form.get("sport"):
        return render_template("failure.html")
    return render_template("success.html")
