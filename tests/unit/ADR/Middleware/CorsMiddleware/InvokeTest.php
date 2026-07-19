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

namespace Phalcon\Tests\Unit\ADR\Middleware\CorsMiddleware;

use Phalcon\ADR\Middleware\CorsMiddleware;
use Phalcon\Contracts\ADR\Handler;
use Phalcon\Contracts\Http\AttributeRequest;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Http\ResponseInterface;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class InvokeTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Middleware\CorsMiddleware :: __invoke() echoes an allowed origin
     */
    public function testAdrMiddlewareCorsMiddlewareAllowsConfiguredOrigin(): void
    {
        $_SERVER['HTTP_ORIGIN'] = 'https://example.com';

        $middleware = new CorsMiddleware(['origins' => ['https://example.com']]);
        $response   = $middleware(new Request(), $this->next());

        $this->assertSame(
            'https://example.com',
            $response->getHeaders()->get('Access-Control-Allow-Origin')
        );

        unset($_SERVER['HTTP_ORIGIN']);
    }
    /**
     * Unit Tests Phalcon\ADR\Middleware\CorsMiddleware :: __invoke() is inert unconfigured
     */
    public function testAdrMiddlewareCorsMiddlewareInertWithoutConfig(): void
    {
        $response = (new CorsMiddleware())(new Request(), $this->next());

        $this->assertFalse($response->getHeaders()->get('Access-Control-Allow-Origin'));
    }

    private function next(): Handler
    {
        return new class implements Handler {
            public function __invoke(AttributeRequest $request): ResponseInterface
            {
                return new Response();
            }
        };
    }
}
