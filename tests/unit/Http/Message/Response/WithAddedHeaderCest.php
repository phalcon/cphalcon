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

/**
 * Class WithAddedHeaderCest
 */
class WithAddedHeaderCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: withAddedHeader()
     *
     * @param UnitTester $I
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
        $request     = new Response('php://memory', 200, $data);
        $newInstance = $request->withAddedHeader('Cache-Control', ['max-age=0']);

        $I->assertNotEquals($request, $newInstance);

        $expected = [
            'Accept' => ['text/html'],
        ];
        $actual   = $request->getHeaders();
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
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-09
     */
    public function httpMessageResponseWithAddedHeaderMerge(UnitTester $I)
    {
        $data        = [
            'Accept' => ['text/html'],
        ];
        $request     = new Response('php://memory', 200, $data);
        $newInstance = $request->withAddedHeader('Accept', ['text/json']);

        $I->assertNotEquals($request, $newInstance);

        $expected = [
            'Accept' => ['text/html'],
        ];
        $actual   = $request->getHeaders();
        $I->assertEquals($expected, $actual);

        $expected = [
            'Accept' => ['text/html', 'text/json'],
        ];
        $actual   = $newInstance->getHeaders();
        $I->assertEquals($expected, $actual);
    }
}
