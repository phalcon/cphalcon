DROP TABLE IF EXISTS "co_orders_x_products";

create table co_orders_x_products
(
    oxp_ord_id   integer not null,
    oxp_prd_id   integer not null,
    oxp_quantity integer not null,
    primary key (oxp_ord_id, oxp_prd_id)
);
