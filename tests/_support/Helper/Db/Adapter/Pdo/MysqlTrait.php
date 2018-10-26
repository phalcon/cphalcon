<?php

/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Helper\Db\Adapter\Pdo;

use Phalcon\Db\Adapter\Pdo\Mysql;

trait MysqlTrait
{
    /**
     * @var Mysql
     */
    protected $connection;

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

    /**
     * Returns the database name
     *
     * @return string
     */
    protected function getDatabaseName(): string
    {
        return TEST_DB_MYSQL_NAME;
    }
}
