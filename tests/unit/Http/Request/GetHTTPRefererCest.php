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

class GetHTTPRefererCest
{
    /**
     * Tests Phalcon\Http\Request :: getHTTPReferer()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestGetHTTPReferer(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getHTTPReferer()');

        // Empty
        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT' => $time,
        ];

        $request = new Request();

        $I->assertEmpty($request->getHTTPReferer());

        $_SERVER = $store;

        // Valid
        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT' => $time,
            'HTTP_REFERER'       => 'Phalcon Referrer',
        ];

        $request = new Request();

        $expected = 'Phalcon Referrer';
        $actual   = $request->getHTTPReferer();
        $I->assertEquals($expected, $actual);

        $_SERVER = $store;
    }
}
