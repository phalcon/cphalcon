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

namespace Phalcon\Test\Integration\Mvc\Micro;

use IntegrationTester;
use Phalcon\Di;
use Phalcon\Mvc\Micro;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class GetSetDICest
 */
class GetSetDICest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\Micro :: getDI()/setDI()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcMicroGetSetDI(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Micro - getDI()/setDI()");
        $micro = new Micro();
        $this->newDi();
        $micro->setDI($this->container);

        $class  = Di::class;
        $actual = $micro->getDI();
        $I->assertInstanceOf($class, $actual);
    }
}
