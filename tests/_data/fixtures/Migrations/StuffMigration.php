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

class StuffMigration extends AbstractMigration
{
    protected $table = "stuff";

    public function create()
    {
        $this->drop();

        $sql = <<<SQL
create table stuff
(
    stf_id          int(10) auto_increment primary key,
    stf_name        varchar(100) not null,
    stf_type        tinyint(3) unsigned not null
);
SQL;
        $this->connection->execute($sql);

        $this->insert(1, 'stuff data', 1);
    }

    /**
     * @param int              $id
     * @param string           $name
     * @param int              $type
     */
    public function insert(
        int $id,
        string $name,
        int $type
    ) {
        if (0 === $id) {
            $id = null;
        }

        $sql = <<<SQL
insert into stuff (stf_id, stf_name, stf_type)
values ({$id}, "{$name}", "{$type}");
SQL;

        $this->connection->execute($sql);
    }
}
