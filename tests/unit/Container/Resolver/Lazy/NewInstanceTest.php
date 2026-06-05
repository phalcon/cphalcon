<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Resolver\Lazy;

use Phalcon\Container\Resolver\Lazy\NewInstance;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeNameContainer;
use stdClass;

final class NewInstanceTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyNewInstanceInvokeDelegatesToResolve(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new NewInstance('SomeService');
        $result    = $lazy($container);
        $this->assertInstanceOf(stdClass::class, $result);
        $this->assertSame('SomeService', $result->name);
        $this->assertSame('new', $result->type);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyNewInstanceResolveReturnsNewInstanceFromContainer(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new NewInstance('SomeService');
        $result    = $lazy->resolve($container);
        $this->assertInstanceOf(stdClass::class, $result);
        $this->assertSame('SomeService', $result->name);
        $this->assertSame('new', $result->type);
    }
}
