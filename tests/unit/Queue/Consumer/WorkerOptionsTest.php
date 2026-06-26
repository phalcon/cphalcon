<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Queue\Consumer;

use Phalcon\Queue\Consumer\WorkerOptions;
use Phalcon\Tests\AbstractUnitTestCase;

final class WorkerOptionsTest extends AbstractUnitTestCase
{
    public function testDefaultsAreZero(): void
    {
        $options = new WorkerOptions();

        $this->assertSame(0, $options->getMaxMessages());
        $this->assertSame(0, $options->getMaxSeconds());
        $this->assertSame(0, $options->getMaxMemory());
        $this->assertSame(0, $options->getJitter());
    }

    public function testReturnsConstructorValues(): void
    {
        $options = new WorkerOptions(5, 10, 128, 3);

        $this->assertSame(5, $options->getMaxMessages());
        $this->assertSame(10, $options->getMaxSeconds());
        $this->assertSame(128, $options->getMaxMemory());
        $this->assertSame(3, $options->getJitter());
    }
}
