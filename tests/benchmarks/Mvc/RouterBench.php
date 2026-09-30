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

namespace Phalcon\Tests\Benchmarks\Mvc;

use Phalcon\Di\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Mvc\Router;
use Phalcon\Tests\Benchmarks\Apps\Mvc\Fixture;
use PhpBench\Attributes\BeforeMethods;
use PhpBench\Attributes\Revs;
use RuntimeException;

#[BeforeMethods('setUp')]
final class RouterBench
{
    private const METHODS_URI = '/resource7/7';

    private const URI = '/products/show/7';

    private FactoryDefault $container;

    private Fixture $fixture;

    private Router $router;

    public function setUp(): void
    {
        $_SERVER['REQUEST_METHOD'] = 'GET';
        $_SERVER['REQUEST_URI']    = self::URI;

        Di::reset();
        $this->container = new FactoryDefault();
        $this->fixture   = new Fixture();

        /**
         * A built router: the first handle() builds the route index.
         */
        $this->router = $this->fixture->router();
        $this->router->setDI($this->container);
        $this->router->handle(self::URI);
    }

    /**
     * 50 routes and the first match (with the build of the route index), as in each MVC request.
     */
    #[Revs(200)]
    public function benchDefineAndHandle(): void
    {
        $router = $this->fixture->router();
        $router->setDI($this->container);
        $router->handle(self::URI);

        $this->check($router);
    }

    /**
     * 50 routes with HTTP methods (10 resources: GET and POST on the list,
     * GET, PUT and DELETE on an item) and the first match, as in a REST
     * application.
     */
    #[Revs(200)]
    public function benchDefineAndHandleMethods(): void
    {
        $router = $this->methodRouter();
        $router->setDI($this->container);
        $router->handle(self::METHODS_URI);

        $this->checkMethods($router);
    }

    /**
     * A match on a router that is already built.
     */
    public function benchHandle(): void
    {
        $this->router->handle(self::URI);

        $this->check($this->router);
    }

    private function check(Router $router): void
    {
        if ('products' !== $router->getControllerName() || ['id' => '7'] !== $router->getParams()) {
            throw new RuntimeException(
                sprintf(
                    'Unexpected match: %s %s',
                    $router->getControllerName(),
                    json_encode($router->getParams())
                )
            );
        }
    }

    private function checkMethods(Router $router): void
    {
        if (
            'resource7' !== $router->getControllerName()
            || 'show' !== $router->getActionName()
            || ['id' => '7'] !== $router->getParams()
        ) {
            throw new RuntimeException(
                sprintf(
                    'Unexpected match: %s %s %s',
                    $router->getControllerName(),
                    $router->getActionName(),
                    json_encode($router->getParams())
                )
            );
        }
    }

    private function methodRouter(): Router
    {
        $router = new Router(false);

        for ($index = 1; $index <= 10; $index++) {
            $prefix     = '/resource' . $index;
            $controller = 'resource' . $index;

            $router->addGet($prefix, ['controller' => $controller, 'action' => 'list']);
            $router->addPost($prefix, ['controller' => $controller, 'action' => 'create']);
            $router->addGet($prefix . '/{id:[0-9]+}', ['controller' => $controller, 'action' => 'show']);
            $router->addPut($prefix . '/{id:[0-9]+}', ['controller' => $controller, 'action' => 'update']);
            $router->addDelete($prefix . '/{id:[0-9]+}', ['controller' => $controller, 'action' => 'delete']);
        }

        return $router;
    }
}
