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

namespace Phalcon\Tests\Unit\Mvc\Micro;

use Phalcon\Di\FactoryDefault;
use Phalcon\Events\Event;
use Phalcon\Events\Manager;
use Phalcon\Mvc\Micro;
use Phalcon\Tests\Support\Micro\MyMiddleware;
use Phalcon\Tests\Support\Micro\MyMiddlewareStop;
use Phalcon\Tests\AbstractUnitTestCase;

class AfterBindingTest extends AbstractUnitTestCase
{
    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-11-19
     */
    public function testAfterBindingEvent(): void
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

        $_SERVER['REQUEST_METHOD'] = 'GET';

        $actual = $micro->handle('/test');
        $this->assertEmpty($actual);
    }

    /**
     * Tests after binding middleware
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-11-19
     */
    public function testAfterBindingMiddleware(): void
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

        $_SERVER['REQUEST_METHOD'] = 'GET';

        // Micro echoes out its result as well
        ob_start();
        $actual = $micro->handle('/test');
        ob_end_clean();

        $this->assertEquals('test', $actual);
    }

    public function testStopMiddlewareOnAfterBindingClass(): void
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

        $_SERVER['REQUEST_METHOD'] = 'GET';

        $actual = $micro->handle('/test');
        $this->assertEmpty($actual);

        $expected = 1;
        $actual   = $middlewareStop->getNumber();
        $this->assertEquals($expected, $actual);

        $expected = 3;
        $actual   = $middleware->getNumber();
        $this->assertEquals($expected, $actual);
    }

    public function testStopMiddlewareOnAfterBindingClassFirst(): void
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

        $_SERVER['REQUEST_METHOD'] = 'GET';

        $actual = $micro->handle('/test');
        $this->assertEmpty($actual);

        $expected = 1;
        $actual   = $middlewareStop->getNumber();
        $this->assertEquals($expected, $actual);

        $expected = 0;
        $actual   = $middleware->getNumber();
        $this->assertEquals($expected, $actual);
    }

    public function testStopMiddlewareOnAfterBindingClosure(): void
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

        $_SERVER['REQUEST_METHOD'] = 'GET';

        $actual = $micro->handle('/test');
        $this->assertEmpty($actual);
    }
}
