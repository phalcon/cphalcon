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

namespace Phalcon\Test\Unit\Http\Message\Request;

use Phalcon\Http\Message\Request;
use UnitTester;

/**
 * Class WithMethodCest
 */
class WithMethodCest
{
    /**
     * Tests Phalcon\Http\Message\Request :: withMethod()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageRequestWithMethod(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - withMethod()');
        $request     = new Request();
        $newInstance = $request->withMethod('POST');

        $I->assertNotEquals($request, $newInstance);

        $expected = 'GET';
        $actual   = $request->getMethod();
        $I->assertEquals($expected, $actual);

        $expected = 'POST';
        $actual   = $newInstance->getMethod();
        $I->assertEquals($expected, $actual);
    }
}
