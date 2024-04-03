#

#syntax CREATE TABLE table (column type, ...);

sqlite3 favorites.db # in terminal to create and load yr csv file into a db file

.mode csv
.import favorites.csv favorites # table name load the whole CSV ito favorites db file
.quit

# ls will show you the new db file

sqlite3 favorites.db # open the db file
.schema # shows the schema of the table

#syntax SELECT columns FROM table; # upper case the keyword cmds, lowercase the placeholders

SELECT * FROM favorites; # show whole table

#syntax AVG COUNT DISTINCT LOWER MAX MIN UPPER
SELECT language FROM favorites; # show all the entries showing the laguage column, not distinct
SELECT language FROM favorites limit 10; # limit that to 10
SELECT COUNT(*) FROM favorites; # shows the count of number of rows
SELECT DISTINCT(language) FROM favorites; # show distinct languages
SELECT COUNT(DISTINCT(language)) FROM favorites; # count them

# syntax WHERE, LIKE, ORDER BY, LIMIT, GROUP BY
SELECT COUNT(*) FROM favorites WHERE language = 'C'; # show which of the rows have C as the language
SELECT COUNT(*) FROM favorites WHERE language = 'C' AND problem = 'Hellow, World'; # AND the problem is 'hellow, world' as well

SELECT language, COUNT(*) FROM favorites GROUP BY language; # GROUP BY will group the languages together. Showing the column of language groups n their count
SELECT language, COUNT(*) FROM favorites GROUP BY language ORDER BY COUNT(*) ASC; # order by the count(*) column
SELECT language, COUNT(*) FROM favorites GROUP BY language ORDER BY COUNT(*) DESC;

SELECT language, COUNT(*) AS n FROM favorites GROUP BY language ORDER BY n DESC; # creating synonym

SELECT language, COUNT(*) AS n FROM favorites GROUP BY language ORDER BY n DESC LIMIT 1;

# syntax INSERT INTO table (column, ...) VALUES(value, ...);
INSERT INTO favorites (language, problem) VALUES('SQL', 'Fiftyville');

# NULL no data

# syntax DELETE FROM table WHERE condition;
DELETE FROM favorites; # delete entire table
DELETE FROM favorites WHERE Timestamp IS NULL; # delete rows where timestamp is null

# UPDATE table SET column = value WHERE condition;
UPDATE favorites SET language = 'SQL', problem = 'Fiftyville'; # updates ALL rows and columns to SQL n fiftyville





## shows.db

sqlite3 shows.db
SELECT * FROM ratings LIMIT 10;
SELECT COUNT(*) FROM shows;

# data types
# BLOB binary large object like files, INTEGER, NUMERIC, REAL, TEXT
# NOT NULL, UNIQUE
# PRIMARY KEY, FOREIGN KEY
# unique ID in the table it comes from is pri key, referencing the ID from another table is forieng key

.schema shows # shows table

CREATE TABLE shows (
    id INTEGER,
    title TEXT NOT NULL,
    year NUMERIC,
    episodes INTEGER,
    PRIMARY KEY(id) # id is a pri key
);

.schema ratings # different table

CREATE TABLE ratings (
    show_id INTEGER NOT NULL,
    rating REAL NOT NULL,
    votes INTEGER NOT NULL,
    FOREIGN KEY(show_id) REFERENCES shows(id) # show_id is foreign key
);

SELECT show_id FROM ratings WHERE rating >= 6.0 ORDER BY rating DESC LIMIT 10;
# shows the show ID of top 10 shows. but the show NAME is in another table, shows.
# so do nested

SELECT * FROM shows WHERE id IN
(SELECT show_id FROM ratings WHERE rating >= 6.0 ORDER BY rating DESC LIMIT 10);

