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

final class ResetHeadersTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testHttpResponseResetHeaders(): void
    {
        $response = new Response();
        $headers  = new Headers();

        $headers->set(Http::CACHE_CONTROL, Http::NO_CACHE);
        $response->setHeaders($headers);

        $expected = $headers;
        $actual   = $response->getHeaders();
        $this->assertEquals($expected, $actual);

        $response->resetHeaders();
        $actual = $response->getHeaders();
        $actual = $actual->toArray();
        $this->assertCount(0, $actual);
    }
}
