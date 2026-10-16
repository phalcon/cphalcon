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
use Phalcon\Container\Exceptions\InstanceNotFound;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
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
