<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc;

use IntegrationTester;
use Phalcon\Di\FactoryDefault;
use Phalcon\Events\Event;
use Phalcon\Events\Manager;
use Phalcon\Mvc\Micro;
use Phalcon\Test\Controllers\MicroController;
use Phalcon\Test\Fixtures\Micro\MyMiddleware;
use Phalcon\Test\Fixtures\Micro\MyMiddlewareStop;
use Phalcon\Test\Fixtures\Micro\RestHandler;

/**
 * Phalcon\Test\Integration\Mvc\MicroTest
 *
 * Tests the Phalcon\Mvc\Micro component
 *
 * @package   Phalcon\Test\Integration\Mvc
 */
class MicroCest
{
    /**
     * Tests after binding event
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-11-19
     */
    public function testAfterBindingEvent(IntegrationTester $I)
    {
        $di      = new FactoryDefault();
        $micro   = new Micro($di);
        $manager = new Manager();
        $manager->attach(
            'micro:afterBinding',
            function (Event $event, Micro $micro) {
                return false;
            }
        );
        $micro->setEventsManager($manager);
        $micro->get(
            '/test',
            function () {
                return 'test';
            }
        );
        $actual = $micro->handle('/test');
        $I->assertEmpty($actual);
    }

    /**
     * Tests after binding middleware
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-11-19
     */
    public function testAfterBindingMiddleware(IntegrationTester $I)
    {
        $di    = new FactoryDefault();
        $micro = new Micro($di);
        $micro->afterBinding(
            function () {
                return false;
            }
        );
        $micro->get(
            '/test',
            function () {
                return 'test';
            }
        );

        $expected = 'test';
        $actual   = $micro->handle('/test');
        $I->assertEquals($expected, $actual);
    }

    public function testStopMiddlewareOnAfterBindingClosure(IntegrationTester $I)
    {
        $di    = new FactoryDefault();
        $micro = new Micro($di);
        $micro->afterBinding(
            function () use ($micro) {
                $micro->stop();

                return false;
            }
        );
        $micro->get(
            '/test',
            function () {
                return 'test';
            }
        );

        $actual = $micro->handle('/test');
        $I->assertEmpty($actual);
    }

    public function testStopMiddlewareOnAfterBindingClassFirst(IntegrationTester $I)
    {
        $di             = new FactoryDefault();
        $micro          = new Micro($di);
        $middleware     = new MyMiddleware();
        $middlewareStop = new MyMiddlewareStop();
        $micro->afterBinding($middlewareStop);
        $micro->afterBinding($middleware);
        $micro->afterBinding($middleware);
        $micro->afterBinding($middleware);
        $micro->get(
            '/test',
            function () {
                return 'test';
            }
        );
        $actual = $micro->handle('/test');
        $I->assertEmpty($actual);

        $expected = 1;
        $actual   = $middlewareStop->getNumber();
        $I->assertEquals($expected, $actual);

        $expected = 0;
        $actual   = $middleware->getNumber();
        $I->assertEquals($expected, $actual);
    }

    public function testStopMiddlewareOnAfterBindingClass(IntegrationTester $I)
    {
        $di             = new FactoryDefault();
        $micro          = new Micro($di);
        $middleware     = new MyMiddleware();
        $middlewareStop = new MyMiddlewareStop();
        $micro->afterBinding($middleware);
        $micro->afterBinding($middleware);
        $micro->afterBinding($middleware);
        $micro->afterBinding($middlewareStop);
        $micro->afterBinding($middleware);
        $micro->get(
            '/test',
            function () {
                return 'test';
            }
        );
        $actual = $micro->handle('/test');
        $I->assertEmpty($actual);

        $expected = 1;
        $actual   = $middlewareStop->getNumber();
        $I->assertEquals($expected, $actual);

        $expected = 3;
        $actual   = $middleware->getNumber();
        $I->assertEquals($expected, $actual);
    }

