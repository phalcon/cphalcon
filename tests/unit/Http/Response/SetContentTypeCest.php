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

class SetContentTypeCest extends HttpBase
{
    /**
     * Tests the setContentType
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseSetContentType(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();

        $response->setContentType('application/json');

        $expected = Headers::__set_state(
            [
                'headers' => [
                    'Content-Type' => 'application/json',
                ],
            ]
        );

        $I->assertEquals(
            $expected,
            $response->getHeaders()
        );
    }

    /**
     * Tests the setContentType with charset
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseSetContentTypeWithCharset(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();

        $response->setContentType('application/json', 'utf-8');

        $expected = Headers::__set_state(
            [
                'headers' => [
                    'Content-Type' => 'application/json; charset=utf-8',
                ],
            ]
        );

        $I->assertEquals(
            $expected,
            $response->getHeaders()
        );
    }
}
