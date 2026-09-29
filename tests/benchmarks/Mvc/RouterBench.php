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
use RuntimeException;

#[BeforeMethods('setUp')]
final class RouterBench
{
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
    public function benchDefineAndHandle(): void
    {
        $router = $this->fixture->router();
        $router->setDI($this->container);
        $router->handle(self::URI);

        $this->check($router);
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
}
