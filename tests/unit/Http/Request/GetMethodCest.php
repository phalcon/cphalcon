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

class GetMethodCest
{
    /**
     * Tests Phalcon\Http\Request :: getMethod()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestGetMethod(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getMethod()');

        $I->wantToTest('Http\Request - getDigestAuth()');

        // Default
        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT' => $time,
        ];

        $request = new Request();

        $I->assertEquals('GET', $request->getMethod());

        $_SERVER = $store;

        // Valid
        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT' => $time,
            'REQUEST_METHOD'     => 'POST',
        ];

        $request = new Request();

        $I->assertEquals('POST', $request->getMethod());

        $_SERVER = $store;

        // Valid POST Override
        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT'     => $time,
            'REQUEST_METHOD'         => 'POST',
            'X_HTTP_METHOD_OVERRIDE' => 'TRACE',
        ];

        $request = new Request();
        $I->assertEquals('TRACE', $request->getMethod());

        $_SERVER = $store;

        // Valid POST spoof
        $store1   = $_SERVER ?? [];
        $store2   = $_REQUEST ?? [];
        $time     = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER  = [
            'REQUEST_TIME_FLOAT' => $time,
            'REQUEST_METHOD'     => 'POST',
        ];
        $_REQUEST = [
            '_method' => 'CONNECT',
        ];

        $request = new Request();
        $request->setHttpMethodParameterOverride(true);
        $I->assertEquals('CONNECT', $request->getMethod());

        $_SERVER  = $store1;
        $_REQUEST = $store2;

        // Invalid
        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT' => $time,
            'REQUEST_METHOD'     => 'UNKNOWN',
        ];

        $request = new Request();
        $I->assertEquals('GET', $request->getMethod());

        $_SERVER = $store;
    }
}
