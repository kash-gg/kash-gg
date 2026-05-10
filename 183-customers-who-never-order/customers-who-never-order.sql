# Write your MySQL query statement below
select name as Customers from Customers c1 left outer join Orders o1
on c1.id = o1.customerId where o1.id is null;