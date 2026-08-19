DROP TABLE IF EXISTS "co_invoices";

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
