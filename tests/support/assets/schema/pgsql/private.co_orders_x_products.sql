DROP TABLE IF EXISTS "private"."co_orders_x_products";

create table private.co_orders_x_products
(
    oxp_ord_id  int not null,
    oxp_prd_id  int not null,
    oxp_quantity int not null
);
