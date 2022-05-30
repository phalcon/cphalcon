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

namespace Phalcon\Tests\Cli\Cli\Router;

use CliTester;
use Codeception\Example;
use Phalcon\Cli\Router;
use Phalcon\Cli\Router\Exception;
use Phalcon\Cli\Router\Route;

class HandleCest
{
    /**
     * Tests Phalcon\Cli\Router :: handle()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliRouterHandle(CliTester $I)
    {
        $I->wantToTest('Cli\Router - handle()');
        $router = new Router();

        $router->handle(
            []
        );
        $I->assertSame(
            '',
            $router->getModuleName()
        );
        $I->assertNull(
            $router->getTaskName()
        );
        $I->assertNull(
            $router->getActionName()
        );
        $I->assertEquals(
            [],
            $router->getParams()
        );

        $router->handle(
            [
                'task' => 'main',
            ]
        );
        $I->assertSame(
            '',
            $router->getModuleName()
        );
        $I->assertEquals(
            'main',
            $router->getTaskName()
        );
        $I->assertNull(
            $router->getActionName()
        );
        $I->assertEquals(
            [],
            $router->getParams()
        );


        $router->handle(
            [
                'task' => 'echo',
            ]
        );
        $I->assertSame(
            '',
            $router->getModuleName()
        );
        $I->assertEquals(
            'echo',
            $router->getTaskName()
        );
        $I->assertNull(
            $router->getActionName()
        );
        $I->assertEquals(
            [],
            $router->getParams()
        );
        $router->handle(
            [
                'task'   => 'main',
                'action' => 'hello',
            ]
        );

        $I->assertSame(
            '',
            $router->getModuleName()
        );
        $I->assertEquals(
            'main',
            $router->getTaskName()
        );
        $I->assertEquals(
            $router->getActionName(),
            'hello'
        );
        $I->assertEquals(
            [],
            $router->getParams()
        );
        $router->handle(
            [
                'task'   => 'main',
                'action' => 'hello',
                'arg1',
                'arg2',
            ]
        );

        $I->assertSame(
            '',
            $router->getModuleName()
        );
        $I->assertEquals(
            'main',
            $router->getTaskName()
        );
        $I->assertEquals(
            'hello',
            $router->getActionName()
        );
        $I->assertEquals(
            ['arg1', 'arg2'],
            $router->getParams()
        );
        $router->handle(
            [
                'module' => 'devtools',
                'task'   => 'main',
                'action' => 'hello',
                'arg1',
                'arg2',
            ]
        );

        $I->assertEquals(
            'devtools',
            $router->getModuleName()
        );
        $I->assertEquals(
            'main',
            $router->getTaskName()
        );
        $I->assertEquals(
            'hello',
            $router->getActionName()
        );
        $I->assertEquals(
            ['arg1', 'arg2'],
            $router->getParams()
        );
        $router->handle(
            [
                'module' => 'devtools',
                'task'   => 'echo',
                'action' => 'hello',
                'arg1',
                'arg2',
            ]
        );

        $I->assertEquals('devtools', $router->getModuleName());
        $I->assertEquals('echo', $router->getTaskName());
        $I->assertEquals('hello', $router->getActionName());
        $I->assertEquals(['arg1', 'arg2'], $router->getParams());
    }

    /**
     * @dataProvider getExamplesRouter
     */
    public function testRouter(CliTester $I, Example $example)
    {
        Route::reset();

        $router = new Router();

        $router->add(
            ' ',
            [
                'module' => 'devtools',
                'task'   => 'main',
                'action' => 'hello',
            ]
        );

        $router->add(
            'system :task a :action :params',
            [
                'task'   => 1,
                'action' => 2,
                'params' => 3,
            ]
        );

        $router->add(
            '([a-z]{2}) :task',
            [
                'task'     => 2,
                'action'   => 'index',
                'language' => 1,
            ]
        );

        $router->add(
            'admin :task :action :int',
            [
                'module' => 'admin',
                'task'   => 1,
                'action' => 2,
                'id'     => 3,
            ]
        );

        $router->add(
            'posts ([0-9]{4}) ([0-9]{2}) ([0-9]{2}) :params',
            [
                'task'   => 'posts',
                'action' => 'show',
                'year'   => 1,
                'month'  => 2,
                'day'    => 3,
                'params' => 4,
            ]
        );

        $router->add(
            'manual ([a-z]{2}) ([a-z\.]+)\.txt',
            [
                'task'     => 'manual',
                'action'   => 'show',
                'language' => 1,
                'file'     => 2,
            ]
        );

        $router->add(
            'named-manual {language:([a-z]{2})} {file:[a-z\.]+}\.txt',
            [
                'task'   => 'manual',
                'action' => 'show',
            ]
        );

        $router->add(
            'very static route',
            [
                'task'   => 'static',
                'action' => 'route',
            ]
        );

        $router->add(
            "feed {lang:[a-z]+} blog {blog:[a-z\-]+}\.{type:[a-z\-]+}",
            'Feed::get'
        );

        $router->add(
            "posts {year:[0-9]+} s {title:[a-z\-]+}",
            'Posts::show'
        );

        $router->add(
            'posts delete {id}',
            'Posts::delete'
        );

        $router->add(
            "show {id:video([0-9]+)} {title:[a-z\-]+}",
            'Videos::show'
        );

        $router->handle($example['uri']);

        $I->assertEquals($example['module'], $router->getModuleName());
        $I->assertEquals($example['task'], $router->getTaskName());
        $I->assertEquals($example['action'], $router->getActionName());
        $I->assertEquals($example['params'], $router->getParams());
    }

