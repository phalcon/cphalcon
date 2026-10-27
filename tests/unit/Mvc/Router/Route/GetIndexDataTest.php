<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Mvc\Router\Route;

use Phalcon\Events\Manager as EventsManager;
use Phalcon\Mvc\Router\Route;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Mvc\Fake\RouterTrait;
use PHPUnit\Framework\Attributes\BackupGlobals;
use PHPUnit\Framework\Attributes\DataProvider;

final class GetIndexDataTest extends AbstractUnitTestCase
{
    use RouterTrait;

    /**
     * @return array<string, array{0: bool}>
     */
    public static function getEventsManagerCases(): array
    {
        return [
            'no events manager' => [false],
            'events manager'    => [true],
        ];
    }

    /**
     * getIndexData() returns the values of the six getters, in order.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-03
     */
    public function testMvcRouterRouteGetIndexData(): void
    {
        $route = new Route('/users/{id:[0-9]+}', ['controller' => 'users'], ['GET', 'POST']);

        $actual = $route->getIndexData();

        $this->assertSame(
            [
                ['GET', 'POST'],
                '#^/users/([0-9]+)$#u',
                null,
                null,
                null,
                $route->getRouteId(),
            ],
            $actual
        );
    }

    /**
     * getIndexData() does not call getCompiledHostName() for a route with no
     * host name. A subclass that overrides getCompiledHostName() gets null.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-26
     */
    public function testMvcRouterRouteGetIndexDataNoHostnameNoCompiledHostNameCall(): void
    {
        $route = $this->getNoHostnameRoute();

        $actual = $route->getIndexData();

        $this->assertNull($actual[3]);
        $this->assertSame(0, $route->calls);
    }

    /**
     * The router does not read the compiled host name of a route with no
     * host name: the route matches with any host, with and without an
     * events manager.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-26
     */
    #[BackupGlobals(true)]
    #[DataProvider('getEventsManagerCases')]
    public function testMvcRouterRouteGetIndexDataNoHostnameRoutingUnchanged(bool $events): void
    {
        $route  = $this->getNoHostnameRoute();
        $router = $this->getRouter(false);
        if ($events) {
            $router->setEventsManager(new EventsManager());
        }
        $router->attach($route);

        $_SERVER['HTTP_HOST']      = 'www.other.com';
        $_SERVER['REQUEST_METHOD'] = 'GET';
        $router->handle('/users');

        $this->assertTrue($router->wasMatched());
        $this->assertSame($route, $router->getMatchedRoute());
    }

    /**
     * getIndexData() returns the compiled host name and the beforeMatch
     * callback, and the compiled host name stays in the route.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-03
     */
    public function testMvcRouterRouteGetIndexDataWithHostnameAndBeforeMatch(): void
    {
        $callback = static fn (): bool => true;
        $route    = new Route('/about', ['controller' => 'about']);
        $route->setHostname('([a-z]+).example.com');
        $route->beforeMatch($callback);

        $actual = $route->getIndexData();

        $this->assertSame(
            [
                null,
                '/about',
                '([a-z]+).example.com',
                '#^([a-z]+).example.com(:[[:digit:]]+)?$#i',
                $callback,
                $route->getRouteId(),
            ],
            $actual
        );
        $this->assertSame($actual[3], $route->getCompiledHostName());
    }

    /**
     * A route with no host name. Its getCompiledHostName() counts the calls
     * and returns a host regex.
     */
    private function getNoHostnameRoute(): Route
    {
        return new class ('/users', ['controller' => 'users']) extends Route {
            public int $calls = 0;

            public function getCompiledHostName(): ?string
            {
                $this->calls++;

                return '#^api\.example\.com$#i';
            }
        };
    }
}
