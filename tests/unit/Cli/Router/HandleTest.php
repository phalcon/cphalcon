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

namespace Phalcon\Tests\Unit\Cli\Router;

use Phalcon\Cli\Router;
use Phalcon\Cli\Router\Exception;
use Phalcon\Cli\Router\Route;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

final class HandleTest extends AbstractUnitTestCase
{
    /**
     * @return array[]
     */
    public static function getExamplesDelimiter(): array
    {
        return [
            [
                '/',
                'devtools',
                'main',
                'hello',
                [],
            ],
            [
                '/documentation/index/hellao/aaadpqñda/bbbAdld/cc-ccc',
                '',
                'documentation',
                'index',
                ['hellao', 'aaadpqñda', 'bbbAdld', 'cc-ccc'],
            ],
            [
                '/documentation/index/',
                '',
                'documentation',
                'index',
                [],
            ],
            [
                '/documentation/index',
                '',
                'documentation',
                'index',
                [],
            ],
            [
                '/documentation/',
                '',
                'documentation',
                '',
                [],
            ],
            [
                '/system/admin/a/edit/hellao/aaadp',
                '',
                'admin',
                'edit',
                ['hellao', 'aaadp'],
            ],
            [
                '/es/news',
                '',
                'news',
                'index',
                ['language' => 'es'],
            ],
            [
                '/admin/posts/edit/100',
                'admin',
                'posts',
                'edit',
                ['id' => '100'],
            ],
            [
                '/posts/2010/02/10/title/content',
                '',
                'posts',
                'show',
                [
                    0       => 'title',
                    1       => 'content',
                    'year'  => '2010',
                    'month' => '02',
                    'day'   => '10',
                ],
            ],
            [
                '/manual/en/translate.adapter.txt',
                '',
                'manual',
                'show',
                ['language' => 'en', 'file' => 'translate.adapter'],
            ],
            [
                '/named-manual/en/translate.adapter.txt',
                '',
                'manual',
                'show',
                ['language' => 'en', 'file' => 'translate.adapter'],
            ],
            [
                '/posts/1999/s/le-nice-title',
                '',
                'posts',
                'show',
                ['year' => '1999', 'title' => 'le-nice-title'],
            ],
            [
                '/feed/fr/blog/diaporema.json',
                '',
                'feed',
                'get',
                ['lang' => 'fr', 'blog' => 'diaporema', 'type' => 'json'],
            ],
            [
                '/posts/delete/150',
                '',
                'posts',
                'delete',
                ['id' => '150'],
            ],
            [
                '/very/static/route',
                '',
                'static',
                'route',
                [],
            ],
        ];
    }

    /**
     * @return array[]
     */
    public static function getExamplesRouter(): array
    {
        return [
            [
                '',
                '',
                '',
                '',
                [],
            ],
            [
                ' ',
                'devtools',
                'main',
                'hello',
                [],
            ],
            [
                'documentation index hellao aaadpqñda bbbAdld cc-ccc',
                '',
                'documentation',
                'index',
                ['hellao', 'aaadpqñda', 'bbbAdld', 'cc-ccc'],
            ],
            [
                ' documentation index',
                '',
                'documentation',
                'index',
                [],
            ],
            [
                'documentation index ',
                '',
                'documentation',
                'index',
                [],
            ],
            [
                'documentation index',
                '',
                'documentation',
                'index',
                [],
            ],
            [
                'documentation ',
                '',
                'documentation',
                '',
                [],
            ],
            [
                'system admin a edit hellao aaadp',
                '',
                'admin',
                'edit',
                ['hellao', 'aaadp'],
            ],
            [
                'es news',
                '',
                'news',
                'index',
                ['language' => 'es'],
            ],
            [
                'admin posts edit 100',
                'admin',
                'posts',
                'edit',
                ['id' => '100'],
            ],
            [
                'posts 2010 02 10 title content',
                '',
                'posts',
                'show',
                [
                    0       => 'title',
                    1       => 'content',
                    'year'  => '2010',
                    'month' => '02',
                    'day'   => '10',
                ],
            ],
            [
                'manual en translate.adapter.txt',
                '',
                'manual',
                'show',
                [
                    'language' => 'en',
                    'file'     => 'translate.adapter',
                ],
            ],
            [
                'named-manual en translate.adapter.txt',
                '',
                'manual',
                'show',
                [
                    'language' => 'en',
                    'file'     => 'translate.adapter',
                ],
            ],
            [
                'posts 1999 s le-nice-title',
                '',
                'posts',
                'show',
                [
                    'year'  => '1999',
                    'title' => 'le-nice-title',
                ],
            ],
            [
                'feed fr blog diaporema.json',
                '',
                'feed',
                'get',
                [
                    'lang' => 'fr',
                    'blog' => 'diaporema',
                    'type' => 'json',
                ],
            ],
            [
                'posts delete 150',
                '',
                'posts',
                'delete',
                ['id' => '150'],
            ],
            [
                'very static route',
                '',
                'static',
                'route',
                [],
            ],
        ];
    }

