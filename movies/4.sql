SELECT COUNT(movies.id) FROM movies, ratings WHERE movies.id = ratings.movie_id AND ratings.rating = '10.0';
