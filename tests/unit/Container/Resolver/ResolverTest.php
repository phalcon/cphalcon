<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been heavily influenced by CapsulePHP.
 * Additionally, there are implementations from ioc-interop, which is a
 * Composer dependency, and from service-interop and resolver-interop. The
 * latter two are copied and re-implemented here: service-interop is not yet
 * published on Packagist, and resolver-interop requires PHP 8.4 (this project
 * targets PHP 8.1). Once both packages become available and compatible, the
 * copies will be replaced with the actual Composer dependencies.
 *
 * @link    https://github.com/capsulephp/di
 * @license https://github.com/capsulephp/di/blob/3.x/LICENSE.md
 *
 * @link    https://github.com/ioc-interop/interface
 * @license https://github.com/ioc-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/service-interop/interface
 * @license https://github.com/service-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/resolver-interop/interface/tree/1.x
 * @license https://github.com/resolver-interop/interface/blob/1.x/LICENSE.md
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Resolver;

use Countable;
use Phalcon\Container\Exception\Invalid;
use Phalcon\Container\Resolver\Lazy\Get;
use Phalcon\Container\Resolver\Resolver;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeContainerResolver;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeServiceNoConstructor;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeServiceWithArgs;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeServiceWithInjected;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeServiceWithMethod;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeServiceWithOptional;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeServiceWithTypedArg;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeServiceWithVoidMethod;
use ReflectionClass;
use ReflectionNamedType;
use ReflectionUnionType;

