

drop table if exists `complex_default`;
            
create table complex_default
(
    `id`           int(10) auto_increment primary key,
    `created`      TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    `updated`      TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `updated_null` TIMESTAMP NULL DEFAULT NULL ON UPDATE CURRENT_TIMESTAMP
);
            


drop table if exists `co_customers_defaults`;
            
create table co_customers_defaults
(
    `cst_id`          int(10) auto_increment primary key,
    `cst_status_flag` tinyint(1)   not null DEFAULT 1,
    `cst_name_last`   varchar(100) not null DEFAULT 'cst_default_lastName',
    `cst_name_first`  varchar(50)  not null DEFAULT 'cst_default_firstName'
);
            
create index co_customers_defaults_cst_status_flag_index
    on `co_customers_defaults` (`cst_status_flag`);
            
create index co_customers_defaults_cst_name_last_index
    on `co_customers_defaults` (`cst_name_last`);
            
create index co_customers_defaults_cst_name_first_index
    on `co_customers_defaults` (`cst_name_first`);
            


drop table if exists `co_customers`;
            
create table co_customers
(
    `cst_id`          int(10) auto_increment primary key,
    `cst_status_flag` tinyint(1)   null,
    `cst_name_last`   varchar(100) null,
    `cst_name_first`  varchar(50)  null
);
            
create index co_customers_cst_status_flag_index
    on `co_customers` (`cst_status_flag`);
            
create index co_customers_cst_name_last_index
    on `co_customers` (`cst_name_last`);
            
create index co_customers_cst_name_first_index
    on `co_customers` (`cst_name_first`);
            


drop table if exists `co_dialect`;
            
create table co_dialect
(
  field_primary            int auto_increment primary key,
  field_blob               blob                                        null,
  field_binary             binary(10)                                  null,
  field_bit                bit(10)                                     null,
  field_bit_default        bit(10)       default b'1'                  null,
  field_bigint             bigint        unsigned                      null,
  field_bigint_default     bigint        default 1                     null,
  field_boolean            tinyint(1)    unsigned                      null,
  field_boolean_default    tinyint(1)    default 1                     null,
  field_char               char(10)                                    null,
  field_char_default       char(10)      default 'ABC'                 null,
  field_decimal            decimal(10,4)                               null,
  field_decimal_default    decimal(10,4) default 14.5678               null,
  field_enum               enum('xs', 's', 'm', 'l', 'xl', 'internal') null,
  field_integer            int(10)                                     null,
  field_integer_default    int(10)       default 1                     null,
  field_json               json                                        null,
  field_float              float(10,4)                                 null,
  field_float_default      float(10,4)   default 14.5678               null,
  field_date               date                                        null,
  field_date_default       date          default '2018-10-01'          null,
  field_datetime           datetime                                    null,
  field_datetime_default   datetime      default '2018-10-01 12:34:56' null,
  field_time               time                                        null,
  field_time_default       time          default '12:34:56'            null,
  field_timestamp          timestamp                                   null,
  field_timestamp_default  timestamp     default '2018-10-01 12:34:56' null,
  field_mediumint          mediumint(10) unsigned                      null,
  field_mediumint_default  mediumint(10) default 1                     null,
  field_smallint           smallint(10)  unsigned                      null,
  field_smallint_default   smallint(10)  default 1                     null,
  field_tinyint            tinyint(10)   unsigned                      null,
  field_tinyint_default    tinyint(10)   default 1                     null,
  field_longtext           longtext                                    null,
  field_mediumtext         mediumtext                                  null,
  field_tinytext           tinytext                                    null,
  field_text               text                                        null,
  field_varbinary          varbinary(10)                               null,
  field_varchar            varchar(10)                                 null,
  field_varchar_default    varchar(10)   default 'D'                   null,
  unique key dialect_table_unique (field_integer),
  key dialect_table_index (field_bigint),
  key dialect_table_two_fields (field_char, field_char_default)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
            


drop table if exists `fractal_dates`;
            
create table fractal_dates
(
    `id`           int(10)      auto_increment primary key,
    `ftime`        time(2)      null,
    `fdatetime`    datetime(2)  null,
    `ftimestamp`   timestamp(2) null
);
            


drop table if exists `co_invoices`;
            
create table co_invoices
(
    `inv_id`          int(10) auto_increment primary key,
    `inv_cst_id`      int(10)      null,
    `inv_status_flag` tinyint(1)   null,
    `inv_title`       varchar(100) null,
    `inv_total`       float(10, 2) null,
    `inv_created_at`  datetime     null
);
            
create index co_invoices_inv_cst_id_index
    on `co_invoices` (`inv_cst_id`);
            
create index co_invoices_inv_status_flag_index
    on `co_invoices` (`inv_status_flag`);
            
create index co_invoices_inv_created_at_index
    on `co_invoices` (`inv_created_at`);
            


drop table if exists objects;
            
create table objects
(
    `obj_id`   int(10) auto_increment primary key,
    `obj_name` varchar(100) not null,
    `obj_type` tinyint(3) unsigned not null
);
            


drop table if exists `co_orders`;
            
CREATE TABLE `co_orders` (
    `ord_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
    `ord_name` VARCHAR(70) NULL,
    PRIMARY KEY (`ord_id`)
  ) ENGINE=InnoDB DEFAULT CHARSET=utf8;
            


drop table if exists private.`co_orders_x_products`;
            
CREATE TABLE private.`co_orders_x_products` (
  `oxp_ord_id` int(10) unsigned NOT NULL,
  `oxp_prd_id` int(10) unsigned NOT NULL,
  `oxp_quantity` int(10) unsigned NOT NULL,
  PRIMARY KEY (`oxp_ord_id`, `oxp_prd_id` )
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
            


drop table if exists `co_products`;
            
CREATE TABLE `co_products` (
    `prd_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
    `prd_name` VARCHAR(70) NULL,
    PRIMARY KEY (`prd_id`)
  ) ENGINE=InnoDB DEFAULT CHARSET=utf8;
            


drop table if exists `co_setters`;
            
create table co_setters
(
    `column1`  varchar(100) null,
    `column2`  varchar(100) null,
    `column3`  varchar(100) null
);
            


drop table if exists `co_sources`;
            
create table co_sources
(
    `id`       int(10) auto_increment primary key,
    `username` varchar(100) null,
    `source`   varchar(100) null
);
            
create index co_sources_username_index
    on co_sources (username);
            


drop table if exists `table_with_uuid_primary`;
            
create table table_with_uuid_primary
(
    `uuid`          char(36) not null primary key,
    `int_field`     int null
);
            


drop table if exists `stuff`;
            
create table stuff
(
    `stf_id`   int(10) auto_increment primary key,
    `stf_name` varchar(100) not null,
    `stf_type` tinyint(3) unsigned not null
);
            
