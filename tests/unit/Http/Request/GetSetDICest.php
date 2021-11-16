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

namespace Phalcon\Tests\Unit\Http\Request;

use Phalcon\Di;
use Phalcon\Http\Request;
use UnitTester;

class GetSetDICest
{
    /**
     * Tests Phalcon\Http\Request :: getDI()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestGetDI(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getDI()');
        $url       = new Request();
        $container = new Di();

        $url->setDI($container);

        $class  = Di::class;
        $actual = $url->getDI();
        $I->assertInstanceOf($class, $actual);

        $expected = $container;
        $I->assertEquals($expected, $actual);
    }
}
