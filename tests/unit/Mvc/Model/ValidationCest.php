<?php

namespace Phalcon\Test\Unit\Mvc\Model;

use UnitTester;
use Phalcon\Di;
use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Db\Adapter\Pdo\Sqlite;
use Phalcon\Db\Adapter\Pdo\Postgresql;
use Helper\ConnectionCheckerTrait;
use Phalcon\Test\Unit\Mvc\Model\Helpers\Validation;

class ValidationCest extends Validation
{
    use ConnectionCheckerTrait;

    private function runTest(UnitTester $I, \Closure $db)
    {
        /** @var \Phalcon\Di\FactoryDefault $di */
        $di = Di::getDefault();

        $connection = $di->getShared('db');
        $di->remove('db');

        $di->setShared('db', $db);

        Di::setDefault($di);
        $this->checkConnection($connection);

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

    public function mysql(UnitTester $I)
    {
        $I->wantToTest("Model validation by using MySQL as RDBMS");

        $db = function () {
            return new Mysql([
                'host'     => env('TEST_DB_MYSQL_HOST', '127.0.0.1'),
                'username' => env('TEST_DB_MYSQL_USER', 'root'),
                'password' => env('TEST_DB_MYSQL_PASSWD', ''),
                'dbname'   => env('TEST_DB_MYSQL_NAME', 'phalcon_test'),
                'port'     => env('TEST_DB_MYSQL_PORT', 3306),
                'charset'  => env('TEST_DB_MYSQL_CHARSET', 'utf8'),
            ]);
        };

        $this->runTest($I, $db);
    }

    public function postgresql(UnitTester $I)
    {
        $I->wantToTest("Model validation by using PostgreSQL as RDBMS");

        $db = function () {
            return new Postgresql([
                'host'     => env('TEST_DB_POSTGRESQL_HOST', '127.0.0.1'),
                'username' => env('TEST_DB_POSTGRESQL_USER', 'postgres'),
                'password' => env('TEST_DB_POSTGRESQL_PASSWD', ''),
                'dbname'   => env('TEST_DB_POSTGRESQL_NAME', 'phalcon_test'),
                'port'     => env('TEST_DB_POSTGRESQL_PORT', 5432),
                'schema'   => env('TEST_DB_POSTGRESQL_SCHEMA', 'public'),
            ]);
        };

        $this->runTest($I, $db);
    }

    public function sqlite(UnitTester $I)
    {
        $I->wantToTest("Model validation by using SQLite as RDBMS");

        $db = function () {
            $connection = new Sqlite(['dbname' => env('TEST_DB_SQLITE_NAME', PATH_OUTPUT . 'phalcon_test.sqlite')]);

            /** @var \PDO $pdo */
            $pdo = $connection->getInternalHandler();
            $pdo->sqliteCreateFunction('now', function () {
                return date('Y-m-d H:i:s');
            });

            return $connection;
        };

        $this->runTest($I, $db);
    }
}
