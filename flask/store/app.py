from cs50 import SQL
from flask import Flask, redirect, session, render_template, request
from flask_session import Session

app = Flask(__name__)

db = SQL("sqlite:///store.db")

app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/")
def index():
    books = db.execute("SELECT * FROM books") # returns a list of dictionaries, [{"id": 1, "title": "Jurassic park"}, {id....}]
    return render_template("books.html", books=books)

@app.route("/cart", methods=["GET", "POST"])
def cart():


