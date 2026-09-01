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

use DateTime;
use DateTimeZone;
use Phalcon\Tests\Support\Page\Http;
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

final class SetCacheTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2015-07-14
     */
    public function testHttpResponseSetCache(): void
    {
        $response = $this->getResponseObject();

        $expiry = new DateTime();
        $expiry->setTimezone(new DateTimeZone('UTC'));
        $expiry->modify('+60 minutes');

        $response->setCache(60);

        $headers = $response->getHeaders();

        $expected = $expiry->format(Http::DATETIME_FORMAT) . ' GMT';
        $actual   = $headers->get(Http::EXPIRES);
        $this->assertSame($expected, $actual);

        $expected = Http::CACHE_MAX_AGE;
        $actual   = $headers->get(Http::CACHE_CONTROL);
        $this->assertSame($expected, $actual);
    }
}
