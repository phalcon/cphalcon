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
}
