DROP TABLE IF EXISTS `table_with_string_field`;

create table `table_with_string_field`
            (
                `id`    int(10) unsigned not null auto_increment primary key,
                `field` varchar(255) not null
            ) engine=InnoDB default charset=utf8;
