-- Top 5 longest songs in decending order
SELECT name
FROM songs
ORDER BY duration_ms DESC
LIMIT 5;
