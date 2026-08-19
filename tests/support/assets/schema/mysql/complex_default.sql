DROP TABLE IF EXISTS `complex_default`;

create table complex_default
(
    `id`           int(10) auto_increment primary key,
    `created`      TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    `updated`      TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `updated_null` TIMESTAMP NULL DEFAULT NULL ON UPDATE CURRENT_TIMESTAMP
);
