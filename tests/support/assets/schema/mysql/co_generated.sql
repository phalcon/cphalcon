DROP TABLE IF EXISTS `co_generated`;

create table co_generated
(
    `gen_id`       int(10) auto_increment primary key,
    `gen_url`      varchar(255) not null,
    `gen_url_hash` binary(16) generated always as (unhex(md5(gen_url))) stored
);
