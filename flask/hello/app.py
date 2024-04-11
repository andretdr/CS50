from flask import Flask, render_template, request #flask import

app = Flask(__name__) # to initiate this for web app

@app.route("/") # this app's function, when user visits / will
def index(): # run the function index, which just returns 'hello world'
#    return "hello, world"  # returns just this line
#    return render_template("index.html")  # returns the html in my temple folder, index.html
