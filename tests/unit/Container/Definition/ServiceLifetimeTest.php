<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Definition;

use Phalcon\Container\Interop\Service\Lifetime;
use Phalcon\Tests\AbstractUnitTestCase;

final class ServiceLifetimeTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceLifetimeConstants(): void
    {
        $this->assertSame('SCOPED', Lifetime::SCOPED);
        $this->assertSame('SINGLETON', Lifetime::SINGLETON);
        $this->assertSame('TRANSIENT', Lifetime::TRANSIENT);
    }
}