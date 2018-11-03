<?php

namespace Helper\Db\Connection;

use Phalcon\Db\Adapter\Pdo\Sqlite;

/**
 * Helper\Db\Connection\SqliteFactory
 *
 * @package Helper\Db\Connection
 */
class SqliteFactory extends AbstractFactory
{
    /**
     * {@inheritdoc}
     *
     * @return Sqlite
     */
    public function createConnection()
    {
        return new Sqlite(['dbname' => env('TEST_DB_SQLITE_NAME', PATH_OUTPUT . 'phalcon_test.sqlite')]);
    }
}
