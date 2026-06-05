<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Resolver\Lazy;

use Phalcon\Container\Resolver\Lazy\ArrayValues;
use Phalcon\Container\Resolver\Lazy\Call;
use Phalcon\Container\Resolver\Lazy\CallableGet;
use Phalcon\Container\Resolver\Lazy\CallableNew;
use Phalcon\Container\Resolver\Lazy\CsEnv;
use Phalcon\Container\Resolver\Lazy\Env;
use Phalcon\Container\Resolver\Lazy\FunctionCall;
use Phalcon\Container\Resolver\Lazy\Get;
use Phalcon\Container\Resolver\Lazy\GetCall;
use Phalcon\Container\Resolver\Lazy\LazyFactory;
use Phalcon\Container\Resolver\Lazy\NewCall;
use Phalcon\Container\Resolver\Lazy\NewInstance;
use Phalcon\Container\Resolver\Lazy\StaticCall;
use Phalcon\Tests\AbstractUnitTestCase;

final class LazyFactoryTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyFactoryArrayValues(): void
    {
        $values = ['a' => 1, 'b' => 2];
        $result = LazyFactory::arrayValues($values);
        $this->assertInstanceOf(ArrayValues::class, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyFactoryCall(): void
    {
        $callable = fn() => 'test';
        $result   = LazyFactory::call($callable);
        $this->assertInstanceOf(Call::class, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyFactoryCallableGet(): void
    {
        $result = LazyFactory::callableGet('SomeId');
        $this->assertInstanceOf(CallableGet::class, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyFactoryCallableNew(): void
    {
        $result = LazyFactory::callableNew('SomeId');
        $this->assertInstanceOf(CallableNew::class, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyFactoryCsEnv(): void
    {
        $result = LazyFactory::csEnv('APP_NAME', 'string');
        $this->assertInstanceOf(CsEnv::class, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyFactoryCsEnvWithoutType(): void
    {
        $result = LazyFactory::csEnv('APP_NAME');
        $this->assertInstanceOf(CsEnv::class, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyFactoryEnv(): void
    {
        $result = LazyFactory::env('APP_NAME', 'string');
        $this->assertInstanceOf(Env::class, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyFactoryEnvWithoutType(): void
    {
        $result = LazyFactory::env('APP_NAME');
        $this->assertInstanceOf(Env::class, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyFactoryFunctionCall(): void
    {
        $result = LazyFactory::functionCall('strlen', ['hello']);
        $this->assertInstanceOf(FunctionCall::class, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyFactoryGet(): void
    {
        $result = LazyFactory::get('SomeId');
        $this->assertInstanceOf(Get::class, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyFactoryGetCall(): void
    {
        $result = LazyFactory::getCall('SomeId', 'someMethod', []);
        $this->assertInstanceOf(GetCall::class, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyFactoryNewCall(): void
    {
        $result = LazyFactory::newCall('SomeId', 'someMethod', []);
        $this->assertInstanceOf(NewCall::class, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyFactoryNewInstance(): void
    {
        $result = LazyFactory::newInstance('SomeId');
        $this->assertInstanceOf(NewInstance::class, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyFactoryStaticCall(): void
    {
        $result = LazyFactory::staticCall('Some\\Class', 'someMethod', []);
        $this->assertInstanceOf(StaticCall::class, $result);
    }
}
