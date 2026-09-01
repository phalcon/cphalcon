DROP TABLE IF EXISTS "foreign_key_parent";

CREATE TABLE foreign_key_parent (
    id        serial      not null,
    name      varchar(70) not null,
    refer_int integer     not null,
    PRIMARY KEY (id),
    UNIQUE (refer_int)
);

ALTER TABLE foreign_key_child
    ADD CONSTRAINT test_describereferences
    FOREIGN KEY (child_int)
    REFERENCES foreign_key_parent (refer_int)
    ON UPDATE CASCADE ON DELETE RESTRICT;
