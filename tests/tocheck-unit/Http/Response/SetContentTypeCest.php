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

namespace Phalcon\Test\Unit\Http\Response;

use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class SetContentTypeCest extends HttpBase
{
    /**
     * Tests the setContentType
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseSetContentType(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();

        $response->setContentType('application/json');

        $actual = $response->getHeaders();
        $I->assertEquals(
            'application/json',
            $actual->get('Content-Type')
        );
    }

    /**
     * Tests the setContentType with charset
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseSetContentTypeWithCharset(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();

        $response->setContentType('application/json', 'utf-8');

        $actual = $response->getHeaders();
        $I->assertEquals(
            'application/json; charset=utf-8',
            $actual->get('Content-Type')
        );
    }
}
