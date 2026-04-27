<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Exception;

use Exception;
use Phalcon\Container\Exception\ContainerThrowable;
use Phalcon\Container\Exception\Invalid;
use Phalcon\Tests\AbstractUnitTestCase;
use Throwable;

final class InvalidTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionInvalidCannotExtendResolved(): void
    {
        $exception = Invalid::cannotExtendResolved('myService');
        $this->assertInstanceOf(Invalid::class, $exception);
        $this->assertSame("Cannot extend already-resolved service 'myService'", $exception->getMessage());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionInvalidCannotResolveParameter(): void
    {
        $exception = Invalid::cannotResolveParameter('param', 'MyClass');
        $this->assertInstanceOf(Invalid::class, $exception);
        $this->assertSame("Cannot resolve parameter '\$param' for 'MyClass'", $exception->getMessage());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionInvalidCircularAlias(): void
    {
        $exception = Invalid::circularAlias('myAlias');
        $this->assertInstanceOf(Invalid::class, $exception);
        $this->assertSame("Circular alias detected: 'myAlias'", $exception->getMessage());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionInvalidExtendsException(): void
    {
        $exception = new Invalid('test');
        $this->assertInstanceOf(Exception::class, $exception);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionInvalidFrozenDefinition(): void
    {
        $exception = Invalid::frozenDefinition('myService');
        $this->assertInstanceOf(Invalid::class, $exception);
        $this->assertSame("Cannot modify frozen definition 'myService'", $exception->getMessage());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionInvalidImplementsContainerThrowable(): void
    {
        $exception = new Invalid('test');
        $this->assertInstanceOf(ContainerThrowable::class, $exception);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionInvalidImplementsThrowable(): void
    {
        $exception = new Invalid('test');
        $this->assertInstanceOf(Throwable::class, $exception);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionInvalidMessage(): void
    {
        $exception = new Invalid('something went wrong');
        $this->assertSame('something went wrong', $exception->getMessage());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionInvalidNoClassSet(): void
    {
        $exception = Invalid::noClassSet('myService');
        $this->assertInstanceOf(Invalid::class, $exception);
        $this->assertSame("No class set for service 'myService'", $exception->getMessage());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionInvalidNoFactorySet(): void
    {
        $exception = Invalid::noFactorySet('myService');
        $this->assertInstanceOf(Invalid::class, $exception);
        $this->assertSame("No factory set for service 'myService'", $exception->getMessage());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionInvalidNoProcessorFound(): void
    {
        $exception = Invalid::noProcessorFound();
        $this->assertInstanceOf(Invalid::class, $exception);
        $this->assertSame('No processor found for the given definition', $exception->getMessage());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionInvalidServiceNotFound(): void
    {
        $exception = Invalid::serviceNotFound('myService');
        $this->assertInstanceOf(Invalid::class, $exception);
        $this->assertSame("Service 'myService' not registered", $exception->getMessage());
    }
}
