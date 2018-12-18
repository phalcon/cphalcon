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

use Phalcon\Http\Response;
use Phalcon\Http\Response\Headers;
use UnitTester;

/**
 * Class SetHeadersCest
 */
class SetHeadersCest
{
    /**
     * Tests Phalcon\Http\Response :: setHeaders() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpResponseSetHeadersEmpty(UnitTester $I)
    {
        $I->wantToTest("Http\Response - setHeaders() - empty");
        $response = new Response();
        $headers  = new Headers();

        $headers->set('Cache-Control', 'no-cache');
        $response->setHeaders($headers);

        $expected = $headers;
        $actual   = $response->getHeaders();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Response :: setHeaders() - merge
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
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

        $expected = $headers;
        $actual   = $response->getHeaders();
        $I->assertEquals($expected, $actual);
    }
}
