SELECT movies.title FROM movies, people, stars WHERE movies.id = stars.movie_id AND people.id = stars.person_id AND people.name = 'Jennifer Lawrence' INTERSECT SELECT movies.title FROM movies, people, stars WHERE movies.id = stars.movie_id AND people.id = stars.person_id AND people.name = 'Bradley Cooper';
