<?php

namespace Helper\Db\Connection;

use Phalcon\Db\Adapter\Pdo\Postgresql;

/**
 * Helper\Db\Connection\PostgresqlFactory
 *
 * @package Helper\Db\Connection
 */
class PostgresqlFactory extends AbstractFactory
{
    /**
     * {@inheritdoc}
     *
     * @return Postgresql
     */
    public function createConnection()
    {
        return new Postgresql([
            'host'     => env('TEST_DB_POSTGRESQL_HOST', '127.0.0.1'),
            'username' => env('TEST_DB_POSTGRESQL_USER', 'postgres'),
            'password' => env('TEST_DB_POSTGRESQL_PASSWD', ''),
            'dbname'   => env('TEST_DB_POSTGRESQL_NAME', 'phalcon_test'),
            'port'     => env('TEST_DB_POSTGRESQL_PORT', 5432),
            'schema'   => env('TEST_DB_POSTGRESQL_SCHEMA', 'public')
        ]);
    }
}
