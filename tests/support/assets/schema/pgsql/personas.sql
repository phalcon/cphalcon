DROP TABLE IF EXISTS "personas";

create table personas
(
    cedula            char(15)       not null,
    tipo_documento_id smallint       not null,
    nombres           varchar(100)   not null default '',
    telefono          varchar(20)             default null,
    cupo              numeric(16, 2) not null,
    estado            char(1)        not null default 'A',
    primary key (cedula)
);
