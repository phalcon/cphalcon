



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
            


drop table if exists `objects`;
            
create table objects
    (
    obj_id     integer constraint objects_pk primary key autoincrement,
    obj_name   text not null,
    obj_type   integer not null
);
            








drop table if exists co_setters;
            
create table co_setters
    (
    id        integer constraint co_setters_defaults_pk primary key autoincrement,
    column1    text,
    column2    text,
    column3    text
);
            


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
            
