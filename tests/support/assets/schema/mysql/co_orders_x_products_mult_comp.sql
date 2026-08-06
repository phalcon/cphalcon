DROP TABLE IF EXISTS `co_orders_x_products_mult_comp`;

CREATE TABLE  `co_orders_x_products_mult_comp` (
  `oxp_ord_id` int(10) unsigned NOT NULL,
  `oxp_ord_status_flag` tinyint(1) NOT NULL,
  `oxp_prd_id` int(10) unsigned NOT NULL,
  `oxp_prd_status_flag` tinyint(1) NOT NULL,
  `oxp_quantity` int(10) unsigned NULL,
  PRIMARY KEY (`oxp_ord_id`, `oxp_prd_id`, `oxp_ord_status_flag`, `oxp_prd_status_flag`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
