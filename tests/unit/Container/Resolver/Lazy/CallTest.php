<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Resolver\Lazy;

use Phalcon\Container\Resolver\Lazy\Call;
use Phalcon\Container\Resolver\Lazy\CallableNew;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeNameContainer;
use stdClass;

final class CallTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyCallInvokesDelegateToResolve(): void
    {
        $container = new FakeNameContainer();
        $expected  = new stdClass();
        $lazy      = new Call(
            static function (object $c) use ($expected) {
                return $expected;
            }
        );

        $result = $lazy($container);
        $this->assertSame($expected, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyCallReceivesContainer(): void
    {
        $container = new FakeNameContainer();
        $received  = null;
        $lazy      = new Call(static function (object $c) use (&$received) {
            $received = $c;
            return null;
        });

        $lazy->resolve($container);
        $this->assertSame($container, $received);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyCallResolveInvokesCallable(): void
    {
        $container = new FakeNameContainer();
        $expected  = new stdClass();
        $lazy      = new Call(static function (object $c) use ($expected) {
            return $expected;
        });

        $result = $lazy->resolve($container);
        $this->assertSame($expected, $result);
    }
}
