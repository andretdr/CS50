SELECT DISTINCT(people.name) FROM movies, people, stars WHERE movies.id = stars.movie_id AND people.id = stars.person_id AND movies.year = '2004' ORDER BY people.birth ASC;
