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

namespace Phalcon\Test\Unit\Http\Response;

use Phalcon\Http\Response\Headers;
use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class SetStatusCodeCest extends HttpBase
{
    /**
     * Tests the setStatusCode
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseSetStatusCode(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();

        $response->setStatusCode(404, 'Not Found');

        $expected = Headers::__set_state(
            [
                'headers' => [
                    'HTTP/1.1 404 Not Found' => '',
                    'Status'                 => '404 Not Found',
                ],
            ]
        );

        $I->assertEquals(
            $expected,
            $response->getHeaders()
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

        $expected = Headers::__set_state(
            [
                'headers' => [
                    'HTTP/1.1 409 Conflict' => '',
                    'Status'                => '409 Conflict',
                ],
            ]
        );

        $I->assertEquals(
            $expected,
            $response->getHeaders()
        );
    }

    public function testSetStatusCodeDefaultMessage(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();



        $response->setStatusCode(103);

        $expected = Headers::__set_state(
            [
                'headers' => [
                    'HTTP/1.1 103 Early Hints' => '',
                    'Status'                   => '103 Early Hints',
                ],
            ]
        );

        $I->assertEquals(
            $expected,
            $response->getHeaders()
        );



        $response->setStatusCode(200);

        $expected = Headers::__set_state(
            [
                'headers' => [
                    'HTTP/1.1 200 OK' => '',
                    'Status'          => '200 OK',
                ],
            ]
        );

        $I->assertEquals(
            $expected,
            $response->getHeaders()
        );



        $response->setStatusCode(418);

        $expected = Headers::__set_state(
            [
                'headers' => [
                    "HTTP/1.1 418 I'm a teapot" => '',
                    'Status'                    => "418 I'm a teapot",
                ],
            ]
        );

        $I->assertEquals(
            $expected,
            $response->getHeaders()
        );



        $response->setStatusCode(418, 'My own message');

        $expected = Headers::__set_state(
            [
                'headers' => [
                    'HTTP/1.1 418 My own message' => '',
                    'Status'                      => '418 My own message',
                ],
            ]
        );

        $I->assertEquals(
            $expected,
            $response->getHeaders()
        );
    }
}
