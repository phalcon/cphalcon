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

namespace Phalcon\Tests\Unit\ADR\Middleware\RequestIdMiddleware;

use Phalcon\ADR\Middleware\RequestIdMiddleware;
use Phalcon\Contracts\ADR\Handler;
use Phalcon\Contracts\Http\AttributeRequest;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Http\ResponseInterface;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class InvokeTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Middleware\RequestIdMiddleware :: __invoke()
     */
    public function testAdrMiddlewareRequestIdMiddlewareInvoke(): void
    {
        $request  = new Request();
        $response = (new RequestIdMiddleware())($request, $this->next());

        $id = $request->getAttributes()->get('requestId');

        $this->assertNotEmpty($id);
        $this->assertSame($id, $response->getHeaders()->get('X-Request-Id'));
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
