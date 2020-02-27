<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Migrations;

use PDO;

/**
 * Class AbstractMigration
 *
 * @property PDO    $connection
 * @property string $table
 */
abstract class AbstractMigration
{
    /**
     * @var PDO
     */
    protected $connection;

    /**
     * @var string
     */
    protected $table = '';

    /**
     * AbstractMigration constructor.
     *
     * @param PDO|null $connection
     */
    public function __construct(PDO $connection = null)
    {
        $this->connection = $connection;
        $this->clear();
    }

    /**
     * Create the table by running all the SQL statements for it
     */
    public function create()
    {
        $driver     = $this
            ->connection
            ->getAttribute(PDO::ATTR_DRIVER_NAME)
        ;
        $statements = $this->getSql($driver);
        foreach ($statements as $statement) {
            $this->connection->exec($statement);
        }
    }

    /**
     * Truncate the table
     */
    public function clear()
    {
        if ($this->connection) {
            $driver     = $this
                ->connection
                ->getAttribute(PDO::ATTR_DRIVER_NAME)
            ;
            if ($driver === 'mysql') {
                $this->connection->exec(
                    'truncate table ' . $this->table . ';'
                );
            } elseif ($driver === 'sqlite') {
                $this->connection->exec(
                    'delete from ' . $this->table . ';'
                );
            } else {
                $this->connection->exec(
                    'truncate table ' . $this->table . ' cascade;'
                );
            }
        }
    }

    /**
     * Drop the table
     */
    public function drop()
    {
        $this->connection->exec(
            'drop table if exists ' . $this->table . ';'
        );
    }

    /**
     * Get all the SQL statements that create this table
     *
     * @param string $driver
     *
     * @return array
     */
    public function getSql(string $driver): array
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
     * @param PDO $connection
     */
    public function setConnection(PDO $connection): void
    {
        $this->connection = $connection;
    }

    abstract protected function getSqlMysql(): array;

    abstract protected function getSqlSqlite(): array;

    abstract protected function getSqlPgsql(): array;

    abstract protected function getSqlSqlsrv(): array;
}
