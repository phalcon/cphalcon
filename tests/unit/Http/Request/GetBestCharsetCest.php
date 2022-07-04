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

use Phalcon\Tests\Fixtures\Traits\DiTrait;
use UnitTester;

class GetBestCharsetCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Http\Request :: getBestCharset()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestGetBestCharset(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getBestCharset()');

        $store = $_SERVER ?? [];

        $this->setNewFactoryDefault();
        $request = $this->container->get('request');

        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT' => $time,
            'HTTP_ACCEPT_CHARSET' => 'iso-8859-5,unicode-1-1;q=0.8',
        ];

        $accept   = $request->getClientCharsets();
        $expected = 2;
        $I->assertCount($expected, $accept);


        $expected = 'iso-8859-5';
        $actual   = $accept[0]['charset'];
        $I->assertSame($expected, $actual);

        $expected = 1.0;
        $actual   = $accept[0]['quality'];
        $I->assertSame($expected, $actual);

        $expected = 'unicode-1-1';
        $actual   = $accept[1]['charset'];
        $I->assertSame($expected, $actual);

        $expected = 0.8;
        $actual   = $accept[1]['quality'];
        $I->assertSame($expected, $actual);

        $expected = 'iso-8859-5';
        $actual   = $request->getBestCharset();
        $I->assertSame($expected, $actual);

        $_SERVER = $store;
    }
}
