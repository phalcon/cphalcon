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

final class RemoveHeaderTest extends AbstractHttpBase
{
    /**
     * @author Mohamad Rostami <mb.rostami.h@gmail.com>
     */
    public function testHttpResponseRemoveHeaderContentType(): void
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->setHeader(Http::CONTENT_TYPE, Http::CONTENT_TYPE_HTML);

        $headers = $response->getHeaders()->toArray();

        $this->assertArrayHasKey(Http::CONTENT_TYPE, $headers);

        $expected = Http::CONTENT_TYPE_HTML;
        $actual   = $headers[Http::CONTENT_TYPE];
        $this->assertSame($expected, $actual);

        $response->removeHeader(Http::CONTENT_TYPE);

        $headers = $response->getHeaders()->toArray();
        $this->assertArrayNotHasKey(Http::CONTENT_TYPE, $headers);
    }
}
