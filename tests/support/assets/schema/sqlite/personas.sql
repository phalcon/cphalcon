DROP TABLE IF EXISTS "personas";

create table personas
(
    cedula            text    not null,
    tipo_documento_id integer not null,
    nombres           text    not null default '',
    telefono          text             default null,
    cupo              real    not null default 0,
    estado            text    not null default 'A',
    primary key (cedula)
);
