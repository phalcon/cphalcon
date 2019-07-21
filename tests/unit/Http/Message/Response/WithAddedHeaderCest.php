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

class WithAddedHeaderCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: withAddedHeader()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-09
     */
    public function httpMessageResponseWithAddedHeader(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - withAddedHeader()');
        $data        = [
            'Accept' => ['text/html'],
        ];
        $response    = new Response('php://memory', 200, $data);
        $newInstance = $response->withAddedHeader('Cache-Control', ['max-age=0']);

        $I->assertNotEquals($response, $newInstance);

        $expected = [
            'Accept' => ['text/html'],
        ];
        $actual   = $response->getHeaders();
        $I->assertEquals($expected, $actual);

        $expected = [
            'Accept'        => ['text/html'],
            'Cache-Control' => ['max-age=0'],
        ];
        $actual   = $newInstance->getHeaders();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Response :: withAddedHeader() - merge
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-09
     */
    public function httpMessageResponseWithAddedHeaderMerge(UnitTester $I)
    {
        $data        = [
            'Accept' => ['text/html'],
        ];
        $response    = new Response('php://memory', 200, $data);
        $newInstance = $response->withAddedHeader('Accept', ['text/json']);

        $I->assertNotEquals($response, $newInstance);

        $expected = [
            'Accept' => ['text/html'],
        ];
        $actual   = $response->getHeaders();
        $I->assertEquals($expected, $actual);

        $expected = [
            'Accept' => ['text/html', 'text/json'],
        ];
        $actual   = $newInstance->getHeaders();
        $I->assertEquals($expected, $actual);
    }
}
