--List of the titles of all movies in which both Bradley Cooper and Jennifer Lawrence starred
SELECT title
FROM movies
JOIN stars AS star1 ON star1.movie_id = movies.id
JOIN people AS person1 ON person1.id = star1.person_id
JOIN stars AS star2 ON star2.movie_id = movies.id
JOIN people AS person2 ON person2.id = star2.person_id
where person1.name LIKE '%Bradley Cooper%' AND person2.name LIKE '%Jennifer Lawrence%';

