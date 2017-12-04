<?php
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Test\Unit\Mvc;

use Phalcon\Mvc\Micro;
use Phalcon\Events\Event;
use Phalcon\Events\Manager;
use Phalcon\Di\FactoryDefault;
use Phalcon\Test\Module\UnitTest;

/**
 * Phalcon\Test\Unit\Mvc\MicroTest
 *
 * Tests the Phalcon\Mvc\Micro component
 *
 * @package   Phalcon\Test\Unit\Mvc
 */
class MicroTest extends UnitTest
{
    /**
     * Tests after binding event
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-11-19
     */
    public function testAfterBindingEvent()
    {
        $this->specify(
            'afterBinding event should be fired',
            function () {
                $di = new FactoryDefault();
                $micro = new Micro($di);
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
                expect($micro->handle('/test'))->isEmpty();
            }
        );
    }

    /**
     * Tests after binding middleware
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-11-19
     */
    public function testAfterBindingMiddleware()
    {
        $this->specify(
            'afterBinding middleware should be called',
            function () {
                $di = new FactoryDefault();
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
                expect($micro->handle('/test'))->equals('test');
            }
        );
    }

    public function testStopMiddlewareOnAfterBindingClosure()
    {
        $this->specify(
            "afterBinding middleware doesn't work as expected",
            function () {
                $di = new FactoryDefault();
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
                expect($micro->handle('/test'))->isEmpty();
            }
        );
    }

    public function testStopMiddlewareOnAfterBindingClassFirst()
    {
        $this->specify(
            "afterBinding middleware doesn't work as expected",
            function () {
                $di = new FactoryDefault();
                $micro = new Micro($di);
                $middleware = new \MyMiddleware();
                $middlewareStop = new \MyMiddlewareStop();
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
                expect($micro->handle('/test'))->isEmpty();
                expect($middlewareStop->getNumber())->equals(1);
                expect($middleware->getNumber())->equals(0);
            }
        );
    }

    public function testStopMiddlewareOnAfterBindingClass()
    {
        $this->specify(
            "afterBinding middleware doesn't work as expected",
            function () {
                $di = new FactoryDefault();
                $micro = new Micro($di);
                $middleware = new \MyMiddleware();
                $middlewareStop = new \MyMiddlewareStop();
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
                expect($micro->handle('/test'))->isEmpty();
                expect($middleware->getNumber())->equals(3);
                expect($middlewareStop->getNumber())->equals(1);
            }
        );
    }

    public function testMicroClass()
    {
        $this->specify(
            "MVC Micro doesn't work as expected",
            function () {
                $handler = new \RestHandler();

                $app = new Micro();

                $app->get("/api/site", [$handler, "find"]);
                $app->post("/api/site/save", [$handler, "save"]);
                $app->delete("/api/site/delete/1", [$handler, "delete"]);

                //Getting the url from _url using GET
                $_SERVER["REQUEST_METHOD"] = "GET";
                $_GET["_url"] = "/api/site";

                $app->handle();

                expect($handler->getNumberAccess())->equals(1);
                expect($handler->getTrace())->equals(["find"]);

                //Getting the url from _url using POST
                $_SERVER["REQUEST_METHOD"] = "POST";
                $_GET["_url"] = "/api/site/save";

                $app->handle();

                expect($handler->getNumberAccess())->equals(2);
                expect($handler->getTrace())->equals(["find", "save"]);

                //Passing directly a URI
                $_SERVER["REQUEST_METHOD"] = "DELETE";
                $_GET["_url"] = null;

                $app->handle("/api/site/delete/1");

                expect($handler->getNumberAccess())->equals(3);
                expect($handler->getTrace())->equals(["find", "save", "delete"]);
            }
        );
    }

    /**
     * Tests the notFound
     *
     * @issue T169
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since 2012-11-06
     */
    public function testMicroNotFoundT169()
    {
        $this->specify(
            "MVC Micro notFound doesn't work",
            function () {
                $handler = new \RestHandler();

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
                $_GET["_url"] = "/fourohfour";

                $app->handle();

                expect($flag)->true();
            }
        );
    }

