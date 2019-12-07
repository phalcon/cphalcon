<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Response;

use Phalcon\Di;
use Phalcon\Http\Response;
use UnitTester;

class GetSetDICest
{
    /**
     * Tests Phalcon\Http\Response :: getDI() / setDI()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-07
     */
    public function httpResponseGetSetDI(UnitTester $I)
    {
        $I->wantToTest('Http\Response - getDI() / setDI()');

        $container = new Di();

        $response = new Response();

        $response->setDI($container);

        $I->assertSame(
            $container,
            $response->getDI()
        );

        $class  = Di::class;
        $actual = $response->getDI();
        $I->assertInstanceOf($class, $actual);
    }
}
