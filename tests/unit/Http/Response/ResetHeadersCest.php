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
 * Class ResetHeadersCest
 */
class ResetHeadersCest
{
    /**
     * Tests Phalcon\Http\Response :: resetHeaders()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
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
