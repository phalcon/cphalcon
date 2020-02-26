

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
    inv_id          serial not null constraint co_invoices_pk primary key,
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





drop table if exists co_orders;

create table co_orders
(
    ord_id serial not null
    constraint ord_pk
      primary key,
      ord_name varchar(70)
);



drop table if exists public.co_orders_x_products;

create table public.co_orders_x_products
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







