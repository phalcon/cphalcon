<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Exceptions;

use Phalcon\Container\Exceptions\CannotResolveParameter;
use Phalcon\Container\Exceptions\ContainerThrowable;
use Phalcon\Tests\AbstractUnitTestCase;
use Throwable;

final class CannotResolveParameterTest extends AbstractUnitTestCase
{

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsCannotResolveParameterIsContainerThrowable(): void
    {
        $exception = new CannotResolveParameter('param', 'MyClass');

        $this->assertInstanceOf(ContainerThrowable::class, $exception);
        $this->assertInstanceOf(Throwable::class, $exception);
    }
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsCannotResolveParameterMessage(): void
    {
        $exception = new CannotResolveParameter('param', 'MyClass');

        $this->assertSame(
            "Cannot resolve parameter '\$param' for 'MyClass'",
            $exception->getMessage()
        );
    }
}
