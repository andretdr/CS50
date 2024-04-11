# putting everything together

# https://www.example.com/route?key=value&key=value ?key=value turns your static webpage into dynamic app

                            # GET puts the key value pairs in the URL, in yr HTML code
GET /search?q=cats HTTP/2   #search is the name of google's web application, q is key, cats is value
Host: www.google.com

# Framwework => flask, django micro framework

flask run  # (dynamic website)

# flask conventions

app.py
requirements.txt #what 3rd party librarys you are using, line by line
static/ # images, .js files, etc
templates/ #actual html, css, js files

# request.args
# look up jinja

                            # POST doesnt put the key value pair above
POST
