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

class GetDigestAuthCest
{
    /**
     * Tests Phalcon\Http\Request :: getDigestAuth()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestGetDigestAuth(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getDigestAuth()');

        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT' => $time,
            'PHP_AUTH_DIGEST'    => 'Digest realm="phalcon.io",'
                . 'qop="auth",nonce="abcdef",opaque="123456789"',
        ];

        $request = new Request();

        $expected = [
            'realm'  => 'phalcon.io',
            'qop'    => 'auth',
            'nonce'  => 'abcdef',
            'opaque' => '123456789',
        ];
        $actual   = $request->getDigestAuth();
        $I->assertEquals($expected, $actual);

        $_SERVER = $store;
    }
}
