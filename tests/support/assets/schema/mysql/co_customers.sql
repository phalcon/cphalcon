DROP TABLE IF EXISTS `co_customers`;

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
