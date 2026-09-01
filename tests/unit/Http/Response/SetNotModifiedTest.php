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

final class SetNotModifiedTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-17
     */
    public function testHttpResponseSetNotModified(): void
    {
        $response = $this->getResponseObject();
        $response->setNotModified();

        $expected = Http::CODE_304;
        $actual   = $response->getStatusCode();
        $this->assertSame($expected, $actual);

        $expected = Http::NOT_MODIFIED;
        $actual   = $response->getReasonPhrase();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseSetNotModifiedHeaders(): void
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->setNotModified();

        $headers = $response->getHeaders();

        $actual = $headers->get(Http::HTTP_304_NOT_MODIFIED);
        $this->assertNull($actual);

        $expected = Http::MESSAGE_304_NOT_MODIFIED;
        $actual   = $headers->get(Http::STATUS);
        $this->assertSame($expected, $actual);
    }
}
