<?php

namespace Helper\Db\Connection;

use Phalcon\Db\Adapter\Pdo\Mysql;

/**
 * Helper\Db\Connection\MysqlFactory
 *
 * @package Helper\Db\Connection
 */
class MysqlFactory extends AbstractFactory
{
    /**
     * {@inheritdoc}
     *
     * @return Mysql
     */
    public function createConnection()
    {
        return new Mysql([
            'host'     => env('TEST_DB_MYSQL_HOST', '127.0.0.1'),
            'username' => env('TEST_DB_MYSQL_USER', 'root'),
            'password' => env('TEST_DB_MYSQL_PASSWD', ''),
            'dbname'   => env('TEST_DB_MYSQL_NAME', 'phalcon_test'),
            'port'     => env('TEST_DB_MYSQL_PORT', 3306),
            'charset'  => env('TEST_DB_MYSQL_CHARSET', 'utf8'),
        ]);
    }
}
