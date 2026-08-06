DROP TABLE IF EXISTS `private`.`co_orders_x_products`;

CREATE TABLE private.`co_orders_x_products` (
  `oxp_ord_id` int(10) unsigned NOT NULL,
  `oxp_prd_id` int(10) unsigned NOT NULL,
  `oxp_quantity` int(10) unsigned NOT NULL,
  PRIMARY KEY (`oxp_ord_id`, `oxp_prd_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
