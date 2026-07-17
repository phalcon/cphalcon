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

namespace Phalcon\Tests\Unit\Mvc\Dispatcher\Refactor;

use Exception;
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\BaseDispatcher;

/**
 * @todo    : refactor
 */
class DispatcherBeforeDispatchLoopTest extends BaseDispatcher
{
    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeDispatchLoopBaselinePrePhalcon50MultipleReturnFalse(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeDispatchLoop',
            function () {
                return false;
            }
        );

        // Unfortunately, we really need to collect all responses or use the Event stopping property
        // instead of return <tt>false</tt>. The following statement breaks the ability to stop the chain.
        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeDispatchLoop',
            function () {
                return false;
            }
        );

        $dispatcher->dispatch();


        $expected = [
            'beforeDispatchLoop',
        ];

        $actual = $this->getDispatcherListener()->getTrace();

        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeDispatchLoopBaselinePrePhalcon50MultipleReturnFalseMixed(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeDispatchLoop',
            function () {
                return false;
            }
        );

        // Unfortunately, we really need to collect all responses or use the Event stopping property
        // instead of return <tt>false</tt>. The following statement breaks the ability to stop the chain.

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeDispatchLoop',
            function () {
                return true;
            }
        );

        $dispatcher->dispatch();

        $expected = [
            'beforeDispatchLoop',
            'beforeDispatch',
            'beforeExecuteRoute',
            'beforeExecuteRoute-method',
            'initialize-method',
            'afterInitialize',
            'indexAction',
            'afterExecuteRoute',
            'afterExecuteRoute-method',
            'afterDispatch',
            'afterDispatchLoop',
        ];

        $actual = $this->getDispatcherListener()->getTrace();

        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeDispatchLoopForward(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeDispatchLoop',
            function ($event, $dispatcher) {
                $dispatcher->forward(
                    [
                        'action' => 'index2',
                    ]
                );
            }
        );

        $dispatcher->dispatch();

        $expected = [
            'beforeDispatchLoop',
            'beforeDispatch',
            'beforeExecuteRoute',
            'beforeExecuteRoute-method',
            'initialize-method',
            'afterInitialize',
            'index2Action',
            'afterExecuteRoute',
            'afterExecuteRoute-method',
            'afterDispatch',
            'afterDispatchLoop',
        ];

        $actual = $this->getDispatcherListener()->getTrace();

        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeDispatchLoopReturnFalse(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeDispatchLoop',
            function () {
                return false;
            }
        );

        $dispatcher->dispatch();

        $expected = [
            'beforeDispatchLoop',
        ];

        $actual = $this->getDispatcherListener()->getTrace();

        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeDispatchLoopWithBeforeExceptionBubble(): void
    {
        $dispatcher         = $this->getDispatcher();
        $dispatcherListener = $this->getDispatcherListener();

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeDispatchLoop',
            function () {
                throw new Exception('beforeDispatchLoop exception occurred');
            }
        );

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeException',
            function () use ($dispatcherListener) {
                $dispatcherListener->trace('beforeException: custom before exception bubble');

                return null;
            }
        );

        $this->expectException(Exception::class);

        $dispatcher->dispatch();

        $expected = [
            'beforeDispatchLoop',
            'beforeException: beforeDispatchLoop exception occurred',
            'beforeException: custom before exception bubble',
        ];
        $actual   = $this->getDispatcherListener()->getTrace();
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeDispatchLoopWithBeforeExceptionForward(): void
    {
        $dispatcher         = $this->getDispatcher();
        $dispatcherListener = $this->getDispatcherListener();

        $dispatcher->getEventsManager()->attach('dispatch:beforeDispatchLoop', function () {
            throw new Exception('beforeDispatchLoop exception occurred');
        });
        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeException',
            function ($event, $dispatcher) use ($dispatcherListener) {
                $dispatcherListener->trace(
                    'beforeException: custom before exception forward'
                );

                $dispatcher->forward(
                    [
                        'action' => 'index2',
                    ]
                );
            }
        );

        $dispatcher->dispatch();

        $expected = [
            'beforeDispatchLoop',
            'beforeException: beforeDispatchLoop exception occurred',
            'beforeException: custom before exception forward',
            'beforeDispatch',
            'beforeExecuteRoute',
            'beforeExecuteRoute-method',
            'initialize-method',
            'afterInitialize',
            'index2Action',
            'afterExecuteRoute',
            'afterExecuteRoute-method',
            'afterDispatch',
            'afterDispatchLoop',
        ];
        $actual   = $this->getDispatcherListener()->getTrace();
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeDispatchLoopWithBeforeExceptionReturningFalse(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeDispatchLoop',
            function () {
                throw new Exception('beforeDispatchLoop exception occurred');
            }
        );

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeException',
            function () {
                return false;
            }
        );

        $dispatcher->dispatch();


        $expected = [
            'beforeDispatchLoop',
            'beforeException: beforeDispatchLoop exception occurred',
        ];

        $actual = $this->getDispatcherListener()->getTrace();

        $this->assertEquals($expected, $actual);
    }
}
