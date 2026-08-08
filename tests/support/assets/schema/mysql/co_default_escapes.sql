DROP TABLE IF EXISTS `co_default_escapes`;

create table co_default_escapes
(
    `field_id`         int(10) auto_increment primary key,
    `field_quote`      varchar(20) not null default 'it''s',
    `field_apostrophe` varchar(20) not null default '''',
    `field_backslash`  varchar(20) not null default 'a\\b',
    `field_newline`    varchar(20) not null default 'a\nb',
    `field_tab`        varchar(20) not null default 'a\tb',
    `field_null_word`  varchar(20) not null default 'NULL',
    `field_empty`      varchar(20) not null default '',
    `field_bit`        bit(1)      not null default b'1',
    `field_nullable`   varchar(20)     null default null
);
