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

namespace Phalcon\Tests\Unit\Http\Response\Headers;

use Phalcon\Http\Response\Headers;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Page\Http;

final class SetRawTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-08
     */
    public function testHttpResponseHeadersSetRaw(): void
    {
        $headers = new Headers();
        $headers->setRaw(Http::CONTENT_TYPE_HTML_RAW);

        $this->assertTrue($headers->has(Http::CONTENT_TYPE_HTML_RAW));
        $this->assertFalse($headers->has(Http::CONTENT_TYPE_PLAIN_RAW));
    }
}
