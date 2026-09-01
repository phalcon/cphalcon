DROP TABLE IF EXISTS "co_products";

create table co_products
(
    prd_id serial constraint co_prd_pk primary key,
    prd_name varchar(70),
    prd_status_flag integer
);
