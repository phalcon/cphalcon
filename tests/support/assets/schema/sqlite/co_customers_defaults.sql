DROP TABLE IF EXISTS "co_customers_defaults";

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
