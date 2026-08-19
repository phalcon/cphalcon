DROP TABLE IF EXISTS "co_customers";

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
