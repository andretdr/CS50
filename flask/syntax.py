# putting everything together

# https://www.example.com/route?key=value&key=value ?key=value turns your static webpage into dynamic app

                            # GET puts the key value pairs in the URL, in yr HTML code. USES request.args
GET /search?q=cats   #search is the name of google's web application, q is key, cats is value
USES request.args

# Framwework => flask, django micro framework

flask run  # (dynamic website)

# flask conventions

app.py
requirements.txt #what 3rd party librarys you are using, line by line
static/ # images, .js files, etc
templates/ #actual html, css, js files

# request.args
# look up jinja

                            # POST doesnt put the key value pair above. USES request.form
POST
doesn't use request.args, but uses request.form
USES request.form


# dont rely on client side checks. very easy to break the html using web dev tools
# instead, do server side checks

# this is froshim

# DROP down menu on input forms
#   <form action="/register" method="post">
#        <input autocomplete="off" autofocus name="name" placeholder="Name" type="text"> <!-- required entry, add 'required' -->
#        <select name="sport">
#            <option disabled selected value="">Sport</option> <!-- add a placeholder non selectable avlue as 1st entry -->
#            <option>Basketball</option>
#            <option>Soccer</option>
#            <option>Ultimate Frisbee</option>
#        </select>
#        <button type="submit">Register</button>
#    </form>

# RADIO buttons
#
#  <form action="/register" method="post">
#       <input autocomplete="off" autofocus name="name" placeholder="Name" type="text"> <!-- required entry, add 'required' -->
#       {% for sport in sports %}
#           <input name="sport" type="radio" value="{{ sport }}"> {{ sport }}
#       {% endfor %}
#       <button type="submit">Register</button>
#    </form>


# check boxes
#
#  <form action="/register" method="post">
#       <input autocomplete="off" autofocus name="name" placeholder="Name" type="text"> <!-- required entry, add 'required' -->
#       {% for sport in sports %}
#           <input name="sport" type="check" value="{{ sport }}"> {{ sport }}
#       {% endfor %}
#       <button type="submit">Register</button>
#    </form>

# in app.py
# if not request.form.get("name"):
#    return render_template("failure.thml")
# for sport in request.form.getlist("sport"):
#   if sport not in SPORTS:     # have to check all the sports we get back
#       return render_template("failure.html")
# return render_template("success.html")
#
#

# Implemented MVC Model View Controller


# log in
# GET / HTTP/2

# reply should be
# Content-Type: text/html
# Set-Cookie: session=value   # returns a cookie header, w a key=value pair


