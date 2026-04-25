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

namespace Phalcon\Tests\Support\Migrations;

use PDO;
use Phalcon\DataMapper\Pdo\Connection;
use PHPUnit\Framework\Assert;

/**
 * Class AbstractMigration
 *
 * @property PDO    $connection
 * @property string $table
 */
abstract class AbstractMigration
{
    /**
     * @var string
     */
    protected $table = '';

    /**
     * Migration constructor.
     *
     * @param PDO|Connection|null $connection
     */
    final public function __construct(
        protected PDO|Connection|null $connection = null,
        bool $withClear = true
    ) {
        $withClear && $this->clear();
    }

    /**
     * Truncate the table
     *
     * @return int The number of rows that were affected
     */
    public function clear(): int
    {
        if (! $this->connection) {
            return 0;
        }

        $driver = $this->getDriverName();

        if ($driver === 'mysql') {
            $this->connection->exec('SET FOREIGN_KEY_CHECKS=0;');
            $result = (int)$this->connection->exec('TRUNCATE TABLE ' . $this->table . ';');
            $this->connection->exec('SET FOREIGN_KEY_CHECKS=1;');

            return $result;
        }

        if ($driver === 'pgsql' || $driver === 'postgres') {
            return (int)$this->connection->exec(
                'TRUNCATE TABLE ' . $this->table . ' RESTART IDENTITY CASCADE;',
            );
        }

        return $this->connection->exec(
            'DELETE FROM ' . $this->table . ';',
        );
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
            ->getAttribute(PDO::ATTR_DRIVER_NAME)
        ;

        $statements = $this->getSql($driver);
        foreach ($statements as $statement) {
            $this->connection->exec($statement);
        }
    }

    /**
     * Drop the table
     *
     * @return void
     */
    public function drop(): void
    {
        $this->connection->exec(
            'drop table if exists ' . $this->table . ';',
        );
    }

    /**
     *  Retrieve a database connection driver name.
     *
     * @return string
     */
    public function getDriverName(): string
    {
        if (! $this->connection) {
            return '';
        }

        return $this
            ->connection
            ->getAttribute(PDO::ATTR_DRIVER_NAME)
        ;
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

    abstract protected function getSqlMysql(): array;

    abstract protected function getSqlPgsql(): array;

    abstract protected function getSqlSqlite(): array;

    abstract protected function getSqlSqlsrv(): array;

    /**
     * Get table name
     *
     * @return string
     */
    public function getTable(): string
    {
        return $this->table;
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
     * @param string $sql
     * @param array  $params
     *
     * @return int
     */
    protected function advanceSequence(string $column, int $id): void
    {
        if ($this->getDriverName() !== 'pgsql') {
            return;
        }

        $this->connection->exec(
            sprintf(
                "SELECT setval(pg_get_serial_sequence('%s', '%s'), %d)",
                $this->table,
                $column,
                $id
            )
        );
    }

    protected function execute(string $sql, array $params = []): int
    {
        if ($this->connection instanceof Connection) {
            $result = $this->connection->executeStatement($sql, $params);
        } else {
            $stmt   = $this->connection->prepare($sql);
            $stmt->execute($params);
            $result = $stmt->rowCount();
        }

        if (! $result) {
            $table  = $this->getTable();
            $driver = $this->getDriverName();
            Assert::fail(
                sprintf("Failed to insert row into table '%s' using '%s' driver", $table, $driver),
            );
        }

        return $result;
    }
}
