





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
            




drop table if exists co_products;
            
create table co_products
(
    prd_id serial not null
    constraint prd_pk
      primary key,
      prd_name varchar(70)
);
            

DROP TABLE IF EXISTS co_rb_test_model;CREATE TABLE co_rb_test_model (id SMALLINT, name VARCHAR(10) NOT NULL);


drop table if exists co_setters;
            
create table co_setters
(
    id      SERIAL PRIMARY KEY,
    column1 varchar(100) not null,
    column2 varchar(100) not null,
    column3 varchar(100) not null
);
            




drop table if exists table_with_uuid_primary;
            
create table table_with_uuid_primary
(
    uuid char(36) not null primary key,
    int_field int null
);
            


