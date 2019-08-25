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

use IntegrationTester;
use Phalcon\Events\Manager;
use Phalcon\Mvc\Micro;
use Phalcon\Test\Fixtures\Micro\MyMiddleware;
use Phalcon\Test\Fixtures\Micro\MyMiddlewareStop;
use Phalcon\Test\Fixtures\Micro\RestHandler;

/**
 * Phalcon\Test\Integration\Mvc\MicroTest
 *
 * Tests the Phalcon\Mvc\Micro component
 */
class MicroCest
{
    public function testMicroClass(IntegrationTester $I)
    {
        $handler = new RestHandler();

        $app = new Micro();

        $app->get('/api/site', [$handler, 'find']);
        $app->post('/api/site/save', [$handler, 'save']);
        $app->delete('/api/site/delete/1', [$handler, 'delete']);

        //Getting the url from _url using GET
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $app->handle('/api/site');

        $I->assertEquals(
            1,
            $handler->getNumberAccess()
        );

        $I->assertEquals(
            ['find'],
            $handler->getTrace()
        );

        //Getting the url from _url using POST
        $_SERVER['REQUEST_METHOD'] = 'POST';

        $app->handle('/api/site/save');

        $I->assertEquals(
            2,
            $handler->getNumberAccess()
        );

        $I->assertEquals(
            ['find', 'save'],
            $handler->getTrace()
        );

        //Passing directly a URI
        $_SERVER['REQUEST_METHOD'] = 'DELETE';

        $app->handle('/api/site/delete/1');

        $I->assertEquals(
            3,
            $handler->getNumberAccess()
        );

        $I->assertEquals(
            ['find', 'save', 'delete'],
            $handler->getTrace()
        );
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
            '/blog',
            function () {
            }
        );

        $app->handle('/blog');

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
            '/api/site',
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

        $app->handle('/api/site');

        $I->assertEquals(6, $trace);
    }

    public function testMicroMiddlewareClasses(IntegrationTester $I)
    {
        $app = new Micro();

        $app->map(
            '/api/site',
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

        $app->handle('/api/site');

        $I->assertEquals(
            6,
            $middleware->getNumber()
        );
    }

    public function testMicroStopMiddlewareOnBeforeClasses(IntegrationTester $I)
    {
        $app = new Micro();

        $app->map(
            '/api/site',
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

        $app->handle('/api/site');

        $I->assertEquals(
            1,
            $middleware->getNumber()
        );
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

        $I->assertEquals(
            2,
            $middleware->getNumber()
        );
    }
}
