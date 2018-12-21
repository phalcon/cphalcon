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

use UnitTester;
use Phalcon\Http\Response;

/**
 * Class HasHeaderCest
 */
class HasHeaderCest
{
    /**
     * Tests Phalcon\Http\Response :: hasHeader()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpResponseHasHeader(UnitTester $I)
    {
        $I->wantToTest("Http\Response - hasHeader()");
        $response = new Response();
        $response->setHeader('Content-Length', '1234');

        $actual = $response->hasHeader('Content-Length');
        $I->assertTrue($actual);

        $actual = $response->hasHeader('Cache-Control');
        $I->assertFalse($actual);
    }
}
