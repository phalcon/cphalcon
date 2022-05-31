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

namespace Phalcon\Tests\Integration\Mvc\Router;

use IntegrationTester;
use Phalcon\Di\FactoryDefault;
use Phalcon\Http\Request;
use Phalcon\Mvc\Router;

/**
 * Class HandleCest
 */
class HandleCest
{
    /**
     * Tests Phalcon\Mvc\Router :: handle()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-10-20
     */
    public function mvcRouterHandle(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - handle()');

        $router = new Router();

        $router->add(
            '/admin/invoices/list',
            [
                'controller' => 'invoices',
                'action'     => 'list',
            ]
        );

        $router->handle(
            '/admin/invoices/list'
        );

        $I->assertEquals(
            'invoices',
            $router->getControllerName()
        );

        $I->assertEquals(
            'list',
            $router->getActionName()
        );

        $I->assertEquals(
            [],
            $router->getParams()
        );
    }

    /**
     * Tests Phalcon\Mvc\Router :: handle() - with placeholders
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-10-20
     */
    public function mvcRouterHandleWithPlaceholders(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - handle() - with placeholders');

        /**
         * Regular placeholders
         */
        $router = new Router(false);
        $router->add(
            '/:module/:namespace/:controller/:action/:params/:int',
            [
                'module'     => 1,
                'namespace'  => 2,
                'controller' => 3,
                'action'     => 4,
                'params'     => 5,
                'my-number'  => 6
            ]
        );

        $router->handle(
            '/admin/private/businesses/list/my/123'
        );

        $I->assertEquals(
            'admin',
            $router->getModuleName()
        );

        $I->assertEquals(
            'private',
            $router->getNamespaceName()
        );

        $I->assertEquals(
            'businesses',
            $router->getControllerName()
        );

        $I->assertEquals(
            'list',
            $router->getActionName()
        );

        $I->assertEquals(
            [
                'my',
                'my-number' => 123
            ],
            $router->getParams()
        );

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

        $router->handle(
            '/admin/2020/october/21/456'
        );

        $I->assertSame(
            '',
            $router->getModuleName()
        );

        $I->assertSame(
            '',
            $router->getNamespaceName()
        );

        $I->assertEquals(
            'invoices',
            $router->getControllerName()
        );

        $I->assertEquals(
            'view',
            $router->getActionName()
        );

        $I->assertEquals(
            [
                'invoiceNo' => 456,
                'year'      => 2020,
                'month'     => 'october',
                'day'       => 21,
            ],
            $router->getParams()
        );

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

        $router->handle(
            '/admin/2020/10/21/456'
        );

        $I->assertSame(
            '',
            $router->getModuleName()
        );

        $I->assertSame(
            '',
            $router->getNamespaceName()
        );

        $I->assertEquals(
            'history',
            $router->getControllerName()
        );

        $I->assertEquals(
            'search',
            $router->getActionName()
        );

        $I->assertEquals(
            [
                'year'  => 2020,
                'month' => 10,
                'day'   => 21,
                456
            ],
            $router->getParams()
        );
    }

    /**
     * Tests Phalcon\Mvc\Router :: handle() - short syntax
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-10-20
     */
    public function mvcRouterHandleShortSyntax(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - handle() - short syntax');

        $router = new Router(false);
        $router->add("/about", "About::content");

        $router->handle('/about');

        $I->assertSame(
            '',
            $router->getModuleName()
        );

        $I->assertSame(
            '',
            $router->getNamespaceName()
        );

        $I->assertEquals(
            'About',
            $router->getControllerName()
        );

        $I->assertEquals(
            'content',
            $router->getActionName()
        );

        $I->assertEquals(
            [],
            $router->getParams()
        );

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

        $I->assertNull(
            $router->getMatchedRoute()
        );

        $I->assertSame(
            '',
            $router->getControllerName()
        );

        $I->assertSame(
            '',
            $router->getActionName()
        );

        $I->assertEmpty(
            $router->getParams()
        );

        $router->add(
            "/about",
            "About::content",
            ["POST"],
            Router::POSITION_FIRST
        );

        $router->handle('/about');

        $I->assertSame(
            '',
            $router->getModuleName()
        );

        $I->assertSame(
            '',
            $router->getNamespaceName()
        );

        $I->assertEquals(
            'About',
            $router->getControllerName()
        );

        $I->assertEquals(
            'content',
            $router->getActionName()
        );

        $I->assertEquals(
            [],
            $router->getParams()
        );
    }

    /**
     * Tests Phalcon\Mvc\Router :: handle() - numeric
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-10-17
     */
    public function mvcRouterHandleNumeric(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - handle() - numeric');

        $router = new Router();

        $di = new FactoryDefault();

        $router->setDI($di);
        $router->handle('/12/34/56');

        $I->assertSame(
            '',
            $router->getModuleName()
        );

        $I->assertSame(
            '',
            $router->getNamespaceName()
        );

        $I->assertEquals(
            '12',
            $router->getControllerName()
        );

        $I->assertEquals(
            '34',
            $router->getActionName()
        );

        $I->assertEquals(
            ['56'],
            $router->getParams()
        );
    }
}
