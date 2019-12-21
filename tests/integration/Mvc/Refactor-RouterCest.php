<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Mvc\Router\Route;
use Phalcon\Test\Fixtures\Traits\RouterTrait;

class RouterCest
{
    use RouterTrait;

    /**
     * executed before each test
     */
    protected function _before(IntegrationTester $I)
    {
        Route::reset();
    }

    /**
     * Tests routing by use Route::convert
     *
     * @author       Andy Gutierrez <andres.gutierrez@phalcon.io>
     * @since        2012-12-25
     *
     * @dataProvider getMatchingWithConverted
     */
    public function testUsingRouteConverters(IntegrationTester $I, Example $example)
    {
        $route  = $example[0];
        $params = $example[1];

        $router = $this->getRouterAndSetData();

        $router->handle($route);

        $I->assertTrue(
            $router->wasMatched()
        );

        $I->assertEquals(
            $params['controller'],
            $router->getControllerName()
        );

        $I->assertEquals(
            $params['action'],
            $router->getActionName()
        );
    }

    /**
     * Tests using callbacks before match route
     *
     * @author Andy Gutierrez <andres.gutierrez@phalcon.io>
     * @since  2013-01-08
     */
    public function testUsingCallbacksBeforeMatchRoute(IntegrationTester $I)
    {
        $router = $this->getRouter(false);
        $trace  = 0;

        $router
            ->add('/static/route')
            ->beforeMatch(
                function () use (&$trace) {
                    $trace++;

                    return false;
                }
            )
        ;

        $router
            ->add('/static/route2')
            ->beforeMatch(
                function () use (&$trace) {
                    $trace++;

                    return true;
                }
            )
        ;


        $router->handle('/');

        $I->assertFalse(
            $router->wasMatched()
        );


        $router->handle('/static/route');

        $I->assertFalse(
            $router->wasMatched()
        );


        $router->handle('/static/route2');

        $I->assertTrue(
            $router->wasMatched()
        );


        $I->assertEquals(2, $trace);
    }

    /**
     * Tests router
     *
     * @author       Andy Gutierrez <andres.gutierrez@phalcon.io>
     * @since        2013-01-17
     *
     * @dataProvider getMatchingWithRouter
     */
    public function shouldMatchWithRouter(IntegrationTester $I, Example $example)
    {
        $pathToRouterData = $this->getDataRouter();

        $router = $this->getRouterAndSetRoutes($pathToRouterData);

        $router->handle(
            $example['uri']
        );

        $I->assertEquals(
            $example['controller'],
            $router->getControllerName()
        );

        $I->assertEquals(
            $example['action'],
            $router->getActionName()
        );

        $I->assertEquals(
            $example['params'],
            $router->getParams()
        );
    }

    private function getDataRouter(): array
    {
        return [
            [
                'methodName' => 'add',
                '/',
                [
                    'controller' => 'index',
                    'action'     => 'index',
                ],
            ],
            [
                'methodName' => 'add',
                '/system/:controller/a/:action/:params',
                [
                    'controller' => 1,
                    'action'     => 2,
                    'params'     => 3,
                ],
            ],
            [
                'methodName' => 'add',
                '/([a-z]{2})/:controller',
                [
                    'controller' => 2,
                    'action'     => 'index',
                    'language'   => 1,
                ],
            ],
            [
                'methodName' => 'add',
                '/admin/:controller/:action/:int',
                [
                    'controller' => 1,
                    'action'     => 2,
                    'id'         => 3,
                ],
            ],
            [
                'methodName' => 'add',
                '/posts/([0-9]{4})/([0-9]{2})/([0-9]{2})/:params',
                [
                    'controller' => 'posts',
                    'action'     => 'show',
                    'year'       => 1,
                    'month'      => 2,
                    'day'        => 3,
                    'params'     => 4,
                ],
            ],
            [
                'methodName' => 'add',
                '/manual/([a-z]{2})/([a-z\.]+)\.html',
                [
                    'controller' => 'manual',
                    'action'     => 'show',
                    'language'   => 1,
                    'file'       => 2,
                ],
            ],
            [
                'methodName' => 'add',
                '/named-manual/{language:([a-z]{2})}/{file:[a-z\.]+}\.html',
                [
                    'controller' => 'manual',
                    'action'     => 'show',
                ],
            ],
            [
                'methodName' => 'add',
                '/very/static/route',
                [
                    'controller' => 'static',
                    'action'     => 'route',
                ],
            ],
            [
                'methodName' => 'add',
                '/feed/{lang:[a-z]+}/blog/{blog:[a-z\-]+}\.{type:[a-z\-]+}',
                'Feed::get',
            ],
            [
                'methodName' => 'add',
                '/posts/{year:[0-9]+}/s/{title:[a-z\-]+}',
                'Posts::show',
            ],
            [
                'methodName' => 'add',
                '/posts/delete/{id}',
                'Posts::delete',
            ],
            [
                'methodName' => 'add',
                '/show/{id:video([0-9]+)}/{title:[a-z\-]+}',
                'Videos::show',
            ],
        ];
    }

