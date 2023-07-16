# Write your MySQL query statement below

select *
from Cinema 
where description != "boring" and (id&1 = 1)
order by rating desc;