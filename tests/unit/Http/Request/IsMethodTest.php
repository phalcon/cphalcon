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

use Phalcon\Http\Request\Exceptions\InvalidHttpMethod;
use Phalcon\Tests\Support\Page\Http;
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

final class IsMethodTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function testHttpRequestIsMethod(): void
    {
        $_SERVER['REQUEST_METHOD'] = Http::METHOD_POST;

        $request = $this->getRequestObject();

        $actual = $request->isMethod(Http::METHOD_POST);
        $this->assertTrue($actual);

        $actual = $request->isMethod(
            [
                Http::METHOD_GET,
                Http::METHOD_POST,
            ]
        );
        $this->assertTrue($actual);


        $_SERVER['REQUEST_METHOD'] = Http::METHOD_GET;

        $actual = $request->isMethod(Http::METHOD_GET);
        $this->assertTrue($actual);

        $actual = $request->isMethod(
            [
                Http::METHOD_GET,
                Http::METHOD_POST,
            ]
        );
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testHttpRequestIsMethodNotMatching(): void
    {
        $_SERVER['REQUEST_METHOD'] = Http::METHOD_GET;

        $request = $this->getRequestObject();

        // string that does not match the current method
        $this->assertFalse($request->isMethod(Http::METHOD_POST));

        // array with no matching method
        $this->assertFalse($request->isMethod([Http::METHOD_POST]));

        // non-string, non-strict input returns false
        $this->assertFalse($request->isMethod(123));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testHttpRequestIsMethodStrictInvalidThrows(): void
    {
        $_SERVER['REQUEST_METHOD'] = Http::METHOD_GET;

        $request = $this->getRequestObject();

        $this->expectException(InvalidHttpMethod::class);
        $request->isMethod('INVALID', true);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testHttpRequestIsMethodStrictNonStringThrows(): void
    {
        $_SERVER['REQUEST_METHOD'] = Http::METHOD_GET;

        $request = $this->getRequestObject();

        $this->expectException(InvalidHttpMethod::class);
        $request->isMethod(123, true);
    }
}
