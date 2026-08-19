DROP TABLE IF EXISTS `co_customers_defaults`;

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
