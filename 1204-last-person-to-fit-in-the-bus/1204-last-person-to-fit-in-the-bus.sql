# Write your MySQL query statement below
select person_name
from
(
    select person_name, turn, SUM(weight) 
    over (order by turn) AS total_weight
    from Queue
) q
where total_weight <= 1000
order By total_weight DESC
limit 1