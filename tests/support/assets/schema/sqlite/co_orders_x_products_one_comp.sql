DROP TABLE IF EXISTS "co_orders_x_products_one_comp";

create table co_orders_x_products_one_comp (
  `oxp_ord_id` integer NOT NULL,
  `oxp_prd_id` integer NOT NULL,
  `oxp_quantity` integer NULL,
  primary key (`oxp_ord_id`, `oxp_prd_id`)
);
