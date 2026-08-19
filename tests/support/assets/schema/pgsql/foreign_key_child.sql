DROP TABLE IF EXISTS "foreign_key_child";

CREATE TABLE foreign_key_child (
    id        serial      not null,
    name      varchar(70) not null,
    child_int integer     not null,
    PRIMARY KEY (id),
    UNIQUE (child_int)
);
