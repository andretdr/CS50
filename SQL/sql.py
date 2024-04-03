#



sqlite3 favorites.db # in terminal to create and load yr csv file into a db file

.mode csv
.import favorites.csv favorites # table name load the whole CSV ito favorites db file
.quit

# ls will show you the new db file
