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
     * Each case: the routes in attach order, the request method, the URI,
     * the controller of the expected route and (optional) the host name of
     * the request.
     *
     * @return array<string, array{0: array<int, array<string, mixed>>, 1: string, 2: string, 3: string, 4?: string}>
     */
    public static function getCases(): array
    {
        $fillers = [];
        for ($index = 0; $index < 9; $index++) {
            $fillers[] = [
                'pattern' => '/filler' . $index . '/{id:[0-9]+}',
                'paths'   => ['controller' => 'filler'],
                'methods' => 'GET',
            ];
        }

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
            // #17643
            'later static route skipped by host name'          => [
                [
                    ['pattern' => '/', 'paths' => ['controller' => 'first'], 'methods' => 'PUT'],
                    ['pattern' => '/{page}', 'paths' => ['controller' => 'page'], 'methods' => 'PUT'],
                    ['pattern' => '/', 'paths' => ['controller' => 'admin'], 'hostname' => 'admin.example.com'],
                ],
                'PUT',
                '/',
                'page',
                'api.example.com',
            ],
            'later static route vetoed by beforeMatch'         => [
                [
                    ['pattern' => '/', 'paths' => ['controller' => 'first']],
                    ['pattern' => '/{page}', 'paths' => ['controller' => 'page']],
                    [
                        'pattern'     => '/',
                        'paths'       => ['controller' => 'vetoed'],
                        'beforeMatch' => static fn (): bool => false,
                    ],
                ],
                'GET',
                '/',
                'page',
            ],
            'later static route with a matching host name'    => [
                [
                    ['pattern' => '/', 'paths' => ['controller' => 'first'], 'methods' => 'PUT'],
                    ['pattern' => '/{page}', 'paths' => ['controller' => 'page'], 'methods' => 'PUT'],
                    ['pattern' => '/', 'paths' => ['controller' => 'admin'], 'hostname' => 'admin.example.com'],
                ],
                'PUT',
                '/',
                'admin',
                'admin.example.com',
            ],
            'later static route with no constraints'           => [
                [
                    ['pattern' => '/', 'paths' => ['controller' => 'first']],
                    ['pattern' => '/{page}', 'paths' => ['controller' => 'page']],
                    ['pattern' => '/', 'paths' => ['controller' => 'last']],
                ],
                'GET',
                '/',
                'last',
            ],
            // #17644: 12 regex routes in the GET bucket. Chunk 0 has "raw",
            // "broken" and 8 fillers; chunk 1 has a filler and "first".
            'pattern that does not compile in a chunk'         => [
                array_merge(
                    [['pattern' => '/{a}/{b}', 'paths' => ['controller' => 'first'], 'methods' => 'GET']],
                    $fillers,
                    [
                        ['pattern' => '/(x|e#f)/broken', 'paths' => ['controller' => 'broken'], 'methods' => 'GET'],
                        ['pattern' => '/raw/{id}', 'paths' => ['controller' => 'raw'], 'methods' => 'GET'],
                    ]
                ),
                'GET',
                '/raw/4',
                'raw',
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
        string $controller,
        string $host = 'www.example.com'
    ): void {
        $expected = $this->handleRoutes($routes, $method, $uri, $host, true);
        $actual   = $this->handleRoutes($routes, $method, $uri, $host, false);

        $this->assertSame($controller, $expected['controller']);
        $this->assertSame($expected, $actual);
    }

    /**
     * @param array<int, array<string, mixed>> $routes
     *
     * @return array<string, mixed>
     */
    private function handleRoutes(
        array $routes,
        string $method,
        string $uri,
        string $host,
        bool $withEvents
    ): array {
        $router = $this->getRouter(false);
        if ($withEvents) {
            $router->setEventsManager(new EventsManager());
        }

        foreach ($routes as $route) {
            $added = $router->add($route['pattern'], $route['paths'], $route['methods'] ?? null);

            if (isset($route['hostname'])) {
                $added->setHostname($route['hostname']);
            }

            if (isset($route['beforeMatch'])) {
                $added->beforeMatch($route['beforeMatch']);
            }
        }

        $_SERVER['REQUEST_METHOD'] = $method;
        $_SERVER['HTTP_HOST']      = $host;

        $warnings = [];
        set_error_handler(
            static function (int $number, string $message) use (&$warnings): bool {
                $warnings[] = $message;

                return true;
            }
        );

        try {
            $router->handle($uri);
        } finally {
            restore_error_handler();
        }

        return [
            'controller' => $router->getControllerName(),
            'matched'    => $router->wasMatched(),
            'matches'    => $router->getMatches(),
            'params'     => $router->getParams(),
            'pattern'    => $router->getMatchedRoute()?->getPattern(),
            'warnings'   => $warnings,
        ];
    }
}