    private function getMatchingWithRouter(): array
    {
        return [
            [
                'uri'        => '',
                'controller' => 'index',
                'action'     => 'index',
                'params'     => [],
            ],
            [
                'uri'        => '/',
                'controller' => 'index',
                'action'     => 'index',
                'params'     => [],
            ],
            [
                'uri'        => '/documentation/index/hellao/aaadpqñda/bbbAdld/cc-ccc',
                'controller' => 'documentation',
                'action'     => 'index',
                'params'     => ['hellao', 'aaadpqñda', 'bbbAdld', 'cc-ccc'],
            ],
            [
                'uri'        => '/documentation/index/',
                'controller' => 'documentation',
                'action'     => 'index',
                'params'     => [],
            ],
            [
                'uri'        => '/documentation/index',
                'controller' => 'documentation',
                'action'     => 'index',
                'params'     => [],
            ],
            [
                'uri'        => '/documentation/',
                'controller' => 'documentation',
                'action'     => null,
                'params'     => [],
            ],
            [
                'uri'        => '/documentation',
                'controller' => 'documentation',
                'action'     => null,
                'params'     => [],
            ],
            [
                'uri'        => '/system/admin/a/edit/hellao/aaadp',
                'controller' => 'admin',
                'action'     => 'edit',
                'params'     => ['hellao', 'aaadp'],
            ],
            [
                'uri'        => '/es/news',
                'controller' => 'news',
                'action'     => 'index',
                'params'     => ['language' => 'es'],
            ],
            [
                'uri'        => '/admin/posts/edit/100',
                'controller' => 'posts',
                'action'     => 'edit',
                'params'     => ['id' => 100],
            ],
            [
                'uri'        => '/posts/2010/02/10/title/content',
                'controller' => 'posts',
                'action'     => 'show',
                'params'     => ['year' => '2010', 'month' => '02', 'day' => '10', 0 => 'title', 1 => 'content'],
            ],
            [
                'uri'        => '/manual/en/translate.adapter.html',
                'controller' => 'manual',
                'action'     => 'show',
                'params'     => ['language' => 'en', 'file' => 'translate.adapter'],
            ],
            [
                'uri'        => '/named-manual/en/translate.adapter.html',
                'controller' => 'manual',
                'action'     => 'show',
                'params'     => ['language' => 'en', 'file' => 'translate.adapter'],
            ],
            [
                'uri'        => '/posts/1999/s/le-nice-title',
                'controller' => 'posts',
                'action'     => 'show',
                'params'     => ['year' => '1999', 'title' => 'le-nice-title'],
            ],
            [
                'uri'        => '/feed/fr/blog/diaporema.json',
                'controller' => 'feed',
                'action'     => 'get',
                'params'     => ['lang' => 'fr', 'blog' => 'diaporema', 'type' => 'json'],
            ],
            [
                'uri'        => '/posts/delete/150',
                'controller' => 'posts',
                'action'     => 'delete',
                'params'     => ['id' => '150'],
            ],
            [
                'uri'        => '/very/static/route',
                'controller' => 'static',
                'action'     => 'route',
                'params'     => [],
            ],

        ];
    }

    /**
     * Tests router by using rote params
     *
     * @author       Andy Gutierrez <andres.gutierrez@phalcon.io>
     * @since        2012-08-22
     *
     * @dataProvider getMatchingWithRouterHttp
     */
    public function shouldMatchWithTheRouterByUsingHttpMethods(IntegrationTester $I, Example $example)
    {
        $pathToRouterData = $this->getDataRouterHttp();

        $router = $this->getRouterAndSetRoutes($pathToRouterData);

        $_SERVER['REQUEST_METHOD'] = $example['method'];

        $router->handle(
            $example['uri']
        );

        $I->assertEquals(
            $example['controller'],
            $router->getControllerName()
        );

        $I->assertEquals(
            $example['action'],
            $router->getActionName()
        );

        $I->assertEquals(
            $example['params'],
            $router->getParams()
        );
    }

