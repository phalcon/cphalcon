<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Response;

use Phalcon\Http\Response\Headers;
use Phalcon\Http\Response;
use UnitTester;

class GetSetHeadersCest
{
    /**
     * Tests Phalcon\Http\Response :: getHeaders() / setHeaders()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-08
     */
    public function httpResponseGetSetHeaders(UnitTester $I)
    {
        $I->wantToTest('Http\Response - getHeaders() / setHeaders()');

        //Create headers
        $oHeaders = new Headers();
        $oHeaders->set('status', '200');

        $oResponse = new Response();
        $oResponse->setHeaders($oHeaders);

        $I->assertEquals(
            $oHeaders,
            $oResponse->getHeaders()
        );

        $I->assertSame(
            $oHeaders->toArray(),
            $oResponse->getHeaders()->toArray()
        );
    }

    /**
     * Tests Phalcon\Http\Response :: setHeaders() - empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpResponseSetHeadersEmpty(UnitTester $I)
    {
        $I->wantToTest("Http\Response - setHeaders() - empty");

        $response = new Response();
        $headers  = new Headers();

        $headers->set('Cache-Control', 'no-cache');
        $response->setHeaders($headers);

        $I->assertEquals(
            $headers,
            $response->getHeaders()
        );
    }

    /**
     * Tests Phalcon\Http\Response :: setHeaders() - merge
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpResponseSetHeadersMerge(UnitTester $I)
    {
        $I->wantToTest("Http\Response - setHeaders() - merge");

        $response = new Response();
        $headers  = new Headers();

        /**
         * With setHeader
         */
        $headers->set('Cache-Control', 'no-cache');
        $response->setHeader('Content-Length', '1234');
        $response->setHeaders($headers);

        $headers = new Headers();
        $headers->set('Content-Length', '1234');
        $headers->set('Cache-Control', 'no-cache');

        $I->assertEquals(
            $headers,
            $response->getHeaders()
        );
    }
}
