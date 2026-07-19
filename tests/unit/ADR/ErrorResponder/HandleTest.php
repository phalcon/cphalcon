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

namespace Phalcon\Tests\Unit\ADR\ErrorResponder;

use Phalcon\ADR\ErrorResponder;
use Phalcon\ADR\Exceptions\MethodNotAllowed;
use Phalcon\ADR\Exceptions\RouteNotFound;
use Phalcon\ADR\Responder\JsonResponder;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Logger\Adapter\Noop;
use Phalcon\Logger\Logger;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use RuntimeException;

final class HandleTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\ErrorResponder :: handle() exposes details in debug mode
     */
    public function testAdrErrorResponderHandleExposesDetailsInDebug(): void
    {
        $responder = new ErrorResponder(new JsonResponder(), $this->logger(), true);

        $response = $responder->handle(new Request(), new Response(), new RouteNotFound());

        $this->assertStringContainsString('No route matched the request.', $response->getContent());
    }
    /**
     * Unit Tests Phalcon\ADR\ErrorResponder :: handle() hides the exception behind a generic message
     */
    public function testAdrErrorResponderHandleGenericMessage(): void
    {
        $response = $this->responder()->handle(
            new Request(),
            new Response(),
            new RouteNotFound()
        );

        $this->assertSame(404, $response->getStatusCode());
        $this->assertStringContainsString('Internal Server Error', $response->getContent());
        $this->assertStringNotContainsString('No route matched the request.', $response->getContent());
    }

    /**
     * Unit Tests Phalcon\ADR\ErrorResponder :: handle() maps MethodNotAllowed to 405
     */
    public function testAdrErrorResponderHandleMapsMethodNotAllowed(): void
    {
        $response = $this->responder()->handle(
            new Request(),
            new Response(),
            new MethodNotAllowed()
        );

        $this->assertSame(405, $response->getStatusCode());
    }

    /**
     * Unit Tests Phalcon\ADR\ErrorResponder :: handle() maps an unmapped exception to 500
     */
    public function testAdrErrorResponderHandleUnmappedIsServerError(): void
    {
        $response = $this->responder()->handle(
            new Request(),
            new Response(),
            new RuntimeException('boom')
        );

        $this->assertSame(500, $response->getStatusCode());
    }

    private function logger(): Logger
    {
        return new Logger('adr', ['main' => new Noop()]);
    }

    private function responder(): ErrorResponder
    {
        return new ErrorResponder(new JsonResponder(), $this->logger());
    }
}
