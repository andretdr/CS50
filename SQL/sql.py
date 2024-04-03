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
UPDATE favorites SET language = 'SQL', problem = 'Fiftyville'; 

