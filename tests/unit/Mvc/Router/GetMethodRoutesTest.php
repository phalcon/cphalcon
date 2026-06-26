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

namespace Phalcon\Tests\Unit\Mvc\Router;

use Phalcon\Mvc\Router;
use Phalcon\Mvc\Router\Group;
use Phalcon\Mvc\Router\Route;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Mvc\Fake\RouterTrait;

final class GetMethodRoutesTest extends AbstractUnitTestCase
{
    use RouterTrait;

    /**
     * Tests that clear() empties the method index.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-13
     */
    public function testGetMethodRoutesClearedOnClear(): void
    {
        Route::reset();

        $router = $this->getRouter(false);
        $router->addGet('/users', ['controller' => 'users', 'action' => 'index']);
        $router->clear();

        $index = $router->getMethodRoutes();

        $this->assertEmpty($index);
    }

    /**
     * Tests that routes from a mounted Group are also indexed.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-13
     */
    public function testGetMethodRoutesIndexesMountedGroupRoutes(): void
    {
        Route::reset();

        $router = $this->getRouter(false);

        $group = new Group(['module' => 'api']);
        $group->setPrefix('/api');
        $group->addGet('/users', ['controller' => 'users', 'action' => 'index']);
        $group->addPost('/users', ['controller' => 'users', 'action' => 'create']);

        $router->mount($group);

        $index = $router->getMethodRoutes();

        $this->assertArrayHasKey('GET', $index);
        $this->assertArrayHasKey('POST', $index);
        $this->assertCount(1, $index['GET']);
        $this->assertCount(1, $index['POST']);
    }

    /**
     * Tests that a route with multiple HTTP methods is indexed under each method,
     * and the same route object is shared across buckets.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-13
     */
    public function testGetMethodRoutesIndexesMultipleMethods(): void
    {
        Route::reset();

        $router = $this->getRouter(false);
        $router->add('/products', ['controller' => 'products', 'action' => 'list'], ['GET', 'POST']);

        $index = $router->getMethodRoutes();

        $this->assertArrayHasKey('GET', $index);
        $this->assertArrayHasKey('POST', $index);
        $this->assertCount(1, $index['GET']);
        $this->assertCount(1, $index['POST']);
        $this->assertSame($index['GET'][0], $index['POST'][0]);
    }

    /**
     * Tests that POSITION_FIRST routes appear in the method index.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-13
     */
    public function testGetMethodRoutesIndexesPositionFirstRoute(): void
    {
        Route::reset();

        $router = $this->getRouter(false);
        $router->addGet('/last', ['controller' => 'foo', 'action' => 'last']);
        $router->attach(
            new Route('/first', ['controller' => 'foo', 'action' => 'first'], 'GET'),
            Router::POSITION_FIRST
        );

        $index = $router->getMethodRoutes();

        $this->assertArrayHasKey('GET', $index);
        $this->assertCount(2, $index['GET']);
    }

    /**
     * Tests that a route with a single HTTP method is indexed under that method.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-13
     */
    public function testGetMethodRoutesIndexesSingleMethod(): void
    {
        Route::reset();

        $router = $this->getRouter(false);
        $router->addGet('/users', ['controller' => 'users', 'action' => 'index']);

        $index = $router->getMethodRoutes();

        $this->assertArrayHasKey('GET', $index);
        $this->assertCount(1, $index['GET']);
        $this->assertArrayNotHasKey('*', $index);
    }

    /**
     * Tests that a route with no HTTP constraint is indexed under "*".
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-13
     */
    public function testGetMethodRoutesIndexesUnconstrainedRouteUnderStar(): void
    {
        Route::reset();

        $router = $this->getRouter(false);
        $router->add('/about', ['controller' => 'about', 'action' => 'index']);

        $index = $router->getMethodRoutes();

        $this->assertArrayHasKey('*', $index);
        $this->assertCount(1, $index['*']);
        $this->assertArrayNotHasKey('GET', $index);
    }
}
