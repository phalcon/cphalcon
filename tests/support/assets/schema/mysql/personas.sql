DROP TABLE IF EXISTS `personas`;

create table `personas`
(
    `cedula`            char(15)        not null,
    `tipo_documento_id` int(3) unsigned not null,
    `nombres`           varchar(100)    not null default '',
    `telefono`          varchar(20)              default null,
    `cupo`              decimal(16, 2)  not null,
    `estado`            enum ('A','I','X') not null,
    primary key (`cedula`)
);
