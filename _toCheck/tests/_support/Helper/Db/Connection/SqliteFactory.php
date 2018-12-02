<?php

namespace Helper\Db\Connection;

use function outputFolder;
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
        return new Sqlite(
            [
                'dbname' => env(
                    'DATA_SQLITE_NAME',
                    outputFolder('phalcon_test.sqlite')
                )
            ]
        );
    }
}
