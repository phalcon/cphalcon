<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Resolver\Lazy;

use Phalcon\Container\Resolver\Lazy\FunctionCall;
use Phalcon\Container\Resolver\Lazy\Get;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Container\Fake\FakeContainer;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeContainerWithServiceResolution;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeNameContainer;
use stdClass;

final class GetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyGetInvokeDelegatesToResolve(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new Get('SomeService');
        $result    = $lazy($container);
        $this->assertInstanceOf(stdClass::class, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyGetResolvePassesCorrectIdToContainer(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new Get('MyService');
        $lazy->resolve($container);
        $this->assertSame('MyService', $container->lastId);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyGetResolveReturnsServiceFromContainer(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new Get('SomeService');
        $result    = $lazy->resolve($container);
        $this->assertInstanceOf(stdClass::class, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyGetResolveWithNestedLazyId(): void
    {
        $service = new stdClass();
        $container = new FakeContainerWithServiceResolution($service);
        $inner = new FunctionCall('strtolower', ['TARGET']);
        $outer = new Get($inner);
        $result = $outer->resolve($container);

        $this->assertSame($service, $result);
        $this->assertSame('target', $container->lastId);
    }
}
