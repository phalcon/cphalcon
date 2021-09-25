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

namespace Phalcon\Tests\Integration\Mvc\Dispatcher;

use IntegrationTester;
use Phalcon\Dispatcher\Exception;
use Phalcon\Tests\Integration\Mvc\Dispatcher\Helper\BaseDispatcher;
use Phalcon\Tests\Integration\Mvc\Dispatcher\Helper\DispatcherTestDefaultController;

class DispatchCest extends BaseDispatcher
{
    /**
     * Tests Phalcon\Mvc\Dispatcher :: dispatch()
     * Tests the default order of dispatch events for basic execution
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testDefaultDispatchLoopEvents(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Dispatcher - dispatch()');

        $dispatcher = $this->getDispatcher();

        $handler = $dispatcher->dispatch();

        $I->assertEquals(
            'Phalcon\Tests\Integration\Mvc\Dispatcher\Helper',
            $dispatcher->getNamespaceName()
        );

        $I->assertEquals(
            'dispatcher-test-default',
            $dispatcher->getControllerName()
        );

        $I->assertEquals(
            'index',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            DispatcherTestDefaultController::class,
            $dispatcher->getControllerClass()
        );

        $I->assertFalse(
            $dispatcher->wasForwarded()
        );

        $I->assertInstanceOf(
            DispatcherTestDefaultController::class,
            $handler
        );

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

        $I->assertEquals(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * Tests handler not found
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testHandlerNotFound(IntegrationTester $I)
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->setControllerName('Non-Existent-Dispatcher-Handler');

        $I->expectThrowable(
            new Exception(
                'Phalcon\Tests\Integration\Mvc\Dispatcher\Helper\Non' .
                'ExistentDispatcherHandlerController handler class cannot be loaded',
                Exception::EXCEPTION_HANDLER_NOT_FOUND
            ),
            function () use ($dispatcher) {
                $dispatcher->dispatch();
            }
        );
    }

    /**
     * Tests invalid handler action specified
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testHandlerActionNotFound(IntegrationTester $I)
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->setActionName('Invalid-Dispatcher-Action-Name');

        $I->expectThrowable(
            new Exception(
                "Action 'Invalid-Dispatcher-Action-Name' was not found on handler 'dispatcher-test-default'",
                Exception::EXCEPTION_ACTION_NOT_FOUND
            ),
            function () use ($dispatcher) {
                $dispatcher->dispatch();
            }
        );
    }
}
