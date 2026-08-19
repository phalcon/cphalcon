DROP TABLE IF EXISTS `ph_select`;

create table `ph_select`
(
    `sel_id`   int(11) unsigned not null auto_increment,
    `sel_name` varchar(16)      not null,
    `sel_text` varchar(32)               default null,
    primary key (`sel_id`)
);
