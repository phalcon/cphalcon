<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Resolver\Lazy;

use Phalcon\Container\Resolver\Lazy\CallableGet;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeNameContainer;
use stdClass;

final class CallableGetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyCallableGetClosureInvokesContainerGet(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new CallableGet('SomeService');
        $closure   = $lazy->resolve($container);
        $result    = $closure();
        $this->assertInstanceOf(stdClass::class, $result);
        $this->assertSame('SomeService', $result->name);
        $this->assertSame('get', $result->type);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyCallableGetInvokeReturnsClosure(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new CallableGet('SomeService');
        $result    = $lazy($container);
        $this->assertIsCallable($result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyCallableGetResolveReturnsClosure(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new CallableGet('SomeService');
        $result    = $lazy->resolve($container);
        $this->assertIsCallable($result);
    }
}
