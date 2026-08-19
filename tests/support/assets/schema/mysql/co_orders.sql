DROP TABLE IF EXISTS `co_orders`;

CREATE TABLE `co_orders` (
    `ord_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
    `ord_name` VARCHAR(70) NULL,
    `ord_status_flag` tinyint(1) NULL,
    PRIMARY KEY (`ord_id`)
  ) ENGINE=InnoDB DEFAULT CHARSET=utf8;
