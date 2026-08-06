DROP TABLE IF EXISTS "co_invoices_fk";

DROP TABLE IF EXISTS co_customers_fk;

CREATE TABLE co_customers_fk (
    cst_id   serial PRIMARY KEY,
    cst_name varchar(100)
);

CREATE TABLE co_invoices_fk (
    inv_id     serial PRIMARY KEY,
    inv_cst_id integer NOT NULL,
    inv_title  varchar(100),
    CONSTRAINT co_invoices_fk_cst_fk
        FOREIGN KEY (inv_cst_id)
        REFERENCES co_customers_fk (cst_id)
        ON UPDATE CASCADE ON DELETE RESTRICT
);
