<?php

namespace Phalcon\Test\Integration\Mvc\Model;

use Phalcon\Di;
use IntegrationTester;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Test\Models\Robots;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Mvc\Model\MetaData\Memory;

class CriteriaCest
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
     * Tests creating builder from criteria
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-05-21
     *
     * @param IntegrationTester $I
     */
    public function createBuilderFromCriteria(IntegrationTester $I)
    {
        $criteria = Robots::query()->where("type='mechanical'");
        $I->assertInstanceOf(Builder::class, $criteria->createBuilder());
    }
}