    private function getExamplesRouter(): array
    {
        return [
            [
                'uri'    => '',
                'module' => null,
                'task'   => null,
                'action' => null,
                'params' => [],
            ],

            [
                'uri'    => ' ',
                'module' => 'devtools',
                'task'   => 'main',
                'action' => 'hello',
                'params' => [],
            ],

            [
                'uri'    => 'documentation index hellao aaadpqñda bbbAdld cc-ccc',
                'module' => null,
                'task'   => 'documentation',
                'action' => 'index',
                'params' => ['hellao', 'aaadpqñda', 'bbbAdld', 'cc-ccc'],
            ],

            [
                'uri'    => ' documentation index',
                'module' => null,
                'task'   => 'documentation',
                'action' => 'index',
                'params' => [],
            ],

            [
                'uri'    => 'documentation index ',
                'module' => null,
                'task'   => 'documentation',
                'action' => 'index',
                'params' => [],
            ],

            [
                'uri'    => 'documentation index',
                'module' => null,
                'task'   => 'documentation',
                'action' => 'index',
                'params' => [],
            ],

            [
                'uri'    => 'documentation ',
                'module' => null,
                'task'   => 'documentation',
                'action' => null,
                'params' => [],
            ],

            [
                'uri'    => 'system admin a edit hellao aaadp',
                'module' => null,
                'task'   => 'admin',
                'action' => 'edit',
                'params' => ['hellao', 'aaadp'],
            ],

            [
                'uri'    => 'es news',
                'module' => null,
                'task'   => 'news',
                'action' => 'index',
                'params' => ['language' => 'es'],
            ],

            [
                'uri'    => 'admin posts edit 100',
                'module' => 'admin',
                'task'   => 'posts',
                'action' => 'edit',
                'params' => ['id' => 100],
            ],

            [
                'uri'    => 'posts 2010 02 10 title content',
                'module' => null,
                'task'   => 'posts',
                'action' => 'show',
                'params' => [
                    'year'  => '2010',
                    'month' => '02',
                    'day'   => '10',
                    0       => 'title',
                    1       => 'content',
                ],
            ],

            [
                'uri'    => 'manual en translate.adapter.txt',
                'module' => null,
                'task'   => 'manual',
                'action' => 'show',
                'params' => [
                    'language' => 'en',
                    'file'     => 'translate.adapter',
                ],
            ],

            [
                'uri'    => 'named-manual en translate.adapter.txt',
                'module' => null,
                'task'   => 'manual',
                'action' => 'show',
                'params' => [
                    'language' => 'en',
                    'file'     => 'translate.adapter',
                ],
            ],

            [
                'uri'    => 'posts 1999 s le-nice-title',
                'module' => null,
                'task'   => 'posts',
                'action' => 'show',
                'params' => [
                    'year'  => '1999',
                    'title' => 'le-nice-title',
                ],
            ],

            [
                'uri'    => 'feed fr blog diaporema.json',
                'module' => null,
                'task'   => 'feed',
                'action' => 'get',
                'params' => [
                    'lang' => 'fr',
                    'blog' => 'diaporema',
                    'type' => 'json',
                ],
            ],

            [
                'uri'    => 'posts delete 150',
                'module' => null,
                'task'   => 'posts',
                'action' => 'delete',
                'params' => ['id' => '150'],
            ],

            [
                'uri'    => 'very static route',
                'module' => null,
                'task'   => 'static',
                'action' => 'route',
                'params' => [],
            ],
        ];
    }

