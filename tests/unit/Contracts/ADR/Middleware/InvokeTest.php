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

namespace Phalcon\Tests\Unit\Contracts\ADR\Middleware;

use Phalcon\Contracts\ADR\Handler;
use Phalcon\Contracts\ADR\Middleware;
use Phalcon\Contracts\Http\AttributeRequest;
use Phalcon\Http\ResponseInterface;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class InvokeTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\Contracts\ADR\Middleware :: __invoke()
     */
    public function testContractsAdrMiddlewareInvokeShape(): void
    {
        $middleware = new class implements Middleware {
            public function __invoke(AttributeRequest $request, Handler $next): ResponseInterface
            {
                return $next($request);
            }
        };

        $this->assertInstanceOf(Middleware::class, $middleware);
    }
}
