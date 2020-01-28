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

class SetRawHeaderCest extends HttpBase
{
    /**
     * Tests the setRawHeader
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseSetRawHeader(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();

        $response->setRawHeader('HTTP/1.1 404 Not Found');

        $actual = $response->getHeaders();
        $I->assertEquals(
            '',
            $actual->get('HTTP/1.1 304 Not modified')
        );
    }
}
