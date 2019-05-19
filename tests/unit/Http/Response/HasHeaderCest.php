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

use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class HasHeaderCest extends HttpBase
{
    /**
     * Tests the hasHeader
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseHasHeader(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();

        $response->setHeader('Content-Type', 'text/html');

        $I->assertTrue(
            $response->hasHeader('Content-Type')
        );

        $I->assertFalse(
            $response->hasHeader('some-unknown-header')
        );
    }
}
