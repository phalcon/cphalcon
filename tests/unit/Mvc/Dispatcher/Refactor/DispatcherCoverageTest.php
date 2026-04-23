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
use Phalcon\Dispatcher\Exception as DispatcherException;
use Phalcon\Mvc\Dispatcher\Exception as MvcException;
use Phalcon\Mvc\Model\BinderInterface;
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\BaseDispatcher;
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\DispatcherTestAfterBindingForwardController;
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\DispatcherTestAfterBindingReturnFalseController;
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\DispatcherTestDefaultController;
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\DispatcherTestDefaultTwoController;

/**
 * Tests covering remaining branches in AbstractDispatcher::dispatch().
 */
class DispatcherCoverageTest extends BaseDispatcher
{
    /**
     * Tests cyclic routing detection — exception thrown path (L289-293).
     *
     * The dispatcher forwards on every beforeDispatch event; after 256
     * iterations it detects the cycle and throws EXCEPTION_CYCLIC_ROUTING.
     *
     * @return void
     */
    public function testCyclicRoutingExceptionThrown(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeDispatch',
            function ($event, $disp) {
                $disp->forward(['action' => 'index2']);
            }
        );

        $this->expectException(MvcException::class);
        $this->expectExceptionMessage(
            'Dispatcher has detected a cyclic routing causing stability problems'
        );
        $this->expectExceptionCode(DispatcherException::EXCEPTION_CYCLIC_ROUTING);

