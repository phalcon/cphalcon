<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Support\Migrations;

class PhotoMigration extends AbstractMigration
{
    protected $table = 'photo';

    /**
     * @return int
     */
    public function insert(): int
    {
        return 0;
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `photo`;
            ",
            "
CREATE TABLE `photo` (
	`id`                int(10) unsigned not null auto_increment,
	`date_uploaded`     datetime not null default current_timestamp(),
	`original_filename` text not null collate 'utf8mb4_unicode_520_ci',
	`path`              text not null collate 'utf8mb4_unicode_520_ci',
	`width`             smallint(11) unsigned not null,
	`height`            smallint(11) unsigned not null,
	`thumb_path`        text not null collate 'utf8mb4_unicode_520_ci',
	`thumb_width`       smallint(5) unsigned not null,
	`thumb_height`      smallint(5) unsigned not null,
	`display_path`      text not null collate 'utf8mb4_unicode_520_ci',
	`display_width`     smallint(5) unsigned not null,
	`display_height`    smallint(5) unsigned not null,
	`mime_type`         VARCHAR(255) not null collate 'utf8mb4_unicode_520_ci',
	`filesize`          int(11) unsigned NULL DEFAULT NULL comment 'In bytes',
	`phash`             bigint(255) unsigned not null,
	`battles`           int(10) unsigned not null DEFAULT '0',
	`wins`              int(10) unsigned not null DEFAULT '0',
	primary key (`id`) using BTREE
) collate='utf8mb4_unicode_520_ci';
            ",
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [];
    }

    protected function getSqlSqlite(): array
    {
        return [
            "
drop table if exists photo;
            ",
            "
create table photo
(
    id                integer constraint photo_pk primary key autoincrement not null,
    date_uploaded     text    not null default (datetime('now')),
    original_filename text    not null,
    path              text    not null,
    width             integer not null,
    height            integer not null,
    thumb_path        text    not null,
    thumb_width       integer not null,
    thumb_height      integer not null,
    display_path      text    not null,
    display_width     integer not null,
    display_height    integer not null,
    mime_type         text    not null,
    filesize          integer null,
    phash             integer not null,
    battles           integer not null default 0,
    wins              integer not null default 0
);
            ",
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
