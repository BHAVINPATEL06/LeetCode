# Write your MySQL query statement below
-- Tere bhai ne khud se kiya hai
SELECT email AS Email
FROM Person AS p1
GROUP BY email
HAVING COUNT(email) >= 2;