final class ResolverTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverResolveCallWithNonClosureCallable(): void
    {
        $resolver  = new Resolver();
        $target    = new FakeServiceWithMethod();
        $container = new FakeContainerResolver();

        $result = $resolver->resolveCall($container, [$target, 'greet'], ['name' => 'World']);
        $this->assertSame('Hello, World', $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverResolverIsResolvableClassReturnsFalseForInterface(): void
    {
        $resolver = new Resolver();
        $this->assertFalse($resolver->isResolvableClass(Countable::class));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverResolverIsResolvableClassReturnsFalseForNonExistentClass(): void
    {
        $resolver = new Resolver();
        $this->assertFalse($resolver->isResolvableClass('NonExistent\\Class\\That\\DoesNotExist'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverResolverIsResolvableClassReturnsTrueForInstantiableClass(): void
    {
        $resolver = new Resolver();
        $this->assertTrue($resolver->isResolvableClass(FakeServiceNoConstructor::class));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverResolverResolveCallWithClosure(): void
    {
        $resolver  = new Resolver();
        $container = new FakeContainerResolver();

        $callable = static function (string $name, int $count): string {
            return $name . ':' . $count;
        };

        $result = $resolver->resolveCall($container, $callable, ['world', 42]);
        $this->assertSame('world:42', $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverResolverResolveCallWithNamedArgs(): void
    {
        $resolver  = new Resolver();
        $container = new FakeContainerResolver();

        $callable = static function (string $greeting, int $times): string {
            return str_repeat($greeting, $times);
        };

        $result = $resolver->resolveCall(
            $container,
            $callable,
            ['greeting' => 'hi', 'times' => 3]
        );
        $this->assertSame('hihihi', $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverResolverResolveClassNoConstructor(): void
    {
        $resolver  = new Resolver();
        $container = new FakeContainerResolver();
        $result    = $resolver->resolveClass($container, FakeServiceNoConstructor::class, []);
        $this->assertInstanceOf(FakeServiceNoConstructor::class, $result);
        $this->assertSame('default', $result->value);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverResolverResolveClassThrowsWhenRequiredParamUnresolvable(): void
    {
        $resolver  = new Resolver();
        $container = new FakeContainerResolver();

        $this->expectException(Invalid::class);
        $this->expectExceptionMessage("Cannot resolve parameter '\$host' for");

        $resolver->resolveClass($container, FakeServiceWithArgs::class, []);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverResolverResolveClassWithExplicitNamedArgs(): void
    {
        $resolver  = new Resolver();
        $container = new FakeContainerResolver();
        $result    = $resolver->resolveClass(
            $container,
            FakeServiceWithArgs::class,
            ['host' => 'db.local', 'port' => 3306]
        );
        $this->assertInstanceOf(FakeServiceWithArgs::class, $result);
        $this->assertSame('db.local', $result->host);
        $this->assertSame(3306, $result->port);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverResolverResolveClassWithExplicitPositionalArgs(): void
    {
        $resolver  = new Resolver();
        $container = new FakeContainerResolver();
        $result    = $resolver->resolveClass(
            $container,
            FakeServiceWithArgs::class,
            ['localhost', 5432]
        );
        $this->assertInstanceOf(FakeServiceWithArgs::class, $result);
        $this->assertSame('localhost', $result->host);
        $this->assertSame(5432, $result->port);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverResolverResolveClassWithOptionalDefaultsToDefault(): void
    {
        $resolver  = new Resolver();
        $container = new FakeContainerResolver();
        $result    = $resolver->resolveClass(
            $container,
            FakeServiceWithOptional::class,
            ['host' => 'mysql.local']
        );
        $this->assertInstanceOf(FakeServiceWithOptional::class, $result);
        $this->assertSame('mysql.local', $result->host);
        $this->assertSame(3306, $result->port);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverResolverResolveClassWithTypedArgFromContainer(): void
    {
        $resolver  = new Resolver();
        $container = new FakeContainerResolver(true);
        $result    = $resolver->resolveClass(
            $container,
            FakeServiceWithTypedArg::class,
            []
        );
        $this->assertInstanceOf(FakeServiceWithTypedArg::class, $result);
        $this->assertInstanceOf(FakeServiceNoConstructor::class, $result->dependency);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverResolverResolveMethodInvokesWithResolvedParams(): void
    {
        $resolver  = new Resolver();
        $container = new FakeContainerResolver(true);
        $target    = new FakeServiceWithInjected();

        $method = (new ReflectionClass($target))->getMethod('setup');
        $resolver->resolveMethod($container, $method, $target);
        $this->assertSame('default', $target->injected);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverResolverResolveParametersResolvesLazyValues(): void
    {
        $resolver  = new Resolver();
        $container = new FakeContainerResolver(true);
        $params    = (new ReflectionClass(FakeServiceWithArgs::class))
            ->getConstructor()
            ->getParameters();

        $lazyHost = new Get(FakeServiceNoConstructor::class);
        $resolved = $resolver->resolveParameters($container, $params, [$lazyHost, 8080]);
        $this->assertInstanceOf(FakeServiceNoConstructor::class, $resolved[0]);
        $this->assertSame(8080, $resolved[1]);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverResolverResolveParametersWithPositionalArgs(): void
    {
        $resolver  = new Resolver();
        $container = new FakeContainerResolver();
        $params    = (new ReflectionClass(FakeServiceWithArgs::class))
            ->getConstructor()
            ->getParameters();

        $resolved = $resolver->resolveParameters($container, $params, ['myhost', 9999]);
        $this->assertSame('myhost', $resolved[0]);
        $this->assertSame(9999, $resolved[1]);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverResolverResolveTypeReturnsNameForNamedType(): void
    {
        $resolver  = new Resolver();
        $container = new FakeContainerResolver();
        $param     = (new ReflectionClass(FakeServiceWithTypedArg::class))
            ->getConstructor()
            ->getParameters()[0];
        $type      = $param->getType();

        $this->assertInstanceOf(ReflectionNamedType::class, $type);
        $result = $resolver->resolveType($container, $type);
        $this->assertSame(FakeServiceNoConstructor::class, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverResolverResolveTypeReturnsNullForUnionType(): void
    {
        $resolver  = new Resolver();
        $container = new FakeContainerResolver();
        $target    = new FakeServiceWithVoidMethod();

        $param = (new ReflectionClass($target))->getMethod('method')->getParameters()[0];
        $type  = $param->getType();

        $this->assertInstanceOf(ReflectionUnionType::class, $type);
        $result = $resolver->resolveType($container, $type);
        $this->assertNull($result);
    }
}
