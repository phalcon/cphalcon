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

class GetClientAddressCest
{
    /**
     * Tests Phalcon\Http\Request :: getClientAddress() - trustForwardedHeader
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestGetClientAddressTrustForwardedHeader(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getClientAddress() - trustForwardedHeader');

        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT'   => $time,
            'HTTP_X_FORWARDED_FOR' => '10.4.6.1',
        ];

        $request = new Request();

        $expected = '10.4.6.1';
        $actual   = $request->getClientAddress(true);
        $I->assertEquals($expected, $actual);

        $_SERVER = $store;
        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT' => $time,
            'HTTP_CLIENT_IP'     => '10.4.6.2',
        ];

        $request = new Request();

        $expected = '10.4.6.2';
        $actual   = $request->getClientAddress(true);
        $I->assertEquals($expected, $actual);

        $_SERVER = $store;
    }

    /**
     * Tests Phalcon\Http\Request :: getClientAddress()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestGetClientAddress(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getClientAddress()');

        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT' => $time,
            'REMOTE_ADDR'        => '10.4.6.3',
        ];

        $request = new Request();

        $expected = '10.4.6.3';
        $actual   = $request->getClientAddress();
        $I->assertEquals($expected, $actual);

        $_SERVER = $store;
    }

    /**
     * Tests Phalcon\Http\Request :: getClientAddress() - incorrect
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestGetClientAddressIncorrect(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getClientAddress() - incorrect');

        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT' => $time,
            'REMOTE_ADDR'        => ['10.4.6.3'],
        ];

        $request = new Request();

        $actual = $request->getClientAddress();
        $I->assertFalse($actual);

        $_SERVER = $store;
    }

    /**
     * Tests Phalcon\Http\Request :: getClientAddress() - multiple
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestGetClientAddressMultiple(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getClientAddress() - multiple');

        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT' => $time,
            'REMOTE_ADDR'        => '10.4.6.4,10.4.6.5',
        ];

        $request = new Request();

        $expected = '10.4.6.4';
        $actual   = $request->getClientAddress();
        $I->assertEquals($expected, $actual);

        $_SERVER = $store;
    }

    /**
     * Tests Phalcon\Http\Request :: getClientAddress() - ipv6
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestGetClientAddressIpv6(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getClientAddress() - ipv6');

        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT' => $time,
            'REMOTE_ADDR'        => '2a00:8640:1::224:36ff:feef:1d89',
        ];

        $request = new Request();

        $expected = '2a00:8640:1::224:36ff:feef:1d89';
        $actual   = $request->getClientAddress();
        $I->assertEquals($expected, $actual);

        $_SERVER = $store;
    }
}
