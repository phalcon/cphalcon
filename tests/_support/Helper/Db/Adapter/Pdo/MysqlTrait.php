<?php

namespace Helper\Db\Adapter\Pdo;

use Phalcon\Db\Adapter\Pdo\Mysql;

trait MysqlTrait
{
    /**
     * @var Mysql
     */
    protected $connection;

    protected $databaseName = TEST_DB_MYSQL_HOST;

    public function _before(\UnitTester $I)
    {
        try {
            $this->connection = new Mysql([
                'host'     => TEST_DB_MYSQL_HOST,
                'username' => TEST_DB_MYSQL_USER,
                'password' => TEST_DB_MYSQL_PASSWD,
                'dbname'   => TEST_DB_MYSQL_NAME,
                'port'     => TEST_DB_MYSQL_PORT,
                'charset'  => TEST_DB_MYSQL_CHARSET,
            ]);
        } catch (\PDOException $e) {
            throw new SkippedTestError("Unable to connect to the database: " . $e->getMessage());
        }
    }
}
