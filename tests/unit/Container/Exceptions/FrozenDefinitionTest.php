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
use Phalcon\Container\Exceptions\FrozenDefinition;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Throwable;

final class FrozenDefinitionTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsFrozenDefinitionIsContainerThrowable(): void
    {
        $exception = new FrozenDefinition('myService');

        $this->assertInstanceOf(ContainerThrowable::class, $exception);
        $this->assertInstanceOf(Throwable::class, $exception);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExceptionsFrozenDefinitionMessage(): void
    {
        $exception = new FrozenDefinition('myService');

        $this->assertSame(
            "Cannot modify frozen definition 'myService'",
            $exception->getMessage()
        );
    }
}
