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

namespace Phalcon\Tests\Unit\Dispatcher;

use Phalcon\Di\Di;
use Phalcon\Events\Event;
use Phalcon\Events\Manager;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Support\Collection;
use Phalcon\Tests\AbstractUnitTestCase;

final class CallActionMethodTest extends AbstractUnitTestCase
{
    private bool $wasCalled = false;
    private bool $altCalled = false;
    private string $paramCalled = '';

    protected function setUp(): void
    {
        $this->wasCalled  = false;
        $this->altCalled  = false;
        $this->paramCalled = '';
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-01-06
     */
    public function testDispatcherCallActionMethod(): void
    {
        $dispatcher = new Dispatcher();

        $dispatcher->callActionMethod($this, '_wasCalled');

        $this->assertTrue($this->wasCalled);
        $this->assertFalse($this->altCalled);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-01-06
     */
    public function testDispatcherCallActionMethodWithParams(): void
    {
        $dispatcher = new Dispatcher();

        $dispatcher->callActionMethod(
            $this,
            '_paramCalled',
            ['something' => 'else']
        );

        $this->assertFalse($this->wasCalled);
        $this->assertFalse($this->altCalled);
        $expected = 'else';
        $actual   = $this->paramCalled;
        $this->assertEquals($expected, $actual);

        $dispatcher->callActionMethod(
            $this,
            '_paramCalled',
            ['something']
        );

        $this->assertFalse($this->wasCalled);
        $this->assertFalse($this->altCalled);
        $expected = 'something';
        $actual   = $this->paramCalled;
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-01-06
     */
    public function testDispatcherCallActionMethodWithEvents(): void
    {
        $eventsManager = new Manager();
        $eventsManager->attach(
            'dispatch:beforeCallAction',
            function (Event $event, Dispatcher $dispatcher, Collection $observer) {
                $observer->action = '_altCalled';
            }
        );

        $dispatcher = new Dispatcher();
        $dispatcher->setEventsManager($eventsManager);
        $dispatcher->setDi(new Di());

        $dispatcher->callActionMethod($this, '_wasCalled');

        $this->assertTrue($this->altCalled);
        $this->assertFalse($this->wasCalled);
    }

    public function _wasCalled(): void
    {
        $this->wasCalled = true;
    }

    public function _altCalled(): void
    {
        $this->altCalled = true;
    }

    public function _paramCalled(string $param): void
    {
        $this->paramCalled = $param;
    }
}
