DROP TABLE IF EXISTS `co_invoices`;

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
