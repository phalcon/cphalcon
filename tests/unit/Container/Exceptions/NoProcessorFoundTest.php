<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Exceptions;

use Phalcon\Container\Exceptions\ContainerThrowable;
use Phalcon\Container\Exceptions\NoProcessorFound;
use Phalcon\Tests\AbstractUnitTestCase;
use Throwable;

final class NoProcessorFoundTest extends AbstractUnitTestCase
{

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsNoProcessorFoundIsContainerThrowable(): void
    {
        $exception = new NoProcessorFound();

        $this->assertInstanceOf(ContainerThrowable::class, $exception);
        $this->assertInstanceOf(Throwable::class, $exception);
    }
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsNoProcessorFoundMessage(): void
    {
        $exception = new NoProcessorFound();

        $this->assertSame(
            'No processor found for the given definition',
            $exception->getMessage()
        );
    }
}
