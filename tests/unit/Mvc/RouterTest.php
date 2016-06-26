<?php

namespace Phalcon\Test\Unit\Mvc;

use Phalcon\Di;
use Phalcon\Http\Request;
use Phalcon\Mvc\Router\Route;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Proxy\Mvc\Router;

/**
 * \Phalcon\Test\Unit\Mvc\RouterTest
 * Tests the Phalcon\Mvc\Router component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Mvc
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class RouterTest extends UnitTest
{
    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();

        Route::reset();
    }

    /**
     * Tests router
     *
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2013-01-17
     */
    public function testRouterStandardBehaviour()
    {
        $this->specify(
            'Router does not work as expected',
            function ($uri, $controller, $action, $params) {
                $router = $this->getRouter();

                $_GET['_url'] = '';

                $router->add('/', [
                    'controller' => 'index',
                    'action' => 'index'
                ]);

                $router->add('/system/:controller/a/:action/:params', [
                    'controller' => 1,
                    'action' => 2,
                    'params' => 3,
                ]);

                $router->add('/([a-z]{2})/:controller', [
                    'controller' => 2,
                    'action' => 'index',
                    'language' => 1
                ]);

                $router->add('/admin/:controller/:action/:int', [
                    'controller' => 1,
                    'action' => 2,
                    'id' => 3
                ]);

                $router->add('/posts/([0-9]{4})/([0-9]{2})/([0-9]{2})/:params', [
                    'controller' => 'posts',
                    'action' => 'show',
                    'year' => 1,
                    'month' => 2,
                    'day' => 3,
                    'params' => 4,
                ]);

                $router->add('/manual/([a-z]{2})/([a-z\.]+)\.html', [
                    'controller' => 'manual',
                    'action' => 'show',
                    'language' => 1,
                    'file' => 2
                ]);

                $router->add('/named-manual/{language:([a-z]{2})}/{file:[a-z\.]+}\.html', [
                    'controller' => 'manual',
                    'action' => 'show',
                ]);

                $router->add('/very/static/route', [
                    'controller' => 'static',
                    'action' => 'route'
                ]);

                $router->add('/feed/{lang:[a-z]+}/blog/{blog:[a-z\-]+}\.{type:[a-z\-]+}', 'Feed::get');
                $router->add('/posts/{year:[0-9]+}/s/{title:[a-z\-]+}', 'Posts::show');
                $router->add('/posts/delete/{id}', 'Posts::delete');
                $router->add('/show/{id:video([0-9]+)}/{title:[a-z\-]+}', 'Videos::show');

                $router->handle($uri);

                expect($router->getControllerName())->equals($controller);
                expect($router->getActionName())->equals($action);
                expect($router->getParams())->equals($params);
            }, ['examples' => $this->routerProvider()]
        );
    }

    /**
     * Tests setting host name by using regexp
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-06-23
     */
    public function testHostnameRegexRouter()
    {
        $this->specify(
            'The Router::getControllerName does not return correct controller by using regexp in host name',
            function ($hostname, $expected) {
                $router = $this->getRouter(false);

                $router->add('/edit', [
                    'controller' => 'posts3',
                    'action' => 'edit3'
                ]);

                $router->add('/edit', [
                    'controller' => 'posts',
                    'action' => 'edit'
                ])->setHostname('([a-z]+).phalconphp.com');

                $router->add('/edit', [
                    'controller' => 'posts2',
                    'action' => 'edit2'
                ])->setHostname('mail.([a-z]+).com');

                $router->add('/edit', [
                    'controller' => 'posts4',
                    'action' => 'edit2'
                ])->setHostname('([a-z]+).([a-z]+).net');

                $_SERVER['HTTP_HOST'] = $hostname;
                $router->handle('/edit');
                expect($router->getControllerName())->equals($expected);
            }, ['examples' => [
                ['localhost',         'posts3'],
                ['my.phalconphp.com', 'posts' ],
                [null,                'posts3'],
                ['mail.example.com',  'posts2'],
                ['some-domain.com',   'posts3'],
                ['some.domain.net',   'posts4'],
            ]]
        );
    }

    /**
     * Tests setting host name by using regexp
     *
     * @issue  2573
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-06-26
     */
    public function testHostnameRegexRouterWithHostPort()
    {
        $this->specify(
            'The Router::getControllerName does not return correct controller by using regexp in host name',
            function ($hostname, $expected, $port) {
                $router = $this->getRouter(false);

                $router->add('/edit', [
                    'controller' => 'posts3',
                    'action' => 'edit3'
                ]);

                $router->add('/edit', [
                    'controller' => 'posts',
                    'action' => 'edit'
                ])->setHostname('([a-z]+).phalconphp.com');

                $router->add('/edit', [
                    'controller' => 'posts2',
                    'action' => 'edit2'
                ])->setHostname('mail.([a-z]+).com');

                $router->add('/edit', [
                    'controller' => 'posts4',
                    'action' => 'edit2'
                ])->setHostname('([a-z]+).([a-z]+).net');

                $_SERVER['HTTP_HOST'] = $hostname . ($port ? ':' . $port : '');
                $router->handle('/edit');
                expect($router->getControllerName())->equals($expected);
            }, ['examples' => [
                ['localhost',         'posts3', null],
                ['my.phalconphp.com', 'posts',  80 ],
                ['my.phalconphp.com', 'posts',  8080],
                [null,                'posts3', 8080],
                ['mail.example.com',  'posts2', 9090],
                ['some-domain.com',   'posts3', 9000],
                ['some.domain.net',   'posts4', 0],
            ]]
        );
    }

    /**
     * Tests setting host name
     *
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2013-04-15
     */
    public function testHostnameRouter()
    {
        $this->specify(
            'The Router::getControllerName does not return correct controller by using host name',
            function ($hostname, $expected) {
                $router = $this->getRouter(false);

                $router->add('/edit', [
                    'controller' => 'posts3',
                    'action' => 'edit3'
                ]);

                $router->add('/edit', [
                    'controller' => 'posts',
                    'action' => 'edit'
                ])->setHostname('my.phalconphp.com');

                $router->add('/edit', [
                    'controller' => 'posts2',
                    'action' => 'edit2'
                ])->setHostname('my2.phalconphp.com');

                $_SERVER['HTTP_HOST'] = $hostname;
                $router->handle('/edit');
                expect($router->getControllerName())->equals($expected);
            }, ['examples' => [
                ['localhost',          'posts3'],
                [null,                 'posts3'],
                ['my.phalconphp.com',  'posts'],
                ['my2.phalconphp.com', 'posts2'],
            ]]
        );
    }

    /**
     * Tests setting notFound handler
     *
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2013-03-01
     */
    public function testSettingNotFoundPaths()
    {
        $this->specify(
            'Setting a group of paths to be returned when none of the defined routes are matched does not work as expected',
            function () {
                $router = $this->getRouter(false);

                $router->notFound(
                    [
                        'module'     => 'module',
                        'namespace'  => 'namespace',
                        'controller' => 'controller',
                        'action'     => 'action'
                    ]
                );

                $router->handle();

                expect($router->getControllerName())->equals('controller');
                expect($router->getActionName())->equals('action');
                expect($router->getModuleName())->equals('module');
                expect($router->getNamespaceName())->equals('namespace');
            }
        );
    }

    /**
     * Tests setting different URI source
     *
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2013-04-07
     */
    public function testMatchingByUsingDifferentUriSource()
    {
        $this->specify(
            'Matching uri when setting different uri source does not work as expected',
            function () {
                $router = $this->getRouter(false);

                $_GET['_url'] = '/some/route';
                expect($router->getRewriteUri())->equals('/some/route');

                $router->setUriSource(Router::URI_SOURCE_GET_URL);
                expect($router->getRewriteUri())->equals('/some/route');

                $_SERVER['REQUEST_URI'] = '/some/route';
                $router->setUriSource(Router::URI_SOURCE_SERVER_REQUEST_URI);

                expect($router->getRewriteUri())->equals('/some/route');

                $_SERVER['REQUEST_URI'] = '/some/route?x=1';
                expect($router->getRewriteUri())->equals('/some/route');
            }
        );
    }

    protected function routerProvider()
    {
        return [
            [
                'uri' => '',
                'controller' => 'index',
                'action' => 'index',
                'params' => []
            ],
            [
                'uri' => '/',
                'controller' => 'index',
                'action' => 'index',
                'params' => []
            ],
            [
                'uri' => '/documentation/index/hellao/aaadpqñda/bbbAdld/cc-ccc',
                'controller' => 'documentation',
                'action' => 'index',
                'params' => ['hellao', 'aaadpqñda', 'bbbAdld', 'cc-ccc']
            ],
            [
                'uri' => '/documentation/index/',
                'controller' => 'documentation',
                'action' => 'index',
                'params' => []
            ],
            [
                'uri' => '/documentation/index',
                'controller' => 'documentation',
                'action' => 'index',
                'params' => []
            ],
            [
                'uri' => '/documentation/',
                'controller' => 'documentation',
                'action' => null,
                'params' => []
            ],
            [
                'uri' => '/documentation',
                'controller' => 'documentation',
                'action' => null,
                'params' => []
            ],
            [
                'uri' => '/system/admin/a/edit/hellao/aaadp',
                'controller' => 'admin',
                'action' => 'edit',
                'params' => ['hellao', 'aaadp']
            ],
            [
                'uri' => '/es/news',
                'controller' => 'news',
                'action' => 'index',
                'params' => ['language' => 'es']
            ],
            [
                'uri' => '/admin/posts/edit/100',
                'controller' => 'posts',
                'action' => 'edit',
                'params' => ['id' => 100]
            ],
            [
                'uri' => '/posts/2010/02/10/title/content',
                'controller' => 'posts',
                'action' => 'show',
                'params' => ['year' => '2010', 'month' => '02', 'day' => '10', 0 => 'title', 1 => 'content']
            ],
            [
                'uri' => '/manual/en/translate.adapter.html',
                'controller' => 'manual',
                'action' => 'show',
                'params' => ['language' => 'en', 'file' => 'translate.adapter']
            ],
            [
                'uri' => '/named-manual/en/translate.adapter.html',
                'controller' => 'manual',
                'action' => 'show',
                'params' => ['language' => 'en', 'file' => 'translate.adapter']
            ],
            [
                'uri' => '/posts/1999/s/le-nice-title',
                'controller' => 'posts',
                'action' => 'show',
                'params' => ['year' => '1999', 'title' => 'le-nice-title']
            ],
            [
                'uri' => '/feed/fr/blog/diaporema.json',
                'controller' => 'feed',
                'action' => 'get',
                'params' => ['lang' => 'fr', 'blog' => 'diaporema', 'type' => 'json']
            ],
            [
                'uri' => '/posts/delete/150',
                'controller' => 'posts',
                'action' => 'delete',
                'params' => ['id' => '150']
            ],
            [
                'uri' => '/very/static/route',
                'controller' => 'static',
                'action' => 'route',
                'params' => []
            ],
        ];
    }

    protected function getRouter($defaultRoutes = true)
    {
        $router = new Router($defaultRoutes);

        $di = new Di;
        $di->set('request', function() {
            return new Request;
        });

        $router->setDI($di);

        return $router;
    }
}
