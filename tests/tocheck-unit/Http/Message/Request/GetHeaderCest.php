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

namespace Phalcon\Test\Unit\Http\Message\Request;

use Phalcon\Http\Message\Request;
use UnitTester;

class GetHeaderCest
{
    /**
     * Tests Phalcon\Http\Message\Request :: getHeader() - empty headers
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageRequestGetHeader(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - getHeader()');

        $data = [
            'Cache-Control' => ['max-age=0'],
            'Accept'        => ['text/html'],
        ];

        $request = new Request(
            'GET',
            null,
            'php://memory',
            $data
        );

        $expected = ['text/html'];

        $I->assertEquals(
            $expected,
            $request->getHeader('accept')
        );


        $I->assertEquals(
            $expected,
            $request->getHeader('aCCepT')
        );
    }

    /**
     * Tests Phalcon\Http\Message\Request :: getHeader() - empty headers
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageRequestGetHeaderEmptyHeaders(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - getHeader() - empty headers');

        $request = new Request();

        $I->assertEquals(
            [],
            $request->getHeader('empty')
        );
    }
}
