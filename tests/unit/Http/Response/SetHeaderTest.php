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

use Phalcon\Tests\Support\Page\Http;
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

final class SetHeaderTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseSetHeader(): void
    {
        $length   = '512';
        $response = $this->getResponseObject();

        $response->resetHeaders();
        $response->setHeader(Http::CONTENT_TYPE, Http::CONTENT_TYPE_HTML);

        $headers = $response->getHeaders();

        $expected = Http::CONTENT_TYPE_HTML;
        $actual   = $headers->get(Http::CONTENT_TYPE);
        $this->assertSame($expected, $actual);

        $response->setHeader(Http::CONTENT_LENGTH, $length);

        $headers = $response->getHeaders();

        $expected = Http::CONTENT_TYPE_HTML;
        $actual   = $headers->get(Http::CONTENT_TYPE);
        $this->assertSame($expected, $actual);

        $expected = $length;
        $actual   = $headers->get(Http::CONTENT_LENGTH);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseSetHeaderContentType(): void
    {
        $length   = '256';
        $response = $this->getResponseObject();

        $response->resetHeaders();
        $response->setHeader(Http::CONTENT_TYPE, Http::CONTENT_TYPE_HTML);
        $response->setHeader(Http::CONTENT_LENGTH, $length);

        $headers = $response->getHeaders()->toArray();

        $this->assertArrayHasKey(Http::CONTENT_TYPE, $headers);
        $this->assertArrayHasKey(Http::CONTENT_LENGTH, $headers);

        $expected = Http::CONTENT_TYPE_HTML;
        $actual   = $headers[Http::CONTENT_TYPE];
        $this->assertSame($expected, $actual);

        $expected = $length;
        $actual   = $headers[Http::CONTENT_LENGTH];
        $this->assertSame($expected, $actual);
    }
}
