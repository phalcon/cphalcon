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

namespace Phalcon\Tests\Unit\Container\Resolver\Lazy;

use Error;
use Phalcon\Container\Resolver\Lazy\Call;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeNameContainer;
use PHPUnit\Framework\Attributes\DataProvider;
use stdClass;
use Throwable;

final class CallTest extends AbstractUnitTestCase
{
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyCallInvokesDelegateToResolve(): void
    {
        $container = new FakeNameContainer();
        $expected  = new stdClass();
        $lazy      = new Call(
            static function (object $c) use ($expected) {
                return $expected;
            }
        );

        $result = $lazy($container);
        $this->assertSame($expected, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyCallReceivesContainer(): void
    {
        $container = new FakeNameContainer();
        $received  = null;
        $lazy      = new Call(static function (object $c) use (&$received) {
            $received = $c;
            return null;
        });

        $lazy->resolve($container);
        $this->assertSame($container, $received);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyCallResolveInvokesCallable(): void
    {
        $container = new FakeNameContainer();
        $expected  = new stdClass();
        $lazy      = new Call(static function (object $c) use ($expected) {
            return $expected;
        });

        $result = $lazy->resolve($container);
        $this->assertSame($expected, $result);
    }

    /**
     * A value that cannot be called throws Error with the cphalcon message.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/817
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    #[DataProvider('getNotCallableValues')]
    public function testContainerResolverLazyCallResolveNotCallable(
        mixed $value,
        string $expected
    ): void {
        $lazy = new Call($value);

        $actual = null;
        try {
            $lazy->resolve(new FakeNameContainer());
        } catch (Throwable $ex) {
            $actual = [$ex::class, $ex->getMessage()];
        }

        $this->assertSame([Error::class, $expected], $actual);
    }
}
