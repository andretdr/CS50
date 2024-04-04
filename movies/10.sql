SELECT DISTINCT(people.name) FROM movies, people, directors, ratings WHERE movies.id = directors.movie_id AND people.id = directors.person_id AND movies.id = ratings.movie_id AND ratings.rating >= '9.0';
