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
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\BaseDispatcher;
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\DispatcherTestDefaultController;
use TypeError;

class CallActionMethodTest extends BaseDispatcher
{
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
     * An action that cannot be called throws the TypeError of
     * call_user_func_array(). With no events manager, nothing checks the
     * action before the call.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/815
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testMvcDispatcherCallActionMethodNotCallable(): void
    {
        $dispatcher = new Dispatcher();
        $controller = new DispatcherTestDefaultController();

        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(
            'call_user_func_array(): Argument #1 ($callback) must be a valid callback, '
            . 'class ' . DispatcherTestDefaultController::class . ' does not have a method "unknownAction"'
        );

        $dispatcher->callActionMethod($controller, 'unknownAction', []);
    }
}
