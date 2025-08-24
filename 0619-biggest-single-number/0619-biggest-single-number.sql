# Write your MySQL query statement below
-- Tere bhai ne khud se kiya hai
SELECT (SELECT num
FROM MyNumbers
GROUP BY num
HAVING COUNT(num) = 1
ORDER BY num DESC
LIMIT 1) AS num;
