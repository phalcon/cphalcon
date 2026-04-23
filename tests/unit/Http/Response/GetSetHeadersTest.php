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
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Page\Http;

final class GetSetHeadersTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-08
     */
    public function testHttpResponseGetSetHeaders(): void
    {
        // Create headers
        $headers = new Headers();
        $headers->set(Http::STATUS, '200');

        $response = new Response();
        $response->setHeaders($headers);

        $expected = $headers;
        $actual   = $response->getHeaders();
        $this->assertEquals($expected, $actual);

        $expected = $headers->toArray();
        $actual   = $response->getHeaders()->toArray();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testHttpResponseSetHeadersEmpty(): void
    {
        $response = new Response();
        $headers  = new Headers();

        $headers->set('Cache-Control', 'no-cache');
        $response->setHeaders($headers);

        $expected = $headers;
        $actual   = $response->getHeaders();
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testHttpResponseSetHeadersMerge(): void
    {
        $response = new Response();
        $headers  = new Headers();

        /**
         * With setHeader
         */
        $headers->set('Cache-Control', 'no-cache');
        $response->setHeader('Content-Length', '1234');
        $response->setHeaders($headers);

        $headers = new Headers();
        $headers->set('Content-Length', '1234');
        $headers->set('Cache-Control', 'no-cache');

        $expected = $headers;
        $actual   = $response->getHeaders();
        $this->assertEquals($expected, $actual);
    }
}