        $dispatcher->dispatch();
    }

    /**
     * Tests cyclic routing detection — exception suppressed path (L289-295).
     *
     * When the beforeException listener returns false the exception is not
     * thrown and dispatch() reaches the break at L295.
     *
     * @return void
     */
    public function testCyclicRoutingEventReturnsFalse(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeDispatch',
            function ($event, $disp) {
                $disp->forward(['action' => 'index2']);
            }
        );

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeException',
            function () {
                return false;
            }
        );

        // No exception; dispatch returns null because handler was never set
        $result = $dispatcher->dispatch();
        $this->assertNull($result);
    }

    /**
     * Tests invalid handler (not an object) — exception thrown path (L359-362).
     *
     * @return void
     */
    public function testInvalidHandlerExceptionThrown(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->setNamespaceName('');
        $dispatcher->setControllerName('Test');

        $this->getDI()->set(
            $dispatcher->getHandlerClass(),
            function () {
                return 'not-an-object';
            }
        );

        $this->expectException(MvcException::class);
        $this->expectExceptionMessage(
            'Invalid handler returned from the services container'
        );
        $this->expectExceptionCode(DispatcherException::EXCEPTION_INVALID_HANDLER);

        $dispatcher->dispatch();
    }

    /**
     * Tests invalid handler (not an object) — event returns false, break path
     * (L359-362, L368).
     *
     * When the beforeException listener returns false and $this->finished is
     * still true, dispatch() reaches the break at L368 and exits the loop.
     *
     * @return void
     */
    public function testInvalidHandlerEventReturnsFalseBreak(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->setNamespaceName('');
        $dispatcher->setControllerName('Test');

        $this->getDI()->set(
            $dispatcher->getHandlerClass(),
            function () {
                return 'not-an-object';
            }
        );

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeException',
            function () {
                return false;
            }
        );

        // No exception; dispatch() break'd and returns the non-object handler string
        $result = $dispatcher->dispatch();
        $this->assertSame('not-an-object', $result);
    }

    /**
     * Tests action not found — beforeNotFoundAction returns false path (L390).
     *
     * When the beforeNotFoundAction event returns false, the loop continues
     * with $this->finished still true, which causes the while condition to
     * fail and dispatch() returns the loaded handler.
     *
     * @return void
     */
    public function testActionNotFoundBeforeNotFoundEventReturnsFalse(): void
    {
        $dispatcher = $this->getDispatcher();
        $dispatcher->setActionName('non-existent-action');

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeNotFoundAction',
            function () {
                return false;
            }
        );

        // The continue at L390 causes the while loop to exit (finished=true).
        // dispatch() returns the loaded controller instance.
        $handler = $dispatcher->dispatch();

        $this->assertInstanceOf(DispatcherTestDefaultController::class, $handler);
    }

    /**
     * Tests action not found — beforeNotFoundAction forwards (L394).
     *
     * When the beforeNotFoundAction event forwards to a valid action, finished
     * becomes false and the continue at L394 causes the loop to restart with
     * the new action.
     *
     * @return void
     */
    public function testActionNotFoundBeforeNotFoundEventForwards(): void
    {
        $dispatcher = $this->getDispatcher();
        $dispatcher->setActionName('non-existent-action');

        $forwarded = false;

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeNotFoundAction',
            function ($event, $disp) use (&$forwarded) {
                if (!$forwarded) {
                    $forwarded = true;
                    $disp->forward(['action' => 'index']);
                }
            }
        );

        // After forward, finished=false triggers continue at L394.
        // Next iteration dispatches indexAction successfully.
        $handler = $dispatcher->dispatch();

        $this->assertInstanceOf(DispatcherTestDefaultController::class, $handler);
        $this->assertTrue($forwarded);
    }

    /**
     * Tests action not found — exception suppressed, break path (L408-412).
     *
     * When beforeException returns false and $this->finished is true,
     * dispatch() reaches the break at L412.
     *
     * @return void
     */
    public function testActionNotFoundExceptionSuppressedBreaks(): void
    {
        $dispatcher = $this->getDispatcher();
        $dispatcher->setActionName('non-existent-action');

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeException',
            function () {
                return false;
            }
        );

        // break at L412; $handler (controller) is returned
        $result = $dispatcher->dispatch();
        $this->assertInstanceOf(DispatcherTestDefaultController::class, $result);
    }

    /**
     * Tests action not found — exception suppressed + forward, continue path
     * (L408-409).
     *
     * When beforeException returns false AND forwards (finished=false), dispatch
     * hits the continue at L408-409 and the next iteration completes normally.
     *
     * @return void
     */
    public function testActionNotFoundExceptionSuppressedForwardContinues(): void
    {
        $dispatcher = $this->getDispatcher();
        $dispatcher->setActionName('non-existent-action');

        $forwarded = false;

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeException',
            function ($event, $disp) use (&$forwarded) {
                if (!$forwarded) {
                    $forwarded = true;
                    $disp->forward(['action' => 'index']);
                }

                return false;
            }
        );

        $handler = $dispatcher->dispatch();

        $this->assertInstanceOf(DispatcherTestDefaultController::class, $handler);
    }

    /**
     * Tests afterBinding event returns false (L564).
     *
     * When the dispatch:afterBinding event listener returns false, the continue
     * at L564 is executed and (with finished=true) the loop exits returning the
     * loaded handler.
     *
     * @return void
     */
    public function testAfterBindingEventReturnsFalse(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->getEventsManager()->attach(
            'dispatch:afterBinding',
            function () {
                return false;
            }
        );

        // continue at L564 exits the loop (finished=true)
        $handler = $dispatcher->dispatch();

        $this->assertInstanceOf(DispatcherTestDefaultController::class, $handler);
    }

    /**
     * Tests afterBinding event with forward (L571).
     *
     * When the dispatch:afterBinding event forwards (finished=false) the
     * continue at L571 is executed; the next iteration completes normally.
     *
     * @return void
     */
    public function testAfterBindingEventForwards(): void
    {
        $dispatcher = $this->getDispatcher();

        $forwarded = false;

        $dispatcher->getEventsManager()->attach(
            'dispatch:afterBinding',
            function ($event, $disp) use (&$forwarded) {
                if (!$forwarded) {
                    $forwarded = true;
                    $disp->forward(['action' => 'index2']);
                }
            }
        );

        $handler = $dispatcher->dispatch();

        $this->assertInstanceOf(DispatcherTestDefaultController::class, $handler);
        $this->assertTrue($forwarded);
    }

    /**
     * Tests afterBinding method returns false (L579-580).
     *
     * When the controller's afterBinding() method returns false, dispatch()
     * continues (loop exits because finished=true) and returns the handler.
     *
     * @return void
     */
    public function testAfterBindingMethodReturnsFalse(): void
    {
        $dispatcher = $this->getDispatcher();
        $dispatcher->setControllerName('dispatcher-test-after-binding-return-false');

        // continue at L580 exits the loop (finished=true)
        $handler = $dispatcher->dispatch();

        $this->assertInstanceOf(
            DispatcherTestAfterBindingReturnFalseController::class,
            $handler
        );
    }

    /**
     * Tests action execution exception — exception suppressed, continue path
     * (L609-614).
     *
     * When the action throws and beforeException returns false, handleException
     * returns false → the continue at L614 is executed.
     *
     * @return void
     */
    public function testActionExceptionSuppressedByContinue(): void
    {
        $dispatcher = $this->getDispatcher();
        $dispatcher->setActionName('exception');

        $forwarded = false;

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeException',
            function ($event, $disp) use (&$forwarded) {
                if (!$forwarded) {
                    $forwarded = true;
                    $disp->forward(
                        [
                            'controller' => 'dispatcher-test-default-two',
                            'action'     => 'index',
                        ]
                    );
                }

                return false;
            }
        );

        $handler = $dispatcher->dispatch();

        $this->assertInstanceOf(DispatcherTestDefaultTwoController::class, $handler);
    }

    /**
     * Tests action execution exception — exception bubbles (L609, L617).
     *
     * When the action throws and the beforeException listener does not return
     * false, the exception is re-thrown at L617.
     *
     * @return void
     */
    public function testActionExceptionBubbles(): void
    {
        $dispatcher = $this->getDispatcher();
        $dispatcher->setActionName('exception');

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('An exception occurred.');

        $dispatcher->dispatch();
    }

    /**
     * Tests invalid handler — exception suppressed + forward, continue path
     * (L365).
     *
     * When beforeException returns false AND forwards (finished=false), dispatch
     * hits the continue at L365 and the next iteration loads a valid controller.
     *
     * @return void
     */
    public function testInvalidHandlerExceptionSuppressedForwardContinues(): void
    {
        $dispatcher = $this->getDispatcher();
        $dispatcher->setControllerName('invalid-for-coverage');

        $handlerClass = $dispatcher->getHandlerClass();

        $this->getDI()->set(
            $handlerClass,
            function () {
                return 'not-an-object';
            }
        );

        $count = 0;

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeException',
            function ($event, $disp) use (&$count) {
                $count++;

                if ($count === 1) {
                    $disp->forward(
                        [
                            'controller' => 'dispatcher-test-default',
                            'action'     => 'index',
                        ]
                    );
                }

                return false;
            }
        );

        // continue at L365 restarts the loop with the valid controller
        $handler = $dispatcher->dispatch();

        $this->assertInstanceOf(DispatcherTestDefaultController::class, $handler);
        $this->assertSame(1, $count);
    }

    /**
     * Tests model binding block (L548-556).
     *
     * When $this->modelBinding is true, the model binder is invoked to
     * potentially replace the dispatched parameters before action execution.
     *
     * @return void
     */
    public function testModelBindingBlockExecuted(): void
    {
        $dispatcher = $this->getDispatcher();

        $binder = new class implements BinderInterface {
            private ?\Phalcon\Cache\Adapter\AdapterInterface $cache = null;

            public function bindToHandler(
                $handler,
                array $params,
                string $cacheKey,
                string | null $methodName = null
            ): array {
                return $params;
            }

            public function getBoundModels(): array
            {
                return [];
            }

            public function getCache(): \Phalcon\Cache\Adapter\AdapterInterface
            {
                return $this->cache;
            }

            public function setCache(\Phalcon\Cache\Adapter\AdapterInterface $cache): BinderInterface
            {
                $this->cache = $cache;

                return $this;
            }
        };

        $dispatcher->setModelBinder($binder);

        $handler = $dispatcher->dispatch();

        $this->assertInstanceOf(DispatcherTestDefaultController::class, $handler);
    }

    /**
     * Tests afterBinding method with forward (L586-587).
     *
     * When the controller's afterBinding() method forwards (sets finished=false),
     * the continue at L586-587 causes the loop to restart and dispatch the
     * forwarded action.
     *
     * @return void
     */
    public function testAfterBindingMethodForwards(): void
    {
        $dispatcher = $this->getDispatcher();
        $dispatcher->setControllerName('dispatcher-test-after-binding-forward');

        $handler = $dispatcher->dispatch();

        $this->assertInstanceOf(
            DispatcherTestAfterBindingForwardController::class,
            $handler
        );
    }
}