    private function getDataRouterHttp(): array
    {
        return [
            [
                'methodName' => 'add',
                '/docs/index',
                [
                    'controller' => 'documentation2222',
                    'action'     => 'index',
                ],
            ],
            [
                'methodName' => 'addPost',
                '/docs/index',
                [
                    'controller' => 'documentation3',
                    'action'     => 'index',
                ],
            ],
            [
                'methodName' => 'addGet',
                '/docs/index',
                [
                    'controller' => 'documentation4',
                    'action'     => 'index',
                ],
            ],
            [
                'methodName' => 'addPut',
                '/docs/index',
                [
                    'controller' => 'documentation5',
                    'action'     => 'index',
                ],
            ],
            [
                'methodName' => 'addDelete',
                '/docs/index',
                [
                    'controller' => 'documentation6',
                    'action'     => 'index',
                ],
            ],
            [
                'methodName' => 'addOptions',
                '/docs/index',
                [
                    'controller' => 'documentation7',
                    'action'     => 'index',
                ],
            ],
            [
                'methodName' => 'addHead',
                '/docs/index',
                [
                    'controller' => 'documentation8',
                    'action'     => 'index',
                ],
            ],
            [
                'methodName' => 'addPurge',
                '/docs/index',
                [
                    'controller' => 'documentation9',
                    'action'     => 'index',
                ],
            ],
            [
                'methodName' => 'addTrace',
                '/docs/index',
                [
                    'controller' => 'documentation10',
                    'action'     => 'index',
                ],
            ],
            [
                'methodName' => 'addConnect',
                '/docs/index',
                [
                    'controller' => 'documentation11',
                    'action'     => 'index',
                ],
            ],
        ];
    }

    private function getMatchingWithRouterHttp(): array
    {
        return [
            [
                'method'     => null,
                'uri'        => '/documentation/index/hello',
                'controller' => 'documentation',
                'action'     => 'index',
                'params'     => ['hello'],
            ],
        ];
    }

    /**
     * Tests router by using http method
     *
     * @author       Andy Gutierrez <andres.gutierrez@phalcon.io>
     * @since        2012-08-22
     *
     * @dataProvider getMatchingWithToRouter
     */
    public function shouldMatchWithGotRouterParam(IntegrationTester $I, Example $example)
    {
        $pathToRouterData = $this->getDataToRouter();

        $router = $this->getRouterAndSetRoutes($pathToRouterData);

        $router->handle(
            $example['uri']
        );

        $I->assertEquals(
            $example['controller'],
            $router->getControllerName()
        );

        $I->assertEquals(
            $example['action'],
            $router->getActionName()
        );

        $I->assertEquals(
            $example['params'],
            $router->getParams()
        );
    }

    private function getDataToRouter(): array
    {
        return [
            [
                'methodName' => 'add',
                '/some/{name}',
            ],
            [
                'methodName' => 'add',
                '/some/{name}/{id:[0-9]+}',
            ],
            [
                'methodName' => 'add',
                '/some/{name}/{id:[0-9]+}/{date}',
            ],
        ];
    }

    private function getMatchingWithToRouter(): array
    {
        return [
            [
                'uri'        => '/some/hattie',
                'controller' => '',
                'action'     => '',
                'params'     => ['name' => 'hattie'],
            ],
            [
                'uri'        => '/some/hattie/100',
                'controller' => '',
                'action'     => '',
                'params'     => ['name' => 'hattie', 'id' => 100],
            ],
            [
                'uri'        => '/some/hattie/100/2011-01-02',
                'controller' => '',
                'action'     => '',
                'params'     => ['name' => 'hattie', 'id' => 100, 'date' => '2011-01-02'],
            ],
        ];
    }

    /**
     * Tests adding a route to the router by using short path
     *
     * @author       Andy Gutierrez <andres.gutierrez@phalcon.io>
     * @since        2012-01-16
     *
     * @dataProvider getMatchingWithPathProvider
     */
    public function testAddingRouteByUsingShortPaths(IntegrationTester $I, Example $example)
    {
        $route    = $example[0];
        $path     = $example[1];
        $expected = $example[2];

        $router = $this->getRouter(false);

        $route = $router->add($route, $path);

        $I->assertEquals(
            $expected,
            $route->getPaths()
        );
    }

