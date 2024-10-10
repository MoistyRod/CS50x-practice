SELECT COUNT(DISTINCT name) FROM people
JOIN stars ON stars.person_id = people.id
WHERE movie_id IN
    (SELECT movies.id FROM movies WHERE year = 2004)
ORDER BY birth;