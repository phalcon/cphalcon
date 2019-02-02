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

namespace Phalcon\Test\Unit\Http\Request;

use Phalcon\Di;
use Phalcon\Http\Request;
use UnitTester;

/**
 * Class GetSetDICest
 */
class GetSetDICest
{
    /**
     * Tests Phalcon\Http\Request :: getDI()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
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
