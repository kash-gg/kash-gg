# Write your MySQL query statement below
select p.product_name, s.year,s.price from Product p left join sales s on p.product_id = s.product_id where s.year is not null;