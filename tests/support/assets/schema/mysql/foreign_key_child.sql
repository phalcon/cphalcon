DROP TABLE IF EXISTS `foreign_key_child`;

CREATE TABLE `foreign_key_child` (
    `id`        int(10) NOT NULL AUTO_INCREMENT,
    `name`      varchar(70) NOT NULL,
    `child_int` int NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE KEY `foreign_key_child_child_int` (`child_int`)
) ENGINE=InnoDB;