    /**
     * @dataProvider getExamplesRouterParams
     */
    public function testRouterParams(CliTester $I, Example $example)
    {
        $router = new Router();

        $router->add('some {name}');
        $router->add('some {name} {id:[0-9]+}');
        $router->add('some {name} {id:[0-9]+} {date}');

        $router->handle($example['uri']);
        $I->assertEquals($example['module'], $router->getModuleName());
        $I->assertEquals($example['task'], $router->getTaskName());
        $I->assertEquals($example['action'], $router->getActionName());
        $I->assertEquals($example['params'], $router->getParams());
    }

    public function testShortPaths2(CliTester $I)
    {
        $I->expectThrowable(
            new Exception('The route contains invalid paths'),
            function () {
                Route::reset();

                $router = new Router(false);

                $route = $router->add('route3', 'MyApp\\Tasks\\::show');
            }
        );
    }

    /**
     * @dataProvider getExamplesDelimiter
     */
    public function testDelimiter(CliTester $I, Example $example)
    {
        Route::reset();
        Route::delimiter('/');

        $router = new Router();

        $router->add(
            '/',
            [
                'module' => 'devtools',
                'task'   => 'main',
                'action' => 'hello',
            ]
        );

        $router->add(
            '/system/:task/a/:action/:params',
            [
                'task'   => 1,
                'action' => 2,
                'params' => 3,
            ]
        );

        $router->add(
            '/([a-z]{2})/:task',
            [
                'task'     => 2,
                'action'   => 'index',
                'language' => 1,
            ]
        );

        $router->add(
            '/admin/:task/:action/:int',
            [
                'module' => 'admin',
                'task'   => 1,
                'action' => 2,
                'id'     => 3,
            ]
        );

        $router->add(
            '/posts/([0-9]{4})/([0-9]{2})/([0-9]{2})/:params',
            [
                'task'   => 'posts',
                'action' => 'show',
                'year'   => 1,
                'month'  => 2,
                'day'    => 3,
                'params' => 4,
            ]
        );

        $router->add(
            '/manual/([a-z]{2})/([a-z\.]+)\.txt',
            [
                'task'     => 'manual',
                'action'   => 'show',
                'language' => 1,
                'file'     => 2,
            ]
        );

        $router->add(
            '/named-manual/{language:([a-z]{2})}/{file:[a-z\.]+}\.txt',
            [
                'task'   => 'manual',
                'action' => 'show',
            ]
        );

        $router->add(
            '/very/static/route',
            [
                'task'   => 'static',
                'action' => 'route',
            ]
        );

        $router->add(
            "/feed/{lang:[a-z]+}/blog/{blog:[a-z\-]+}\.{type:[a-z\-]+}",
            'Feed::get'
        );

        $router->add(
            "/posts/{year:[0-9]+}/s/{title:[a-z\-]+}",
            'Posts::show'
        );

        $router->add(
            '/posts/delete/{id}',
            'Posts::delete'
        );

        $router->add(
            "/show/{id:video([0-9]+)}/{title:[a-z\-]+}",
            'Videos::show'
        );

        $router->handle($example['uri']);

        $I->assertEquals($example['module'], $router->getModuleName());
        $I->assertEquals($example['task'], $router->getTaskName());
        $I->assertEquals($example['action'], $router->getActionName());
        $I->assertEquals($example['params'], $router->getParams());
    }

