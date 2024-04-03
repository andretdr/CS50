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
(SELECT show_id FROM ratings WHERE rating >= 6.0 ORDER BY rating DESC LIMIT 10); # showing all the info from shows table where their ratings are > 6

SELECT title FROM shows WHERE id IN
(SELECT show_id FROM ratings WHERE rating >= 6.0 ORDER BY rating DESC LIMIT 10); # showing all the titles from shows table where their ratings are > 6

# JOIN
SELECT * FROM shows JOIN ratings ON shows.id = ratings.show_id WHERE rating >= 6.0 LIMIT 10; # join them by this value shows.id and ratings.show_id

SELECT title, rating FROM shows JOIN ratings ON shows.id = ratings.show_id WHERE rating >= 6.0 LIMIT 10;

## 1 to 1 relationship, 1 to many relationship

sqlite> .schema genres
CREATE TABLE genres (
    show_id INTEGER NOT NULL,
    genre TEXT NOT NULL,
    FOREIGN KEY(show_id) REFERENCES shows(id)
);

SELECT * FROM genres LIMIT 10; # show all rows from genre
SELECT show_id FROM genres WHERE genre = 'Comedy' LIMIT 10;
SELECT title FROM shows WHERE id IN (SELECT show_id FROM genres WHERE genre = 'Comedy' LIMIT 10);
# show titles where all are comedy
SELECT genre FROM genres WHERE show_id = (SELECT id FROM shows WHERE title = 'Catweazle');

# 1 to MANY relation trying to join 1 to many relational tables, result set will have dupications
SELECT * FROM shows JOIN genres ON shows.id = genres.show_id WHERE id = 63881;
SELECT title, genre FROM shows JOIN genres ON shows.id = genres.show_id WHERE id = 63881;

## MANY to MANY relation
.schema stars
CREATE TABLE stars (
    show_id INTEGER NOT NULL,
    person_id INTEGER NOT NULL,
    FOREIGN KEY(show_id) REFERENCES shows(id),
    FOREIGN KEY(person_id) REFERENCES people(id)
);

.schema people
CREATE TABLE people (
    id INTEGER,
    name TEXT NOT NULL,
    birth NUMERIC,
    PRIMARY KEY(id)
);

SELECT * FROM shows WHERE title = 'The Office' AND year = 2005;
SELECT person_id FROM stars WHERE show_id = (SELECT * FROM shows WHERE title = 'The Office' AND year = 2005);
