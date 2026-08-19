DROP TABLE IF EXISTS "co_orders";

create table co_orders
(
    ord_id serial not null constraint ord_pk primary key,
    ord_name varchar(70),
    ord_status_flag integer
);
