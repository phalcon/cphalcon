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
            'host'     => env('DATA_MYSQL_HOST', '127.0.0.1'),
            'username' => env('DATA_MYSQL_USER', 'root'),
            'password' => env('DATA_MYSQL_PASS', ''),
            'dbname'   => env('DATA_MYSQL_NAME', 'phalcon_test'),
            'port'     => env('DATA_MYSQL_PORT', 3306),
            'charset'  => env('DATA_MYSQL_CHARSET', 'utf8'),
        ]);
    }
}
