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

use Phalcon\Http\Response;
use Phalcon\Http\Response\Headers;
use UnitTester;

class ResetHeadersCest
{
    /**
     * Tests Phalcon\Http\Response :: resetHeaders()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpResponseResetHeaders(UnitTester $I)
    {
        $I->wantToTest("Http\Response - resetHeaders()");
        $response = new Response();
        $headers  = new Headers();

        $headers->set('Cache-Control', 'no-cache');
        $response->setHeaders($headers);

        $expected = $headers;
        $actual   = $response->getHeaders();
        $I->assertEquals($expected, $actual);

        $response->resetHeaders();
        $actual = $response->getHeaders();
        $actual = $actual->toArray();
        $I->assertCount(0, $actual);
    }
}
