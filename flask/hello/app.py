from flask import Flask, render_template, request #flask import

app = Flask(__name__) # to initiate this for web app

@app.route("/") # this app's function, when user visits / will
def index(): # run the function index, which just returns 'hello world'
#    return "hello, world"  # returns just this line
#    return render_template("index.html")  # returns the static html in my temple folder, index.html

    if "name" in request.args:  # if there is a 'name' value pair request
                                    # request.args returns a dictionary of keyvalue pairs ?key=value&key=value from the URL
        name = request.args["name"] # create a variable called name, give it the value whos key is name
    else:                       # else just call 'world'
        name = "world"
                                                            # python supports named parameters, specify the name of the parameter
    return render_template("index.html", placeholder=name)  # giving the parameter placeholder the value of the name var i just defined
