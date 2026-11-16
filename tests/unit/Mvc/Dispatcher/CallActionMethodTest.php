<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Mvc\Dispatcher;

use Phalcon\Mvc\Dispatcher;
use Phalcon\Tests\Support\Traits\ErrorHandlerTrait;
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\BaseDispatcher;
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\DispatcherTestDefaultController;

class CallActionMethodTest extends BaseDispatcher
{
    use ErrorHandlerTrait;

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testMvcDispatcherCallActionMethod(): void
    {
        $multiply = [5, 6];

        $controller = new DispatcherTestDefaultController();

        $controller->setDI(
            $this->getDI()
        );

        $returnValue = $this->getDispatcher()->callActionMethod(
            $controller,
            'multiplyAction',
            $multiply
        );

        $this->assertEquals(30, $returnValue);

        $this->assertEquals(
            ['multiplyAction'],
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * An action that cannot be called gives a warning and null, the same as
     * cphalcon. With no events manager, nothing checks the action before
     * the call.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/815
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testMvcDispatcherCallActionMethodNotCallable(): void
    {
        $dispatcher = new Dispatcher();
        $controller = new DispatcherTestDefaultController();

        [$actual, $messages] = $this->collectErrors(
            static fn () => $dispatcher->callActionMethod($controller, 'unknownAction', [])
        );

        $this->assertNull($actual);
        $this->assertSame(
            ['class ' . DispatcherTestDefaultController::class . ' does not have a method "unknownAction"'],
            $messages
        );
    }
}
