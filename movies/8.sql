-- List of people who stars in Toy Story
SELECT name
FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON movies.id = stars.movie_id
WHERE title LIKE '%Toy Story%';
