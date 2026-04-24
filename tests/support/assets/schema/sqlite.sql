

drop table if exists album;
            


create table album
(
    id       integer constraint album_pk primary key autoincrement not null,
    name     text    not null,
    album_id integer null,
    photo_id integer null
);
            


drop table if exists album_photo;
            


create table album_photo
(
    id       integer constraint album_photo_pk primary key autoincrement not null,
    photo_id integer null,
    album_id integer null,
    position integer not null default 999999999
);
            


drop table if exists albums;
            


create table albums
(
    id         integer constraint albums_pk primary key autoincrement not null,
    artists_id integer not null,
    name       text    not null
);
            


create index albums_artists_id_index on albums (artists_id);
            


drop table if exists artists;
            


create table artists
(
    id   integer constraint artists_pk primary key autoincrement not null,
    name text not null
);
            


drop table if exists complex_default;
            


create table complex_default
(
    id           integer constraint complex_default_pk primary key autoincrement,
    created      text default (datetime('now')),
    updated      text default (datetime('now')),
    updated_null text null
);
            


drop table if exists co_customers_defaults;
            


create table co_customers_defaults
(
    cst_id          integer constraint co_customers_defaults_pk primary key autoincrement,
    cst_status_flag integer      not null DEFAULT 1,
    cst_name_last   text         not null DEFAULT 'cst_default_lastName',
    cst_name_first  text         not null DEFAULT 'cst_default_firstName'
);
            


create index co_customers_defaults_cst_status_flag_index
    on co_customers_defaults (cst_status_flag);
            


create index co_customers_defaults_cst_name_last_index
    on co_customers_defaults (cst_name_last);
            


create index co_customers_defaults_cst_name_first_index
    on co_customers_defaults (cst_name_first);
            


drop table if exists co_customers;
            


create table co_customers
(
    cst_id          integer constraint co_customers_pk primary key autoincrement,
    cst_status_flag integer      null,
    cst_name_last   text         null,
    cst_name_first  text         null
);
            


create index co_customers_cst_status_flag_index
    on co_customers (cst_status_flag);
            


create index co_customers_cst_name_last_index
    on co_customers (cst_name_last);
            


create index co_customers_cst_name_first_index
    on co_customers (cst_name_first);
            


drop table if exists co_dialect;
            


create table co_dialect
(
    field_primary           integer constraint co_dialect_pk primary key autoincrement,
    field_blob              blob    null,
    field_binary            blob    null,
    field_bit               integer null,
    field_bit_default       integer default 1    null,
    field_bigint            integer null,
    field_bigint_default    integer default 1    null,
    field_boolean           integer null,
    field_boolean_default   integer default 1    null,
    field_char              text    null,
    field_char_default      text    default 'ABC' null,
    field_decimal           real    null,
    field_decimal_default   real    default 14.5678 null,
    field_enum              text    null,
    field_integer           integer null,
    field_integer_default   integer default 1    null,
    field_json              text    null,
    field_float             real    null,
    field_float_default     real    default 14.5678 null,
    field_date              text    null,
    field_date_default      text    default '2018-10-01' null,
    field_datetime          text    null,
    field_datetime_default  text    default '2018-10-01 12:34:56' null,
    field_time              text    null,
    field_time_default      text    default '12:34:56' null,
    field_timestamp         text    null,
    field_timestamp_default text    default '2018-10-01 12:34:56' null,
    field_mediumint         integer null,
    field_mediumint_default integer default 1    null,
    field_smallint          integer null,
    field_smallint_default  integer default 1    null,
    field_tinyint           integer null,
    field_tinyint_default   integer default 1    null,
    field_longtext          text    null,
    field_mediumtext        text    null,
    field_tinytext          text    null,
    field_text              text    null,
    field_varbinary         blob    null,
    field_varchar           text    null,
    field_varchar_default   text    default 'D'  null
);
            


drop table if exists co_invoices;
            


create table co_invoices
    (
    inv_id          integer constraint co_invoices_pk primary key autoincrement not null,
    inv_cst_id      integer,
    inv_status_flag integer,
    inv_title       text,
    inv_total       real,
    inv_created_at  text
);
            


create index co_invoices_inv_cst_id_index
    on co_invoices (inv_cst_id);
            


create index co_invoices_inv_status_flag_index
    on co_invoices (inv_status_flag);
            


create index co_invoices_inv_created_at_index
    on co_invoices (inv_created_at);
            


drop table if exists co_manufacturers;


create table co_manufacturers (
    id integer constraint co_manufacturers_pk primary key autoincrement,
    name text not null,
    country text null,
    founded_year integer not null
);
            


drop table if exists `objects`;
            


create table objects
    (
    obj_id     integer constraint objects_pk primary key autoincrement,
    obj_name   text not null,
    obj_type   integer not null
);
            


drop table if exists personas;
            


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
            


drop table if exists photo;
            


create table photo
(
    id                integer constraint photo_pk primary key autoincrement not null,
    date_uploaded     text    not null default (datetime('now')),
    original_filename text    not null,
    path              text    not null,
    width             integer not null,
    height            integer not null,
    thumb_path        text    not null,
    thumb_width       integer not null,
    thumb_height      integer not null,
    display_path      text    not null,
    display_width     integer not null,
    display_height    integer not null,
    mime_type         text    not null,
    filesize          integer null,
    phash             integer not null,
    battles           integer not null default 0,
    wins              integer not null default 0
);
            

DROP TABLE IF EXISTS co_rb_test_model;

CREATE TABLE co_rb_test_model (id integer, name text not null);


drop table if exists ph_select;
            


create table ph_select
(
    sel_id   integer not null,
    sel_name text    not null,
    sel_text text             default null,
    primary key (sel_id autoincrement)
);
            


drop table if exists co_setters;
            


create table co_setters
    (
    id        integer constraint co_setters_defaults_pk primary key autoincrement,
    column1    text,
    column2    text,
    column3    text
);
            


drop table if exists songs;
            


create table songs
(
    id        integer constraint songs_pk primary key autoincrement not null,
    albums_id integer not null,
    name      text    not null
);
            


create index songs_albums_id_index on songs (albums_id);
            


drop table if exists co_sources;
            


create table co_sources
    (
    id          integer constraint co_sources_pk primary key autoincrement,
    username    text,
    source      text
);
            


create index co_sources_username_index
    on co_sources (username);
            


drop table if exists table_with_uuid_primary;
            


create table table_with_uuid_primary
(
    uuid        text constraint uuid_pk primary key,
    int_field   integer
);
            


drop table if exists stuff;
            


create table stuff
(
    stf_id      integer constraint stf_id_pk primary key autoincrement,
    stf_name    text not null,
    stf_type    integer not null
);
            
