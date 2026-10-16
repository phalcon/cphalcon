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

namespace Phalcon\Tests\Unit\Container\Definition;

use Phalcon\Container\Definition\ServiceLifetime;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class ServiceLifetimeTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceLifetimeConstants(): void
    {
        $this->assertSame('SCOPED', ServiceLifetime::SCOPED);
        $this->assertSame('SINGLETON', ServiceLifetime::SINGLETON);
        $this->assertSame('TRANSIENT', ServiceLifetime::TRANSIENT);
    }
}
