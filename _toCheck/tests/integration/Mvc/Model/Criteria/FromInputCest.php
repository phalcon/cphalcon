<?php

namespace Phalcon\Test\Integration\Mvc\Model\Criteria;

use Phalcon\Di;
use IntegrationTester;
use Codeception\Example;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Mvc\Model\Criteria;
use Phalcon\Test\Models\Robots;
use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Db\Adapter\Pdo\Sqlite;
use Phalcon\Mvc\Model\MetaData\Memory;
use Phalcon\Db\Adapter\Pdo\Postgresql;

class FromInputCest
{
    /**
     * Executed before each test
     *
     * @param IntegrationTester $I
     */
    public function _before(IntegrationTester $I)
    {
        $I->haveServiceInDi('modelsManager', Manager::class, true);
        $I->haveServiceInDi('modelsMetadata', Memory::class, true);

        Di::setDefault($I->getApplication()->getDI());
    }

    /**
     * @param IntegrationTester $I
     * @param Example $example
     *
     * @dataprovider adapterProvider
     */
    public function emptyImput(IntegrationTester $I, Example $example)
    {
        $di = Di::getDefault();
        $di->setShared('db', $example['adapter']);

        $data = [];
        $criteria = Criteria::fromInput($di, Robots::class, $data);

        $I->assertNull($criteria->getParams());
        $I->assertEquals($criteria->getModelName(), Robots::class);
    }

    /**
     * @param IntegrationTester $I
     * @param Example $example
     *
     * @dataprovider adapterProvider
     */
    public function simpleCondition(IntegrationTester $I, Example $example)
    {
        $di = Di::getDefault();
        $di->setShared('db', $example['adapter']);

        $data = ['id' => 1];
        $criteria = Criteria::fromInput($di, Robots::class, $data);
        $expected = [
            'conditions' => '[id] = :id:',
            'bind'       => ['id' => 1],
        ];

        $I->assertEquals($expected, $criteria->getParams());
        $I->assertEquals($criteria->getModelName(), Robots::class);
    }

    /**
     * @param IntegrationTester $I
     * @param Example $example
     *
     * @dataprovider adapterProvider
     */
    public function likeCondition(IntegrationTester $I, Example $example)
    {
        $di = Di::getDefault();
        $di->setShared('db', $example['adapter']);

        $data = ['name' => 'ol'];
        $criteria = Criteria::fromInput($di, Robots::class, $data);
        $expected = [
            'conditions' => '[name] LIKE :name:',
            'bind'       => ['name' => '%ol%'],
        ];

        $I->assertEquals($expected, $criteria->getParams());
        $I->assertEquals($criteria->getModelName(), Robots::class);
    }

    /**
     * @param IntegrationTester $I
     * @param Example $example
     *
     * @dataprovider adapterProvider
     */
    public function complexCondition(IntegrationTester $I, Example $example)
    {
        $di = Di::getDefault();
        $di->setShared('db', $example['adapter']);

        $data = ['id' => 1, 'name' => 'ol'];
        $criteria = Criteria::fromInput($di, Robots::class, $data);
        $expected = [
            'conditions' => '[id] = :id: AND [name] LIKE :name:',
            'bind'       => [
                'id'   => 1,
                'name' => '%ol%',
            ],
        ];

        $I->assertEquals($expected, $criteria->getParams());
        $I->assertEquals($criteria->getModelName(), Robots::class);
    }

    /**
     * @param IntegrationTester $I
     * @param Example $example
     *
     * @dataprovider adapterProvider
     */
    public function complexConditionWithNonExistentField(IntegrationTester $I, Example $example)
    {
        $di = Di::getDefault();
        $di->setShared('db', $example['adapter']);

        $data = ['id' => 1, 'name' => 'ol', 'other' => true];
        $criteria = Criteria::fromInput($di, Robots::class, $data);
        $expected = [
            'conditions' => '[id] = :id: AND [name] LIKE :name:',
            'bind'       => [
                'id'   => 1,
                'name' => '%ol%',
            ],
        ];

        $I->assertEquals($expected, $criteria->getParams());
        $I->assertEquals($criteria->getModelName(), Robots::class);
    }

    protected function adapterProvider()
    {
        return [
            [
                'adapter' => new Mysql([
                    'host'     => env('DATA_MYSQL_HOST', '127.0.0.1'),
                    'username' => env('DATA_MYSQL_USER', 'root'),
                    'password' => env('DATA_MYSQL_PASS', ''),
                    'dbname'   => env('DATA_MYSQL_NAME', 'phalcon_test'),
                    'port'     => env('DATA_MYSQL_PORT', 3306),
                    'charset'  => env('DATA_MYSQL_CHARSET', 'utf8'),
                ]),
            ],
            [
                'adapter' => new Sqlite([
                    'dbname' => env('DATA_SQLITE_NAME', '/tmp/phalcon_test.sqlite'),
                ]),
            ],
            [
                'adapter' => new Postgresql([
                    'host'     => env('DATA_POSTGRES_HOST', '127.0.0.1'),
                    'username' => env('DATA_POSTGRES_USER', 'postgres'),
                    'password' => env('DATA_POSTGRES_PASS', ''),
                    'dbname'   => env('DATA_POSTGRES_NAME', 'phalcon_test'),
                    'port'     => env('DATA_POSTGRES_PORT', 5432),
                ]),
            ],
        ];
    }
}
