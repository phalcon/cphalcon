<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Exceptions;

use Phalcon\Container\Exceptions\CannotExtendResolved;
use Phalcon\Container\Exceptions\ContainerThrowable;
use Phalcon\Tests\AbstractUnitTestCase;
use Throwable;

final class CannotExtendResolvedTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsCannotExtendResolvedIsContainerThrowable(): void
    {
        $exception = new CannotExtendResolved('myService');

        $this->assertInstanceOf(ContainerThrowable::class, $exception);
        $this->assertInstanceOf(Throwable::class, $exception);
    }
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsCannotExtendResolvedMessage(): void
    {
        $exception = new CannotExtendResolved('myService');

        $this->assertSame(
            "Cannot extend already-resolved service 'myService'",
            $exception->getMessage()
        );
    }
}
