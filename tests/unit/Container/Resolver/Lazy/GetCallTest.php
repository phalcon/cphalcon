<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Resolver\Lazy;

use Phalcon\Container\Resolver\Lazy\GetCall;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeContainerWithService;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeServiceWithMethod;

final class GetCallTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyGetCallInvokeDelegatesToResolve(): void
    {
        $service   = new FakeServiceWithMethod();
        $container = new FakeContainerWithService($service);
        $lazy      = new GetCall('SomeService', 'ping', []);
        $result    = $lazy($container);
        $this->assertSame('pong', $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyGetCallResolveCallsMethodOnService(): void
    {
        $service   = new FakeServiceWithMethod();
        $container = new FakeContainerWithService($service);
        $lazy      = new GetCall('SomeService', 'greet', ['World']);
        $result    = $lazy->resolve($container);
        $this->assertSame('Hello, World', $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyGetCallResolveWithNoArguments(): void
    {
        $service   = new FakeServiceWithMethod();
        $container = new FakeContainerWithService($service);
        $lazy      = new GetCall('SomeService', 'value', []);
        $result    = $lazy->resolve($container);
        $this->assertSame(99, $result);
    }
}
