<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Cli\Cli;

use CliTester;
use Phalcon\Cli\Router;
use Phalcon\Cli\Router\Route;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class RouterCest
{
    use DiTrait;

    public function _before(CliTester $I)
    {
        $this->setNewCliFactoryDefault();
    }

    public function testRouters(CliTester $I)
    {
        $this->container->set(
            "data",
            function () {
                return "data";
            }
        );
        $router = new Router();
        $router->handle([]);
        $I->assertNull($router->getModuleName());
        $I->assertNull($router->getTaskName());
        $I->assertNull($router->getActionName());
        $I->assertEquals($router->getParams(), []);
        $router->handle(
            [
                "task" => "main",
            ]
        );
        $I->assertNull($router->getModuleName());
        $I->assertEquals($router->getTaskName(), "main");
        $I->assertNull($router->getActionName());
        $I->assertEquals($router->getParams(), []);
        $router->handle(
            [
                "task" => "echo",
            ]
        );
        $I->assertNull($router->getModuleName());
        $I->assertEquals($router->getTaskName(), "echo");
        $I->assertNull($router->getActionName());
        $I->assertEquals($router->getParams(), []);
        $router->handle(
            [
                "task"   => "main",
                "action" => "hello",
            ]
        );
        $I->assertNull($router->getModuleName());
        $I->assertEquals($router->getTaskName(), "main");
        $I->assertEquals($router->getActionName(), "hello");
        $I->assertEquals($router->getParams(), []);
        $router->handle(
            [
                "task"   => "main",
                "action" => "hello",
                "arg1",
                "arg2",
            ]
        );
        $I->assertNull($router->getModuleName());
        $I->assertEquals($router->getTaskName(), "main");
        $I->assertEquals($router->getActionName(), "hello");
        $I->assertEquals($router->getParams(), ["arg1", "arg2"]);
        $router->handle(
            [
                "module" => "devtools",
                "task"   => "main",
                "action" => "hello",
                "arg1",
                "arg2",
            ]
        );
        $I->assertEquals($router->getModuleName(), "devtools");
        $I->assertEquals($router->getTaskName(), "main");
        $I->assertEquals($router->getActionName(), "hello");
        $I->assertEquals($router->getParams(), ["arg1", "arg2"]);
        $router->handle(
            [
                "module" => "devtools",
                "task"   => "echo",
                "action" => "hello",
                "arg1",
                "arg2",
            ]
        );
        $I->assertEquals($router->getModuleName(), "devtools");
        $I->assertEquals($router->getTaskName(), "echo");
        $I->assertEquals($router->getActionName(), "hello");
        $I->assertEquals($router->getParams(), ["arg1", "arg2"]);
    }

    public function testRouter(CliTester $I)
    {
        $examples = $this->getExamplesRouter();
        foreach ($examples as $example) {
            $test = $example[0];
            Route::reset();
            $router = new Router();
            $router->add(' ', [
                'module' => 'devtools',
                'task' => 'main',
                'action' => 'hello',
            ]);
            $router->add('system :task a :action :params', [
                'task' => 1,
                'action' => 2,
                'params' => 3,
            ]);
            $router->add('([a-z]{2}) :task', [
                'task' => 2,
                'action' => 'index',
                'language' => 1
            ]);
            $router->add('admin :task :action :int', [
                'module' => 'admin',
                'task' => 1,
                'action' => 2,
                'id' => 3
            ]);
            $router->add('posts ([0-9]{4}) ([0-9]{2}) ([0-9]{2}) :params', [
                'task' => 'posts',
                'action' => 'show',
                'year' => 1,
                'month' => 2,
                'day' => 3,
                'params' => 4,
            ]);
            $router->add('manual ([a-z]{2}) ([a-z\.]+)\.txt', [
                'task' => 'manual',
                'action' => 'show',
                'language' => 1,
                'file' => 2
            ]);
            $router->add('named-manual {language:([a-z]{2})} {file:[a-z\.]+}\.txt', [
                'task' => 'manual',
                'action' => 'show',
            ]);
            $router->add('very static route', [
                'task' => 'static',
                'action' => 'route'
            ]);
            $router->add("feed {lang:[a-z]+} blog {blog:[a-z\-]+}\.{type:[a-z\-]+}", "Feed::get");
            $router->add("posts {year:[0-9]+} s {title:[a-z\-]+}", "Posts::show");
            $router->add("posts delete {id}", "Posts::delete");
            $router->add("show {id:video([0-9]+)} {title:[a-z\-]+}", "Videos::show");
            $this->runTests($I, $router, $test);
        }
    }

    public function testRouterParams(CliTester $I)
    {
        $examples = $this->getExamplesRouterParams();
        foreach ($examples as $example) {
            $test   = $example[0];
            $router = new Router();
            $router->add('some {name}');
            $router->add('some {name} {id:[0-9]+}');
            $router->add('some {name} {id:[0-9]+} {date}');
            $this->runTests($I, $router, $test);
        }
    }

    public function testNamedRoutes(CliTester $I)
    {
        Route::reset();
        $router = new Router(false);
        $usersFind = $router->add('api users find')->setName('usersFind');
        $usersAdd = $router->add('api users add')->setName('usersAdd');
        $I->assertEquals($usersAdd, $router->getRouteByName('usersAdd'));
        $I->assertEquals($usersAdd, $router->getRouteByName('usersAdd'));
        $I->assertEquals($usersFind, $router->getRouteById(0));
    }

    public function testConverters(CliTester $I)
    {
        $examples = $this->getExamplesConverters();
        foreach ($examples as $example) {
            $route = $example['route'];
            $paths = $example['paths'];
            Route::reset();
            $router = new Router();
            $router
                ->add('{task:[a-z\-]+} {action:[a-z\-]+} this-is-a-country')
                ->convert(
                    'task',
                    function ($task) {
                        return str_replace('-', '', $task);
                    }
                )
                ->convert(
                    'action',
                    function ($action) {
                        return str_replace('-', '', $action);
                    }
                );

            $router
                ->add(
                    '([A-Z]+) ([0-9]+)',
                    [
                        'task' => 1,
                        'action' => 'default',
                        'id' => 2,
                    ]
                )
                ->convert(
                    'task',
                    function ($task) {
                        return strtolower($task);
                    }
                )
                ->convert(
                    'action',
                    function ($action) {
                        if ($action == 'default') {
                            return 'index';
                        }

                        return $action;
                    }
                )
                ->convert(
                    'id',
                    function ($id) {
                        return strrev($id);
                    }
                );
            $router->handle($route);
            $I->assertTrue($router->wasMatched());
            $I->assertEquals($paths['task'], $router->getTaskName());
            $I->assertEquals($paths['action'], $router->getActionName());
        }
    }

    public function testShortPaths(CliTester $I)
    {
        Route::reset();
        $router = new Router(false);
        $route = $router->add("route0", "Feed");
        $I->assertEquals($route->getPaths(), [
            'task' => 'feed'
        ]);
        $route = $router->add("route1", "Feed::get");
        $I->assertEquals($route->getPaths(), [
            'task' => 'feed',
            'action' => 'get',
        ]);
        $route = $router->add("route2", "News::Posts::show");
        $I->assertEquals($route->getPaths(), [
            'module' => 'News',
            'task' => 'posts',
            'action' => 'show',
        ]);
        $route = $router->add("route3", "MyApp\\Tasks\\Posts::show");
        $I->assertEquals($route->getPaths(), [
            'namespace' => 'MyApp\\Tasks',
            'task' => 'posts',
            'action' => 'show',
        ]);
        $route = $router->add("route3", "MyApp\\Tasks\\::show");
        $I->assertEquals($route->getPaths(), [
            'task' => '',
            'action' => 'show',
        ]);
        $route = $router->add("route3", "News::MyApp\\Tasks\\Posts::show");
        $I->assertEquals($route->getPaths(), [
            'module' => 'News',
            'namespace' => 'MyApp\\Tasks',
            'task' => 'posts',
            'action' => 'show',
        ]);
        $route = $router->add("route3", "\\Posts::show");
        $I->assertEquals($route->getPaths(), [
            'task' => 'posts',
            'action' => 'show',
        ]);
    }

    public function testBeforeMatch(CliTester $I)
    {
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
        $I->assertFalse($router->wasMatched());
        $router->handle('static route');
        $I->assertFalse($router->wasMatched());
        $router->handle('static route2');
        $I->assertTrue($router->wasMatched());
        $I->assertEquals($trace, 2);
    }

    public function testDelimiter(CliTester $I)
    {
        $examples = $this->getExamplesDelimiter();
        foreach ($examples as $example) {
            $test = $example[0];
            Route::reset();
            Route::delimiter('/');
            $router = new Router();
            $router->add('/', [
                'module' => 'devtools',
                'task' => 'main',
                'action' => 'hello',
            ]);
            $router->add('/system/:task/a/:action/:params', [
                'task' => 1,
                'action' => 2,
                'params' => 3,
            ]);
            $router->add('/([a-z]{2})/:task', [
                'task' => 2,
                'action' => 'index',
                'language' => 1
            ]);
            $router->add('/admin/:task/:action/:int', [
                'module' => 'admin',
                'task' => 1,
                'action' => 2,
                'id' => 3
            ]);
            $router->add('/posts/([0-9]{4})/([0-9]{2})/([0-9]{2})/:params', [
                'task' => 'posts',
                'action' => 'show',
                'year' => 1,
                'month' => 2,
                'day' => 3,
                'params' => 4,
            ]);
            $router->add('/manual/([a-z]{2})/([a-z\.]+)\.txt', [
                'task' => 'manual',
                'action' => 'show',
                'language' => 1,
                'file' => 2
            ]);
            $router->add('/named-manual/{language:([a-z]{2})}/{file:[a-z\.]+}\.txt', [
                'task' => 'manual',
                'action' => 'show',
            ]);
            $router->add('/very/static/route', [
                'task' => 'static',
                'action' => 'route'
            ]);
            $router->add("/feed/{lang:[a-z]+}/blog/{blog:[a-z\-]+}\.{type:[a-z\-]+}", "Feed::get");
            $router->add("/posts/{year:[0-9]+}/s/{title:[a-z\-]+}", "Posts::show");
            $router->add("/posts/delete/{id}", "Posts::delete");
            $router->add("/show/{id:video([0-9]+)}/{title:[a-z\-]+}", "Videos::show");

            $this->runTests($I, $router, $test);
        }
    }

    private function getExamplesRouter(): array
    {
        return [
            [
                [
                    'uri' => '',
                    'module' => null,
                    'task' => null,
                    'action' => null,
                    'params' => []
                ]
            ],
            [
                [
                    'uri' => ' ',
                    'module' => 'devtools',
                    'task' => 'main',
                    'action' => 'hello',
                    'params' => []
                ]
            ],
            [
                [
                    'uri' => 'documentation index hellao aaadpqñda bbbAdld cc-ccc',
                    'module' => null,
                    'task' => 'documentation',
                    'action' => 'index',
                    'params' => ['hellao', 'aaadpqñda', 'bbbAdld', 'cc-ccc']
                ]
            ],
            [
                [
                    'uri' => ' documentation index',
                    'module' => null,
                    'task' => 'documentation',
                    'action' => 'index',
                    'params' => []
                ]
            ],
            [
                [
                    'uri' => 'documentation index ',
                    'module' => null,
                    'task' => 'documentation',
                    'action' => 'index',
                    'params' => []
                ]
            ],
            [
                [
                    'uri' => 'documentation index',
                    'module' => null,
                    'task' => 'documentation',
                    'action' => 'index',
                    'params' => []
                ]
            ],
            [
                [
                    'uri' => 'documentation ',
                    'module' => null,
                    'task' => 'documentation',
                    'action' => null,
                    'params' => []
                ]
            ],
            [
                [
                    'uri' => 'system admin a edit hellao aaadp',
                    'module' => null,
                    'task' => 'admin',
                    'action' => 'edit',
                    'params' => ['hellao', 'aaadp']
                ]
            ],
            [
                [
                    'uri' => 'es news',
                    'module' => null,
                    'task' => 'news',
                    'action' => 'index',
                    'params' => ['language' => 'es']
                ]
            ],
            [
                [
                    'uri' => 'admin posts edit 100',
                    'module' => 'admin',
                    'task' => 'posts',
                    'action' => 'edit',
                    'params' => ['id' => 100]
                ]
            ],
            [
                [
                    'uri' => 'posts 2010 02 10 title content',
                    'module' => null,
                    'task' => 'posts',
                    'action' => 'show',
                    'params' => [
                        'year' => '2010',
                        'month' => '02',
                        'day' => '10',
                        0 => 'title',
                        1 => 'content',
                    ]
                ]
            ],
            [
                [
                    'uri' => 'manual en translate.adapter.txt',
                    'module' => null,
                    'task' => 'manual',
                    'action' => 'show',
                    'params' => ['language' => 'en', 'file' => 'translate.adapter']
                ]
            ],
            [
                [
                    'uri' => 'named-manual en translate.adapter.txt',
                    'module' => null,
                    'task' => 'manual',
                    'action' => 'show',
                    'params' => ['language' => 'en', 'file' => 'translate.adapter']
                ]
            ],
            [
                [
                    'uri' => 'posts 1999 s le-nice-title',
                    'module' => null,
                    'task' => 'posts',
                    'action' => 'show',
                    'params' => ['year' => '1999', 'title' => 'le-nice-title']
                ]
            ],
            [
                [
                    'uri' => 'feed fr blog diaporema.json',
                    'module' => null,
                    'task' => 'feed',
                    'action' => 'get',
                    'params' => ['lang' => 'fr', 'blog' => 'diaporema', 'type' => 'json']
                ]
            ],
            [
                [
                    'uri' => 'posts delete 150',
                    'module' => null,
                    'task' => 'posts',
                    'action' => 'delete',
                    'params' => ['id' => '150']
                ]
            ],
            [
                [
                    'uri' => 'very static route',
                    'module' => null,
                    'task' => 'static',
                    'action' => 'route',
                    'params' => []
                ]
            ],
        ];
    }

    private function getExamplesRouterParams(): array
    {
        return [
            [
                [
                    'uri' => 'some hattie',
                    'module' => null,
                    'task' => '',
                    'action' => '',
                    'params' => ['name' => 'hattie']
                ]
            ],
            [
                [
                    'uri' => 'some hattie 100',
                    'module' => null,
                    'task' => '',
                    'action' => '',
                    'params' => ['name' => 'hattie', 'id' => 100]
                ]
            ],
            [
                [
                    'uri' => 'some hattie 100 2011-01-02',
                    'module' => null,
                    'task' => '',
                    'action' => '',
                    'params' => ['name' => 'hattie', 'id' => 100, 'date' => '2011-01-02']
                ]
            ],
        ];
    }

    private function getExamplesConverters(): array
    {
        return [
            [
                "route" => 'some-controller my-action-name this-is-a-country',
                "paths" => [
                    'task' => 'somecontroller',
                    'action' => 'myactionname',
                    'params' => ['this-is-a-country']
                ]
            ],
            [
                "route" => 'BINARY 1101',
                "paths" => [
                    'task' => 'binary',
                    'action' => 'index',
                    'params' => [1011]
                ]
            ],
        ];
    }

    private function getExamplesDelimiter(): array
    {
        return [
            [
                [
                    'uri' => '/',
                    'module' => 'devtools',
                    'task' => 'main',
                    'action' => 'hello',
                    'params' => []
                ]
            ],
            [
                [
                    'uri' => '/documentation/index/hellao/aaadpqñda/bbbAdld/cc-ccc',
                    'module' => null,
                    'task' => 'documentation',
                    'action' => 'index',
                    'params' => ['hellao', 'aaadpqñda', 'bbbAdld', 'cc-ccc']
                ]
            ],
            [
                [
                    'uri' => '/documentation/index/',
                    'module' => null,
                    'task' => 'documentation',
                    'action' => 'index',
                    'params' => []
                ]
            ],
            [
                [
                    'uri' => '/documentation/index',
                    'module' => null,
                    'task' => 'documentation',
                    'action' => 'index',
                    'params' => []
                ]
            ],
            [
                [
                    'uri' => '/documentation/',
                    'module' => null,
                    'task' => 'documentation',
                    'action' => null,
                    'params' => []
                ]
            ],
            [
                [
                    'uri' => '/system/admin/a/edit/hellao/aaadp',
                    'module' => null,
                    'task' => 'admin',
                    'action' => 'edit',
                    'params' => ['hellao', 'aaadp']
                ]
            ],
            [
                [
                    'uri' => '/es/news',
                    'module' => null,
                    'task' => 'news',
                    'action' => 'index',
                    'params' => ['language' => 'es']
                ]
            ],
            [
                [
                    'uri' => '/admin/posts/edit/100',
                    'module' => 'admin',
                    'task' => 'posts',
                    'action' => 'edit',
                    'params' => ['id' => 100]
                ]
            ],
            [
                [
                    'uri' => '/posts/2010/02/10/title/content',
                    'module' => null,
                    'task' => 'posts',
                    'action' => 'show',
                    'params' => [
                        'year' => '2010',
                        'month' => '02',
                        'day' => '10',
                        0 => 'title',
                        1 => 'content',
                    ]
                ]
            ],
            [
                [
                    'uri' => '/manual/en/translate.adapter.txt',
                    'module' => null,
                    'task' => 'manual',
                    'action' => 'show',
                    'params' => ['language' => 'en', 'file' => 'translate.adapter']
                ]
            ],
            [
                [
                    'uri' => '/named-manual/en/translate.adapter.txt',
                    'module' => null,
                    'task' => 'manual',
                    'action' => 'show',
                    'params' => ['language' => 'en', 'file' => 'translate.adapter']
                ]
            ],
            [
                [
                    'uri' => '/posts/1999/s/le-nice-title',
                    'module' => null,
                    'task' => 'posts',
                    'action' => 'show',
                    'params' => ['year' => '1999', 'title' => 'le-nice-title']
                ]
            ],
            [
                [
                    'uri' => '/feed/fr/blog/diaporema.json',
                    'module' => null,
                    'task' => 'feed',
                    'action' => 'get',
                    'params' => ['lang' => 'fr', 'blog' => 'diaporema', 'type' => 'json']
                ]
            ],
            [
                [
                    'uri' => '/posts/delete/150',
                    'module' => null,
                    'task' => 'posts',
                    'action' => 'delete',
                    'params' => ['id' => '150']
                ]
            ],
            [
                [
                    'uri' => '/very/static/route',
                    'module' => null,
                    'task' => 'static',
                    'action' => 'route',
                    'params' => []
                ]
            ],
        ];
    }

    private function runTests(CliTester $I, $router, array $test)
    {
        $router->handle($test['uri']);
        $I->assertEquals($test['module'], $router->getModuleName());
        $I->assertEquals($test['task'], $router->getTaskName());
        $I->assertEquals($test['action'], $router->getActionName());
        $I->assertEquals($test['params'], $router->getParams());
    }
}
