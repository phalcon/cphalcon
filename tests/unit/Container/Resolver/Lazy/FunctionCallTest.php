<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Resolver\Lazy;

use Phalcon\Container\Resolver\Lazy\FunctionCall;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeNameContainer;
use stdClass;

final class FunctionCallTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyFunctionCallInvokeDelegatesToResolve(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new FunctionCall('strtolower', ['WORLD']);
        $result    = $lazy($container);
        $this->assertSame('world', $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyFunctionCallResolveCallsFunction(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new FunctionCall('strtoupper', ['hello']);
        $result    = $lazy->resolve($container);
        $this->assertSame('HELLO', $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyFunctionCallResolveWithMultipleArguments(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new FunctionCall('implode', [',', ['a', 'b', 'c']]);
        $result    = $lazy->resolve($container);
        $this->assertSame('a,b,c', $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyFunctionCallResolveWithNoArguments(): void
    {
        $version = PHP_VERSION;
        $container = new FakeNameContainer();
        $lazy      = new FunctionCall('phpversion', []);
        $result    = $lazy->resolve($container);
        $this->assertIsString($result);
        $this->assertSame($version, $result);
    }
}
