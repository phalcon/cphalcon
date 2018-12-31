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

namespace Phalcon\Test\Integration\Mvc\Url;

use Phalcon\Di;
use Phalcon\Mvc\Url;
use IntegrationTester;

/**
 * Class GetSetDICest
 *
 * @package Phalcon\Test\Integration\Mvc\Url
 */
class GetSetDICest
{
    /**
     * Tests Phalcon\Mvc\Url :: getDI()/setDI()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcUrlGetSetDI(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Url - getDI()/setDI()");
        $url       = new Url();
        $container = new Di();

        $url->setDI($container);

        $class  = Di::class;
        $actual = $url->getDI();
        $I->assertInstanceOf($class, $actual);

        $expected = $container;
        $I->assertEquals($expected, $actual);
    }
}
