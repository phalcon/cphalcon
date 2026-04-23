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

use function uniqid;

final class HasHeaderTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseHasHeader(): void
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();

        $response->setHeader(Http::CONTENT_TYPE, Http::CONTENT_TYPE_HTML);

        $actual = $response->hasHeader(Http::CONTENT_TYPE);
        $this->assertTrue($actual);

        $name   = uniqid('head-');
        $actual = $response->hasHeader($name);
        $this->assertFalse($actual);
    }
}
