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

namespace Phalcon\Tests\Unit\Http\Request;

use Phalcon\Tests\Support\Page\Http;
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

final class GetUserAgentTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function testHttpRequestGetUserAgent(): void
    {
        $_SERVER['HTTP_USER_AGENT'] = Http::TEST_USER_AGENT;

        $request = $this->getRequestObject();

        $expected = Http::TEST_USER_AGENT;
        $actual   = $request->getUserAgent();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function testHttpRequestGetUserAgentDefault(): void
    {
        $request = $this->getRequestObject();

        $actual = $request->getUserAgent();
        $this->assertEmpty($actual);
    }
}
