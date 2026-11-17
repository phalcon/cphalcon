<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container;

use ArrayObject;
use Error;
use Phalcon\Container\Container;
use Phalcon\Container\Definition\ServiceDefinition;
use Phalcon\Container\Resolver\Lazy\GetCall;
use Phalcon\Container\Resolver\Lazy\LazyFactory;
use Phalcon\Container\Resolver\Lazy\NewCall;
use Phalcon\Container\Resolver\Lazy\StaticCall;
use Phalcon\Container\Resolver\Resolver;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\ErrorHandlerTrait;
use PHPUnit\Framework\Attributes\DataProvider;
use stdClass;
use Throwable;
use TypeError;

/**
 * cphalcon does not enforce these parameter types. phalcon accepts the same
 * values, and the later call fails the same way as cphalcon.
 */
final class ParameterTypesTest extends AbstractUnitTestCase
{
    use ErrorHandlerTrait;

    /**
     * A value that cannot be called and the cphalcon message.
     *
     * @return array<string, array{0: mixed, 1: string}>
     */
    public static function getNotCallableValues(): array
    {
        return [
            'string' => ['nope', 'Call to undefined function nope()'],
            'array'  => [[new stdClass(), 'missing'], 'Call to undefined method stdClass::missing()'],
            'object' => [new stdClass(), 'Call to undefined function undefined()'],
            'int'    => [5, 'Call to undefined function undefined()'],
        ];
    }

    /**
     * A value that cannot be called and the cphalcon message of
     * resolveCall().
     *
     * @return array<string, array{0: mixed, 1: string}>
     */
    public static function getResolveCallValues(): array
    {
        $prefix = 'Failed to create closure from callable: ';

        return [
            'string' => ['nope', $prefix . 'function "nope" not found or invalid function name'],
            'array'  => [[new stdClass(), 'missing'], $prefix . 'class stdClass does not have a method "missing"'],
            'object' => [new stdClass(), $prefix . 'no array or string given'],
            'int'    => [5, $prefix . 'no array or string given'],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/818
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    #[DataProvider('getNotCallableValues')]
    public function testContainerDefinitionAddExtenderNotCallable(mixed $value, string $expected): void
    {
        $definition = new ServiceDefinition('stdClass', 'string');
        $definition->addExtender($value);

        $actual = $this->getThrown(
            static fn () => $definition->buildService(new stdClass())
        );

        $this->assertSame([Error::class, $expected], $actual);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/818
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    #[DataProvider('getNotCallableValues')]
    public function testContainerDefinitionSetFactoryNotCallable(mixed $value, string $expected): void
    {
        $definition = new ServiceDefinition('svc', 'closure');
        $definition->setFactory($value);

        $actual = $this->getThrown(
            static fn () => $definition->buildService(new stdClass())
        );

        $this->assertSame([Error::class, $expected], $actual);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/818
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    #[DataProvider('getNotCallableValues')]
    public function testContainerExtendNotCallable(mixed $value, string $expected): void
    {
        $container = new Container();
        $container->set('svc', static fn () => new stdClass());
        $container->extend('svc', $value);

        $actual = $this->getThrown(static fn () => $container->get('svc'));

        $this->assertSame([Error::class, $expected], $actual);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/818
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    #[DataProvider('getNotCallableValues')]
    public function testContainerLazyFactoryCallNotCallable(mixed $value, string $expected): void
    {
        $lazy = LazyFactory::call($value);

        $actual = $this->getThrown(static fn () => $lazy->resolve(new stdClass()));

        $this->assertSame([Error::class, $expected], $actual);
    }

    /**
     * An id that is not a string is used as a string, the same as cphalcon.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/818
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testContainerLazyGetCallIdNotString(): void
    {
        $lazy = new GetCall(5, 'count', []);

        $this->assertSame(2, $lazy->resolve($this->getNumberContainer()));
    }

    /**
     * An id that is not a string is used as a string, the same as cphalcon.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/818
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testContainerLazyNewCallIdNotString(): void
    {
        $lazy = new NewCall(5, 'count', []);

        $this->assertSame(2, $lazy->resolve($this->getNumberContainer()));
    }

    /**
     * A class name that is not a string gives a warning and null, the same as
     * cphalcon.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/818
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testContainerLazyStaticCallClassNameNotString(): void
    {
        $lazy      = new StaticCall(5, 'm', []);
        $container = $this->getNumberContainer();

        $actual = $this->collectErrors(static fn () => $lazy->resolve($container));

        $this->assertSame(
            [null, ['first array member is not a valid class name or object']],
            $actual
        );
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/818
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    #[DataProvider('getResolveCallValues')]
    public function testContainerResolverResolveCallNotCallable(mixed $value, string $expected): void
    {
        $actual = $this->getThrown(
            static fn () => (new Resolver())->resolveCall(new stdClass(), $value, [])
        );

        $this->assertSame([TypeError::class, $expected], $actual);
    }

    /**
     * A container with the service "5"
     */
    private function getNumberContainer(): Container
    {
        $container = new Container();
        $container->set('5', static fn () => new ArrayObject([1, 2]));

        return $container;
    }

    /**
     * Returns the class and the message of the exception that the callable
     * throws, or null.
     *
     * @return array{0: string, 1: string}|null
     */
    private function getThrown(callable $callable): ?array
    {
        try {
            $callable();
        } catch (Throwable $ex) {
            return [$ex::class, $ex->getMessage()];
        }

        return null;
    }
}
