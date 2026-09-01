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

namespace Phalcon\Tests\Unit\ADR\Middleware\MethodOverrideMiddleware;

use Phalcon\ADR\Middleware\MethodOverrideMiddleware;
use Phalcon\Contracts\ADR\Handler;
use Phalcon\Contracts\Http\AttributeRequest;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Http\ResponseInterface;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class InvokeTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Middleware\MethodOverrideMiddleware :: __invoke() ignores non-whitelisted verbs
     */
    public function testAdrMiddlewareMethodOverrideMiddlewareIgnoresNonWhitelisted(): void
    {
        $_SERVER['REQUEST_METHOD'] = 'POST';
        $_POST['_method']          = 'GET';
        $_REQUEST['_method']       = 'GET';

        $request = new Request();

        (new MethodOverrideMiddleware())($request, $this->next());

        $this->assertSame('POST', $request->getMethod());

        unset($_SERVER['REQUEST_METHOD'], $_POST['_method'], $_REQUEST['_method']);
    }
    /**
     * Unit Tests Phalcon\ADR\Middleware\MethodOverrideMiddleware :: __invoke()
     */
    public function testAdrMiddlewareMethodOverrideMiddlewareInvokeEnablesWhitelisted(): void
    {
        $_SERVER['REQUEST_METHOD'] = 'POST';
        $_POST['_method']          = 'PUT';
        $_REQUEST['_method']       = 'PUT';

        $request = new Request();
        $this->assertSame('POST', $request->getMethod());

        (new MethodOverrideMiddleware())($request, $this->next());

        $this->assertSame('PUT', $request->getMethod());

        unset($_SERVER['REQUEST_METHOD'], $_POST['_method'], $_REQUEST['_method']);
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
