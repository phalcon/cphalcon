
CREATE SCHEMA IF NOT EXISTS private;


drop table if exists album;
            


create table album
(
    id       serial        constraint album_pk primary key,
    name     varchar(100)  not null,
    album_id integer       null,
    photo_id integer       null
);
            


create index index_foreignkey_album_album on album (album_id);
            


create index album_ibfk_2 on album (photo_id);
            


drop table if exists album_photo;
            


create table album_photo
(
    id       serial   constraint album_photo_pk primary key,
    photo_id integer  null,
    album_id integer  null,
    position integer  not null default 999999999,
    constraint UQ_cadf1c545153612614511f15197cae7b6dacac97 unique (album_id, photo_id)
);
            


create index index_foreignkey_album_photo_photo on album_photo (photo_id);
            


create index index_foreignkey_album_photo_album on album_photo (album_id);
            


drop table if exists albums;
            


create table albums
(
    id         serial       constraint albums_pk primary key,
    artists_id integer      not null,
    name       varchar(100) not null
);
            


create index albums_artists_id_index on albums (artists_id);
            


drop table if exists artists;
            


create table artists
(
    id   serial constraint artists_pk primary key,
    name varchar(100) not null
);
            


drop table if exists complex_default;
            


create table complex_default
(
    id           SERIAL PRIMARY KEY,
    created      TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated      TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_null TIMESTAMP NULL DEFAULT NULL
);
            


CREATE OR REPLACE FUNCTION update_timestamp()
RETURNS TRIGGER AS $$
BEGIN
   NEW.updated = NOW(); 
   NEW.updated_null = NOW();
   RETURN NEW;
END;
$$ language 'plpgsql';
            


CREATE TRIGGER update_timestamp BEFORE UPDATE
ON complex_default FOR EACH ROW EXECUTE PROCEDURE 
update_timestamp();
            


drop table if exists co_customers_defaults;
            


create table co_customers_defaults
(
    cst_id          serial not null constraint co_customers_defaults_pk primary key,
    cst_status_flag smallint   not null DEFAULT 1,
    cst_name_last   varchar(100) not null DEFAULT 'cst_default_lastName',
    cst_name_first  varchar(50)  not null DEFAULT 'cst_default_firstName'
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
    cst_id          serial not null constraint co_customers_pk primary key,
    cst_status_flag smallint   null,
    cst_name_last   varchar(100) null,
    cst_name_first  varchar(50)  null
);
            


create index co_customers_cst_status_flag_index
    on co_customers (cst_status_flag);
            


create index co_customers_cst_name_last_index
    on co_customers (cst_name_last);
            


create index co_customers_cst_name_first_index
    on co_customers (cst_name_first);
            


DROP TABLE IF EXISTS co_dialect;
            


CREATE TABLE co_dialect (
    field_primary            INTEGER GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    field_blob               BYTEA,
    field_binary             BYTEA,
    field_bit                BIT(10),
    field_bit_default        BIT(10) DEFAULT B'1',
    field_bigint             BIGINT,
    field_bigint_default     BIGINT DEFAULT 1,
    field_boolean            SMALLINT,
    field_boolean_default    SMALLINT DEFAULT 1,
    field_char               CHAR(10),
    field_char_default       CHAR(10) DEFAULT 'ABC',
    field_decimal            NUMERIC(10,4),
    field_decimal_default    NUMERIC(10,4) DEFAULT 14.5678,
    field_enum               VARCHAR(10),
    field_integer            INTEGER,
    field_integer_default    INTEGER DEFAULT 1,
    field_json               JSONB,
    field_float              REAL,
    field_float_default      REAL DEFAULT 14.5678,
    field_date               DATE,
    field_date_default       DATE DEFAULT '2018-10-01',
    field_datetime           TIMESTAMP,
    field_datetime_default   TIMESTAMP DEFAULT '2018-10-01 12:34:56',
    field_time               TIME,
    field_time_default       TIME DEFAULT '12:34:56',
    field_timestamp          TIMESTAMP,
    field_timestamp_default  TIMESTAMP DEFAULT '2018-10-01 12:34:56',
    field_mediumint          INTEGER,
    field_mediumint_default  INTEGER DEFAULT 1,
    field_smallint           SMALLINT,
    field_smallint_default   SMALLINT DEFAULT 1,
    field_tinyint            SMALLINT,
    field_tinyint_default    SMALLINT DEFAULT 1,
    field_longtext           TEXT,
    field_mediumtext         TEXT,
    field_tinytext           TEXT,
    field_text               TEXT,
    field_varbinary          BYTEA,
    field_varchar            VARCHAR(10),
    field_varchar_default    VARCHAR(10) DEFAULT 'D',
    UNIQUE (field_integer)
);
            

