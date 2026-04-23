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

use function uniqid;

final class GetMethodTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function testHttpRequestGetMethodDefault(): void
    {
        // Default
        $request = $this->getRequestObject();

        $expected = Http::METHOD_GET;
        $actual   = $request->getMethod();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function testHttpRequestGetMethodHeaderPost(): void
    {
        $_SERVER['REQUEST_METHOD'] = Http::METHOD_POST;

        $request = $this->getRequestObject();

        $expected = Http::METHOD_POST;
        $actual   = $request->getMethod();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function testHttpRequestGetMethodHeaderPostOverride(): void
    {
        $_SERVER['REQUEST_METHOD']         = Http::METHOD_POST;
        $_SERVER['X_HTTP_METHOD_OVERRIDE'] = Http::METHOD_TRACE;

        $request = $this->getRequestObject();

        $expected = Http::METHOD_TRACE;
        $actual   = $request->getMethod();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function testHttpRequestGetMethodHeaderSpoof(): void
    {
        $_SERVER['REQUEST_METHOD'] = Http::METHOD_POST;
        $_REQUEST['_method']       = Http::METHOD_CONNECT;

        $request = $this->getRequestObject();
        $request->setHttpMethodParameterOverride(true);

        $expected = Http::METHOD_CONNECT;
        $actual   = $request->getMethod();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function testHttpRequestGetMethodNotValid(): void
    {
        $method                    = uniqid('meth-');
        $_SERVER['REQUEST_METHOD'] = $method;

        $request = $this->getRequestObject();

        $expected = Http::METHOD_GET;
        $actual   = $request->getMethod();
        $this->assertSame($expected, $actual);
    }
}