    /**
     * Tests setting host name by using regexp
     *
     * @test
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2016-06-23
     *
     * @dataProvider getMatchingWithHostnameRegex
     */
    public function shouldMathWithHostnameRegex(IntegrationTester $I, Example $example)
    {
//        $pathToRouterData = $this->getDataRouterHostName();
        $pathToRouterData = $this->getDataToHostnameRegex();

        $expected = $example[0];
        $handle   = $example[1];
        $hostname = $example[2];

        $router = $this->getRouterAndSetRoutesAndHostNames(
            $pathToRouterData,
            false
        );

        $_SERVER['HTTP_HOST'] = $hostname;

        $router->handle($handle);

        $I->assertEquals(
            $expected,
            $router->getControllerName()
        );
    }

    private function getDataToHostnameRegex(): array
    {
        return [
            [
                'methodName' => 'add',
                '/edit',
                [
                    'controller' => 'posts3',
                    'action'     => 'edit3',
                ],
            ],
            [
                'methodName' => 'add',
                '/edit',
                [
                    'controller' => 'posts',
                    'action'     => 'edit',
                ],
                'hostname'   => '([a-z]+).phalcon.io',
            ],
            [
                'methodName' => 'add',
                '/edit',
                [
                    'controller' => 'posts2',
                    'action'     => 'edit2',
                ],
                'hostname'   => 'mail.([a-z]+).com',
            ],
            [
                'methodName' => 'add',
                '/edit',
                [
                    'controller' => 'posts4',
                    'action'     => 'edit2',
                ],
                'hostname'   => '([a-z]+).([a-z]+).net',
            ],
        ];
    }

    private function getMatchingWithHostnameRegex(): array
    {
        return [
            ['posts3', '/edit', 'localhost'],
            ['posts', '/edit', 'my.phalcon.io'],
            ['posts3', '/edit', null],
            ['posts2', '/edit', 'mail.example.com'],
            ['posts3', '/edit', 'some-domain.com'],
            ['posts4', '/edit', 'some.domain.net'],
        ];
    }

    /**
     * Tests setting host name by using regexp
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/2573
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2016-06-26
     *
     * @dataProvider getMatchingWithRegexRouterHostPort
     */
    public function shouldMatchWithHostnameRegexWithHostPort111(IntegrationTester $I, Example $example)
    {
        $I->skipTest('TODO - Check');

        $pathToRouterData = $this->getDataRegexRouterHostPort();

        $param    = $example[0];
        $expected = $example[1];

        $router = $this->getRouterAndSetRoutesAndHostNames(
            $pathToRouterData,
            false
        );

        $_SERVER['HTTP_HOST'] = $param['hostname'] . ($param['port'] ? ':' . $param['port'] : '');

        $router->handle(
            $param['handle']
        );

        $I->assertEquals(
            $expected,
            $router->getControllerName()
        );
    }

    private function getDataRegexRouterHostPort(): array
    {
        return [
            [
                'methodName' => 'add',
                '/edit',
                [
                    'controller' => 'posts3',
                    'action'     => 'edit3',
                ],
                'hostname'   => '',
            ],
            [
                'methodName' => 'add',
                '/edit',
                [
                    'controller' => 'posts',
                    'action'     => 'edit',
                ],
                'hostname'   => '',
            ],
            [
                'methodName' => 'add',
                '/edit',
                [
                    'controller' => 'posts2',
                    'action'     => 'edit2',
                ],
                'hostname'   => '',
            ],
            [
                'methodName' => 'add',
                '/edit',
                [
                    'controller' => 'posts4',
                    'action'     => 'edit2',
                ],
                'hostname'   => '',
            ],
        ];
    }

