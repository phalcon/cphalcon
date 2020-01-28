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

namespace Phalcon\Test\Unit\Http\Response\Cookies;

use Phalcon\Di;
use Phalcon\Http\Response\Cookies as ResponseCookies;
use UnitTester;

class GetSetDICest
{
    /**
     * Tests Phalcon\Http\Response\Cookies :: getDI() / setDI()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-07
     */
    public function httpResponseCookiesGetSetDI(UnitTester $I)
    {
        $I->wantToTest('Http\Response\Cookies - getDI() / setDI()');

        $container = new Di();

        $oResponseCookies = new ResponseCookies();

        $oResponseCookies->setDI($container);

        $I->assertSame(
            $container,
            $oResponseCookies->getDI()
        );

        $class  = Di::class;
        $actual = $oResponseCookies->getDI();
        $I->assertInstanceOf($class, $actual);
    }
}
