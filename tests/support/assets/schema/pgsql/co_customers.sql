DROP TABLE IF EXISTS "co_customers";

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
