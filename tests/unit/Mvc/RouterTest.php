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
 * @copyright (c) 2011-2017 Phalcon Team
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
     * Tests routing by use Route::convert
     *
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2012-12-25
     */
    public function testUsingRouteConverters()
    {
        $this->specify(
            'The Route::convert doest not work as expected',
            function ($route, $paths) {
                $router= $this->getRouter();

                $router->add('/{controller:[a-z\-]+}/{action:[a-z\-]+}/this-is-a-country')
                    ->convert('controller', function ($controller) {
                        return str_replace('-', '', $controller);
                    })
                    ->convert('action', function ($action) {
                        return str_replace('-', '', $action);
                    });

                $router->add('/([A-Z]+)/([0-9]+)', [
                    'controller' => 1,
                    'action' => 'default',
                    'id' => 2,
                ])->convert('controller', function ($controller) {
                    return strtolower($controller);
                })->convert('action', function ($action) {
                    return $action == 'default' ? 'index' : $action;
                })->convert('id', function ($id) {
                    return strrev($id);
                });

                $router->handle($route);

                expect($router->wasMatched())->true();
                expect($router->getControllerName())->equals($paths['controller']);
                expect($router->getActionName())->equals($paths['action']);
            },
            [
                'examples' => $this->convertersProvider()
            ]
        );
    }

    /**
     * Tests using callbacks before match route
     *
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2013-01-08
     */
    public function testUsingCallbacksBeforeMatchRoute()
    {
        $this->specify(
            'The Route::beforeMatch does not use callback as expected',
            function () {
                $router= $this->getRouter(false);
                $trace = 0;

                $router
                    ->add('/static/route')
                    ->beforeMatch(function () use (&$trace) {
                        $trace++;
                        return false;
                    });

                $router
                    ->add('/static/route2')
                    ->beforeMatch(function () use (&$trace) {
                        $trace++;
                        return true;
                    });

                $router->handle();
                expect($router->wasMatched())->false();

                $router->handle('/static/route');
                expect($router->wasMatched())->false();

                $router->handle('/static/route2');
                expect($router->wasMatched())->true();

                expect($trace)->equals(2);
            }
        );
    }

    /**
     * Tests getting named route
     *
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2012-08-27
     */
    public function testGettingNamedRoutes()
    {
        $this->specify(
            'Getting named route does not return expect result',
            function () {
                $router= $this->getRouter(false);

                $usersFind = $router->add('/api/users/find')->setHttpMethods('GET')->setName('usersFind');
                $usersAdd = $router->add('/api/users/add')->setHttpMethods('POST')->setName('usersAdd');

                expect($router->getRouteByName('usersAdd'), $usersAdd);
                // second check when the same route goes from name lookup
                expect($router->getRouteByName('usersAdd'), $usersAdd);
                expect($router->getRouteById(0), $usersFind);
            }
        );
    }

    /**
     * Tests removing extra slashes
     *
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2012-12-16
     */
    public function testRemovingExtraSlashes()
    {
        $this->specify(
            'Removing extra slashes does not work as expected',
            function ($route, $paths) {
                $router= $this->getRouter();
                $router->removeExtraSlashes(true);

                $router->handle($route);

                expect($router->wasMatched())->true();
                expect($router->getControllerName())->equals($paths['controller']);
                expect($router->getActionName())->equals($paths['action']);
            },
            [
                'examples' => $this->extraSlashesProvider()
            ]
        );
    }

    /**
     * Tests router
     *
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2013-01-17
     */
    public function testMatchingWithTheRouter()
    {
        $this->specify(
            'Router does not matched correctly',
            function ($uri, $controller, $action, $params) {
                $router = $this->getRouter();

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
            },
            [
                'examples' => $this->routerProvider()
            ]
        );
    }

    /**
     * Tests router by using http method
     *
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2012-08-22
     */
    public function testMatchingWithTheRouterByUsingHttpMethods()
    {
        $this->specify(
            'Router does not matched correctly by using http method',
            function ($method, $uri, $controller, $action, $params) {
                $router = $this->getRouter();

                $router->add('/docs/index', [
                    'controller' => 'documentation2222',
                    'action' => 'index'
                ]);

                $router->addPost('/docs/index', [
                    'controller' => 'documentation3',
                    'action' => 'index'
                ]);

                $router->addGet('/docs/index', [
                    'controller' => 'documentation4',
                    'action' => 'index'
                ]);

                $router->addPut('/docs/index', [
                    'controller' => 'documentation5',
                    'action' => 'index'
                ]);

                $router->addDelete('/docs/index', [
                    'controller' => 'documentation6',
                    'action' => 'index'
                ]);

                $router->addOptions('/docs/index', [
                    'controller' => 'documentation7',
                    'action' => 'index'
                ]);

                $router->addHead('/docs/index', [
                    'controller' => 'documentation8',
                    'action' => 'index'
                ]);

                $router->addPurge('/docs/index', [
                    'controller' => 'documentation9',
                    'action' => 'index'
                ]);

                $router->addTrace('/docs/index', [
                    'controller' => 'documentation10',
                    'action' => 'index'
                ]);

                $router->addConnect('/docs/index', [
                    'controller' => 'documentation11',
                    'action' => 'index'
                ]);

                $_SERVER['REQUEST_METHOD'] = $method;
                $router->handle($uri);

                expect($router->getControllerName())->equals($controller);
                expect($router->getActionName())->equals($action);
                expect($router->getParams())->equals($params);
            },
            [
                'examples' => $this->methodProvider()
            ]
        );
    }

    /**
     * Tests router by using rote params
     *
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2012-08-22
     */
    public function testGettingRouterParams()
    {
        $this->specify(
            'Router does not matched correctly by using rote params',
            function ($uri, $controller, $action, $params) {
                $router = $this->getRouter();

                $router->add('/some/{name}');
                $router->add('/some/{name}/{id:[0-9]+}');
                $router->add('/some/{name}/{id:[0-9]+}/{date}');

                $router->handle($uri);

                expect($router->getControllerName())->equals($controller);
                expect($router->getActionName())->equals($action);
                expect($router->getParams())->equals($params);
            },
            [
                'examples' => $this->paramsProvider()
            ]
        );
    }

    /**
     * Tests adding a route to the router by using short path
     *
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2012-01-16
     */
    public function testAddingRouteByUsingShortPaths()
    {
        $this->specify(
            'Adding a route to the router by using short path does not produce expected paths',
            function ($route, $path, $expected) {
                $router = $this->getRouter(false);
                $route = $router->add($route, $path);
                expect($route->getPaths())->equals($expected);
            },
            [
                'examples' => $this->pathsProvider()
            ]
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
            },
            [
                'examples' => $this->hostnameRegexProvider()
            ]
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
            },
            [
                'examples' => $this->hostnameRegexRouterWithHostPortProvider()
            ]
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
            },
            [
                'examples' => $this->hostnameProvider()
            ]
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

    protected function convertersProvider()
    {
        return [
            [
                '/some-controller/my-action-name/this-is-a-country',
                [
                    'controller' => 'somecontroller',
                    'action' => 'myactionname',
                    'params' => ['this-is-a-country']
                ]
            ],
            [
                '/BINARY/1101',
                [
                    'controller' => 'binary',
                    'action' => 'index',
                    'params' => [1011]
                ]
            ]
        ];
    }

    protected function extraSlashesProvider()
    {
        return [
            [
                '/index/',
                [
                    'controller' => 'index',
                    'action' => '',
                ]
            ],
            [
                '/session/start/',
                [
                    'controller' => 'session',
                    'action' => 'start'
                ]
            ],
            [
                '/users/edit/100/',
                [
                    'controller' => 'users',
                    'action' => 'edit'
                ]
            ]
        ];
    }

    protected function pathsProvider()
    {
        return [
            [
                '/route0',
                'Feed',
                [
                    'controller' => 'feed'
                ]
            ],
            [
                '/route1',
                'Feed::get',
                [
                    'controller' => 'feed',
                    'action' => 'get',
                ]
            ],
            [
                '/route2',
                'News::Posts::show',
                [
                    'module' => 'News',
                    'controller' => 'posts',
                    'action' => 'show',
                ]
            ],
            [
                '/route3',
                'MyApp\Controllers\Posts::show',
                [
                    'namespace' => 'MyApp\Controllers',
                    'controller' => 'posts',
                    'action' => 'show',
                ]
            ],
            [
                '/route3',
                'MyApp\Controllers\::show',
                [
                    'controller' => '',
                    'action' => 'show',
                ]
            ],
            [
                '/route3',
                'News::MyApp\Controllers\Posts::show',
                [
                    'module' => 'News',
                    'namespace' => 'MyApp\\Controllers',
                    'controller' => 'posts',
                    'action' => 'show',
                ]
            ],
            [
                '/route3',
                '\Posts::show',
                [
                    'controller' => 'posts',
                    'action' => 'show',
                ]
            ],
        ];
    }

    protected function hostnameProvider()
    {
        return [
            ['localhost',          'posts3'],
            [null,                 'posts3'],
            ['my.phalconphp.com',  'posts'],
            ['my2.phalconphp.com', 'posts2'],
        ];
    }

    protected function hostnameRegexRouterWithHostPortProvider()
    {
        return [
            ['localhost',         'posts3', null],
            ['my.phalconphp.com', 'posts',  80 ],
            ['my.phalconphp.com', 'posts',  8080],
            [null,                'posts3', 8080],
            ['mail.example.com',  'posts2', 9090],
            ['some-domain.com',   'posts3', 9000],
            ['some.domain.net',   'posts4', 0],
        ];
    }

    protected function hostnameRegexProvider()
    {
        return [
            ['localhost',         'posts3'],
            ['my.phalconphp.com', 'posts' ],
            [null,                'posts3'],
            ['mail.example.com',  'posts2'],
            ['some-domain.com',   'posts3'],
            ['some.domain.net',   'posts4'],
        ];
    }

    protected function paramsProvider()
    {
        return [
            [
                'uri' => '/some/hattie',
                'controller' => '',
                'action' => '',
                'params' => ['name' => 'hattie']
            ],
            [
                'uri' => '/some/hattie/100',
                'controller' => '',
                'action' => '',
                'params' => ['name' => 'hattie', 'id' => 100]
            ],
            [
                'uri' => '/some/hattie/100/2011-01-02',
                'controller' => '',
                'action' => '',
                'params' => ['name' => 'hattie', 'id' => 100, 'date' => '2011-01-02']
            ],
        ];
    }

    protected function methodProvider()
    {
        return [
            'NULL' => [
                'method' => null,
                'uri' => '/documentation/index/hello',
                'controller' => 'documentation',
                'action' => 'index',
                'params' => ['hello']
            ],
            'POST' => [
                'method' => 'POST',
                'uri' => '/docs/index',
                'controller' => 'documentation3',
                'action' => 'index',
                'params' => []
            ],
            'GET' => [
                'method' => 'GET',
                'uri' => '/docs/index',
                'controller' => 'documentation4',
                'action' => 'index',
                'params' => []
            ],
            'PUT' => [
                'method' => 'PUT',
                'uri' => '/docs/index',
                'controller' => 'documentation5',
                'action' => 'index',
                'params' => []
            ],
            'DELETE' => [
                'method' => 'DELETE',
                'uri' => '/docs/index',
                'controller' => 'documentation6',
                'action' => 'index',
                'params' => []
            ],
            'OPTIONS' => [
                'method' => 'OPTIONS',
                'uri' => '/docs/index',
                'controller' => 'documentation7',
                'action' => 'index',
                'params' => []
            ],
            'HEAD' => [
                'method' => 'HEAD',
                'uri' => '/docs/index',
                'controller' => 'documentation8',
                'action' => 'index',
                'params' => []
            ],
            'PURGE' => [
                'method' => 'PURGE',
                'uri' => '/docs/index',
                'controller' => 'documentation9',
                'action' => 'index',
                'params' => []
            ],
            'TRACE' => [
                'method' => 'TRACE',
                'uri' => '/docs/index',
                'controller' => 'documentation10',
                'action' => 'index',
                'params' => []
            ],
            'CONNECT' => [
                'method' => 'CONNECT',
                'uri' => '/docs/index',
                'controller' => 'documentation11',
                'action' => 'index',
                'params' => []
            ],
        ];
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
        $di->setShared('request', function () {
            return new Request;
        });

        $router->setDI($di);

        return $router;
    }
}
