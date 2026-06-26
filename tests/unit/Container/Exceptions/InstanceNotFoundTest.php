<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Exceptions;

use Phalcon\Container\Exceptions\ContainerThrowable;
use Phalcon\Container\Exceptions\InstanceNotFound;
use Phalcon\Tests\AbstractUnitTestCase;
use Throwable;

final class InstanceNotFoundTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsInstanceNotFoundIsContainerThrowable(): void
    {
        $exception = new InstanceNotFound('myInstance');

        $this->assertInstanceOf(ContainerThrowable::class, $exception);
        $this->assertInstanceOf(Throwable::class, $exception);
    }
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsInstanceNotFoundMessage(): void
    {
        $exception = new InstanceNotFound('myInstance');

        $this->assertSame(
            "Instance 'myInstance' not found",
            $exception->getMessage()
        );
    }
}
