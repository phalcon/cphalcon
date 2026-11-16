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
use Phalcon\Tests\Support\Traits\ErrorHandlerTrait;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeContainerWithService;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeServiceWithMethod;

final class NewCallTest extends AbstractUnitTestCase
{
    use ErrorHandlerTrait;

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
     * A method that cannot be called gives a warning and null, the same as
     * cphalcon.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/815
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testContainerResolverLazyNewCallResolveNotCallable(): void
    {
        $container = new FakeContainerWithService(new FakeServiceWithMethod());
        $lazy      = new NewCall('SomeService', 'unknownMethod', []);

        [$actual, $messages] = $this->collectErrors(
            static fn () => $lazy->resolve($container)
        );

        $this->assertNull($actual);
        $this->assertSame(
            ['class ' . FakeServiceWithMethod::class . ' does not have a method "unknownMethod"'],
            $messages
        );
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
