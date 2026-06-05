<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Exceptions;

use Phalcon\Container\Exceptions\ContainerThrowable;
use Phalcon\Container\Exceptions\ServiceNotFound;
use Phalcon\Tests\AbstractUnitTestCase;
use Throwable;

final class ServiceNotFoundTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsServiceNotFoundMessage(): void
    {
        $exception = new ServiceNotFound('myService');

        $this->assertSame(
            "Service 'myService' not found",
            $exception->getMessage()
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsServiceNotFoundIsContainerThrowable(): void
    {
        $exception = new ServiceNotFound('myService');

        $this->assertInstanceOf(ContainerThrowable::class, $exception);
        $this->assertInstanceOf(Throwable::class, $exception);
    }
}
