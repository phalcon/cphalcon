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
use Phalcon\Container\Exceptions\InvalidExtender;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Throwable;

final class InvalidExtenderTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsInvalidExtenderIsContainerThrowable(): void
    {
        $exception = new InvalidExtender('myService', 'myKey');

        $this->assertInstanceOf(ContainerThrowable::class, $exception);
        $this->assertInstanceOf(Throwable::class, $exception);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsInvalidExtenderMessage(): void
    {
        $exception = new InvalidExtender('myService', 'myKey');

        $this->assertSame(
            "Extender at key 'myKey' for service 'myService' is not callable",
            $exception->getMessage()
        );
    }
}
