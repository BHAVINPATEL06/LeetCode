# Write your MySQL query statement below
-- Tere bhai ne khud se kiya hai
SELECT * FROM Cinema
WHERE MOD(id,2) != 0 AND description NOT IN ('boring')
ORDER BY rating DESC;