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

class GetBestAcceptCest
{
    /**
     * Tests Phalcon\Http\Request :: getBestAccept()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestGetBestAccept(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getBestAccept()');

        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT' => $time,
            'HTTP_ACCEPT'        => 'text/html,'
                . 'application/xhtml+xml,application/xml;q=0.9,'
                . 'image/webp,image/apng,'
                . 'language'
                . '*/*;q=0.8',
        ];

        $request = new Request();

        $expected = 'text/html';
        $actual   = $request->getBestAccept();
        $I->assertEquals($expected, $actual);

        $_SERVER = $store;
    }
}