    public function testMicroBeforeHandlers()
    {
        $this->specify(
            "Micro::before event handlers don't work as expected",
            function () {
                $trace = [];

                $app = new Micro();

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

                expect($trace)->count(1);
            }
        );
    }

    public function testMicroAfterHandlers()
    {
        $this->specify(
            "Micro::after event handlers don't work as expected",
            function () {
                $trace = [];

                $app = new Micro();

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

                expect($trace)->count(3);
            }
        );
    }

    public function testMicroAfterHandlersIfOneStop()
    {
        $this->specify(
            "Micro::finish event handlers don't work as expected",
            function () {
                $trace = array();

                $app = new Micro();

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

                expect($trace)->count(3);
            }
        );
    }

    public function testMicroFinishHandlers()
    {
        $this->specify(
            "Micro::finish event handlers don't work as expected",
            function () {
                $trace = [];

                $app = new Micro();

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

                expect($trace)->count(3);
            }
        );
    }

    public function testMicroFinishHandlersIfOneStop()
    {
        $this->specify(
            "Micro::finish event handlers don't work as expected",
            function () {
                $trace = array();

                $app = new Micro();

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

                expect($trace)->count(3);
            }
        );
    }

    public function testMicroEvents()
    {
        $this->specify(
            "Micro event handlers don't work as expected",
            function () {
                $trace = [];

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

                expect($trace)->equals(
                    [
                        'beforeHandleRoute' => true,
                        'beforeExecuteRoute' => true,
                        'afterExecuteRoute' => true,
                        'afterHandleRoute' => true,
                        'afterBinding' => true,
                    ]
                );
            }
        );
    }

    public function testMicroMiddlewareSimple()
    {
        $this->specify(
            "Micro before/after/finish events don't work as expected",
            function () {
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

                expect($trace)->equals(6);
            }
        );
    }

    public function testMicroMiddlewareClasses()
    {
        $this->specify(
            "Micro middleware events don't work as expected",
            function () {
                $app = new Micro();

                $app->map(
                    "/api/site",
                    function () {
                        return true;
                    }
                );

                $middleware = new \MyMiddleware();

                $app->before($middleware);
                $app->before($middleware);

                $app->after($middleware);
                $app->after($middleware);

                $app->finish($middleware);
                $app->finish($middleware);

                $app->handle("/api/site");

                expect($middleware->getNumber())->equals(6);
            }
        );
    }

    public function testMicroStopMiddlewareOnBeforeClasses()
    {
        $this->specify(
            "Micro middleware events don't work as expected",
            function () {
                $app = new Micro();

                $app->map(
                    "/api/site",
                    function () {
                        return true;
                    }
                );

                $middleware = new \MyMiddlewareStop();

                $app->before($middleware);
                $app->before($middleware);

                $app->after($middleware);
                $app->after($middleware);

                $app->finish($middleware);
                $app->finish($middleware);

                $app->handle("/api/site");

                expect($middleware->getNumber())->equals(1);
            }
        );
    }

    public function testMicroStopMiddlewareOnAfterAndFinishClasses()
    {
        $this->specify(
            "Micro middleware events don't work as expected",
            function () {
                $app = new Micro();

                $app->map(
                    '/api/site',
                    function () {
                        return true;
                    }
                );

                $middleware = new \MyMiddlewareStop();

                $app->after($middleware);
                $app->after($middleware);

                $app->finish($middleware);
                $app->finish($middleware);

                $app->handle('/api/site');

                expect($middleware->getNumber())->equals(2);
            }
        );
    }

    public function testMicroResponseAlreadySentError()
    {
        $this->specify(
            "Micro::handle method doesn't work as expected",
            function () {
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
                expect($app->handle('/api'))->equals('success');
            }
        );
    }

    public function testMicroCollectionVia()
    {
        $this->specify(
            "Adding collection via doesn't work as exepected",
            function () {
                $app = new Micro();
                $collection = new Micro\Collection();
                $collection->setHandler(new \Test2Controller());
                $collection->mapVia(
                    "/test",
                    'indexAction',
                    ["POST", "GET"],
                    "test"
                );
                $app->mount($collection);
                expect($app->getRouter()->getRouteByName("test")->getHttpMethods())->equals(["POST", "GET"]);
            }
        );
    }
}
