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

use Phalcon\Container\Resolver\Lazy\FunctionCall;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeNameContainer;
use TypeError;

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
     * A function that cannot be called throws the TypeError of
     * call_user_func_array().
     *
     * @issue  https://github.com/phalcon/phalcon/issues/815
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testContainerResolverLazyFunctionCallResolveNotCallable(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new FunctionCall('unknownFunction', []);

        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(
            'call_user_func_array(): Argument #1 ($callback) must be a valid callback, '
            . 'function "unknownFunction" not found or invalid function name'
        );

        $lazy->resolve($container);
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
        $version   = PHP_VERSION;
        $container = new FakeNameContainer();
        $lazy      = new FunctionCall('phpversion', []);
        $result    = $lazy->resolve($container);
        $this->assertIsString($result);
        $this->assertSame($version, $result);
    }
}
