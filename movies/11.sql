SELECT movies.title FROM movies, people, stars, ratings WHERE movies.id = stars.movie_id  AND people.id = stars.person_id AND ratings.movie_id = movies.id AND people.id = stars.person_id AND people.name = 'Chadwick Boseman' ORDER BY ratings.rating DESC;