<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Exception;

use Phalcon\Container\Exception\ContainerThrowable;
use Phalcon\Container\Exception\Invalid;
use Phalcon\Container\Exception\NotFound;
use Phalcon\Tests\AbstractUnitTestCase;

final class NotFoundTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionNotFoundEnvNotDefined(): void
    {
        $exception = NotFound::envNotDefined('MY_VAR');
        $this->assertInstanceOf(NotFound::class, $exception);
        $this->assertSame("Environment variable 'MY_VAR' is not defined", $exception->getMessage());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionNotFoundExtendsInvalid(): void
    {
        $exception = new NotFound('test');
        $this->assertInstanceOf(Invalid::class, $exception);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionNotFoundImplementsContainerThrowable(): void
    {
        $exception = new NotFound('test');
        $this->assertInstanceOf(ContainerThrowable::class, $exception);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionNotFoundInstanceNotFound(): void
    {
        $exception = NotFound::instanceNotFound('myInstance');
        $this->assertInstanceOf(NotFound::class, $exception);
        $this->assertSame("Instance 'myInstance' not found", $exception->getMessage());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionNotFoundMessage(): void
    {
        $exception = new NotFound('service not found');
        $this->assertSame('service not found', $exception->getMessage());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionNotFoundParameterNotFound(): void
    {
        $exception = NotFound::parameterNotFound('myParam');
        $this->assertInstanceOf(NotFound::class, $exception);
        $this->assertSame("Parameter 'myParam' not found", $exception->getMessage());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionNotFoundServiceNotFound(): void
    {
        $exception = NotFound::serviceNotFound('myService');
        $this->assertInstanceOf(NotFound::class, $exception);
        $this->assertSame("Service 'myService' not found", $exception->getMessage());
    }
}
