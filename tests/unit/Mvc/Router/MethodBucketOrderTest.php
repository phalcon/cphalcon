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

use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Mvc\Fake\RouterTrait;

final class MethodBucketOrderTest extends AbstractUnitTestCase
{
    use RouterTrait;

    /**
     * Regression for [#17062]: the `addGet()` helper produces a route in the
     * "GET" method bucket. Attached after the default catch-all routes, it
     * must still win for a GET request - rebuildMethodIndex() must preserve
     * the global attach order inside the merged bucket.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-03
     */
    public function testAddGetHelperWinsOverDefaultCatchAll(): void
    {
        $router = $this->getRouter();
        $router->addGet(
            '/home',
            [
                'controller' => 'index',
                'action'     => 'home',
            ]
        );

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $router->handle('/home');

        $this->assertTrue($router->wasMatched());
        $this->assertSame('index', $router->getControllerName());
        $this->assertSame('home', $router->getActionName());
    }

    /**
     * Regression for [#17062]: a method-constrained route attached after the
     * default catch-all routes was deprioritized because rebuildMethodIndex()
     * merged the method bucket as [method routes, "*" routes], placing the
     * later-attached GET route ahead of the earlier defaults and inverting
     * the reverse-iteration priority. The GET route must win for a GET
     * request rather than falling back to the default `/:controller` route.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-03
     */
    public function testMethodConstrainedRouteWinsOverDefaultCatchAll(): void
    {
        $router = $this->getRouter();
        $router->add(
            '/home',
            [
                'controller' => 'index',
                'action'     => 'home',
            ],
            'GET'
        );

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $router->handle('/home');

        $this->assertTrue($router->wasMatched());
        $this->assertSame('index', $router->getControllerName());
        $this->assertSame('home', $router->getActionName());
    }

    /**
     * Guard for [#17062]: the fix must not swallow the method constraint.
     * A GET-only route must not match a POST request; with no POST-specific
     * route the default catch-all takes over, so `/home` resolves to the
     * default `/:controller` route (controller "home", empty action).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-03
     */
    public function testMethodConstraintStillHonoredForOtherMethods(): void
    {
        $router = $this->getRouter();
        $router->add(
            '/home',
            [
                'controller' => 'index',
                'action'     => 'home',
            ],
            'GET'
        );

        $_SERVER['REQUEST_METHOD'] = 'POST';
        $router->handle('/home');

        $this->assertSame('home', $router->getControllerName());
        $this->assertSame('', $router->getActionName());
    }

    /**
     * Regression for [#17062]: a route constrained to several methods lands
     * in each of those buckets via the array branch of rebuildMethodIndex().
     * Attached after the defaults, it must still win for any of its methods -
     * here a POST request.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-03
     */
    public function testMultiMethodRouteWinsOverDefaultCatchAll(): void
    {
        $router = $this->getRouter();
        $router->add(
            '/home',
            [
                'controller' => 'index',
                'action'     => 'home',
            ],
            ['GET', 'POST']
        );

        $_SERVER['REQUEST_METHOD'] = 'POST';
        $router->handle('/home');

        $this->assertTrue($router->wasMatched());
        $this->assertSame('index', $router->getControllerName());
        $this->assertSame('home', $router->getActionName());
    }
}
