<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Exceptions;

use Phalcon\Container\Exceptions\ContainerThrowable;
use Phalcon\Container\Exceptions\FrozenDefinition;
use Phalcon\Tests\AbstractUnitTestCase;
use Throwable;

final class FrozenDefinitionTest extends AbstractUnitTestCase
{
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
}
