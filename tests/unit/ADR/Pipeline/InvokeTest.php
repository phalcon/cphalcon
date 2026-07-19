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

namespace Phalcon\Tests\Unit\ADR\Pipeline;

use Phalcon\ADR\Pipeline;
use Phalcon\Contracts\ADR\Handler;
use Phalcon\Contracts\ADR\Middleware;
use Phalcon\Contracts\Http\AttributeRequest;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Http\ResponseInterface;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class InvokeTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Pipeline :: __invoke() a middleware can short-circuit
     */
    public function testAdrPipelineInvokeMiddlewareCanShortCircuit(): void
    {
        $shortCircuit = new class implements Middleware {
            public function __invoke(AttributeRequest $request, Handler $next): ResponseInterface
            {
                return (new Response())->setContent('short-circuit');
            }
        };

        $pipeline = new Pipeline([$shortCircuit], $this->terminal('terminal-ran'));

        $result = $pipeline(new Request());

        $this->assertSame('short-circuit', $result->getContent());
    }

    /**
     * Unit Tests Phalcon\ADR\Pipeline :: __invoke() threads middleware as an onion
     */
    public function testAdrPipelineInvokeRunsMiddlewareOnion(): void
    {
        $wrap = new class implements Middleware {
            public function __invoke(AttributeRequest $request, Handler $next): ResponseInterface
            {
                $response = $next($request);

                return $response->setContent('[' . $response->getContent() . ']');
            }
        };

        $pipeline = new Pipeline([$wrap, $wrap], $this->terminal('T'));

        $result = $pipeline(new Request());

        $this->assertSame('[[T]]', $result->getContent());
    }
    /**
     * Unit Tests Phalcon\ADR\Pipeline :: __invoke() runs the terminal handler
     */
    public function testAdrPipelineInvokeRunsTerminal(): void
    {
        $pipeline = new Pipeline([], $this->terminal('terminal'));

        $result = $pipeline(new Request());

        $this->assertSame('terminal', $result->getContent());
    }

    private function terminal(string $body): Handler
    {
        return new class ($body) implements Handler {
            public function __construct(private string $body)
            {
            }

            public function __invoke(AttributeRequest $request): ResponseInterface
            {
                return (new Response())->setContent($this->body);
            }
        };
    }
}
