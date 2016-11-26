<?php

namespace Phalcon\Test\Unit\Mvc\Model;

use UnitTester;
use Phalcon\Di;
use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Db\Adapter\Pdo\Sqlite;
use Phalcon\Db\Adapter\Pdo\Postgresql;
use Phalcon\Test\Unit\Mvc\Model\Helpers\Validation;

class ValidationCest extends Validation
{
    public function mysql(UnitTester $I)
    {
        $I->wantToTest("Model validation by using MySQL as RDBMS");

        /** @var \Phalcon\Di\FactoryDefault $di */
        $di = Di::getDefault();

        $connection = $di->getShared('db');
        $di->remove('db');

        $di->setShared('db', function () {
            return new Mysql([
                'host'     => TEST_DB_MYSQL_HOST,
                'username' => TEST_DB_MYSQL_USER,
                'password' => TEST_DB_MYSQL_PASSWD,
                'dbname'   => TEST_DB_MYSQL_NAME,
                'port'     => TEST_DB_MYSQL_PORT,
                'charset'  => TEST_DB_MYSQL_CHARSET,
            ]);
        });

        Di::setDefault($di);

        $this->success($I);
        $this->presenceOf($I);
        $this->email($I);
        $this->emailWithDot($I);
        $this->exclusionIn($I);
        $this->inclusionIn($I);
        $this->uniqueness1($I);
        $this->uniqueness2($I);
        $this->regex($I);
        $this->tooLong($I);
        $this->tooShort($I);

        $di->remove('db');
        $di->setShared('db', $connection);
    }

    public function postgresql(UnitTester $I)
    {
        $I->wantToTest("Model validation by using PostgreSQL as RDBMS");

        /** @var \Phalcon\Di\FactoryDefault $di */
        $di = Di::getDefault();

        $connection = $di->getShared('db');
        $di->remove('db');

        $di->setShared('db', function () {
            return new Postgresql([
                'host'     => TEST_DB_POSTGRESQL_HOST,
                'username' => TEST_DB_POSTGRESQL_USER,
                'password' => TEST_DB_POSTGRESQL_PASSWD,
                'dbname'   => TEST_DB_POSTGRESQL_NAME,
                'port'     => TEST_DB_POSTGRESQL_PORT,
            ]);
        });

        $this->success($I);
        $this->presenceOf($I);
        $this->email($I);
        $this->emailWithDot($I);
        $this->exclusionIn($I);
        $this->inclusionIn($I);
        $this->uniqueness1($I);
        $this->uniqueness2($I);
        $this->regex($I);
        $this->tooLong($I);
        $this->tooShort($I);

        $di->remove('db');
        $di->setShared('db', $connection);
    }

    public function sqlite(UnitTester $I)
    {
        $I->wantToTest("Model validation by using SQLite as RDBMS");

        /** @var \Phalcon\Di\FactoryDefault $di */
        $di = Di::getDefault();

        $connection = $di->getShared('db');
        $di->remove('db');

        $di->setShared('db', function () {
            $connection = new Sqlite(['dbname' => TEST_DB_SQLITE_NAME]);

            /** @var \PDO $pdo */
            $pdo = $connection->getInternalHandler();
            $pdo->sqliteCreateFunction('now', function () {
                return date('Y-m-d H:i:s');
            });

            return $connection;
        });

        Di::setDefault($di);

        $this->success($I);
        $this->presenceOf($I);
        $this->email($I);
        $this->emailWithDot($I);
        $this->exclusionIn($I);
        $this->inclusionIn($I);
        $this->uniqueness1($I);
        $this->uniqueness2($I);
        $this->regex($I);
        $this->tooLong($I);
        $this->tooShort($I);

        $di->remove('db');
        $di->setShared('db', $connection);
    }
}
