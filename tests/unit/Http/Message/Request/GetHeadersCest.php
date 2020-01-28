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

namespace Phalcon\Test\Unit\Http\Message\Request;

use Phalcon\Collection;
use Phalcon\Http\Message\Request;
use UnitTester;

class GetHeadersCest
{
    /**
     * Tests Phalcon\Http\Message\Request :: getHeaders()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageRequestGetHeaders(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - getHeaders()');

        $data = [
            'Cache-Control' => ['max-age=0'],
            'Accept'        => ['text/html'],
        ];

        $request = new Request(
            'GET',
            null,
            'php://memory',
            $data
        );

        $expected = [
            'Accept'        => ['text/html'],
            'Cache-Control' => ['max-age=0'],
        ];

        $I->assertEquals(
            $expected,
            $request->getHeaders()
        );
    }

    /**
     * Tests Phalcon\Http\Message\Request :: getHeaders() - collection
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageRequestGetHeadersCollection(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - getHeaders()');

        $data = [
            'Cache-Control' => ['max-age=0'],
            'Accept'        => ['text/html'],
        ];

        $headers = new Collection($data);

        $request = new Request(
            'GET',
            null,
            'php://memory',
            $headers
        );

        $expected = [
            'Accept'        => ['text/html'],
            'Cache-Control' => ['max-age=0'],
        ];

        $I->assertEquals(
            $expected,
            $request->getHeaders()
        );
    }

    /**
     * Tests Phalcon\Http\Message\Request :: getHeaders() - empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageRequestGetHeadersEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - getHeaders() - empty');

        $request = new Request();

        $I->assertEquals(
            [],
            $request->getHeaders()
        );
    }
}
