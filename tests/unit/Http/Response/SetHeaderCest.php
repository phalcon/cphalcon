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

namespace Phalcon\Test\Unit\Http\Response;

use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class SetHeaderCest extends HttpBase
{
    /**
     * Tests the setHeader
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseSetHeader(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();

        $response->setHeader('Content-Type', 'text/html');

        $actual = $response->getHeaders();
        $I->assertEquals(
            'text/html',
            $actual->get('Content-Type')
        );

        $response->setHeader('Content-Length', '1234');

        $actual = $response->getHeaders();
        $I->assertEquals(
            'text/html',
            $actual->get('Content-Type')
        );
        $I->assertEquals(
            '1234',
            $actual->get('Content-Length')
        );
    }

    /**
     * Tests the setHeader
     *
     * @author Phalcon Team <team@phalcon.io>
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
