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

namespace Phalcon\Tests\Unit\Mvc\Dispatcher;

use Phalcon\Dispatcher\Exception;
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\BaseDispatcher;
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\DispatcherTestDefaultController;

class DispatchTest extends BaseDispatcher
{
    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testDefaultDispatchLoopEvents(): void
    {
        $dispatcher = $this->getDispatcher();

        $handler = $dispatcher->dispatch();

        $this->assertEquals(
            'Phalcon\Tests\Unit\Mvc\Dispatcher\Helper',
            $dispatcher->getNamespaceName()
        );

        $this->assertEquals(
            'dispatcher-test-default',
            $dispatcher->getControllerName()
        );

        $this->assertEquals(
            'index',
            $dispatcher->getActionName()
        );

        $this->assertEquals(
            DispatcherTestDefaultController::class,
            $dispatcher->getControllerClass()
        );

        $this->assertFalse(
            $dispatcher->wasForwarded()
        );

        $this->assertInstanceOf(
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

        $this->assertEquals(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testHandlerActionNotFound(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->setActionName('Invalid-Dispatcher-Action-Name');

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Action 'Invalid-Dispatcher-Action-Name' was not found "
            . "on handler 'dispatcher-test-default'"
        );
        $this->expectExceptionCode(Exception::EXCEPTION_ACTION_NOT_FOUND);

        $dispatcher->dispatch();
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testHandlerNotFound(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->setControllerName('Non-Existent-Dispatcher-Handler');

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\Non' .
            'ExistentDispatcherHandlerController handler class cannot be loaded'
        );
        $this->expectExceptionCode(Exception::EXCEPTION_HANDLER_NOT_FOUND);

        $dispatcher->dispatch();
    }
}
