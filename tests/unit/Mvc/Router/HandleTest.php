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

    /**
     * @dataProvider groupsProvider
     *
     */
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
     * @dataProvider getUrlsWithColons
     *
     * @issue        16741
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2025-04-04
     */
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
}
