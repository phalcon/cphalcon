DROP TABLE IF EXISTS "foreign_key_child";

CREATE TABLE foreign_key_child (
    id        INTEGER PRIMARY KEY AUTOINCREMENT,
    name      varchar(70) NOT NULL,
    child_int INTEGER     NOT NULL,
    UNIQUE (child_int)
);
