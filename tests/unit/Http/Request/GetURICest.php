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

class GetURICest
{
    /**
     * Tests Phalcon\Http\Request :: getURI()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestGetURI(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getURI()');

        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT' => $time,
        ];

        $request = new Request();

        $I->assertEmpty($request->getURI());

        $_SERVER = $store;

        // Valid
        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT' => $time,
            'REQUEST_URI'        => 'https://dev.phalcon.io?a=b',
        ];

        $request = new Request();

        $expected = 'https://dev.phalcon.io?a=b';
        $actual   = $request->getURI();
        $I->assertEquals($expected, $actual);

        $_SERVER = $store;

        // Valid - only path
        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT' => $time,
            'REQUEST_URI'        => 'https://dev.phalcon.io?a=b',
        ];

        $request = new Request();

        $expected = 'https://dev.phalcon.io';
        $actual   = $request->getURI(true);
        $I->assertEquals($expected, $actual);

        $_SERVER = $store;
    }
}
