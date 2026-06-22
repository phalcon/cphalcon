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

use Phalcon\Di\FactoryDefault;
use Phalcon\Http\Request;
use Phalcon\Mvc\Router;
use Phalcon\Mvc\Router\Group;
use Phalcon\Mvc\Router\Route;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use Phalcon\Tests\Unit\Mvc\Fake\RouterTrait;
use PHPUnit\Framework\Attributes\BackupGlobals;
use PHPUnit\Framework\Attributes\DataProvider;

#[BackupGlobals(true)]
final class HandleTest extends AbstractUnitTestCase
{
    use DiTrait;
    use RouterTrait;

    /**
     * @return array[]
     */
    public static function getUrlsWithColons(): array
    {
        return [
            ['/1:1/test'],
            ['/a:1/test'],
            ['/1:a/test'],
            ['/a:a/test'],
        ];
    }

    /**
     * @return array[]
     */
    public static function groupsProvider(): array
    {
        return [
            [
                '/blog/save',
                'blog',
                'index',
                'save',
            ],
            [
                '/blog/edit/1',
                'blog',
                'index',
                'edit',
            ],
            [
                '/blog/about',
                'blog',
                'about',
                'index',
            ],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-10-20
     */
    public function testMvcRouterHandle(): void
    {
        $router = $this->getRouter();

        $router->add(
            '/admin/invoices/list',
            [
                'controller' => 'invoices',
                'action'     => 'list',
            ]
        );

        $router->handle('/admin/invoices/list');

        $expected = 'invoices';
        $actual   = $router->getControllerName();
        $this->assertSame($expected, $actual);

        $expected = 'list';
        $actual   = $router->getActionName();
        $this->assertSame($expected, $actual);

        $expected = [];
        $actual   = $router->getParams();
        $this->assertSame($expected, $actual);
    }

    #[DataProvider('groupsProvider')]
    public function testMvcRouterHandleGroups(
        string $route,
        string $module,
        string $controller,
        string $action
    ): void {
        Route::reset();

        $router = $this->getRouter(false);

        $blog = new Group(
            [
                'module'     => 'blog',
                'controller' => 'index',
            ]
        );

        $blog->setPrefix('/blog');

        $blog->add(
            '/save',
            [
                'action' => 'save',
            ]
        );

        $blog->add(
            '/edit/{id}',
            [
                'action' => 'edit',
            ]
        );

        $blog->add(
            '/about',
            [
                'controller' => 'about',
                'action'     => 'index',
            ]
        );

        $router->mount($blog);
        $router->handle($route);

        $this->assertTrue($router->wasMatched());
        $this->assertSame($module, $router->getModuleName());
        $this->assertSame($controller, $router->getControllerName());
        $this->assertSame($action, $router->getActionName());

        $this->assertSame(
            $blog,
            $router->getMatchedRoute()->getGroup()
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-10-17
     */
    public function testMvcRouterHandleNumeric(): void
    {
        $router = $this->getRouter();
        $router->handle('/12/34/56');

        $expected = '';
        $actual   = $router->getModuleName();
        $this->assertSame($expected, $actual);

        $expected = '';
        $actual   = $router->getNamespaceName();
        $this->assertSame($expected, $actual);

        $expected = '12';
        $actual   = $router->getControllerName();
        $this->assertSame($expected, $actual);

        $expected = '34';
        $actual   = $router->getActionName();
        $this->assertSame($expected, $actual);

        $expected = ['56'];
        $actual   = $router->getParams();
        $this->assertSame($expected, $actual);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/security/advisories/GHSA-x7rj-f32v-7jjg
     * @author Nikko Enggaliano Pratama <nikkoenggaliano@gmail.com>
     * @since  2026-06-18
     */
    public function testMvcRouterHandleParamsNoCatastrophicBacktracking(): void
    {
        $router = $this->getRouter();

        /**
         * The default /:controller/:action/:params route still splits a
         * multi-segment trailing path into individual parameters.
         */
        $router->handle('/products/show/1/2/3');

        $this->assertSame('products', $router->getControllerName());
        $this->assertSame('show', $router->getActionName());
        $this->assertSame(['1', '2', '3'], $router->getParams());

        /**
         * Take the compiled pattern of the default :params route and match a
         * crafted URI: a long run of slashes followed by an unmatchable byte.
         * The previous (/.*)* was a nested quantifier that exhausted
         * pcre.backtrack_limit on such input, while (/.*)? matches in linear
         * time, so preg_match() completes without a PCRE error.
         */
        $pattern = '';

        foreach ($router->getRoutes() as $route) {
            if (str_contains($route->getCompiledPattern(), '(/.*)')) {
                $pattern = $route->getCompiledPattern();

                break;
            }
        }

        $this->assertNotSame('', $pattern);

        preg_match($pattern, '/a/a' . str_repeat('/', 50) . "\n\n");

        $this->assertSame(PREG_NO_ERROR, preg_last_error());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-10-20
     */
    public function testMvcRouterHandleShortSyntax(): void
    {
        $router = $this->getRouter(false);
        $router->add("/about", "About::content");

        $router->handle('/about');

        $expected = '';
        $actual   = $router->getModuleName();
        $this->assertSame($expected, $actual);

        $expected = '';
        $actual   = $router->getNamespaceName();
        $this->assertSame($expected, $actual);

        $expected = 'About';
        $actual   = $router->getControllerName();
        $this->assertSame($expected, $actual);

        $expected = 'content';
        $actual   = $router->getActionName();
        $this->assertSame($expected, $actual);

        $expected = [];
        $actual   = $router->getParams();
        $this->assertSame($expected, $actual);

        $_SERVER['REQUEST_METHOD'] = 'POST';

        $container = new FactoryDefault();
        $container->set('request', new Request());

        $router = new Router(false);
        $router->setDI($container);
        $router->add(
            "/about",
            "About::content",
            ["GET"]
        );

        $router->handle('/about');

        $actual = $router->getMatchedRoute();
        $this->assertNull($actual);

        $expected = '';
        $actual   = $router->getControllerName();
        $this->assertSame($expected, $actual);

        $expected = '';
        $actual   = $router->getActionName();
        $this->assertSame($expected, $actual);

        $actual = $router->getParams();
        $this->assertEmpty($actual);

        $router->add(
            "/about",
            "About::content",
            ["POST"],
            Router::POSITION_FIRST
        );

        $router->handle('/about');

        $expected = '';
        $actual   = $router->getModuleName();
        $this->assertSame($expected, $actual);

        $expected = '';
        $actual   = $router->getNamespaceName();
        $this->assertSame($expected, $actual);

        $expected = 'About';
        $actual   = $router->getControllerName();
        $this->assertSame($expected, $actual);

        $expected = 'content';
        $actual   = $router->getActionName();
        $this->assertSame($expected, $actual);

        $expected = [];
        $actual   = $router->getParams();
        $this->assertSame($expected, $actual);
    }

    /**
     * @issue        https://github.com/phalcon/cphalcon/issues/16741
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2025-04-04
     */
    #[DataProvider('getUrlsWithColons')]
    public function testMvcRouterHandleWithColons(string $url): void
    {
        $this->setNewFactoryDefault();
        $router = new Router(false);
        $router->setDI($this->container);

        // Simple catch-all route
        $router->add(
            '/{param:.+}',
            [
                'controller' => 'index',
                'action'     => 'test',
            ]
        );

        // Explicitly set request method (for CLI testing)
        $_SERVER["REQUEST_METHOD"] = "GET";

        $router->handle($url);

        $route = $router->getMatchedRoute();
        $this->assertInstanceOf(Route::class, $route);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-10-20
     */
    public function testMvcRouterHandleWithPlaceholders(): void
    {
        /**
         * Regular placeholders
         */
        $router = $this->getRouter(false);
        $router->add(
            '/:module/:namespace/:controller/:action/:params/:int',
            [
                'module'     => 1,
                'namespace'  => 2,
                'controller' => 3,
                'action'     => 4,
                'params'     => 5,
                'my-number'  => 6,
            ]
        );

        $router->handle('/admin/private/businesses/list/my/123');

        $expected = 'admin';
        $actual   = $router->getModuleName();
        $this->assertSame($expected, $actual);

        $expected = 'private';
        $actual   = $router->getNamespaceName();
        $this->assertSame($expected, $actual);

        $expected = 'businesses';
        $actual   = $router->getControllerName();
        $this->assertSame($expected, $actual);

        $expected = 'list';
        $actual   = $router->getActionName();
        $this->assertSame($expected, $actual);

        $expected = [
            'my',
            'my-number' => '123',
        ];
        $actual   = $router->getParams();
        $this->assertSame($expected, $actual);

        /**
         * Parameters
         */
        $router->add(
            '/admin/{year}/{month}/{day}/{invoiceNo:[0-9]+}',
            [
                'controller' => 'invoices',
                'action'     => 'view',
            ]
        );

        $router->handle('/admin/2020/october/21/456');

        $expected = '';
        $actual   = $router->getModuleName();
        $this->assertSame($expected, $actual);

        $expected = '';
        $actual   = $router->getNamespaceName();
        $this->assertSame($expected, $actual);

        $expected = 'invoices';
        $actual   = $router->getControllerName();
        $this->assertSame($expected, $actual);

        $expected = 'view';
        $actual   = $router->getActionName();
        $this->assertSame($expected, $actual);

        $expected = [
            'year'      => '2020',
            'month'     => 'october',
            'day'       => '21',
            'invoiceNo' => '456',
        ];
        $actual   = $router->getParams();
        $this->assertSame($expected, $actual);

        /**
         * Named parameters
         */
        $router->add(
            '/admin/([0-9]{4})/([0-9]{2})/([0-9]{2})/:params',
            [
                'controller' => 'history',
                'action'     => 'search',
                'year'       => 1, // ([0-9]{4})
                'month'      => 2, // ([0-9]{2})
                'day'        => 3, // ([0-9]{2})
                'params'     => 4, // :params
            ]
        );

        $router->handle('/admin/2020/10/21/456');

        $expected = '';
        $actual   = $router->getModuleName();
        $this->assertSame($expected, $actual);

        $expected = '';
        $actual   = $router->getNamespaceName();
        $this->assertSame($expected, $actual);

        $expected = 'history';
        $actual   = $router->getControllerName();
        $this->assertSame($expected, $actual);

        $expected = 'search';
        $actual   = $router->getActionName();
        $this->assertSame($expected, $actual);

        $expected = [
            '456',
            'year'  => '2020',
            'month' => '10',
            'day'   => '21',
        ];
        $actual   = $router->getParams();
        $this->assertSame($expected, $actual);
    }

    /**
     * Tests that a route registered for POST is not matched on a GET request.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-13
     */
    public function testMvcRouterHandleDoesNotMatchWrongMethod(): void
    {
        Route::reset();

        $router = $this->getRouter(false);
        $router->addPost('/submit', ['controller' => 'form', 'action' => 'submit']);

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $router->handle('/submit');

        $this->assertFalse($router->wasMatched());
        $this->assertSame('', $router->getControllerName());
        $this->assertSame('', $router->getActionName());
    }

    /**
     * Tests that unconstrained routes match any HTTP method.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-13
     */
    public function testMvcRouterHandleMatchesUnconstrainedRouteOnAnyMethod(): void
    {
        foreach (['GET', 'POST', 'PUT', 'DELETE', 'PATCH'] as $method) {
            Route::reset();

            $router = $this->getRouter(false);
            $router->add('/info', ['controller' => 'info', 'action' => 'index']);

            $_SERVER['REQUEST_METHOD'] = $method;
            $router->handle('/info');

            $this->assertTrue(
                $router->wasMatched(),
                "Expected unconstrained route to match on {$method}"
            );
            $this->assertSame('info', $router->getControllerName());
        }
    }

    /**
     * Tests that the last-registered matching route wins (reverse iteration preserved).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-13
     */
    public function testMvcRouterHandleLastRouteWinsForSamePattern(): void
    {
        Route::reset();

        $router = $this->getRouter(false);
        $router->addGet('/page', ['controller' => 'first',  'action' => 'index']);
        $router->addGet('/page', ['controller' => 'second', 'action' => 'index']);

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $router->handle('/page');

        $this->assertTrue($router->wasMatched());
        $this->assertSame('second', $router->getControllerName());
    }
}
