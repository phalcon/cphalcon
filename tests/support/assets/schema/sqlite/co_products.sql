DROP TABLE IF EXISTS "co_products";

create table `co_products` (
    `prd_id` integer constraint prd_id_pk primary key autoincrement,
    `prd_name` text NULL,
    `prd_status_flag` integer NULL
);
