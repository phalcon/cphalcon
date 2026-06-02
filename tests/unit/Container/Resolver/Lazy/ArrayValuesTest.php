<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Resolver\Lazy;

use ArrayIterator;
use Phalcon\Container\Resolver\Lazy\ArrayValues;
use Phalcon\Container\Resolver\Lazy\Get;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeNameContainer;
use stdClass;

final class ArrayValuesTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyArrayValuesArrayAccessSyntax(): void
    {
        $lazy        = new ArrayValues();
        $lazy['key'] = 'value';
        $this->assertTrue(isset($lazy['key']));
        $this->assertSame('value', $lazy['key']);
        unset($lazy['key']);
        $this->assertFalse(isset($lazy['key']));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyArrayValuesCount(): void
    {
        $lazy = new ArrayValues(['a' => 1, 'b' => 2, 'c' => 3]);
        $this->assertSame(3, $lazy->count());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyArrayValuesCountEmpty(): void
    {
        $lazy = new ArrayValues();
        $this->assertSame(0, $lazy->count());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyArrayValuesGetIterator(): void
    {
        $lazy = new ArrayValues(['x' => 10]);
        $this->assertInstanceOf(ArrayIterator::class, $lazy->getIterator());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyArrayValuesMergeIntKeys(): void
    {
        $lazy = new ArrayValues([1, 2]);
        $lazy->merge([3, 4]);
        $this->assertSame(4, $lazy->count());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyArrayValuesMergeStringKeys(): void
    {
        $lazy = new ArrayValues(['a' => 1]);
        $lazy->merge(['b' => 2]);
        $this->assertSame(2, $lazy->count());
        $this->assertTrue($lazy->offsetExists('b'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyArrayValuesOffsetExists(): void
    {
        $lazy = new ArrayValues(['key' => 'value']);
        $this->assertTrue($lazy->offsetExists('key'));
        $this->assertFalse($lazy->offsetExists('missing'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyArrayValuesOffsetGet(): void
    {
        $lazy = new ArrayValues(['foo' => 'bar']);
        $this->assertSame('bar', $lazy->offsetGet('foo'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyArrayValuesOffsetSetWithKey(): void
    {
        $lazy = new ArrayValues();
        $lazy->offsetSet('myKey', 'myValue');
        $this->assertTrue($lazy->offsetExists('myKey'));
        $this->assertSame('myValue', $lazy->offsetGet('myKey'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyArrayValuesOffsetSetWithNull(): void
    {
        $lazy = new ArrayValues();
        $lazy->offsetSet(null, 'appended');
        $this->assertSame(1, $lazy->count());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyArrayValuesOffsetUnset(): void
    {
        $lazy = new ArrayValues(['a' => 1, 'b' => 2]);
        $lazy->offsetUnset('a');
        $this->assertFalse($lazy->offsetExists('a'));
        $this->assertSame(1, $lazy->count());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyArrayValuesResolveLazyValues(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new ArrayValues(['service' => new Get('SomeService')]);
        $result    = $lazy->resolve($container);
        $this->assertArrayHasKey('service', $result);
        $this->assertInstanceOf(stdClass::class, $result['service']);
        $this->assertSame('SomeService', $result['service']->name);
        $this->assertSame('get', $result['service']->type);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyArrayValuesResolveNestedArrayValues(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new ArrayValues(['nested' => ['a' => 1, 'b' => 2]]);
        $result    = $lazy->resolve($container);
        $this->assertSame(['nested' => ['a' => 1, 'b' => 2]], $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyArrayValuesResolvePlainValues(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new ArrayValues(['x' => 42, 'y' => 'hello']);
        $result    = $lazy->resolve($container);
        $this->assertSame(['x' => 42, 'y' => 'hello'], $result);
    }
}
