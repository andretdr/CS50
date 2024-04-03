from cs50 import SQL

db = SQL("sqlite:///favorites.db") # make sure your db is there

favorite = input("Favorite: ")

db.execute("SELECT COUNT(*) AS n FROM favorites WHERE problem = ?", favorite)
