<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\Criteria;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Mvc\Model\Criteria;
use Phalcon\Test\Models\Robots;

class FromInputCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
    }

    /**
     * Tests Phalcon\Mvc\Model\Criteria :: fromInput() - Mysql
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelCriteriaFromInput(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Model\Criteria - fromInput() - Mysql");
        $this->setDiMysql();

        $this->runEmptyInput($I);
        $this->runSimpleCondition($I);
        $this->runLikeCondition($I);
        $this->runComplexCondition($I);
        $this->runComplexConditionWithNonExistentField($I);
    }

    /**
     * Tests Phalcon\Mvc\Model\Criteria :: fromInput() - Mysql
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelCriteriaFromInputPostgresql(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Model\Criteria - fromInput() - Postgresql");
        $this->setDiMysql();

        $this->runEmptyInput($I);
        $this->runSimpleCondition($I);
        $this->runLikeCondition($I);
        $this->runComplexCondition($I);
        $this->runComplexConditionWithNonExistentField($I);
    }

    /**
     * Tests Phalcon\Mvc\Model\Criteria :: fromInput() - Sqlite
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelCriteriaFromInputSqlite(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Model\Criteria - fromInput() - Sqlite");
        $this->setDiMysql();

        $this->runEmptyInput($I);
        $this->runSimpleCondition($I);
        $this->runLikeCondition($I);
        $this->runComplexCondition($I);
        $this->runComplexConditionWithNonExistentField($I);
    }

    private function runEmptyInput(IntegrationTester $I)
    {
        $data = [];
        $criteria = Criteria::fromInput($this->container, Robots::class, $data);

        $I->assertNull($criteria->getParams());
        $I->assertEquals($criteria->getModelName(), Robots::class);
    }

    private function runSimpleCondition(IntegrationTester $I)
    {
        $data = ['id' => 1];
        $criteria = Criteria::fromInput($this->container, Robots::class, $data);
        $expected = [
            'conditions' => '[id] = :id:',
            'bind'       => ['id' => 1],
        ];

        $I->assertEquals($expected, $criteria->getParams());
        $I->assertEquals($criteria->getModelName(), Robots::class);
    }

    private function runLikeCondition(IntegrationTester $I)
    {
        $data = ['name' => 'ol'];
        $criteria = Criteria::fromInput($this->container, Robots::class, $data);
        $expected = [
            'conditions' => '[name] LIKE :name:',
            'bind'       => ['name' => '%ol%'],
        ];

        $I->assertEquals($expected, $criteria->getParams());
        $I->assertEquals($criteria->getModelName(), Robots::class);
    }

    private function runComplexCondition(IntegrationTester $I)
    {
        $data = ['id' => 1, 'name' => 'ol'];
        $criteria = Criteria::fromInput($this->container, Robots::class, $data);
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

    private function runComplexConditionWithNonExistentField(IntegrationTester $I)
    {
        $data = ['id' => 1, 'name' => 'ol', 'other' => true];
        $criteria = Criteria::fromInput($this->container, Robots::class, $data);
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
}
