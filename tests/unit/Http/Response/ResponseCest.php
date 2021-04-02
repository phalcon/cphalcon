<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Response;

use Phalcon\Http\Response;
use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class ResponseCest extends HttpBase
{
    /**
     * Tests the instance of the object
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
     */
    public function testHttpResponseInstanceOf(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $I->assertInstanceOf(
            Response::class,
            $response
        );
    }
}
