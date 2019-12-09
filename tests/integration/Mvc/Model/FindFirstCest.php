<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Customers;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Models\RobotsExtended;

class FindFirstCest
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
     * Tests Phalcon\Mvc\Model :: findFirst()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelFindFirst(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - findFirst()');

        $robot = Robots::findFirst();

        $I->assertInstanceOf(
            Robots::class,
            $robot
        );

        $I->assertEquals(1, $robot->id);

        $robot = Robots::findFirst(null);

        $I->assertInstanceOf(
            Robots::class,
            $robot
        );

        $robot = Robots::findFirst(1);

        $I->assertInstanceOf(
            Robots::class,
            $robot
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: findFirst() - not found
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelFindFirstNotFound(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - findFirst() - not found');

        $robot = Robots::findFirst(
            [
                'conditions' => 'id < 0',
            ]
        );

        $I->assertNull($robot);
    }

    /**
     * Tests Phalcon\Mvc\Model :: findFirstBy() - not found
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelFindFirstByNotFound(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - findFirstBy() - not found');

        $I->assertNull(
            Customers::findFirstByEmail('unknown')
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: findFirst() - extended
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelFindFirstExtended(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - findFirst() - extended');

        $robot = RobotsExtended::findFirst(1);

        $I->assertInstanceOf(
            RobotsExtended::class,
            $robot
        );

        $I->assertEquals(1, $robot->id);

        $robot = RobotsExtended::findFirst(0);
        $I->assertNull($robot);
    }

    /**
     * Tests Phalcon\Mvc\Model :: findFirst() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelFindFirstException(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - findFirst() - exception');

        $I->expectThrowable(
            new Exception(
                'Parameters passed must be of type array, string, numeric or null'
            ),
            function () {
                Robots::findFirst(false);
            }
        );
    }
}
