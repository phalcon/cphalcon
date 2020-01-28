<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Migrations;

use Phalcon\Db\Adapter\AdapterInterface;

class SourcesMigration extends AbstractMigration
{
    protected $table = "co_sources";

    public function getSql(): array
    {
        return [
            "
drop table if exists `co_sources`
            ",
            "
create table co_sources
(
    id       int(10) auto_increment primary key,
    username varchar(100) null,
    source   varchar(100) null
);
            ",
            "
create index co_sources_username_index
    on co_sources (username);
            ",
//            $this->insert($db, 1, 'darth', 'vader');
        ];
    }

    /**
     * @param int              $id
     * @param string           $username
     * @param string           $source
     */
    public function insert(
        int $id,
        string $username,
        string $source
    ) {
        if (0 === $id) {
            $id = null;
        }

        $sql = <<<SQL
insert into co_sources (id, username, source)
values ({$id}, "{$username}", "{$source}");
SQL;

        $this->connection->execute($sql);
    }
}
