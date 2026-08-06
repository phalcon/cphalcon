DROP TABLE IF EXISTS "co_invoices_fk";

DROP TABLE IF EXISTS co_customers_fk;

CREATE TABLE co_customers_fk (
    cst_id   integer CONSTRAINT co_customers_fk_pk PRIMARY KEY AUTOINCREMENT,
    cst_name text
);

CREATE TABLE co_invoices_fk (
    inv_id     integer CONSTRAINT co_invoices_fk_pk PRIMARY KEY AUTOINCREMENT,
    inv_cst_id integer NOT NULL,
    inv_title  text,
    CONSTRAINT co_invoices_fk_cst_fk
        FOREIGN KEY (inv_cst_id)
        REFERENCES co_customers_fk (cst_id)
        ON UPDATE CASCADE ON DELETE RESTRICT
);
