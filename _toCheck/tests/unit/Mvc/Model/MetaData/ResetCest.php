<?php

namespace Phalcon\Test\Unit\Mvc\Model\MetaData;

use UnitTester;
use Phalcon\Mvc\Model;
use Codeception\Example;
use Phalcon\Test\Models\Robots;

class ResetCest
{
    public function _before(UnitTester $I)
    {
        Model::setup(['columnRenaming' => false]);
        $I->haveServiceInDi('modelsMetadata', Model\MetaData\Memory::class);
    }

    public function _after(UnitTester $I)
    {
        Model::setup(['columnRenaming' => true]);
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/1801
     * @param UnitTester $I
     * @param Example $example
     *
     * @example { "factory": "\\Helper\\Db\\Connection\\MysqlFactory" }
     * @example { "factory": "\\Helper\\Db\\Connection\\SqliteFactory" }
     * @example { "factory": "\\Helper\\Db\\Connection\\PostgresqlFactory" }
     */
    public function findAModelAfterDisablingColumnRenamingAndReset(UnitTester $I, Example $example)
    {
        $I->wantToTest("Find a model after disabling column renaming and reset");

        $I->haveServiceInDi('db', function () use ($example) {
            $className = $example['factory'];
            $factory = new $className();

            return $factory->createConnection();
        });

        $robot1 = Robots::findFirst(1);

        $md = $I->grabServiceFromDi('modelsMetadata');
        $md->reset();

        $robot2 = Robots::findFirst(1);

        $I->assertEquals($robot1, $robot2);
    }
}
