<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Resolver\Lazy;

use Phalcon\Container\Resolver\Lazy\NewCall;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeContainerWithService;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeServiceWithMethod;

final class NewCallTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyNewCallInvokeDelegatesToResolve(): void
    {
        $service   = new FakeServiceWithMethod();
        $container = new FakeContainerWithService($service);
        $lazy      = new NewCall('SomeService', 'ping', []);
        $result    = $lazy($container);
        $this->assertSame('pong', $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyNewCallResolveCallsMethodOnNewInstance(): void
    {
        $service   = new FakeServiceWithMethod();
        $container = new FakeContainerWithService($service);
        $lazy      = new NewCall('SomeService', 'greet', ['Alice']);
        $result    = $lazy->resolve($container);
        $this->assertSame('Hello, Alice', $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyNewCallResolveWithNoArguments(): void
    {
        $service   = new FakeServiceWithMethod();
        $container = new FakeContainerWithService($service);
        $lazy      = new NewCall('SomeService', 'value', []);
        $result    = $lazy->resolve($container);
        $this->assertSame(99, $result);
    }
}