    public function testMicroClass(IntegrationTester $I)
    {
        $handler = new RestHandler();

        $app = new Micro();

        $app->get("/api/site", [$handler, "find"]);
        $app->post("/api/site/save", [$handler, "save"]);
        $app->delete("/api/site/delete/1", [$handler, "delete"]);

        //Getting the url from _url using GET
        $_SERVER["REQUEST_METHOD"] = "GET";

        $app->handle("/api/site");

        $expected = 1;
        $actual   = $handler->getNumberAccess();
        $I->assertEquals($expected, $actual);

        $expected = ['find'];
        $actual   = $handler->getTrace();
        $I->assertEquals($expected, $actual);

        //Getting the url from _url using POST
        $_SERVER["REQUEST_METHOD"] = "POST";

        $app->handle("/api/site/save");

        $expected = 2;
        $actual   = $handler->getNumberAccess();
        $I->assertEquals($expected, $actual);

        $expected = ['find', 'save'];
        $actual   = $handler->getTrace();
        $I->assertEquals($expected, $actual);

        //Passing directly a URI
        $_SERVER["REQUEST_METHOD"] = "DELETE";

        $app->handle("/api/site/delete/1");

        $expected = 3;
        $actual   = $handler->getNumberAccess();
        $I->assertEquals($expected, $actual);

        $expected = ['find', 'save', 'delete'];
        $actual   = $handler->getTrace();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the notFound
     *
     * @issue  T169
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-06
     */
    public function testMicroNotFoundT169(IntegrationTester $I)
    {
        $handler = new RestHandler();

        $app = new Micro();

        $app->get("/api/site", [$handler, "find"]);
        $app->post("/api/site/save", [$handler, "save"]);

        $flag = false;

        $app->notFound(
            function () use (&$flag) {
                $flag = true;
            }
        );

        $_SERVER["REQUEST_METHOD"] = "GET";

        $app->handle("/fourohfour");

        $I->assertTrue($flag);
    }

    public function testMicroBeforeHandlers(IntegrationTester $I)
    {
        $trace = [];
        $app   = new Micro();

        $app->before(
            function () use ($app, &$trace) {
                $trace[] = 1;
                $app->stop();

                return false;
            }
        );

        $app->before(
            function () use ($app, &$trace) {
                $trace[] = 1;
                $app->stop();

                return false;
            }
        );

        $app->map(
            "/blog",
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->handle("/blog");
        $I->assertCount(1, $trace);
    }

    public function testMicroAfterHandlers(IntegrationTester $I)
    {
        $trace = [];
        $app   = new Micro();

        $app->after(
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->after(
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->map(
            "/blog",
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->handle("/blog");
        $I->assertCount(3, $trace);
    }

    public function testMicroAfterHandlersIfOneStop(IntegrationTester $I)
    {
        $trace = [];
        $app   = new Micro();

        $app->after(
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->after(
            function () use ($app, &$trace) {
                $trace[] = 1;
                $app->stop();
            }
        );

        $app->after(
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->map(
            '/blog',
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->handle('/blog');
        $I->assertCount(3, $trace);
    }

    public function testMicroFinishHandlers(IntegrationTester $I)
    {
        $trace = [];
        $app   = new Micro();

        $app->finish(
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->finish(
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->map(
            "/blog",
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->handle("/blog");
        $I->assertCount(3, $trace);
    }

    public function testMicroFinishHandlersIfOneStop(IntegrationTester $I)
    {
        $trace = [];
        $app   = new Micro();

        $app->finish(
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->finish(
            function () use ($app, &$trace) {
                $trace[] = 1;
                $app->stop();
            }
        );

        $app->finish(
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->map(
            '/blog',
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->handle('/blog');
        $I->assertCount(3, $trace);
    }

    public function testMicroEvents(IntegrationTester $I)
    {
        $trace         = [];
        $eventsManager = new Manager();

        $eventsManager->attach(
            'micro',
            function ($event) use (&$trace) {
                $trace[$event->getType()] = true;
            }
        );

        $app = new Micro();

        $app->setEventsManager($eventsManager);

        $app->map(
            "/blog",
            function () {
            }
        );

        $app->handle("/blog");

        $expected = [
            'beforeHandleRoute'  => true,
            'beforeExecuteRoute' => true,
            'afterExecuteRoute'  => true,
            'afterHandleRoute'   => true,
            'afterBinding'       => true,
        ];
        $I->assertEquals($expected, $trace);
    }

    public function testMicroMiddlewareSimple(IntegrationTester $I)
    {
        $app = new Micro();
        $app->map(
            "/api/site",
            function () {
                return true;
            }
        );

        $trace = 0;

        $app->before(
            function () use (&$trace) {
                $trace++;
            }
        );

        $app->before(
            function () use (&$trace) {
                $trace++;
            }
        );

        $app->after(
            function () use (&$trace) {
                $trace++;
            }
        );

        $app->after(
            function () use (&$trace) {
                $trace++;
            }
        );

        $app->finish(
            function () use (&$trace) {
                $trace++;
            }
        );

        $app->finish(
            function () use (&$trace) {
                $trace++;
            }
        );
        $app->handle("/api/site");
        $I->assertEquals(6, $trace);
    }

    public function testMicroMiddlewareClasses(IntegrationTester $I)
    {
        $app = new Micro();

        $app->map(
            "/api/site",
            function () {
                return true;
            }
        );

        $middleware = new MyMiddleware();

        $app->before($middleware);
        $app->before($middleware);

        $app->after($middleware);
        $app->after($middleware);

        $app->finish($middleware);
        $app->finish($middleware);

        $app->handle("/api/site");

        $actual = $middleware->getNumber();
        $I->assertEquals(6, $actual);
    }

    public function testMicroStopMiddlewareOnBeforeClasses(IntegrationTester $I)
    {
        $app = new Micro();
        $app->map(
            "/api/site",
            function () {
                return true;
            }
        );

        $middleware = new MyMiddlewareStop();

        $app->before($middleware);
        $app->before($middleware);

        $app->after($middleware);
        $app->after($middleware);

        $app->finish($middleware);
        $app->finish($middleware);

        $app->handle("/api/site");

        $actual = $middleware->getNumber();
        $I->assertEquals(1, $actual);
    }

    public function testMicroStopMiddlewareOnAfterAndFinishClasses(IntegrationTester $I)
    {
        $app = new Micro();
        $app->map(
            '/api/site',
            function () {
                return true;
            }
        );

        $middleware = new MyMiddlewareStop();

        $app->after($middleware);
        $app->after($middleware);

        $app->finish($middleware);
        $app->finish($middleware);

        $app->handle('/api/site');

        $actual = $middleware->getNumber();
        $I->assertEquals(2, $actual);
    }

    public function testMicroResponseAlreadySentError(IntegrationTester $I)
    {
        $app = new Micro();
        $app->after(
            function () use ($app) {
                $content = $app->getReturnedValue();
                $app->response->setJsonContent($content)->send();
            }
        );
        $app->map(
            '/api',
            function () {
                return 'success';
            }
        );

        $expected = 'success';
        $actual   = $app->handle('/api');
        $I->assertEquals($expected, $actual);
    }

    public function testMicroCollectionVia(IntegrationTester $I)
    {
        $app        = new Micro();
        $collection = new Micro\Collection();
        $collection->setHandler(new MicroController());
        $collection->mapVia(
            "/test",
            'indexAction',
            ["POST", "GET"],
            "test"
        );
        $app->mount($collection);

        $expected = ["POST", "GET"];
        $actual   = $app->getRouter()->getRouteByName("test")->getHttpMethods();
        $I->assertEquals($expected, $actual);
    }

    public function testMicroResponseHandler(IntegrationTester $I)
    {
        $trace = [];
        $app   = new Micro();
        $app->setResponseHandler(
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->map(
            "/blog",
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->handle("/blog");

        $I->assertCount(2, $trace);
    }
}
