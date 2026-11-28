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

use Phalcon\Container\Resolver\Lazy\NewCall;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeContainerWithService;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeServiceWithMethod;
use TypeError;

final class NewCallTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyNewCallInvokeDelegatesToResolve(): void
    {
        $service   = new FakeServiceWithMethod();
        $container = new FakeContainerWithService($service);
        $lazy      = new NewCall('SomeService', 'ping', []);
        $result    = $lazy($container);
        $this->assertSame('pong', $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyNewCallResolveCallsMethodOnNewInstance(): void
    {
        $service   = new FakeServiceWithMethod();
        $container = new FakeContainerWithService($service);
        $lazy      = new NewCall('SomeService', 'greet', ['Alice']);
        $result    = $lazy->resolve($container);
        $this->assertSame('Hello, Alice', $result);
    }

    /**
     * A method that cannot be called throws the TypeError of
     * call_user_func_array().
     *
     * @issue  https://github.com/phalcon/phalcon/issues/815
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testContainerResolverLazyNewCallResolveNotCallable(): void
    {
        $container = new FakeContainerWithService(new FakeServiceWithMethod());
        $lazy      = new NewCall('SomeService', 'unknownMethod', []);

        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(
            'call_user_func_array(): Argument #1 ($callback) must be a valid callback, '
            . 'class ' . FakeServiceWithMethod::class . ' does not have a method "unknownMethod"'
        );

        $lazy->resolve($container);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyNewCallResolveWithNoArguments(): void
    {
        $service   = new FakeServiceWithMethod();
        $container = new FakeContainerWithService($service);
        $lazy      = new NewCall('SomeService', 'value', []);
        $result    = $lazy->resolve($container);
        $this->assertSame(99, $result);
    }
}