CREATE INDEX dialect_table_index ON co_dialect(field_bigint);

CREATE INDEX dialect_table_two_fields ON co_dialect(field_char, field_char_default);

COMMENT ON COLUMN co_dialect.field_primary IS 'field_primary field';

COMMENT ON COLUMN co_dialect.field_blob IS 'field_blob field';

COMMENT ON COLUMN co_dialect.field_binary IS 'field_binary field';

COMMENT ON COLUMN co_dialect.field_bit IS 'field_bit field';

COMMENT ON COLUMN co_dialect.field_bit_default IS 'field_bit_default field';

COMMENT ON COLUMN co_dialect.field_bigint IS 'field_bigint field';

COMMENT ON COLUMN co_dialect.field_bigint_default IS 'field_bigint_default field';

COMMENT ON COLUMN co_dialect.field_boolean IS 'field_boolean field';

COMMENT ON COLUMN co_dialect.field_boolean_default IS 'field_boolean_default field';

COMMENT ON COLUMN co_dialect.field_char IS 'field_char field';

COMMENT ON COLUMN co_dialect.field_char_default IS 'field_char_default field';

COMMENT ON COLUMN co_dialect.field_decimal IS 'field_decimal field';

COMMENT ON COLUMN co_dialect.field_decimal_default IS 'field_decimal_default field';

COMMENT ON COLUMN co_dialect.field_enum IS 'field_enum field';

COMMENT ON COLUMN co_dialect.field_integer IS 'field_integer field';

COMMENT ON COLUMN co_dialect.field_integer_default IS 'field_integer_default field';

COMMENT ON COLUMN co_dialect.field_json IS 'field_json field';

COMMENT ON COLUMN co_dialect.field_float IS 'field_float field';

COMMENT ON COLUMN co_dialect.field_float_default IS 'field_float_default field';

COMMENT ON COLUMN co_dialect.field_date IS 'field_date field';

COMMENT ON COLUMN co_dialect.field_date_default IS 'field_date_default field';

COMMENT ON COLUMN co_dialect.field_datetime IS 'field_datetime field';

COMMENT ON COLUMN co_dialect.field_datetime_default IS 'field_datetime_default field';

COMMENT ON COLUMN co_dialect.field_time IS 'field_time field';

COMMENT ON COLUMN co_dialect.field_time_default IS 'field_time_default field';

COMMENT ON COLUMN co_dialect.field_timestamp IS 'field_timestamp field';

COMMENT ON COLUMN co_dialect.field_timestamp_default IS 'field_timestamp_default field';

COMMENT ON COLUMN co_dialect.field_mediumint IS 'field_mediumint field';

COMMENT ON COLUMN co_dialect.field_mediumint_default IS 'field_mediumint_default field';

COMMENT ON COLUMN co_dialect.field_smallint IS 'field_smallint field';

COMMENT ON COLUMN co_dialect.field_smallint_default IS 'field_smallint_default field';

COMMENT ON COLUMN co_dialect.field_tinyint IS 'field_tinyint field';

COMMENT ON COLUMN co_dialect.field_tinyint_default IS 'field_tinyint_default field';

COMMENT ON COLUMN co_dialect.field_longtext IS 'field_longtext field';

COMMENT ON COLUMN co_dialect.field_mediumtext IS 'field_mediumtext field';

COMMENT ON COLUMN co_dialect.field_tinytext IS 'field_tinytext field';

COMMENT ON COLUMN co_dialect.field_text IS 'field_text field';

COMMENT ON COLUMN co_dialect.field_varbinary IS 'field_varbinary field';

COMMENT ON COLUMN co_dialect.field_varchar IS 'field_varchar field';

COMMENT ON COLUMN co_dialect.field_varchar_default IS 'field_varchar_default field';


DROP TABLE IF EXISTS foreign_key_child;
            


DROP TABLE IF EXISTS foreign_key_parent;
            


CREATE TABLE foreign_key_parent (
    id        serial      not null,
    name      varchar(70) not null,
    refer_int integer     not null,
    PRIMARY KEY (id),
    UNIQUE (refer_int)
);
            


CREATE TABLE foreign_key_child (
    id        serial      not null,
    name      varchar(70) not null,
    child_int integer     not null,
    PRIMARY KEY (id),
    UNIQUE (child_int)
);
            


