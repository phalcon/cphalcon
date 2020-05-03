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

namespace Phalcon\Test\Fixtures\Migrations;

use PDO;
use Phalcon\DataMapper\Pdo\Connection;

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
     * Migration constructor.
     *
     * @param PDO|Connection|null $connection
     */
    final public function __construct($connection = null)
    {
        if ($connection !== null && !$connection instanceof PDO && !$connection instanceof Connection) {
            $actual = is_object($connection) ? get_class($connection) : $connection;
            throw new \InvalidArgumentException(sprintf('Unsupported connection type: %s', $actual));
        }

        if ($connection instanceof Connection) {
            $this->connection = $connection->getAdapter();
        } else {
            $this->connection = $connection;
        }

        $this->clear();
    }

    /**
     * Create the table by running all the SQL statements for it.
     *
     * @return void
     */
    public function create(): void
    {
        $driver = $this
            ->connection
            ->getAttribute(PDO::ATTR_DRIVER_NAME);

        $statements = $this->getSql($driver);
        foreach ($statements as $statement) {
            $this->connection->exec($statement);
        }
    }

    /**
     *  Retrieve a database connection driver name.
     *
     * @return string
     */
    public function getDriverName(): string
    {
        if (!$this->connection) {
            return '';
        }

        return $this
            ->connection
            ->getAttribute(PDO::ATTR_DRIVER_NAME);
    }

    /**
     * Truncate the table
     *
     * @return int The number of rows that were affected
     */
    public function clear(): int
    {
        if (!$this->connection) {
            return 0;
        }

        $driver = $this->getDriverName();

        if ($driver === 'mysql') {
            return $this->connection->exec(
                'truncate table ' . $this->table . ';'
            );
        }

        if ($driver === 'sqlite') {
            return $this->connection->exec(
                'delete from ' . $this->table . ';'
            );
        }

        return $this->connection->exec(
            'truncate table ' . $this->table . ' cascade;'
        );
    }

    /**
     * Drop the table
     *
     * @return void
     */
    public function drop(): void
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

    /**
     * Get table name
     *
     * @return string
     */
    public function getTable(): string
    {
        return $this->table;
    }

    abstract protected function getSqlMysql(): array;

    abstract protected function getSqlSqlite(): array;

    abstract protected function getSqlPgsql(): array;

    abstract protected function getSqlSqlsrv(): array;
}
