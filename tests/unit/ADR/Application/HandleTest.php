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

namespace Phalcon\Tests\Unit\ADR\Application;

use Phalcon\ADR\Application;
use Phalcon\ADR\Dispatcher;
use Phalcon\ADR\ErrorResponder;
use Phalcon\ADR\Responder\JsonResponder;
use Phalcon\ADR\Router\Router;
use Phalcon\Contracts\Container\Ioc\IocContainer;
use Phalcon\Events\Manager;
use Phalcon\Http\Request;
use Phalcon\Logger\Adapter\Noop;
use Phalcon\Logger\Logger;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\ADR\Action\Hello\GetHello as HelloAction;
use stdClass;

final class HandleTest extends AbstractUnitTestCase
{
    protected function tearDown(): void
    {
        unset($_SERVER['REQUEST_URI'], $_SERVER['REQUEST_METHOD']);

        parent::tearDown();
    }

    /**
     * Unit Tests Phalcon\ADR\Application :: handle() dispatches the matched action with its attributes
     */
    public function testAdrApplicationHandleDispatchesMatchedAction(): void
    {
        $_SERVER['REQUEST_URI']    = '/hello/world';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $action = new HelloAction();

        $router = (new Router())->setBaseNamespace('Phalcon\\Tests\\Support\\ADR\\Action');

        $app = new Application(
            $router,
            new Dispatcher($this->containerReturning($action), new Manager()),
            $this->errorResponder(),
            new Manager()
        );

        $response = $app->handle(new Request());

        $this->assertSame('hello world', $response->getContent());
    }

    /**
     * Unit Tests Phalcon\ADR\Application :: handle() routes a missing route through the error responder
     */
    public function testAdrApplicationHandleRoutesRouteNotFound(): void
    {
        $_SERVER['REQUEST_URI']    = '/nope';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $app = new Application(
            (new Router())->setBaseNamespace('Phalcon\\Tests\\Support\\ADR\\Action'),
            new Dispatcher($this->containerReturning(new stdClass()), new Manager()),
            $this->errorResponder(),
            new Manager()
        );

        $response = $app->handle(new Request());

        $this->assertSame(404, $response->getStatusCode());
    }

    private function containerReturning(object $service): IocContainer
    {
        return new class ($service) implements IocContainer {
            public function __construct(private object $service)
            {
            }

            public function getService(string $serviceName): object
            {
                return $this->service;
            }

            public function hasService(string $serviceName): bool
            {
                return true;
            }
        };
    }

    private function errorResponder(): ErrorResponder
    {
        return new ErrorResponder(new JsonResponder(), new Logger('adr', ['main' => new Noop()]));
    }
}
