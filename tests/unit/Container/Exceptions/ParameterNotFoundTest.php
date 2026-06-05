<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Exceptions;

use Phalcon\Container\Exceptions\ContainerThrowable;
use Phalcon\Container\Exceptions\ParameterNotFound;
use Phalcon\Tests\AbstractUnitTestCase;
use Throwable;

final class ParameterNotFoundTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsParameterNotFoundMessage(): void
    {
        $exception = new ParameterNotFound('myParam');

        $this->assertSame(
            "Parameter 'myParam' not found",
            $exception->getMessage()
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsParameterNotFoundIsContainerThrowable(): void
    {
        $exception = new ParameterNotFound('myParam');

        $this->assertInstanceOf(ContainerThrowable::class, $exception);
        $this->assertInstanceOf(Throwable::class, $exception);
    }
}