    private function getMatchingWithRegexRouterHostPort(): array
    {
        return [
            [
                [
                    'hostname' => 'localhost',
                    'port'     => null,
                    'handle'   => '/edit',
                ],
                'posts3',
            ],
            [
                [
                    'hostname' => 'my.phalcon.io',
                    'port'     => 80,
                    'handle'   => '/edit',
                ],
                'posts',
            ],
            [
                [
                    'hostname' => 'my.phalcon.io',
                    'port'     => 8080,
                    'handle'   => '/edit',
                ],
                'posts',
            ],
            [
                [
                    'hostname' => null,
                    'port'     => 8080,
                    'handle'   => '/edit',
                ],
                'posts3',
            ],
            [
                [
                    'hostname' => 'mail.example.com',
                    'port'     => 9090,
                    'handle'   => '/edit',
                ],
                'posts2',
            ],
            [
                [
                    'hostname' => 'some-domain.com',
                    'port'     => 9000,
                    'handle'   => '/edit',
                ],
                'posts3',
            ],
            [
                [
                    'hostname' => 'some.domain.net',
                    'port'     => 0,
                    'handle'   => '/edit',
                ],
                'posts4',
            ],
        ];
    }

    /**
     * Tests setting host name
     *
     * @author       Andy Gutierrez <andres.gutierrez@phalcon.io>
     * @since        2013-04-15
     *
     * @dataProvider getMatchingWithHostName
     */
    public function shouldReturnCorrectController(IntegrationTester $I, Example $example)
    {
        $pathToRouterData = $this->getDataRouterHostName();

        $param    = $example[0];
        $expected = $example[1];

        $router = $this->getRouterAndSetRoutesAndHostNames(
            $pathToRouterData,
            false
        );

        $_SERVER['HTTP_HOST'] = $param['hostname'];

        $router->handle(
            $param['handle']
        );

        $I->assertEquals(
            $expected,
            $router->getControllerName()
        );
    }

    private function getDataRouterHostName(): array
    {
        return [
            [
                'methodName' => 'add',
                '/edit',
                [
                    'controller' => 'posts3',
                    'action'     => 'edit3',
                ],
            ],
            [
                'methodName' => 'add',
                '/edit',
                [
                    'controller' => 'posts',
                    'action'     => 'edit',
                ],
                'hostname'   => 'my.phalcon.io',
            ],
            [
                'methodName' => 'add',
                '/edit',
                [
                    'controller' => 'posts2',
                    'action'     => 'edit2',
                ],
                'hostname'   => 'my2.phalcon.io',
            ],
        ];
    }

    private function getMatchingWithHostName(): array
    {
        return [
            [
                [
                    'hostname' => 'localhost',
                    'handle'   => '/edit',
                ],
                'posts3',
            ],
            [
                [
                    'hostname' => null,
                    'handle'   => '/edit',
                ],
                'posts3',
            ],
            [
                [
                    'hostname' => 'my.phalcon.io',
                    'handle'   => '/edit',
                ],
                'posts',
            ],
            [
                [
                    'hostname' => 'my2.phalcon.io',
                    'handle'   => '/edit',
                ],
                'posts2',
            ],
        ];
    }

    private function getMatchingWithConverted(): array
    {
        return [
            [
                '/some-controller/my-action-name/this-is-a-country',
                [
                    'controller' => 'somecontroller',
                    'action'     => 'myactionname',
                    'params'     => ['this-is-a-country'],
                ],
            ],

            [
                '/BINARY/1101',
                [
                    'controller' => 'binary',
                    'action'     => 'index',
                    'params'     => [1011],
                ],
            ],
        ];
    }

    private function getMatchingWithPathProvider(): array
    {
        return [
            [
                '/route0',
                'Feed',
                [
                    'controller' => 'feed',
                ],
            ],
            [
                '/route1',
                'Feed::get',
                [
                    'controller' => 'feed',
                    'action'     => 'get',
                ],
            ],
            [
                '/route2',
                'News::Posts::show',
                [
                    'module'     => 'News',
                    'controller' => 'posts',
                    'action'     => 'show',
                ],
            ],
            [
                '/route3',
                'MyApp\Controllers\Posts::show',
                [
                    'namespace'  => 'MyApp\Controllers',
                    'controller' => 'posts',
                    'action'     => 'show',
                ],
            ],
            [
                '/route3',
                'MyApp\Controllers\::show',
                [
                    'controller' => '',
                    'action'     => 'show',
                ],
            ],
            [
                '/route3',
                'News::MyApp\Controllers\Posts::show',
                [
                    'module'     => 'News',
                    'namespace'  => 'MyApp\\Controllers',
                    'controller' => 'posts',
                    'action'     => 'show',
                ],
            ],
            [
                '/route3',
                '\Posts::show',
                [
                    'controller' => 'posts',
                    'action'     => 'show',
                ],
            ],
        ];
    }
}
