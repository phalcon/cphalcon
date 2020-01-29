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
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models;

class UnderscoreCallCest
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
     * Tests Phalcon\Mvc\Model :: __call()
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-10-03
     */
    public function mvcModelCall(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Model - __call()");

        /**
         * Belongs-to relationship
         */
        $robotPart = Models\RobotsParts::findFirst();

        $part = $robotPart->getPart();

        $I->assertInstanceOf(
            Models\Parts::class,
            $part
        );

        $nonExistentPart = $robotPart->getPart(
            [
                'id < 0',
                'order' => 'id DESC',
            ]
        );

        $I->assertNull($nonExistentPart);

        /**
         * Testing has-one relationship
         */
        $customer = Models\Customers::findFirst();

        $user = $customer->getUser();

        $I->assertInstanceOf(
            Models\Users::class,
            $user
        );

        $nonExistentUser = $customer->getUser(
            [
                'id < 0',
                'order' => 'id DESC',
            ]
        );

        $I->assertNull($nonExistentUser);

        /**
         * Has-many relationship
         */
        $robot = Models\Robots::findFirst();

        $robotParts = $robot->getRobotsParts();

        $I->assertInstanceOf(
            \Phalcon\Mvc\Model\Resultset\Simple::class,
            $robotParts
        );

        $countRobotParts = $robot->countRobotsParts();

        $I->assertEquals(
            $robotParts->count(),
            $countRobotParts
        );

        $nonExistentRobotParts = $robot->getRobotsParts(
            [
                'id < 0',
                'order' => 'id DESC',
            ]
        );

        $I->assertEquals(
            0,
            $nonExistentRobotParts->count()
        );

        /**
         * Reusable has-many relationship
         */
        $reusableRobot = Models\RobotsReusable::findFirst();

        $reusableRobotParts = $reusableRobot->getRobotsParts();

        $I->assertInstanceOf(
            \Phalcon\Mvc\Model\Resultset\Simple::class,
            $reusableRobotParts
        );

        $countReusableRobotParts = $reusableRobot->countRobotsParts();

        $I->assertEquals(
            $reusableRobotParts->count(),
            $countReusableRobotParts
        );

        $nonExistentReusableRobotParts = $reusableRobot->getRobotsParts(
            [
                'id < 0',
                'order' => 'id DESC',
            ]
        );

        $I->assertEquals(
            0,
            $nonExistentReusableRobotParts->count()
        );
    }
}
