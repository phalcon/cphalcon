<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Exceptions;

use Phalcon\Container\Exceptions\ContainerThrowable;
use Phalcon\Container\Exceptions\NoFactorySet;
use Phalcon\Tests\AbstractUnitTestCase;
use Throwable;

final class NoFactorySetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsNoFactorySetIsContainerThrowable(): void
    {
        $exception = new NoFactorySet('myService');

        $this->assertInstanceOf(ContainerThrowable::class, $exception);
        $this->assertInstanceOf(Throwable::class, $exception);
    }
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsNoFactorySetMessage(): void
    {
        $exception = new NoFactorySet('myService');

        $this->assertSame(
            "No factory set for service 'myService'",
            $exception->getMessage()
        );
    }
}
