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

namespace Phalcon\Tests\Unit\ADR\Middleware\TimingMiddleware;

use Phalcon\ADR\Middleware\TimingMiddleware;
use Phalcon\Contracts\ADR\Handler;
use Phalcon\Contracts\Http\AttributeRequest;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Http\ResponseInterface;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class InvokeTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Middleware\TimingMiddleware :: __invoke()
     */
    public function testAdrMiddlewareTimingMiddlewareInvoke(): void
    {
        $response = (new TimingMiddleware())(new Request(), $this->next());

        $time = $response->getHeaders()->get('X-Response-Time');

        $this->assertIsString($time);
        $this->assertStringEndsWith('ms', $time);
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
