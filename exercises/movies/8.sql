SELECT COUNT(name) FROM stars
JOIN movies ON movies.id = stars.movie_id
JOIN people ON people.id = stars.person_id
WHERE title LIKE 'Toy Story';