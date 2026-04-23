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

final class RedirectTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseRedirectLocalUrl(): void
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();
        $response->redirect(Http::REDIRECT_URI);

        $headers = $response->getHeaders();

        $expected = Http::MESSAGE_302_FOUND;
        $actual   = $headers->get(Http::STATUS);
        $this->assertSame($expected, $actual);

        $expected = '/' . Http::REDIRECT_URI;
        $actual   = $headers->get(Http::LOCATION);
        $this->assertSame($expected, $actual);

        $actual = $headers->get(Http::HTTP_302_FOUND);
        $this->assertNull($actual);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/11324
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-19
     */
    public function testHttpResponseRedirectLocalUrlWithNonStandardCode(): void
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();
        $response->redirect(Http::REDIRECT_URI, false, 309);

        $headers = $response->getHeaders();

        $expected = Http::MESSAGE_302_FOUND;
        $actual   = $headers->get(Http::STATUS);
        $this->assertSame($expected, $actual);

        $expected = '/' . Http::REDIRECT_URI;
        $actual   = $headers->get(Http::LOCATION);
        $this->assertSame($expected, $actual);

        $actual = $headers->get(Http::HTTP_302_FOUND);
        $this->assertNull($actual);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/1182
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseRedirectRemoteUrl301(): void
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();
        $response->redirect(
            Http::TEST_URI,
            true,
            Http::CODE_301
        );

        $headers = $response->getHeaders();

        $expected = Http::MESSAGE_301_MOVED_PERMANENTLY;
        $actual   = $headers->get(Http::STATUS);
        $this->assertSame($expected, $actual);

        $expected = Http::TEST_URI;
        $actual   = $headers->get(Http::LOCATION);
        $this->assertSame($expected, $actual);

        $actual = $headers->get(Http::HTTP_302_FOUND);
        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseRedirectRemoteUrl302(): void
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();
        $response->redirect(Http::TEST_URI, true);

        $headers = $response->getHeaders();

        $expected = Http::MESSAGE_302_FOUND;
        $actual   = $headers->get(Http::STATUS);
        $this->assertSame($expected, $actual);

        $expected = Http::TEST_URI;
        $actual   = $headers->get(Http::LOCATION);
        $this->assertSame($expected, $actual);

        $actual = $headers->get(Http::HTTP_302_FOUND);
        $this->assertNull($actual);
    }
}
