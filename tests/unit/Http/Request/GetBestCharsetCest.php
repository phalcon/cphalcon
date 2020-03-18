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

class GetBestCharsetCest
{
    /**
     * Tests Phalcon\Http\Request :: getBestCharset()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestGetBestCharset(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getBestCharset()');

        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT'  => $time,
            'HTTP_ACCEPT_CHARSET' => 'iso-8859-5,unicode-1-1;q=0.8',
        ];

        $request = new Request();

        $expected = 'iso-8859-5';
        $actual   = $request->getBestCharset();
        $I->assertEquals($expected, $actual);

        $_SERVER = $store;
    }
}
