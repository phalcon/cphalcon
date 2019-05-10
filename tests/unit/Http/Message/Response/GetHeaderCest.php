<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\Response;

use Phalcon\Http\Message\Response;
use UnitTester;

class GetHeaderCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: getHeader() - empty headers
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-09
     */
    public function httpMessageResponseGetHeader(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getHeader()');

        $data = [
            'Cache-Control' => ['max-age=0'],
            'Accept'        => ['text/html'],
        ];

        $request = new Response('php://memory', 200, $data);

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
     * Tests Phalcon\Http\Message\Response :: getHeader() - empty headers
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-09
     */
    public function httpMessageResponseGetHeaderEmptyHeaders(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getHeader() - empty headers');

        $request = new Response();

        $I->assertEquals(
            [],
            $request->getHeader('empty')
        );
    }
}
