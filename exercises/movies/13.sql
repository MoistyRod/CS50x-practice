SELECT DISTINCT people.name FROM people
JOIN stars ON stars.person_id = people.id
WHERE stars.movie_id IN (
    SELECT stars.movie_id FROM stars
    JOIN people ON people.id = stars.person_id
    WHERE people.name LIKE 'Kevin Bacon' AND people.birth = 1958
)
AND people.name NOT LIKE 'Kevin Bacon';