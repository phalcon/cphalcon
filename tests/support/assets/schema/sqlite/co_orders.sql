DROP TABLE IF EXISTS "co_orders";

create table `co_orders` (
    `ord_id` integer constraint ord_id_pk primary key autoincrement,
    `ord_name` text NULL,
    `ord_status_flag` integer NULL
);
