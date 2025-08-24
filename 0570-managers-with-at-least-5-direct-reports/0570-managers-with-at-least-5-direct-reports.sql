# Write your MySQL query statement below
-- Tere bhai ne khud se kiya hai
SELECT E1.name
FROM Employee E1
INNER JOIN Employee E2
WhERE E1.id = E2.managerId
GROUP BY E1.id
HAVING COUNT(E1.id)>=5;