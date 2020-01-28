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

use Phalcon\Http\Response;
use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class SetNotModifiedCest extends HttpBase
{
    /**
     * Tests Phalcon\Http\Response :: setNotModified()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-17
     */
    public function httpResponseSetNotModified(UnitTester $I)
    {
        $I->wantToTest('Http\Response - setNotModified()');

        $response = new Response();

        $response->setNotModified();

        $I->assertEquals(
            304,
            $response->getStatusCode()
        );

        $I->assertEquals(
            'Not modified',
            $response->getReasonPhrase()
        );
    }

    /**
     * Tests setNotModified
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseSetNotModified(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();
        $response->setNotModified();

        $actual = $response->getHeaders();
        $I->assertEquals(
            false,
            $actual->get('HTTP/1.1 304 Not modified')
        );
        $I->assertEquals(
            '304 Not modified',
            $actual->get('Status')
        );
    }
}
