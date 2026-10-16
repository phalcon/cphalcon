<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Exceptions;

use Phalcon\Container\Exceptions\ContainerThrowable;
use Phalcon\Container\Exceptions\ServiceNotFound;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Throwable;

final class ServiceNotFoundTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsServiceNotFoundIsContainerThrowable(): void
    {
        $exception = new ServiceNotFound('myService');

        $this->assertInstanceOf(ContainerThrowable::class, $exception);
        $this->assertInstanceOf(Throwable::class, $exception);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsServiceNotFoundMessage(): void
    {
        $exception = new ServiceNotFound('myService');

        $this->assertSame(
            "Service 'myService' not found",
            $exception->getMessage()
        );
    }
}
