--  List of the names of all people who starred in a movie in which Kevin Bacon also starred
SELECT DISTINCT p2.name
FROM people p1
JOIN stars s1 ON s1.person_id = p1.id
JOIN stars s2 ON s1.movie_id = s2.movie_id
JOIN people p2 ON s2.person_id = p2.id
WHERE p1.name = 'Kevin Bacon' and p2.name !='Kevin Bacon';
