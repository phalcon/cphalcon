DROP TABLE IF EXISTS "table_with_string_field";

create table table_with_string_field
            (
                id    integer constraint table_with_string_field_pk primary key autoincrement not null,
                field text not null
            );
