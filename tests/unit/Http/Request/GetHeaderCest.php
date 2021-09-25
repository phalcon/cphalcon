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

use Phalcon\Http\Request;
use UnitTester;

class GetHeaderCest
{
    /**
     * Tests getHeader empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testHttpRequestHeaderGetEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getHeader() - empty');

        $request = new Request();
        $I->assertEmpty($request->getHeader('LOL'));
    }

    /**
     * Tests getHeader
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testHttpRequestHeaderGet(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getHeader() - empty');

        $store   = $_SERVER ?? [];
        $_SERVER = [
            'HTTP_LOL' => 'zup',
        ];

        $request = new Request();

        $expected = 'zup';
        $actual   = $request->getHeader('LOL');
        $I->assertEquals($expected, $actual);

        $_SERVER = $store;
    }
}
