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

class ObjectsMigration
{
    public function __invoke(AdapterInterface $db)
    {
        $sql = <<<SQL
drop table if exists objects
SQL;
        $db->execute($sql);

        $sql = <<<SQL
create table objects
(
    obj_id          int(10) auto_increment primary key,
    obj_name        varchar(100) not null,
    obj_type        tinyint(3) unsigned not null
);
SQL;
        $db->execute($sql);

        $sql = <<<SQL
insert into objects ( obj_id, obj_name, obj_type )
values (1, 'random data', 1);
SQL;
        $db->execute($sql);

        $sql = <<<SQL
drop table if exists stuff
SQL;
        $db->execute($sql);

        $sql = <<<SQL
create table stuff
(
    stf_id          int(10) auto_increment primary key,
    stf_name        varchar(100) not null,
    stf_type        tinyint(3) unsigned not null
);
SQL;
        $db->execute($sql);

        $sql = <<<SQL
insert into stuff ( stf_id, stf_name, stf_type )
values (2, 'stuff data', 1);
SQL;
        $db->execute($sql);
    }
}
