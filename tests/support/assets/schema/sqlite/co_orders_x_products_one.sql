DROP TABLE IF EXISTS "co_orders_x_products_one";

create table co_orders_x_products_one (
  `oxp_id` integer constraint co_oxp_one_pk primary key autoincrement,
  `oxp_ord_id` integer NOT NULL,
  `oxp_prd_id` integer NOT NULL,
  `oxp_quantity` integer NULL
);
