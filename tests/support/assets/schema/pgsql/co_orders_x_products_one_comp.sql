DROP TABLE IF EXISTS "co_orders_x_products_one_comp";

create table co_orders_x_products_one_comp
(
    oxp_ord_id int not null,
    oxp_prd_id int not null,
    oxp_quantity int null,
    primary key (oxp_ord_id, oxp_prd_id)
);
