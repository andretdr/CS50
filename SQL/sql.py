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

SELECT * FROM favorites;

#syntax AVG COUNT DISTINCT LOWER MAX MIN UPPER
SELECT language FROM favorites; # show all the rows showing the laguage column
SELECT language FROM favorites limit 10;
SELECT COUNT(*) FROM favorites; #number of rows
SELECT DISTINCT(language) FROM favorites; # show distinct languages
SELECT COUNT(DISTINCT(language)) FROM favorites; # count them

# syntax WHERE, LIKE, ORDER BY, LIMIT, GROUP BY
SELECT COUNT(*) FROM favorites WHERE language = 'C'; # show which of the rows have C as the language
SELECT COUNT(*) FROM favorites WHERE language = 'C' AND problem = 'Hellow, World'; # AND the problem is 'hellow, world' as well

SELECT language, COUNT(*)
