# Write your MySQL query statement below
SELECT  SUBSTR(trans_date,1,7) as month, country, count(id) as trans_count, SUM(if( state = 'approved' , 1 , 0)) as approved_count, SUM(amount) as trans_total_amount, SUM(CASE WHEN state = 'approved' then amount else 0 END) as approved_total_amount
FROM Transactions
GROUP BY month, country