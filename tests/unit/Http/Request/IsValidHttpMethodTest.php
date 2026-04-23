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

use Phalcon\Http\Request;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Page\Http;

use function uniqid;

final class IsValidHttpMethodTest extends AbstractUnitTestCase
{
    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            [
                Http::METHOD_CONNECT,
                true,
            ],
            [
                Http::METHOD_DELETE,
                true,
            ],
            [
                Http::METHOD_GET,
                true,
            ],
            [
                Http::METHOD_HEAD,
                true,
            ],
            [
                Http::METHOD_OPTIONS,
                true,
            ],
            [
                Http::METHOD_PATCH,
                true,
            ],
            [
                Http::METHOD_POST,
                true,
            ],
            [
                Http::METHOD_PURGE,
                true,
            ],
            [
                Http::METHOD_PUT,
                true,
            ],
            [
                Http::METHOD_TRACE,
                true,
            ],
            [
                strtolower(Http::METHOD_CONNECT),
                true,
            ],
            [
                strtolower(Http::METHOD_DELETE),
                true,
            ],
            [
                strtolower(Http::METHOD_GET),
                true,
            ],
            [
                strtolower(Http::METHOD_HEAD),
                true,
            ],
            [
                strtolower(Http::METHOD_OPTIONS),
                true,
            ],
            [
                strtolower(Http::METHOD_PATCH),
                true,
            ],
            [
                strtolower(Http::METHOD_POST),
                true,
            ],
            [
                strtolower(Http::METHOD_PURGE),
                true,
            ],
            [
                strtolower(Http::METHOD_PUT),
                true,
            ],
            [
                strtolower(Http::METHOD_TRACE),
                true,
            ],
            [
                uniqid('meth-'),
                false,
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-03-17
     */
    public function testHttpRequestIsValidHttpMethod(
        string $method,
        bool $expected
    ): void {
        $request = new Request();

        $actual = $request->isValidHttpMethod($method);
        $this->assertSame($expected, $actual);
    }
}
