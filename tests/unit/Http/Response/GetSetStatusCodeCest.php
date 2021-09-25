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

namespace Phalcon\Tests\Unit\Http\Response;

use Phalcon\Tests\Unit\Http\Helper\HttpBase;
use UnitTester;

class GetSetStatusCodeCest extends HttpBase
{
    /**
     * Tests Phalcon\Http\Response :: getStatusCode() / setStatusCode()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-08
     */
    public function httpResponseGetSetStatusCode(UnitTester $I)
    {
        $I->wantToTest('Http\Response - getStatusCode() / setStatusCode()');
        $nCode     = 200;
        $oResponse = $this->getResponseObject();
        $oResponse->setStatusCode($nCode);

        $I->assertSame(
            $nCode,
            $oResponse->getStatusCode()
        );
    }

    /**
     * Tests the setStatusCode
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseSetStatusCode(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->setStatusCode(404, 'Not Found');
        $actual = $response->getHeaders();
        $I->assertEquals(
            '',
            $actual->get('HTTP/1.1 404 Not Found')
        );
        $I->assertEquals(
            '404 Not Found',
            $actual->get('Status')
        );
    }

    /**
     * Tests the Multiple Status Codes
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1892
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testMultipleHttpHeaders(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->setStatusCode(200, 'OK');
        $response->setStatusCode(404, 'Not Found');
        $response->setStatusCode(409, 'Conflict');
        $actual = $response->getHeaders();
        $I->assertEquals(
            '',
            $actual->get('HTTP/1.1 409 Conflict')
        );
        $I->assertEquals(
            '409 Conflict',
            $actual->get('Status')
        );
    }

    public function testSetStatusCodeDefaultMessage(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->setStatusCode(103);
        $actual = $response->getHeaders();
        $I->assertEquals(
            '',
            $actual->get('HTTP/1.1 103 Early Hints')
        );
        $I->assertEquals(
            '103 Early Hints',
            $actual->get('Status')
        );
        $response->setStatusCode(200);
        $actual = $response->getHeaders();
        $I->assertEquals(
            '',
            $actual->get('HTTP/1.1 200 OK')
        );
        $I->assertEquals(
            '200 OK',
            $actual->get('Status')
        );
        $response->setStatusCode(418);
        $actual = $response->getHeaders();
        $I->assertEquals(
            '',
            $actual->get("HTTP/1.1 418 I'm a teapot")
        );
        $I->assertEquals(
            "418 I'm a teapot",
            $actual->get('Status')
        );
        $response->setStatusCode(418, 'My own message');
        $actual = $response->getHeaders();
        $I->assertEquals(
            '',
            $actual->get('HTTP/1.1 418 My own message')
        );
        $I->assertEquals(
            '418 My own message',
            $actual->get('Status')
        );
    }
}
