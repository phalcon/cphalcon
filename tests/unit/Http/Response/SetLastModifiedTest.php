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
use Phalcon\Http\Response;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Page\Http;

final class SetLastModifiedTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-08
     */
    public function testHttpResponseSetLastModified(): void
    {
        $response = new Response(Http::TEST_CONTENT);

        $modified = new DateTime();
        $modified->modify('+1 months');
        $modified->setTimezone(new DateTimeZone('UTC'));

        $response->setLastModified($modified);

        $expected = $modified->format(Http::DATETIME_FORMAT) . ' GMT';
        $actual   = $response->getHeaders()->get(Http::LAST_MODIFIED);
        $this->assertSame($expected, $actual);
    }
}
