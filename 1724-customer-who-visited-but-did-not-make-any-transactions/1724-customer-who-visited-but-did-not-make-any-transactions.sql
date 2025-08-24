# Write your MySQL query statement below
-- Tere bhai ne khud se kiya hai
-- Vishwas nhi hoga liken khud se kiya hai

SELECT V.customer_id,COUNT(V.visit_id) AS count_no_trans
FROM Visits AS V
LEFT JOIN Transactions AS T
ON V.visit_id = T.visit_id
WHERE T.transaction_id IS NULL
GROUP BY V.customer_id
ORDER BY count_no_trans;
