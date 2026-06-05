<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Exceptions;

use Phalcon\Container\Exceptions\ContainerThrowable;
use Phalcon\Container\Exceptions\ServiceNotRegistered;
use Phalcon\Tests\AbstractUnitTestCase;
use Throwable;

final class ServiceNotRegisteredTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsServiceNotRegisteredMessage(): void
    {
        $exception = new ServiceNotRegistered('myService');

        $this->assertSame(
            "Service 'myService' not registered",
            $exception->getMessage()
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsServiceNotRegisteredIsContainerThrowable(): void
    {
        $exception = new ServiceNotRegistered('myService');

        $this->assertInstanceOf(ContainerThrowable::class, $exception);
        $this->assertInstanceOf(Throwable::class, $exception);
    }
}
