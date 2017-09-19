<?php

namespace Phalcon\Test\Unit\Cli;

use Phalcon\Cli\Router;
use Phalcon\Cli\Router\Route;
use Phalcon\Di\FactoryDefault\Cli as CliFactoryDefault;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Cli\RouterTest
 * Tests the \Phalcon\Cli\Router component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Cli
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class RouterTest extends UnitTest
{
    public function testRouters()
    {
        $this->specify(
            "CLI Router doesn't match the correct paths",
            function () {
                $di = new CliFactoryDefault();

                $di->set(
                    "data",
                    function () {
                        return "data";
                    }
                );

                $router = new Router();

                $router->handle([]);
                expect($router->getModuleName())->null();
                expect($router->getTaskName())->null();
                expect($router->getActionName())->null();
                expect($router->getParams())->equals([]);

                $router->handle(
                    [
                        "task" => "main",
                    ]
                );
                expect($router->getModuleName())->null();
                expect($router->getTaskName())->equals("main");
                expect($router->getActionName())->null();
                expect($router->getParams())->equals([]);

                $router->handle(
                    [
                        "task" => "echo",
                    ]
                );
                expect($router->getModuleName())->null();
                expect($router->getTaskName())->equals("echo");
                expect($router->getActionName())->null();
                expect($router->getParams())->equals([]);

                $router->handle(
                    [
                        "task"   => "main",
                        "action" => "hello",
                    ]
                );
                expect($router->getModuleName())->null();
                expect($router->getTaskName())->equals("main");
                expect($router->getActionName())->equals("hello");
                expect($router->getParams())->equals([]);

                $router->handle(
                    [
                        "task"   => "main",
                        "action" => "hello",
                        "arg1",
                        "arg2",
                    ]
                );
                expect($router->getModuleName())->null();
                expect($router->getTaskName())->equals("main");
                expect($router->getActionName())->equals("hello");
                expect($router->getParams())->equals(["arg1", "arg2"]);

                $router->handle(
                    [
                        "module" => "devtools",
                        "task"   => "main",
                        "action" => "hello",
                        "arg1",
                        "arg2",
                    ]
                );
                expect($router->getModuleName())->equals("devtools");
                expect($router->getTaskName())->equals("main");
                expect($router->getActionName())->equals("hello");
                expect($router->getParams())->equals(["arg1", "arg2"]);

                $router->handle(
                    [
                        "module" => "devtools",
                        "task"   => "echo",
                        "action" => "hello",
                        "arg1",
                        "arg2",
                    ]
                );
                expect($router->getModuleName())->equals("devtools");
                expect($router->getTaskName())->equals("echo");
                expect($router->getActionName())->equals("hello");
                expect($router->getParams())->equals(["arg1", "arg2"]);
            }
        );
    }

    private function _runTest($router, $test)
    {
        $router->handle($test['uri']);
        expect($router->getModuleName())->equals($test['module']);
        expect($router->getTaskName())->equals($test['task']);
        expect($router->getActionName())->equals($test['action']);
        expect($router->getParams())->equals($test['params']);
    }

    public function testRouter()
    {
        $this->specify(
            "CLI Router doesn't work match correct routes",
            function ($test) {
                Route::reset();

                $router = new Router();

                $router->add(' ', array(
                    'module' => 'devtools',
                    'task' => 'main',
                    'action' => 'hello',
                ));

                $router->add('system :task a :action :params', array(
                    'task' => 1,
                    'action' => 2,
                    'params' => 3,
                ));

                $router->add('([a-z]{2}) :task', array(
                    'task' => 2,
                    'action' => 'index',
                    'language' => 1
                ));

                $router->add('admin :task :action :int', array(
                    'module' => 'admin',
                    'task' => 1,
                    'action' => 2,
                    'id' => 3
                ));

                $router->add('posts ([0-9]{4}) ([0-9]{2}) ([0-9]{2}) :params', array(
                    'task' => 'posts',
                    'action' => 'show',
                    'year' => 1,
                    'month' => 2,
                    'day' => 3,
                    'params' => 4,
                ));

                $router->add('manual ([a-z]{2}) ([a-z\.]+)\.txt', array(
                    'task' => 'manual',
                    'action' => 'show',
                    'language' => 1,
                    'file' => 2
                ));

                $router->add('named-manual {language:([a-z]{2})} {file:[a-z\.]+}\.txt', array(
                    'task' => 'manual',
                    'action' => 'show',
                ));

                $router->add('very static route', array(
                    'task' => 'static',
                    'action' => 'route'
                ));

                $router->add("feed {lang:[a-z]+} blog {blog:[a-z\-]+}\.{type:[a-z\-]+}", "Feed::get");

                $router->add("posts {year:[0-9]+} s {title:[a-z\-]+}", "Posts::show");

                $router->add("posts delete {id}", "Posts::delete");

                $router->add("show {id:video([0-9]+)} {title:[a-z\-]+}", "Videos::show");

                $this->_runTest($router, $test);
            },
            [
                "examples" => array(
                    [
                        array(
                            'uri' => '',
                            'module' => null,
                            'task' => null,
                            'action' => null,
                            'params' => array()
                        )
                    ],
                    [
                        array(
                            'uri' => ' ',
                            'module' => 'devtools',
                            'task' => 'main',
                            'action' => 'hello',
                            'params' => array()
                        )
                    ],
                    [
                        array(
                            'uri' => 'documentation index hellao aaadpqñda bbbAdld cc-ccc',
                            'module' => null,
                            'task' => 'documentation',
                            'action' => 'index',
                            'params' => array('hellao', 'aaadpqñda', 'bbbAdld', 'cc-ccc')
                        )
                    ],
                    [
                        array(
                            'uri' => ' documentation index',
                            'module' => null,
                            'task' => 'documentation',
                            'action' => 'index',
                            'params' => array()
                        )
                    ],
                    [
                        array(
                            'uri' => 'documentation index ',
                            'module' => null,
                            'task' => 'documentation',
                            'action' => 'index',
                            'params' => array()
                        )
                    ],
                    [
                        array(
                            'uri' => 'documentation index',
                            'module' => null,
                            'task' => 'documentation',
                            'action' => 'index',
                            'params' => array()
                        )
                    ],
                    [
                        array(
                            'uri' => 'documentation ',
                            'module' => null,
                            'task' => 'documentation',
                            'action' => null,
                            'params' => array()
                        )
                    ],
                    [
                        array(
                            'uri' => 'system admin a edit hellao aaadp',
                            'module' => null,
                            'task' => 'admin',
                            'action' => 'edit',
                            'params' => array('hellao', 'aaadp')
                        )
                    ],
                    [
                        array(
                            'uri' => 'es news',
                            'module' => null,
                            'task' => 'news',
                            'action' => 'index',
                            'params' => array('language' => 'es')
                        )
                    ],
                    [
                        array(
                            'uri' => 'admin posts edit 100',
                            'module' => 'admin',
                            'task' => 'posts',
                            'action' => 'edit',
                            'params' => array('id' => 100)
                        )
                    ],
                    [
                        array(
                            'uri' => 'posts 2010 02 10 title content',
                            'module' => null,
                            'task' => 'posts',
                            'action' => 'show',
                            'params' => array(
                                'year' => '2010',
                                'month' => '02',
                                'day' => '10',
                                0 => 'title',
                                1 => 'content',
                            )
                        )
                    ],
                    [
                        array(
                            'uri' => 'manual en translate.adapter.txt',
                            'module' => null,
                            'task' => 'manual',
                            'action' => 'show',
                            'params' => array('language' => 'en', 'file' => 'translate.adapter')
                        )
                    ],
                    [
                        array(
                            'uri' => 'named-manual en translate.adapter.txt',
                            'module' => null,
                            'task' => 'manual',
                            'action' => 'show',
                            'params' => array('language' => 'en', 'file' => 'translate.adapter')
                        )
                    ],
                    [
                        array(
                            'uri' => 'posts 1999 s le-nice-title',
                            'module' => null,
                            'task' => 'posts',
                            'action' => 'show',
                            'params' => array('year' => '1999', 'title' => 'le-nice-title')
                        )
                    ],
                    [
                        array(
                            'uri' => 'feed fr blog diaporema.json',
                            'module' => null,
                            'task' => 'feed',
                            'action' => 'get',
                            'params' => array('lang' => 'fr', 'blog' => 'diaporema', 'type' => 'json')
                        )
                    ],
                    [
                        array(
                            'uri' => 'posts delete 150',
                            'module' => null,
                            'task' => 'posts',
                            'action' => 'delete',
                            'params' => array('id' => '150')
                        )
                    ],
                    [
                        array(
                            'uri' => 'very static route',
                            'module' => null,
                            'task' => 'static',
                            'action' => 'route',
                            'params' => array()
                        )
                    ],
                )
            ]
        );
    }

    public function testRouterParams()
    {
        $this->specify(
            "CLI Router doesn't work with custom parameters",
            function ($test) {
                $router = new Router();

                $router->add('some {name}');
                $router->add('some {name} {id:[0-9]+}');
                $router->add('some {name} {id:[0-9]+} {date}');

                $this->_runTest($router, $test);
            },
            [
                "examples" => array(
                    [
                        array(
                            'uri' => 'some hattie',
                            'module' => null,
                            'task' => '',
                            'action' => '',
                            'params' => array('name' => 'hattie')
                        )
                    ],
                    [
                        array(
                            'uri' => 'some hattie 100',
                            'module' => null,
                            'task' => '',
                            'action' => '',
                            'params' => array('name' => 'hattie', 'id' => 100)
                        )
                    ],
                    [
                        array(
                            'uri' => 'some hattie 100 2011-01-02',
                            'module' => null,
                            'task' => '',
                            'action' => '',
                            'params' => array('name' => 'hattie', 'id' => 100, 'date' => '2011-01-02')
                        )
                    ],
                )
            ]
        );
    }

    public function testNamedRoutes()
    {
        $this->specify(
            "CLI Router doesn't work with named routes",
            function () {
                Route::reset();

                $router = new Router(false);

                $usersFind = $router->add('api users find')->setName('usersFind');
                $usersAdd = $router->add('api users add')->setName('usersAdd');

                expect($usersAdd)->equals($router->getRouteByName('usersAdd'));
                expect($usersAdd)->equals($router->getRouteByName('usersAdd'));
                expect($usersFind)->equals($router->getRouteById(0));
            }
        );
    }

    public function testConverters()
    {
        $this->specify(
            "CLI Router doesn't work with converters",
            function ($route, $paths) {
                Route::reset();

                $router = new Router();

                $router->add('{task:[a-z\-]+} {action:[a-z\-]+} this-is-a-country')
                ->convert('task', function ($task) {
                    return str_replace('-', '', $task);
                })
                ->convert('action', function ($action) {
                    return str_replace('-', '', $action);
                });

                $router->add('([A-Z]+) ([0-9]+)', array(
                    'task' => 1,
                    'action' => 'default',
                    'id' => 2,
                ))
                ->convert('task', function ($task) {
                    return strtolower($task);
                })
                ->convert('action', function ($action) {
                    if ($action == 'default') {
                        return 'index';
                    }
                    return $action;
                })
                ->convert('id', function ($id) {
                    return strrev($id);
                });

                $router->handle($route);
                expect($router->wasMatched())->true();
                expect($paths['task'])->equals($router->getTaskName());
                expect($paths['action'])->equals($router->getActionName());
            },
            [
                "examples" => array(
                    [
                        "route" => 'some-controller my-action-name this-is-a-country',
                        "paths" => array(
                            'task' => 'somecontroller',
                            'action' => 'myactionname',
                            'params' => array('this-is-a-country')
                        )
                    ],
                    [
                        "route" => 'BINARY 1101',
                        "paths" => array(
                            'task' => 'binary',
                            'action' => 'index',
                            'params' => array(1011)
                        )
                    ],
                )
            ]
        );
    }

    public function testShortPaths()
    {
        $this->specify(
            "CLI Router doesn't work with short paths",
            function () {
                Route::reset();

                $router = new Router(false);

                $route = $router->add("route0", "Feed");
                expect($route->getPaths())->equals(array(
                    'task' => 'feed'
                ));

                $route = $router->add("route1", "Feed::get");
                expect($route->getPaths())->equals(array(
                    'task' => 'feed',
                    'action' => 'get',
                ));

                $route = $router->add("route2", "News::Posts::show");
                expect($route->getPaths())->equals(array(
                    'module' => 'News',
                    'task' => 'posts',
                    'action' => 'show',
                ));

                $route = $router->add("route3", "MyApp\\Tasks\\Posts::show");
                expect($route->getPaths())->equals(array(
                    'namespace' => 'MyApp\\Tasks',
                    'task' => 'posts',
                    'action' => 'show',
                ));

                $route = $router->add("route3", "MyApp\\Tasks\\::show");
                expect($route->getPaths())->equals(array(
                    'task' => '',
                    'action' => 'show',
                ));

                $route = $router->add("route3", "News::MyApp\\Tasks\\Posts::show");
                expect($route->getPaths())->equals(array(
                    'module' => 'News',
                    'namespace' => 'MyApp\\Tasks',
                    'task' => 'posts',
                    'action' => 'show',
                ));

                $route = $router->add("route3", "\\Posts::show");
                expect($route->getPaths())->equals(array(
                    'task' => 'posts',
                    'action' => 'show',
                ));
            }
        );
    }

    public function testBeforeMatch()
    {
        $this->specify(
            "CLI Router doesn't work with custom before match",
            function () {
                Route::reset();

                $trace = 0;

                $router = new Router(false);

                $router
                    ->add('static route')
                    ->beforeMatch(function () use (&$trace) {
                        $trace++;
                        return false;
                    });

                $router
                    ->add('static route2')
                    ->beforeMatch(function () use (&$trace) {
                        $trace++;
                        return true;
                    });

                $router->handle();
                expect($router->wasMatched())->false();

                $router->handle('static route');
                expect($router->wasMatched())->false();

                $router->handle('static route2');
                expect($router->wasMatched())->true();

                expect($trace)->equals(2);
            }
        );
    }

    public function testDelimiter()
    {
        $this->specify(
            "CLI Router doesn't work with custom delimiters",
            function ($test) {
                Route::reset();
                Route::delimiter('/');

                $router = new Router();

                $router->add('/', array(
                    'module' => 'devtools',
                    'task' => 'main',
                    'action' => 'hello',
                ));

                $router->add('/system/:task/a/:action/:params', array(
                    'task' => 1,
                    'action' => 2,
                    'params' => 3,
                ));

                $router->add('/([a-z]{2})/:task', array(
                    'task' => 2,
                    'action' => 'index',
                    'language' => 1
                ));

                $router->add('/admin/:task/:action/:int', array(
                    'module' => 'admin',
                    'task' => 1,
                    'action' => 2,
                    'id' => 3
                ));

                $router->add('/posts/([0-9]{4})/([0-9]{2})/([0-9]{2})/:params', array(
                    'task' => 'posts',
                    'action' => 'show',
                    'year' => 1,
                    'month' => 2,
                    'day' => 3,
                    'params' => 4,
                ));

                $router->add('/manual/([a-z]{2})/([a-z\.]+)\.txt', array(
                    'task' => 'manual',
                    'action' => 'show',
                    'language' => 1,
                    'file' => 2
                ));

                $router->add('/named-manual/{language:([a-z]{2})}/{file:[a-z\.]+}\.txt', array(
                    'task' => 'manual',
                    'action' => 'show',
                ));

                $router->add('/very/static/route', array(
                    'task' => 'static',
                    'action' => 'route'
                ));

                $router->add("/feed/{lang:[a-z]+}/blog/{blog:[a-z\-]+}\.{type:[a-z\-]+}", "Feed::get");

                $router->add("/posts/{year:[0-9]+}/s/{title:[a-z\-]+}", "Posts::show");

                $router->add("/posts/delete/{id}", "Posts::delete");

                $router->add("/show/{id:video([0-9]+)}/{title:[a-z\-]+}", "Videos::show");

                $this->_runTest($router, $test);
            },
            [
                "examples" => array(
                    [
                        array(
                            'uri' => '/',
                            'module' => 'devtools',
                            'task' => 'main',
                            'action' => 'hello',
                            'params' => array()
                        )
                    ],
                    [
                        array(
                            'uri' => '/documentation/index/hellao/aaadpqñda/bbbAdld/cc-ccc',
                            'module' => null,
                            'task' => 'documentation',
                            'action' => 'index',
                            'params' => array('hellao', 'aaadpqñda', 'bbbAdld', 'cc-ccc')
                        )
                    ],
                    [
                        array(
                            'uri' => '/documentation/index/',
                            'module' => null,
                            'task' => 'documentation',
                            'action' => 'index',
                            'params' => array()
                        )
                    ],
                    [
                        array(
                            'uri' => '/documentation/index',
                            'module' => null,
                            'task' => 'documentation',
                            'action' => 'index',
                            'params' => array()
                        )
                    ],
                    [
                        array(
                            'uri' => '/documentation/',
                            'module' => null,
                            'task' => 'documentation',
                            'action' => null,
                            'params' => array()
                        )
                    ],
                    [
                        array(
                            'uri' => '/system/admin/a/edit/hellao/aaadp',
                            'module' => null,
                            'task' => 'admin',
                            'action' => 'edit',
                            'params' => array('hellao', 'aaadp')
                        )
                    ],
                    [
                        array(
                            'uri' => '/es/news',
                            'module' => null,
                            'task' => 'news',
                            'action' => 'index',
                            'params' => array('language' => 'es')
                        )
                    ],
                    [
                        array(
                            'uri' => '/admin/posts/edit/100',
                            'module' => 'admin',
                            'task' => 'posts',
                            'action' => 'edit',
                            'params' => array('id' => 100)
                        )
                    ],
                    [
                        array(
                            'uri' => '/posts/2010/02/10/title/content',
                            'module' => null,
                            'task' => 'posts',
                            'action' => 'show',
                            'params' => array(
                                'year' => '2010',
                                'month' => '02',
                                'day' => '10',
                                0 => 'title',
                                1 => 'content',
                            )
                        )
                    ],
                    [
                        array(
                            'uri' => '/manual/en/translate.adapter.txt',
                            'module' => null,
                            'task' => 'manual',
                            'action' => 'show',
                            'params' => array('language' => 'en', 'file' => 'translate.adapter')
                        )
                    ],
                    [
                        array(
                            'uri' => '/named-manual/en/translate.adapter.txt',
                            'module' => null,
                            'task' => 'manual',
                            'action' => 'show',
                            'params' => array('language' => 'en', 'file' => 'translate.adapter')
                        )
                    ],
                    [
                        array(
                            'uri' => '/posts/1999/s/le-nice-title',
                            'module' => null,
                            'task' => 'posts',
                            'action' => 'show',
                            'params' => array('year' => '1999', 'title' => 'le-nice-title')
                        )
                    ],
                    [
                        array(
                            'uri' => '/feed/fr/blog/diaporema.json',
                            'module' => null,
                            'task' => 'feed',
                            'action' => 'get',
                            'params' => array('lang' => 'fr', 'blog' => 'diaporema', 'type' => 'json')
                        )
                    ],
                    [
                        array(
                            'uri' => '/posts/delete/150',
                            'module' => null,
                            'task' => 'posts',
                            'action' => 'delete',
                            'params' => array('id' => '150')
                        )
                    ],
                    [
                        array(
                            'uri' => '/very/static/route',
                            'module' => null,
                            'task' => 'static',
                            'action' => 'route',
                            'params' => array()
                        )
                    ],
                )
            ]
        );
    }
}
