DROP TABLE IF EXISTS "fractal_dates";

CREATE TABLE fractal_dates (
    id           serial       constraint fractal_dates_pk primary key,
    ftime        TIME(2),
    fdatetime    TIMESTAMP(2),
    ftimestamp   TIMESTAMP(2),
    cuuid        uuid         not null default gen_random_uuid()
);
