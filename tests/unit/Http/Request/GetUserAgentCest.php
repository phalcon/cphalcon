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

namespace Phalcon\Test\Unit\Http\Request;

use Phalcon\Http\Request;
use UnitTester;

class GetUserAgentCest
{
    /**
     * Tests Phalcon\Http\Request :: getUserAgent()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestGetUserAgent(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getUserAgent()');

        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT' => $time,
        ];

        $request = new Request();

        $I->assertEmpty($request->getUserAgent());

        $_SERVER = $store;

        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT' => $time,
            'HTTP_USER_AGENT'    => 'Chrome/Other 1.0.0',
        ];

        $request = new Request();


        $expected = 'Chrome/Other 1.0.0';
        $actual   = $request->getUserAgent();
        $I->assertEquals($expected, $actual);

        $_SERVER = $store;
    }
}