ALTER TABLE foreign_key_child
    ADD CONSTRAINT test_describereferences
    FOREIGN KEY (child_int)
    REFERENCES foreign_key_parent (refer_int)
    ON UPDATE CASCADE ON DELETE RESTRICT;
            


drop table if exists fractal_dates;
            


CREATE TABLE fractal_dates (
    id           serial       constraint fractal_dates_pk primary key,
    ftime        TIME(2),
    fdatetime    TIMESTAMP(2),
    ftimestamp   TIMESTAMP(2)
);
            


drop table if exists co_invoices;
            


create table co_invoices
(
    inv_id          serial constraint co_invoices_pk primary key,
    inv_cst_id      integer,
    inv_status_flag smallint,
    inv_title       varchar(100),
    inv_total       numeric(10, 2),
    inv_created_at  timestamp
);
            


create index co_invoices_inv_created_at_index
    on co_invoices (inv_created_at);
            


create index co_invoices_inv_cst_id_index
    on co_invoices (inv_cst_id);
            


create index co_invoices_inv_status_flag_index
    on co_invoices (inv_status_flag);
            


drop table if exists co_manufacturers;


create table co_manufacturers
(
    id serial not null
    constraint manufacturers_pk
      primary key,
    name varchar(100) not null,
    country varchar(100) null,
    founded_year int not null
);
            


drop table if exists no_primary_key;
            


create table no_primary_key
(
    nokey_id   integer,
    nokey_name varchar(100) not null
);
            


drop table if exists objects;
            


create table objects
(
    obj_id serial not null constraint objects_pk primary key,
    obj_name varchar(100) not null,
    obj_type smallint not null
);
            


drop table if exists co_orders;
            


create table co_orders
(
    ord_id serial not null
    constraint ord_pk
      primary key,
      ord_name varchar(70)
);
            


drop table if exists private.co_orders_x_products;
            


create table private.co_orders_x_products
(
    oxp_ord_id int not null,
    oxp_prd_id int not null,
    oxp_quantity int not null
);
            


drop table if exists personas;
            


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
            


drop table if exists photo;
            


create table photo
(
    id                serial        constraint photo_pk primary key,
    date_uploaded     timestamp     not null default current_timestamp,
    original_filename text          not null,
    path              text          not null,
    width             smallint      not null,
    height            smallint      not null,
    thumb_path        text          not null,
    thumb_width       smallint      not null,
    thumb_height      smallint      not null,
    display_path      text          not null,
    display_width     smallint      not null,
    display_height    smallint      not null,
    mime_type         varchar(255)  not null,
    filesize          integer       null,
    phash             bigint        not null,
    battles           integer       not null default 0,
    wins              integer       not null default 0
);
            


drop table if exists private.co_orders_x_products;
            


create table private.co_orders_x_products
(
    oxp_ord_id  int not null,
    oxp_prd_id  int not null,
    oxp_quantity int not null
);
            


drop table if exists co_products;
            


create table co_products
(
    prd_id serial not null
    constraint prd_pk
      primary key,
      prd_name varchar(70)
);
            

DROP TABLE IF EXISTS co_rb_test_model;

CREATE TABLE co_rb_test_model (id SMALLINT, name VARCHAR(10) NOT NULL);


drop table if exists ph_select;
            


create table ph_select
(
    sel_id   serial      not null constraint ph_select_pk primary key,
    sel_name varchar(16) not null,
    sel_text varchar(32)          default null
);
            


drop table if exists co_setters;
            


create table co_setters
(
    id      SERIAL PRIMARY KEY,
    column1 varchar(100) not null,
    column2 varchar(100) not null,
    column3 varchar(100) not null
);
            


drop table if exists songs;
            


create table songs
(
    id        serial       constraint songs_pk primary key,
    albums_id integer      not null,
    name      varchar(100) not null
);
            


create index songs_albums_id_index on songs (albums_id);
            


drop table if exists co_sources;
            


create table co_sources
(
    id       serial       constraint co_sources_pk primary key,
    username varchar(100) null,
    source   varchar(100) null
);
            


create index co_sources_username_index on co_sources (username);
            

drop table if exists table_with_string_field;

create table table_with_string_field
            (
                id    serial       constraint table_with_string_field_pk primary key,
                field varchar(255) not null
            );


drop table if exists table_with_uuid_primary;
            


create table table_with_uuid_primary
(
    uuid char(36) not null primary key,
    int_field int null
);
            


drop table if exists stuff;
            


create table stuff
(
    stf_id   serial       constraint stuff_pk primary key,
    stf_name varchar(100) not null,
    stf_type smallint     not null
);
            
