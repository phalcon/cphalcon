<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Support\Migrations;

/**
 * Class SourcesMigration
 */
class SourcesMigration extends AbstractMigration
{
    protected $table = "co_sources";

    public function insert(
        int $id,
        string $username,
        string $source,
    ) {
        $sql = <<<SQL
insert into co_sources (
    id, username, source
) values (
    :id, :username, :source
);
SQL;

        $params = [
            ':id'       => $id,
            ':username' => $username,
            ':source'   => $source,
        ];

        return $this->execute($sql, $params);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `co_sources`;
            ",
            "
create table co_sources
(
    `id`       int(10) auto_increment primary key,
    `username` varchar(100) null,
    `source`   varchar(100) null
);
            ",
            "
create index co_sources_username_index
    on co_sources (username);
            ",
            //            $this->insert($db, 1, 'darth', 'vader');
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
drop table if exists co_sources;
            ",
            "
create table co_sources
    (
    id          integer constraint co_sources_pk primary key autoincrement,
    username    text,
    source      text
);
            ",
            "
create index co_sources_username_index
    on co_sources (username);
            ",
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
