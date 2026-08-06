DROP TABLE IF EXISTS `co_manufacturers`;

CREATE TABLE `co_manufacturers` (
    `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
    `name` VARCHAR(100) NOT NULL,
    `country` VARCHAR(100) NULL,
    `founded_year` INT NOT NULL,
    PRIMARY KEY (`id`)
  ) ENGINE=InnoDB DEFAULT CHARSET=utf8;
