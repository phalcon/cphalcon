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

use DateTime;
use Phalcon\Container\Resolver\Lazy\StaticCall;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeNameContainer;
use TypeError;

final class StaticCallTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyStaticCallInvokeDelegatesToResolve(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new StaticCall('DateTime', 'createFromFormat', ['Y-m-d', '2024-06-01']);
        $result    = $lazy($container);
        $this->assertInstanceOf(DateTime::class, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyStaticCallResolveCallsStaticMethod(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new StaticCall('DateTime', 'createFromFormat', ['Y-m-d', '2024-01-15']);
        $result    = $lazy->resolve($container);
        $this->assertInstanceOf(DateTime::class, $result);
    }

    /**
     * A method that cannot be called throws the TypeError of
     * call_user_func_array().
     *
     * @issue  https://github.com/phalcon/phalcon/issues/815
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testContainerResolverLazyStaticCallResolveNotCallable(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new StaticCall(DateTime::class, 'unknownMethod', []);

        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(
            'call_user_func_array(): Argument #1 ($callback) must be a valid callback, '
            . 'class DateTime does not have a method "unknownMethod"'
        );

        $lazy->resolve($container);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyStaticCallResolveWithNoArguments(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new StaticCall(DateTime::class, 'createFromFormat', ['U', '0']);
        $result    = $lazy->resolve($container);
        $this->assertInstanceOf(DateTime::class, $result);
    }
}
