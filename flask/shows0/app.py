from flask import Flask, redirect, render_template, request
from cs50 import SQL

app = Flask(__name__)

db = SQL("sqlite:///shows.db")

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/search")
def search():
    shows = db.execute("SELECT * FROM movies WHERE title = (?)", request.args.get("q"))
    return render_template("search.html", shows=shows)
