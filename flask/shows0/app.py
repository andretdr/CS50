from flask import Flask, redirect, session, render_html
from flask_session import Session
from cs50 import SQL

app = Flask(__name__)

app.config("SESSION_PERMANENT") = False
app.config("SESSION_TYPE") = "filesystem"
Session(app)

db = SQL("sqlite:///shows.db")

@app.route = ("/")
def index():
    
