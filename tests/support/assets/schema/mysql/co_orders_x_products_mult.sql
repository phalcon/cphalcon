DROP TABLE IF EXISTS `co_orders_x_products_mult`;

CREATE TABLE  `co_orders_x_products_mult` (
  `oxp_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `oxp_ord_id` int(10) unsigned NOT NULL,
  `oxp_ord_status_flag` tinyint(1) NOT NULL,
  `oxp_prd_id` int(10) unsigned NOT NULL,
  `oxp_prd_status_flag` tinyint(1) NOT NULL,
  `oxp_quantity` int(10) unsigned NULL,
  PRIMARY KEY (`oxp_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
