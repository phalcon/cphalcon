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

namespace Phalcon\Test\Unit\Http\Cookie;

use Phalcon\Di;
use Phalcon\Http\Cookie;
use UnitTester;

class GetSetDICest
{
    /**
     * Tests Phalcon\Http\Cookie :: getDI() / setDI()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-07
     */
    public function httpCookieGetSetDI(UnitTester $I)
    {
        $I->wantToTest('Http\Cookie - getDI() / setDI()');

        $container = new Di();

        $cookie = new Cookie('test');

        $cookie->setDI($container);

        $I->assertSame(
            $container,
            $cookie->getDI()
        );

        $class  = Di::class;
        $actual = $cookie->getDI();
        $I->assertInstanceOf($class, $actual);
    }
}
