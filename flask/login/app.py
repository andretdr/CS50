from flask import Flask, redirect, render_template, request

app = Flask(__name__)

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        name = request.form.get("name", "world") # request form is for POST. request.arg is for get
        return render_template("greet.html", name=name)
    return render_template("index.html")







