# Write your MySQL query statement below

select e.name , b.bonus
from Employee as e left join Bonus as b
on e.empID = b.empID
where (b.bonus is null) or (b.bonus < 1000)