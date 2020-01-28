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
    /**
     * @var AdapterInterface
     */
    protected $connection;

    /**
     * @var string
     */
    protected $table = '';

    /**
     * AbstractMigration constructor.
     *
     * @param AdapterInterface|null $connection
     */
    public function __construct(AdapterInterface $connection = null)
    {
        $this->connection = $connection;
    }

    /**
     * Create the table by running all the SQL statements for it
     */
    public function create()
    {
        $statements = $this->getSql();
        foreach ($statements as $statement) {
            $this->connection->execute($statement);
        }
    }

    /**
     * Truncate the table
     */
    public function clear()
    {
        $this->connection->execute(
            sprintf("delete from `%s`;", $this->table)
        );
    }

    /**
     * Drop the table
     */
    public function drop()
    {
        $this->connection->execute(
            sprintf("drop table if exists `%s`;", $this->table)
        );
    }

    /**
     * Get all the SQL statements that create this table
     *
     * @param string $driver
     *
     * @return array
     */
    public function getSql(string $driver = 'mysql'): array
    {
        switch ($driver) {
            case 'mysql':
                return $this->getSqlMysql();
            case 'sqlite':
                return $this->getSqlSqlite();
            case 'pgsql':
            case 'postgres':
                return $this->getSqlPgsql();
            case 'sqlsrv':
                return $this->getSqlSqlsrv();
            default:
                return [];
        }
    }

    /**
     * Sets the connection
     *
     * @param AdapterInterface $connection
     */
    public function setConnection(AdapterInterface $connection): void
    {
        $this->connection = $connection;
    }

    abstract protected function getSqlMysql(): array;
    abstract protected function getSqlSqlite(): array;
    abstract protected function getSqlPgsql(): array;
    abstract protected function getSqlSqlsrv(): array;
}
