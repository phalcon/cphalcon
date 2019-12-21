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

namespace Phalcon\Test\Unit\Http\Response\Headers;

use Phalcon\Http\Response\Headers;
use UnitTester;

class ToArrayCest
{
    /**
     * Tests Phalcon\Http\Response\Headers :: toArray()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-08
     */
    public function httpResponseHeadersToArray(UnitTester $I)
    {
        $I->wantToTest('Http\Response\Headers - toArray()');

        $headers = new Headers();
        $headers->set('Content-Type', 'text/html; charset=UTF-8');
        $headers->set('Content-Encoding', 'gzip');

        $expected = [
            'Content-Type'     => 'text/html; charset=UTF-8',
            'Content-Encoding' => 'gzip',
        ];
        $actual   = $headers->toArray();

        $I->assertEquals($expected, $actual);
    }
}
