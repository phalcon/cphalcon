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

class ObjectsMigration extends AbstractMigration
{
    protected $table = "objects";

    public function create()
    {
        $this->drop();

        $sql = <<<SQL
create table objects
(
    obj_id          int(10) auto_increment primary key,
    obj_name        varchar(100) not null,
    obj_type        tinyint(3) unsigned not null
);
SQL;
        $this->connection->execute($sql);

        $this->insert(1, 'random data', 1);
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
insert into objects (obj_id, obj_name, obj_type)
values ({$id}, "{$name}", "{$type}");
SQL;

        $this->connection->execute($sql);
    }
}
