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

namespace Phalcon\Test\Integration\Url;

use IntegrationTester;
use Phalcon\Di;
use Phalcon\Url;

/**
 * Class GetSetDICest
 *
 * @package Phalcon\Test\Integration\Url
 */
class GetSetDICest
{
    /**
     * Tests Phalcon\Url :: getDI()/setDI()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function urlGetSetDI(IntegrationTester $I)
    {
        $I->wantToTest("Url - getDI()/setDI()");
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
