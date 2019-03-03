<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Robots;

/**
 * Class FindFirstCest
 */
class FindFirstCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\Model :: findFirst()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelFindFirst(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - findFirst()');
        $this->setNewFactoryDefault();
        $this->setDiMysql();

        $robot = Robots::findFirst();
        $class = Robots::class;
        $I->assertInstanceOf($class, $robot);
        $I->assertEquals(1, $robot->id);

        $robot = Robots::findFirst(null);
        $class = Robots::class;
        $I->assertInstanceOf($class, $robot);

        $robot = Robots::findFirst(1);
        $class = Robots::class;
        $I->assertInstanceOf($class, $robot);
    }

    /**
     * Tests Phalcon\Mvc\Model :: findFirst() - exception
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelFindFirstException(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - findFirst() - exception');
        $this->setNewFactoryDefault();
        $this->setDiMysql();

        $I->expectThrowable(
            new Exception("Parameters passed must be of type array, string, numeric or null"),
            function () {
                Robots::findFirst(false);
            }
        );
    }
}
