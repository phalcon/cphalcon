DROP TABLE IF EXISTS `foreign_key_parent`;

CREATE TABLE `foreign_key_parent` (
    `id`        int(10) NOT NULL AUTO_INCREMENT,
    `name`      varchar(70) NOT NULL,
    `refer_int` int NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE KEY `foreign_key_parent_refer_int` (`refer_int`)
) ENGINE=InnoDB;
