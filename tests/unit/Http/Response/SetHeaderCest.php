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

class SetHeaderCest extends HttpBase
{
    /**
     * Tests the setHeader
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseSetHeader(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();

        $response->setHeader('Content-Type', 'text/html');

        $expected = Headers::__set_state(
            [
                'headers' => [
                    'Content-Type' => 'text/html',
                ],
            ]
        );

        $I->assertEquals(
            $expected,
            $response->getHeaders()
        );



        $response->setHeader('Content-Length', '1234');

        $expected = Headers::__set_state(
            [
                'headers' => [
                    'Content-Type'   => 'text/html',
                    'Content-Length' => '1234',
                ],
            ]
        );

        $I->assertEquals(
            $expected,
            $response->getHeaders()
        );
    }

    /**
     * Tests the setHeader
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseSetHeaderContentType(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();

        $response->setHeader('Content-Type', 'text/html');
        $response->setHeader('Content-Length', '1234');

        $headers = $response->getHeaders()->toArray();

        $I->assertArrayHasKey('Content-Type', $headers);
        $I->assertArrayHasKey('Content-Length', $headers);

        $I->assertEquals(
            'text/html',
            $headers['Content-Type']
        );

        $I->assertEquals(
            '1234',
            $headers['Content-Length']
        );
    }
}
