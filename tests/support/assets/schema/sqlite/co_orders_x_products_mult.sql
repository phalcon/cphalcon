DROP TABLE IF EXISTS "co_orders_x_products_mult";

create table co_orders_x_products_mult (
  `oxp_id` integer constraint co_oxp_mult_pk primary key autoincrement,
  `oxp_ord_id` integer NOT NULL,
  `oxp_ord_status_flag` integer NULL,
  `oxp_prd_id` integer NOT NULL,
  `oxp_prd_status_flag` integer NULL,
  `oxp_quantity` integer NULL
);