    private function getExamplesRouterParams(): array
    {
        return [
            [
                'uri'    => 'some hattie',
                'module' => null,
                'task'   => '',
                'action' => '',
                'params' => [
                    'name' => 'hattie',
                ],
            ],

            [
                'uri'    => 'some hattie 100',
                'module' => null,
                'task'   => '',
                'action' => '',
                'params' => [
                    'name' => 'hattie',
                    'id'   => 100,
                ],
            ],

            [
                'uri'    => 'some hattie 100 2011-01-02',
                'module' => null,
                'task'   => '',
                'action' => '',
                'params' => [
                    'name' => 'hattie',
                    'id'   => 100,
                    'date' => '2011-01-02',
                ],
            ],
        ];
    }

    private function getExamplesDelimiter(): array
    {
        return [
            [
                'uri'    => '/',
                'module' => 'devtools',
                'task'   => 'main',
                'action' => 'hello',
                'params' => [],
            ],

            [
                'uri'    => '/documentation/index/hellao/aaadpqñda/bbbAdld/cc-ccc',
                'module' => null,
                'task'   => 'documentation',
                'action' => 'index',
                'params' => ['hellao', 'aaadpqñda', 'bbbAdld', 'cc-ccc'],
            ],

            [
                'uri'    => '/documentation/index/',
                'module' => null,
                'task'   => 'documentation',
                'action' => 'index',
                'params' => [],
            ],

            [
                'uri'    => '/documentation/index',
                'module' => null,
                'task'   => 'documentation',
                'action' => 'index',
                'params' => [],
            ],
            [
                'uri'    => '/documentation/',
                'module' => null,
                'task'   => 'documentation',
                'action' => null,
                'params' => [],
            ],

            [
                'uri'    => '/system/admin/a/edit/hellao/aaadp',
                'module' => null,
                'task'   => 'admin',
                'action' => 'edit',
                'params' => ['hellao', 'aaadp'],
            ],

            [
                'uri'    => '/es/news',
                'module' => null,
                'task'   => 'news',
                'action' => 'index',
                'params' => ['language' => 'es'],
            ],
            [
                'uri'    => '/admin/posts/edit/100',
                'module' => 'admin',
                'task'   => 'posts',
                'action' => 'edit',
                'params' => ['id' => 100],
            ],

            [
                'uri'    => '/posts/2010/02/10/title/content',
                'module' => null,
                'task'   => 'posts',
                'action' => 'show',
                'params' => [
                    'year'  => '2010',
                    'month' => '02',
                    'day'   => '10',
                    0       => 'title',
                    1       => 'content',
                ],
            ],

            [
                'uri'    => '/manual/en/translate.adapter.txt',
                'module' => null,
                'task'   => 'manual',
                'action' => 'show',
                'params' => ['language' => 'en', 'file' => 'translate.adapter'],
            ],

            [
                'uri'    => '/named-manual/en/translate.adapter.txt',
                'module' => null,
                'task'   => 'manual',
                'action' => 'show',
                'params' => ['language' => 'en', 'file' => 'translate.adapter'],
            ],

            [
                'uri'    => '/posts/1999/s/le-nice-title',
                'module' => null,
                'task'   => 'posts',
                'action' => 'show',
                'params' => ['year' => '1999', 'title' => 'le-nice-title'],
            ],

            [
                'uri'    => '/feed/fr/blog/diaporema.json',
                'module' => null,
                'task'   => 'feed',
                'action' => 'get',
                'params' => ['lang' => 'fr', 'blog' => 'diaporema', 'type' => 'json'],
            ],

            [
                'uri'    => '/posts/delete/150',
                'module' => null,
                'task'   => 'posts',
                'action' => 'delete',
                'params' => ['id' => '150'],
            ],

            [
                'uri'    => '/very/static/route',
                'module' => null,
                'task'   => 'static',
                'action' => 'route',
                'params' => [],
            ],
        ];
    }
}
