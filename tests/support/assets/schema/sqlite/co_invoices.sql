DROP TABLE IF EXISTS "co_invoices";

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
