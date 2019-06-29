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

use Phalcon\Http\Response\Headers;
use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class SetContentLengthCest extends HttpBase
{
    /**
     * Tests the setContentLength
     *
     * @author Zamrony P. Juhara <zamronypj@yahoo.com>
     * @since  2016-07-18
     */
    public function testHttpResponseSetContentLength(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();

        $response->setContentLength(100);

        $actual   = $response->getHeaders();
        $I->assertEquals(
            100,
            $actual->get('Content-Length')
        );
    }
}
