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
use UnitTester;

class CallActionMethodCest
{
    private bool $wasCalled = false;
    private bool $altCalled = false;
    private string $paramCalled = '';

    public function _before(UnitTester $I)
    {
        $this->wasCalled = false;
        $this->altCalled = false;
        $this->paramCalled = '';
    }

    /**
     * Tests Phalcon\Dispatcher :: callActionMethod()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2025-01-06
     */
    public function dispatcherCallActionMethod(UnitTester $I)
    {
        $I->wantToTest('Dispatcher - callActionMethod()');

        $dispatcher = new Dispatcher();

        $dispatcher->callActionMethod(
            $this,
            '_wasCalled'
        );

        $I->assertTrue($this->wasCalled);
        $I->assertFalse($this->altCalled);
    }

    /**
     * Tests Phalcon\Dispatcher :: callActionMethod()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2025-01-06
     */
    public function dispatcherCallActionMethodWithParams(UnitTester $I)
    {
        $I->wantToTest('Dispatcher - callActionMethod() - Params');

        $dispatcher = new Dispatcher();

        $dispatcher->callActionMethod(
            $this,
            '_paramCalled',
            [
                'something' => 'else'
            ]
        );

        $I->assertFalse($this->wasCalled);
        $I->assertFalse($this->altCalled);
        $I->assertEquals('else', $this->paramCalled);

        $dispatcher->callActionMethod(
            $this,
            '_paramCalled',
            [
                'something'
            ]
        );

        $I->assertFalse($this->wasCalled);
        $I->assertFalse($this->altCalled);
        $I->assertEquals('something', $this->paramCalled);
    }

    /**
     * Tests Phalcon\Dispatcher :: callActionMethod() Events
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2025-01-06
     */
    public function dispatcherCallActionMethodWithEvents(UnitTester $I)
    {
        $I->wantToTest('Dispatcher - callActionMethod() - Events');

        $eventsManager = new Manager();
        $eventsManager->attach(
            'dispatch:beforeCallAction',
            function (Event $event, Dispatcher $dispatcher, Collection $observer) {
                $observer->action = "_altCalled";
            }
        );

        $dispatcher = new Dispatcher();
        $dispatcher->setEventsManager($eventsManager);
        $dispatcher->setDi(new Di());

        $dispatcher->callActionMethod(
            $this,
            '_wasCalled'
        );

        $I->assertTrue($this->altCalled);
        $I->assertFalse($this->wasCalled);
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
