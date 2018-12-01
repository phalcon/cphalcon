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
            'host'     => env('DATA_POSTGRES_HOST', '127.0.0.1'),
            'username' => env('DATA_POSTGRES_USER', 'postgres'),
            'password' => env('DATA_POSTGRES_PASS', ''),
            'dbname'   => env('DATA_POSTGRES_NAME', 'phalcon_test'),
            'port'     => env('DATA_POSTGRES_PORT', 5432),
            'schema'   => env('DATA_POSTGRES_SCHEMA', 'public')
        ]);
    }
}
