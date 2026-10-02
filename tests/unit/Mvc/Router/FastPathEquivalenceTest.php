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

use Phalcon\Events\Manager as EventsManager;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Mvc\Fake\RouterTrait;
use PHPUnit\Framework\Attributes\BackupGlobals;
use PHPUnit\Framework\Attributes\DataProvider;

#[BackupGlobals(true)]
final class FastPathEquivalenceTest extends AbstractUnitTestCase
{
    use RouterTrait;

    /**
     * Each case: the routes in attach order, the request method, the URI
     * and the controller of the expected route.
     *
     * @return array<string, array{0: array<int, array<string, mixed>>, 1: string, 2: string, 3: string}>
     */
    public static function getCases(): array
    {
        return [
            // #17642
            'static "*" route, later regex route of the method' => [
                [
                    ['pattern' => '/', 'paths' => ['controller' => 'index']],
                    ['pattern' => '/{slug}', 'paths' => ['controller' => 'page'], 'methods' => 'PATCH'],
                ],
                'PATCH',
                '/',
                'page',
            ],
            'static "*" route, method with no bucket'          => [
                [
                    ['pattern' => '/', 'paths' => ['controller' => 'index']],
                    ['pattern' => '/{slug}', 'paths' => ['controller' => 'page'], 'methods' => 'PATCH'],
                ],
                'GET',
                '/',
                'index',
            ],
        ];
    }

    /**
     * The fast paths of handle() (static routes, combined regex) give the
     * same result as the per-route loop. An events manager turns the fast
     * paths off, so each case runs with one (the reference) and without
     * one.
     *
     * @param array<int, array<string, mixed>> $routes
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-02
     */
    #[DataProvider('getCases')]
    public function testFastPathsMatchPerRouteLoop(
        array $routes,
        string $method,
        string $uri,
        string $controller
    ): void {
        $expected = $this->handleRoutes($routes, $method, $uri, true);
        $actual   = $this->handleRoutes($routes, $method, $uri, false);

        $this->assertSame($controller, $expected['controller']);
        $this->assertSame($expected, $actual);
    }

    /**
     * @param array<int, array<string, mixed>> $routes
     *
     * @return array<string, mixed>
     */
    private function handleRoutes(array $routes, string $method, string $uri, bool $withEvents): array
    {
        $router = $this->getRouter(false);
        if ($withEvents) {
            $router->setEventsManager(new EventsManager());
        }

        foreach ($routes as $route) {
            $router->add($route['pattern'], $route['paths'], $route['methods'] ?? null);
        }

        $_SERVER['REQUEST_METHOD'] = $method;
        $router->handle($uri);

        return [
            'controller' => $router->getControllerName(),
            'matched'    => $router->wasMatched(),
            'matches'    => $router->getMatches(),
            'params'     => $router->getParams(),
            'pattern'    => $router->getMatchedRoute()?->getPattern(),
        ];
    }
}
