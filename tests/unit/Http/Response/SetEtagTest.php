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
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Page\Http;

final class SetEtagTest extends AbstractUnitTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-17
     */
    public function testHttpResponseSetEtag(): void
    {
        $etag     = md5((string)time());
        $response = new Response();

        $response->setEtag($etag);

        $headers = $response->getHeaders();

        $expected = $etag;
        $actual   = $headers->get(Http::ETAG);
        $this->assertSame($expected, $actual);
    }
}
