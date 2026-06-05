<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Exceptions;

use Phalcon\Container\Exceptions\ContainerThrowable;
use Phalcon\Container\Exceptions\NoClassSet;
use Phalcon\Tests\AbstractUnitTestCase;
use Throwable;

final class NoClassSetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsNoClassSetMessage(): void
    {
        $exception = new NoClassSet('myService');

        $this->assertSame(
            "No class set for service 'myService'",
            $exception->getMessage()
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsNoClassSetIsContainerThrowable(): void
    {
        $exception = new NoClassSet('myService');

        $this->assertInstanceOf(ContainerThrowable::class, $exception);
        $this->assertInstanceOf(Throwable::class, $exception);
    }
}
