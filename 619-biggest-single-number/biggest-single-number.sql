# Write your MySQL query statement below
with inn as (
    select *
    from MyNumbers
    group by num
    having count(num) = 1
)
select max(num) as num from inn
