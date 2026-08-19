DROP TABLE IF EXISTS "co_orders_x_products_mult";

create table co_orders_x_products_mult
(
    oxp_id serial not null constraint co_oxp_mult_pk primary key,
    oxp_ord_id int not null,
    oxp_prd_id int not null,
    oxp_quantity int null,
    oxp_ord_status_flag integer,
    oxp_prd_status_flag integer
);
