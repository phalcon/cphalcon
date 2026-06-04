<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Exceptions;

use Phalcon\Container\Exceptions\ContainerThrowable;
use Phalcon\Container\Exceptions\EnvNotDefined;
use Phalcon\Tests\AbstractUnitTestCase;
use Throwable;

final class EnvNotDefinedTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsEnvNotDefinedMessage(): void
    {
        $exception = new EnvNotDefined('MY_VAR');

        $this->assertSame(
            "Environment variable 'MY_VAR' is not defined",
            $exception->getMessage()
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsEnvNotDefinedIsContainerThrowable(): void
    {
        $exception = new EnvNotDefined('MY_VAR');

        $this->assertInstanceOf(ContainerThrowable::class, $exception);
        $this->assertInstanceOf(Throwable::class, $exception);
    }
}
