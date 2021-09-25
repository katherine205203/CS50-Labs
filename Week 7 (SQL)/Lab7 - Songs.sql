-- 1
SELECT name FROM songs;


-- In 2.sql, write a SQL query to list the names of all songs in increasing order of tempo
SELECT name FROM songs ORDER BY tempo;


-- In 3.sql, write a SQL query to list the names of the top 5 longest songs, in descending order of length.
SELECT name FROM songs ORDER BY duration_ms DESC LIMIT 5;


-- In 4.sql, write a SQL query that lists the names of any songs that have danceability, energy, and valence greater than 0.75.
SELECT name FROM songs WHERE danceability > 0.75 and energy > 0.75 and valence > 0.75;


-- In 5.sql, write a SQL query that returns the average energy of all the songs
SELECT avg(energy) FROM songs;


-- In 6.sql, write a SQL query that lists the names of songs that are by Post Malone.
SELECT name FROM songs WHERE artist_id IN (SELECT id FROM artists WHERE name = "Post Malone");


-- In 7.sql, write a SQL query that returns the average energy of songs that are by Drake.
SELECT avg(energy) FROM songs WHERE artist_id IN (SELECT id FROM artists WHERE name = "Drake");


-- In 8.sql, write a SQL query that lists the names of the songs that feature other artists.
SELECT name FROM songs WHERE name LIKE "%feat%"
