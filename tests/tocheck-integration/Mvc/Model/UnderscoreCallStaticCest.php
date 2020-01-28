<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\Resultset;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models;

class UnderscoreCallStaticCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Mvc\Model :: __callStatic()
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-10-14
     */
    public function mvcModelUnderscoreCallStatic(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Model - __callStatic()");

        $robot = Models\Robots::findFirst();

        /**
         * Testing Model::findByField()
         */
        $magicRobots = Models\Robots::findById(
            $robot->id
        );

        $I->assertInstanceOf(
            Resultset\Simple::class,
            $magicRobots
        );

        $I->assertCount(
            1,
            $magicRobots
        );

        $I->assertInstanceOf(
            Models\Robots::class,
            $magicRobots->getFirst()
        );

        $I->assertEquals(
            $robot,
            $magicRobots->getFirst()
        );

        /**
         * Testing Model::findByField()
         * with impossible conditions
         */
        $nonExistentRobots = Models\Robots::findById(0);

        $I->assertInstanceOf(
            Resultset\Simple::class,
            $nonExistentRobots
        );

        $I->assertCount(
            0,
            $nonExistentRobots
        );

        /**
         * Testing Model::findFirstByField()
         */
        $firstMagicRobot = Models\Robots::findFirstById(
            $robot->id
        );

        $I->assertInstanceOf(
            Models\Robots::class,
            $firstMagicRobot
        );

        $I->assertEquals(
            $robot,
            $firstMagicRobot
        );

        /**
         * Testing Model::findFirstByField()
         * with impossible conditions
         */
        $nonExistentRobot = Models\Robots::findFirstById(0);

        $I->assertNull(
            $nonExistentRobot
        );

        /**
         * Testing Model::countByField()
         */
        $countMagicRobots = Models\Robots::countById(
            $robot->id
        );

        $I->assertInternalType(
            'int',
            $countMagicRobots
        );

        $I->assertEquals(
            1,
            $countMagicRobots
        );

        /**
         * Testing Model::countByField()
         * with impossible conditions
         */
        $countEmptyMagicRobots = Models\Robots::countById(null);

        $I->assertInternalType(
            'int',
            $countEmptyMagicRobots
        );

        $I->assertEquals(
            0,
            $countEmptyMagicRobots
        );

        /**
         * Testing with unknown method
         */
        $I->expectThrowable(
            new Exception(
                "The method 'nonExistentStaticMethod' doesn't exist on model '" . Models\Robots::class . "'"
            ),
            function () {
                Models\Robots::nonExistentStaticMethod(1);
            }
        );

        /**
         * Testing Model::findFirstByField() with unknown field
         */
        $I->expectThrowable(
            new Exception(
                "Cannot resolve attribute 'UnknownField' in the model"
            ),
            function () {
                Models\Robots::findFirstByUnknownField(1);
            }
        );

        /**
         * Testing Model::countByField() with unknown field
         */
        $I->expectThrowable(
            new Exception(
                "Cannot resolve attribute 'UnknownField' in the model"
            ),
            function () {
                Models\Robots::countByUnknownField(1);
            }
        );
    }
}
