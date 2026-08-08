DROP TABLE IF EXISTS "table_with_string_field";

create table table_with_string_field
            (
                id    serial       constraint table_with_string_field_pk primary key,
                field varchar(255) not null
            );
