<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Exceptions;

use Phalcon\Container\Exceptions\CircularAliasFound;
use Phalcon\Container\Exceptions\ContainerThrowable;
use Phalcon\Tests\AbstractUnitTestCase;
use Throwable;

final class CircularAliasFoundTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsCircularAliasFoundIsContainerThrowable(): void
    {
        $exception = new CircularAliasFound('myAlias');

        $this->assertInstanceOf(ContainerThrowable::class, $exception);
        $this->assertInstanceOf(Throwable::class, $exception);
    }
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsCircularAliasFoundMessage(): void
    {
        $exception = new CircularAliasFound('myAlias');

        $this->assertSame(
            "Circular alias detected: 'myAlias'",
            $exception->getMessage()
        );
    }
}
