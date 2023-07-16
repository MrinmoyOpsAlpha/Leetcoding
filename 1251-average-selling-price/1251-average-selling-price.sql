# Write your MySQL query statement below

select p.product_id , round(SUM(u.units*p.price)/SUM(u.units),2) as average_price
from prices as p join unitssold as u
on p.product_id = u.product_id and (u.purchase_date between p.start_date and p.end_date)
group by product_id;
