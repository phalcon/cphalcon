DROP TABLE IF EXISTS "co_orders_x_products_one";

create table co_orders_x_products_one
(
    oxp_id serial not null constraint co_oxp_one_pk primary key,
    oxp_ord_id int not null,
    oxp_prd_id int not null,
    oxp_quantity int null
);
