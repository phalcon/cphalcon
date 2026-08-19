DROP TABLE IF EXISTS "foreign_key_parent";

CREATE TABLE foreign_key_parent (
    id        INTEGER PRIMARY KEY AUTOINCREMENT,
    name      varchar(70) NOT NULL,
    refer_int INTEGER     NOT NULL,
    UNIQUE (refer_int)
);
