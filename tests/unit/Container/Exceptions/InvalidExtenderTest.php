<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Exceptions;

use Phalcon\Container\Exceptions\ContainerThrowable;
use Phalcon\Container\Exceptions\InvalidExtender;
use Phalcon\Tests\AbstractUnitTestCase;
use Throwable;

final class InvalidExtenderTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsInvalidExtenderMessage(): void
    {
        $exception = new InvalidExtender('myService', 'myKey');

        $this->assertSame(
            "Extender at key 'myKey' for service 'myService' is not callable",
            $exception->getMessage()
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsInvalidExtenderIsContainerThrowable(): void
    {
        $exception = new InvalidExtender('myService', 'myKey');

        $this->assertInstanceOf(ContainerThrowable::class, $exception);
        $this->assertInstanceOf(Throwable::class, $exception);
    }
}