    /**
     * @return array[]
     */
    public static function getExamplesRouterHandle(): array
    {
        return [
            [
                'uri'    => [],
                'module' => '',
                'task'   => '',
                'action' => '',
                'params' => [],
            ],
            [
                'uri'    => [
                    'task' => 'main',
                ],
                'module' => '',
                'task'   => 'main',
                'action' => '',
                'params' => [],
            ],
            [
                'uri'    => [
                    'task' => 'echo',
                ],
                'module' => '',
                'task'   => 'echo',
                'action' => '',
                'params' => [],
            ],
            [
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
    public static function getExamplesRouterParams(): array
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

    public static function setupRoutes(string $test): array
    {
        $routes = [
            'router'    => [
                ' '                                                        => [
                    'module' => 'devtools',
                    'task'   => 'main',
                    'action' => 'hello',
                ],
                'system :task a :action :params'                           => [
                    'task'   => 1,
                    'action' => 2,
                    'params' => 3,
                ],
                '([a-z]{2}) :task'                                         => [
                    'task'     => 2,
                    'action'   => 'index',
                    'language' => 1,
                ],
                'admin :task :action :int'                                 => [
                    'module' => 'admin',
                    'task'   => 1,
                    'action' => 2,
                    'id'     => 3,
                ],
                'posts ([0-9]{4}) ([0-9]{2}) ([0-9]{2}) :params'           => [
                    'task'   => 'posts',
                    'action' => 'show',
                    'year'   => 1,
                    'month'  => 2,
                    'day'    => 3,
                    'params' => 4,
                ],
                'manual ([a-z]{2}) ([a-z\.]+)\.txt'                        => [
                    'task'     => 'manual',
                    'action'   => 'show',
                    'language' => 1,
                    'file'     => 2,
                ],
                'named-manual {language:([a-z]{2})} {file:[a-z\.]+}\.txt'  => [
                    'task'   => 'manual',
                    'action' => 'show',
                ],
                'very static route'                                        => [
                    'task'   => 'static',
                    'action' => 'route',
                ],
                "feed {lang:[a-z]+} blog {blog:[a-z\-]+}\.{type:[a-z\-]+}" => 'Feed::get',
                "posts {year:[0-9]+} s {title:[a-z\-]+}"                   => 'Posts::show',
                'posts delete {id}'                                        => 'Posts::delete',
                "show {id:video([0-9]+)} {title:[a-z\-]+}"                 => 'Videos::show',
            ],
            'delimiter' => [
                '/'                                                         => [
                    'module' => 'devtools',
                    'task'   => 'main',
                    'action' => 'hello',
                ],
                '/system/:task/a/:action/:params'                           => [
                    'task'   => 1,
                    'action' => 2,
                    'params' => 3,
                ],
                '/([a-z]{2})/:task'                                         => [
                    'task'     => 2,
                    'action'   => 'index',
                    'language' => 1,
                ],
                '/admin/:task/:action/:int'                                 => [
                    'module' => 'admin',
                    'task'   => 1,
                    'action' => 2,
                    'id'     => 3,
                ],
                '/posts/([0-9]{4})/([0-9]{2})/([0-9]{2})/:params'           => [
                    'task'   => 'posts',
                    'action' => 'show',
                    'year'   => 1,
                    'month'  => 2,
                    'day'    => 3,
                    'params' => 4,
                ],
                '/manual/([a-z]{2})/([a-z\.]+)\.txt'                        => [
                    'task'     => 'manual',
                    'action'   => 'show',
                    'language' => 1,
                    'file'     => 2,
                ],
                '/named-manual/{language:([a-z]{2})}/{file:[a-z\.]+}\.txt'  => [
                    'task'   => 'manual',
                    'action' => 'show',
                ],
                '/very/static/route'                                        => [
                    'task'   => 'static',
                    'action' => 'route',
                ],
                "/feed/{lang:[a-z]+}/blog/{blog:[a-z\-]+}\.{type:[a-z\-]+}" => 'Feed::get',
                "/posts/{year:[0-9]+}/s/{title:[a-z\-]+}"                   => 'Posts::show',
                '/posts/delete/{id}'                                        => 'Posts::delete',
                "/show/{id:video([0-9]+)}/{title:[a-z\-]+}"                 => 'Videos::show',

            ],
        ];

        return $routes[$test] ?? [];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    #[DataProvider('getExamplesRouterHandle')]
    public function testCliRouterHandle(
        array $uri,
        string $module,
        string $task,
        string $action,
        array $params
    ): void {
        $router = new Router();

        $this->assertParameters(
            $router,
            $uri,
            $module,
            $task,
            $action,
            $params
        );
    }
    /**
     * @issue  https://github.com/phalcon/cphalcon/security/advisories/GHSA-x7rj-f32v-7jjg
     * @author https://github.com/nikkoenggaliano
     * @since  2026-06-18
     */
    public function testCliRouterHandleParamsNoCatastrophicBacktracking(): void
    {
        Route::reset();
        Route::delimiter('/');

        $router = new Router();

        /**
         * The default :task/:action/:params route still splits a multi-segment
         * trailing path into individual parameters.
         */
        $router->handle('/products/show/1/2/3');

        $this->assertSame('products', $router->getTaskName());
        $this->assertSame('show', $router->getActionName());
        $this->assertSame(['1', '2', '3'], $router->getParams());

        /**
         * Take the compiled pattern of the default :params route and match a
         * crafted argument string: a long run of delimiters followed by an
         * unmatchable byte. The previous (:delimiter.*)* was a nested quantifier
         * that exhausted pcre.backtrack_limit on such input, while
         * (:delimiter.*)? matches in linear time, so preg_match() completes
         * without a PCRE error.
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

    #[DataProvider('getExamplesRouter')]
    public function testCliRouterHandleRouter(
        string $uri,
        string $module,
        string $task,
        string $action,
        array $params
    ): void {
        Route::reset();
        Route::delimiter(Route::DEFAULT_DELIMITER);

        $router = new Router();
        $routes = $this->setupRoutes('router');
        foreach ($routes as $pattern => $parameters) {
            $router->add($pattern, $parameters);
        }

        $this->assertParameters(
            $router,
            $uri,
            $module,
            $task,
            $action,
            $params
        );
    }

    #[DataProvider('getExamplesDelimiter')]
    public function testCliRouterHandleRouterDelimiter(
        string $uri,
        string $module,
        string $task,
        string $action,
        array $params
    ): void {
        Route::reset();
        Route::delimiter('/');

        $router = new Router();
        $routes = $this->setupRoutes('delimiter');
        foreach ($routes as $pattern => $parameters) {
            $router->add($pattern, $parameters);
        }

        $this->assertParameters(
            $router,
            $uri,
            $module,
            $task,
            $action,
            $params
        );
    }

    /**
     * @return void
     */
    public function testCliRouterHandleRouterInvalidPathsException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('The route contains invalid paths');

        Route::reset();

        $router = new Router(false);

        $route = $router->add('route3', 'MyApp\\Tasks\\::show');
    }

    #[DataProvider('getExamplesRouterParams')]
    public function testCliRouterHandleRouterParams(
        string $uri,
        string $module,
        string $task,
        string $action,
        array $params
    ): void {
        $router = new Router();

        $router->add('some {name}');
        $router->add('some {name} {id:[0-9]+}');
        $router->add('some {name} {id:[0-9]+} {date}');

        $this->assertParameters(
            $router,
            $uri,
            $module,
            $task,
            $action,
            $params
        );
    }

    /**
     * @return void
     */
    private function assertParameters(
        Router $router,
        array | string $uri,
        string $module,
        string $task,
        string $action,
        array $params
    ): void {
        $router->handle($uri);

        $expected = $module;
        $actual   = $router->getModuleName();
        $this->assertSame($expected, $actual);

        $expected = $task;
        $actual   = $router->getTaskName();
        $this->assertSame($expected, $actual);

        $expected = $action;
        $actual   = $router->getActionName();
        $this->assertSame($expected, $actual);

        $expected = $params;
        $actual   = $router->getParams();
        $this->assertSame($expected, $actual);
    }
}
