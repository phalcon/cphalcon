<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Resolver\Lazy;

use Phalcon\Container\Resolver\Lazy\CallableGet;
use Phalcon\Container\Resolver\Lazy\CallableNew;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeNameContainer;
use stdClass;

final class CallableNewTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyCallableNewClosureInvokesContainerNew(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new CallableNew('SomeService');
        $closure   = $lazy->resolve($container);
        $result    = $closure();
        $this->assertInstanceOf(stdClass::class, $result);
        $this->assertSame('SomeService', $result->name);
        $this->assertSame('new', $result->type);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyCallableNewInvokeReturnsClosure(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new CallableNew('SomeService');
        $result    = $lazy($container);
        $this->assertIsCallable($result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyCallableNewResolveReturnsClosure(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new CallableNew('SomeService');
        $result    = $lazy->resolve($container);
        $this->assertIsCallable($result);
    }
}
