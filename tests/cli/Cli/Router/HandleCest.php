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
     * @dataProvider getExamplesRouterHandle
     *
     * @param CliTester $I
     * @param Example   $example
     *
     * @return void
     * @throws Exception
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function cliRouterHandle(CliTester $I, Example $example)
    {
        $label = $example['label'];

        $I->wantToTest('Cli\Router - handle() - ' . $label);

        $router = new Router();

        $this->assertParameters($I, $router, $example);
    }

    /**
     * @dataProvider getExamplesRouter
     *
     * @param CliTester $I
     * @param Example   $example
     *
     * @return void
     * @throws Exception
     */
    public function cliRouterHandleRouter(CliTester $I, Example $example)
    {
        $label = $example['uri'];

        $I->wantToTest('Cli\Router - handle() - router - ' . $label);

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

        $this->assertParameters($I, $router, $example);
    }

    /**
     * @dataProvider getExamplesRouterParams
     */
    public function cliRouterHandleRouterParams(CliTester $I, Example $example)
    {
        $router = new Router();

        $router->add('some {name}');
        $router->add('some {name} {id:[0-9]+}');
        $router->add('some {name} {id:[0-9]+} {date}');

        $this->assertParameters($I, $router, $example);
    }

    /**
     * @dataProvider getExamplesDelimiter
     *
     * @param CliTester $I
     * @param Example   $example
     *
     * @return void
     * @throws Exception
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

        $this->assertParameters($I, $router, $example);
    }

    /**
     * @param CliTester $I
     *
     * @return void
     */
    public function cliRouterHandleRouterInvalidPathsException(CliTester $I)
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
     * @param CliTester $I
     * @param Router    $router
     * @param Example   $example
     *
     * @return void
     */
    private function assertParameters(CliTester $I, Router $router, Example $example): void
    {
        $router->handle($example['uri']);

        $expected = $example['module'];
        $actual   = $router->getModuleName();
        $I->assertSame($expected, $actual);

        $expected = $example['task'];
        $actual   = $router->getTaskName();
        $I->assertSame($expected, $actual);

        $expected = $example['action'];
        $actual   = $router->getActionName();
        $I->assertSame($expected, $actual);

        $expected = $example['params'];
        $actual   = $router->getParams();
        $I->assertSame($expected, $actual);
    }

    /**
     * @return array[]
     */
    private function getExamplesRouterHandle(): array
    {
        return [
            [
                'label'  => 'empty',
                'uri'    => [],
                'module' => '',
                'task'   => '',
                'action' => '',
                'params' => [],
            ],
            [
                'label'  => 'task main',
                'uri'    => [
                    'task' => 'main',
                ],
                'module' => '',
                'task'   => 'main',
                'action' => '',
                'params' => [],
            ],
            [
                'label'  => 'task echo',
                'uri'    => [
                    'task' => 'echo',
                ],
                'module' => '',
                'task'   => 'echo',
                'action' => '',
                'params' => [],
            ],
            [
                'label'  => 'task action',
                'uri'    => [
                    'task'   => 'main',
                    'action' => 'hello',
                ],
                'module' => '',
                'task'   => 'main',
                'action' => 'hello',
                'params' => [],
            ],
            [
                'label'  => 'task action params',
                'uri'    => [
                    'task'   => 'main',
                    'action' => 'hello',
                    'arg1',
                    'arg2',
                ],
                'module' => '',
                'task'   => 'main',
                'action' => 'hello',
                'params' => [
                    'arg1',
                    'arg2',
                ],
            ],
            [
                'label'  => 'module task main action params',
                'uri'    => [
                    'module' => 'devtools',
                    'task'   => 'main',
                    'action' => 'hello',
                    'arg1',
                    'arg2',
                ],
                'module' => 'devtools',
                'task'   => 'main',
                'action' => 'hello',
                'params' => [
                    'arg1',
                    'arg2',
                ],
            ],
            [
                'label'  => 'module task echo action params',
                'uri'    => [
                    'module' => 'devtools',
                    'task'   => 'echo',
                    'action' => 'hello',
                    'arg1',
                    'arg2',
                ],
                'module' => 'devtools',
                'task'   => 'echo',
                'action' => 'hello',
                'params' => [
                    'arg1',
                    'arg2',
                ],
            ],
        ];
    }

    /**
     * @return array[]
     */
    private function getExamplesRouter(): array
    {
        return [
            [
                'uri'    => '',
                'module' => '',
                'task'   => '',
                'action' => '',
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
                'module' => '',
                'task'   => 'documentation',
                'action' => 'index',
                'params' => ['hellao', 'aaadpqñda', 'bbbAdld', 'cc-ccc'],
            ],
            [
                'uri'    => ' documentation index',
                'module' => '',
                'task'   => 'documentation',
                'action' => 'index',
                'params' => [],
            ],
            [
                'uri'    => 'documentation index ',
                'module' => '',
                'task'   => 'documentation',
                'action' => 'index',
                'params' => [],
            ],
            [
                'uri'    => 'documentation index',
                'module' => '',
                'task'   => 'documentation',
                'action' => 'index',
                'params' => [],
            ],
            [
                'uri'    => 'documentation ',
                'module' => '',
                'task'   => 'documentation',
                'action' => '',
                'params' => [],
            ],
            [
                'uri'    => 'system admin a edit hellao aaadp',
                'module' => '',
                'task'   => 'admin',
                'action' => 'edit',
                'params' => ['hellao', 'aaadp'],
            ],
            [
                'uri'    => 'es news',
                'module' => '',
                'task'   => 'news',
                'action' => 'index',
                'params' => ['language' => 'es'],
            ],
            [
                'uri'    => 'admin posts edit 100',
                'module' => 'admin',
                'task'   => 'posts',
                'action' => 'edit',
                'params' => ['id' => '100'],
            ],
            [
                'uri'    => 'posts 2010 02 10 title content',
                'module' => '',
                'task'   => 'posts',
                'action' => 'show',
                'params' => [
                    0       => 'title',
                    1       => 'content',
                    'year'  => '2010',
                    'month' => '02',
                    'day'   => '10',
                ],
            ],
            [
                'uri'    => 'manual en translate.adapter.txt',
                'module' => '',
                'task'   => 'manual',
                'action' => 'show',
                'params' => [
                    'language' => 'en',
                    'file'     => 'translate.adapter',
                ],
            ],
            [
                'uri'    => 'named-manual en translate.adapter.txt',
                'module' => '',
                'task'   => 'manual',
                'action' => 'show',
                'params' => [
                    'language' => 'en',
                    'file'     => 'translate.adapter',
                ],
            ],
            [
                'uri'    => 'posts 1999 s le-nice-title',
                'module' => '',
                'task'   => 'posts',
                'action' => 'show',
                'params' => [
                    'year'  => '1999',
                    'title' => 'le-nice-title',
                ],
            ],
            [
                'uri'    => 'feed fr blog diaporema.json',
                'module' => '',
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
                'module' => '',
                'task'   => 'posts',
                'action' => 'delete',
                'params' => ['id' => '150'],
            ],
            [
                'uri'    => 'very static route',
                'module' => '',
                'task'   => 'static',
                'action' => 'route',
                'params' => [],
            ],
        ];
    }

    /**
     * @return array[]
     */
    private function getExamplesRouterParams(): array
    {
        return [
            [
                'uri'    => 'some hattie',
                'module' => '',
                'task'   => '',
                'action' => '',
                'params' => [
                    'name' => 'hattie',
                ],
            ],

            [
                'uri'    => 'some hattie 100',
                'module' => '',
                'task'   => '',
                'action' => '',
                'params' => [
                    'name' => 'hattie',
                    'id'   => '100',
                ],
            ],

            [
                'uri'    => 'some hattie 100 2011-01-02',
                'module' => '',
                'task'   => '',
                'action' => '',
                'params' => [
                    'name' => 'hattie',
                    'id'   => '100',
                    'date' => '2011-01-02',
                ],
            ],
        ];
    }

    /**
     * @return array[]
     */
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
                'module' => '',
                'task'   => 'documentation',
                'action' => 'index',
                'params' => ['hellao', 'aaadpqñda', 'bbbAdld', 'cc-ccc'],
            ],
            [
                'uri'    => '/documentation/index/',
                'module' => '',
                'task'   => 'documentation',
                'action' => 'index',
                'params' => [],
            ],
            [
                'uri'    => '/documentation/index',
                'module' => '',
                'task'   => 'documentation',
                'action' => 'index',
                'params' => [],
            ],
            [
                'uri'    => '/documentation/',
                'module' => '',
                'task'   => 'documentation',
                'action' => '',
                'params' => [],
            ],
            [
                'uri'    => '/system/admin/a/edit/hellao/aaadp',
                'module' => '',
                'task'   => 'admin',
                'action' => 'edit',
                'params' => ['hellao', 'aaadp'],
            ],
            [
                'uri'    => '/es/news',
                'module' => '',
                'task'   => 'news',
                'action' => 'index',
                'params' => ['language' => 'es'],
            ],
            [
                'uri'    => '/admin/posts/edit/100',
                'module' => 'admin',
                'task'   => 'posts',
                'action' => 'edit',
                'params' => ['id' => '100'],
            ],
            [
                'uri'    => '/posts/2010/02/10/title/content',
                'module' => '',
                'task'   => 'posts',
                'action' => 'show',
                'params' => [
                    0       => 'title',
                    1       => 'content',
                    'year'  => '2010',
                    'month' => '02',
                    'day'   => '10',
                ],
            ],
            [
                'uri'    => '/manual/en/translate.adapter.txt',
                'module' => '',
                'task'   => 'manual',
                'action' => 'show',
                'params' => ['language' => 'en', 'file' => 'translate.adapter'],
            ],
            [
                'uri'    => '/named-manual/en/translate.adapter.txt',
                'module' => '',
                'task'   => 'manual',
                'action' => 'show',
                'params' => ['language' => 'en', 'file' => 'translate.adapter'],
            ],
            [
                'uri'    => '/posts/1999/s/le-nice-title',
                'module' => '',
                'task'   => 'posts',
                'action' => 'show',
                'params' => ['year' => '1999', 'title' => 'le-nice-title'],
            ],
            [
                'uri'    => '/feed/fr/blog/diaporema.json',
                'module' => '',
                'task'   => 'feed',
                'action' => 'get',
                'params' => ['lang' => 'fr', 'blog' => 'diaporema', 'type' => 'json'],
            ],
            [
                'uri'    => '/posts/delete/150',
                'module' => '',
                'task'   => 'posts',
                'action' => 'delete',
                'params' => ['id' => '150'],
            ],
            [
                'uri'    => '/very/static/route',
                'module' => '',
                'task'   => 'static',
                'action' => 'route',
                'params' => [],
            ],
        ];
    }
}
