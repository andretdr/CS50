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

    # ensure cart exists
    if "cart" not in session: # if the name "cart" is not in the session
        session["cart"] = [] #just create an empty list

    # POST
    if request.method == "POST":
        book_id = request.form.get("id")
        if book_id: # if there is something there, correct number
            session["cart"].append(book_id)
        return redirect("/cart") # redirect to yourself, its a GET request, not POST

    # GET
    books = db.execute("SELECT * FROM books WHERE id IN (?)")

