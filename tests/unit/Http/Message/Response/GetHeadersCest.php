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

namespace Phalcon\Tests\Unit\Http\Message\Response;

use Phalcon\Http\Message\Response;
use UnitTester;

class GetHeadersCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: getHeaders()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-09
     */
    public function httpMessageResponseGetHeaders(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getHeaders()');

        $data = [
            'Cache-Control' => ['max-age=0'],
            'Accept'        => ['text/html'],
        ];

        $response = new Response('php://memory', 200, $data);

        $expected = [
            'Accept'        => ['text/html'],
            'Cache-Control' => ['max-age=0'],
        ];

        $I->assertEquals(
            $expected,
            $response->getHeaders()
        );
    }

    /**
     * Tests Phalcon\Http\Message\Response :: getHeaders() - empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-09
     */
    public function httpMessageResponseGetHeadersEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getHeaders() - empty');

        $response = new Response();

        $I->assertEquals(
            [],
            $response->getHeaders()
        );
    }
}
