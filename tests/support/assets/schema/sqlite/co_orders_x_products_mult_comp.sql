DROP TABLE IF EXISTS "co_orders_x_products_mult_comp";

create table co_orders_x_products_mult_comp (
  `oxp_ord_id` integer NOT NULL,
  `oxp_ord_status_flag` integer NULL,
  `oxp_prd_id` integer NOT NULL,
  `oxp_prd_status_flag` integer NULL,
  `oxp_quantity` integer NULL,
  primary key (`oxp_ord_id`, `oxp_prd_id`, `oxp_ord_status_flag`, `oxp_prd_status_flag`)
);
