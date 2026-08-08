DROP TABLE IF EXISTS `co_invoices_fk`;

DROP TABLE IF EXISTS `co_customers_fk`;

CREATE TABLE `co_customers_fk` (
    `cst_id`   int(10) NOT NULL AUTO_INCREMENT,
    `cst_name` varchar(100) NULL,
    PRIMARY KEY (`cst_id`)
) ENGINE=InnoDB;

CREATE TABLE `co_invoices_fk` (
    `inv_id`     int(10) NOT NULL AUTO_INCREMENT,
    `inv_cst_id` int(10) NOT NULL,
    `inv_title`  varchar(100) NULL,
    PRIMARY KEY (`inv_id`),
    KEY `co_invoices_fk_inv_cst_id_index` (`inv_cst_id`),
    CONSTRAINT `co_invoices_fk_cst_fk`
        FOREIGN KEY (`inv_cst_id`)
        REFERENCES `co_customers_fk` (`cst_id`)
        ON UPDATE CASCADE ON DELETE RESTRICT
) ENGINE=InnoDB;
