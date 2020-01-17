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

/**
 * Class AbstractMigration
 *
 * @property AdapterInterface $connection
 * @property string           $table
 */
abstract class AbstractMigration
{
    protected $connection;

    protected $table = '';

    public function __construct(AdapterInterface $db)
    {
        $this->connection = $db;
    }

    public function __destruct()
    {
        $this->drop();
    }

    abstract public function create();

    public function clear()
    {
        $this->connection->execute(
            sprintf("delete from `%s`", $this->table)
        );
    }

    public function drop()
    {
        $this->connection->execute(
            sprintf("drop table if exists `%s`", $this->table)
        );
    }
}
