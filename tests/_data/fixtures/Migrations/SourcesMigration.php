<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Migrations;

use Phalcon\Db\Adapter\AdapterInterface;

class SourcesMigration
{
    public function __invoke(AdapterInterface $db)
    {
        $sql = <<<SQL
drop table if exists `co_sources`
SQL;
        $db->execute($sql);

        $sql = <<<SQL
create table co_sources
(
    id       int(10) auto_increment primary key,
    username varchar(100) null,
    source   varchar(100) null
);
SQL;
        $db->execute($sql);

        $sql = <<<SQL
create index co_sources_username_index
    on co_sources (username);
SQL;
        $db->execute($sql);

        $sql = <<<SQL
insert into co_sources (id, username, source) 
values (1, 'darth', 'conflict');
SQL;
        $db->execute($sql);
    }
}
