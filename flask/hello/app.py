from flask import Flask, render_template, request #flask import

app = Flask(__name__) # to initiate this for web app

@app.route("/") # this app's function, when user visits / will
def index(): # run the function index, which just returns 'hello world'
#    return "hello, world"  # returns just this line
#    return render_template("index.html")  # returns the static html in my temple folder, index.html

#   example URL
#    checking to make sure request.args actually has the request you want to pull
#    if "name" in request.args:  # if there is a 'name' value pair request
#                                    # request.args returns a dictionary of keyvalue pairs ?key=value&key=value from the URL
#        name = request.args["name"] # create a variable called name, give it the value whos key is name
#    else:                       # else just call 'world'
#        name = "world"
#                                                            # python supports named parameters, specify the name of the parameter
#    return render_template("index.html", placeholder=name)  # giving the parameter placeholder the value of the name var i just defined

#   example URL strealined
#    name = request.args.get("name", "world") # default dict method get to get the value of 'name', if doesnt exist, then return 'world'
#    return render_template("index.html", namevar=name) # the parameter namevar (left) has value name (right). but will be common to see name=name

#   example ROUTE creation, text bar
    return render_template("index.html")

#@app.route("/greet") # POST if you just want to handle post, not get. make sure your HTML is posting, not getting
#def greet():    # create a function called greet
#    name = request.args.get("name", "world")

#    return render_template("greet.html", namevar=name)


#@app.route("/greet", methods=["GET"]) default, method returns a list of string
#@app.route("/greet", methods=["GET", "POST"]) if you want to handle both

@app.route("/greet", methods=["POST"]) # POST if you just want to handle post, not get. make sure your HTML is posting, not getting
def greet():    # create a function called greet
    name = request.form.get("name", "world") #POST uses request.form instead of request.arg
    return render_template("greet.html", namevar=name)
