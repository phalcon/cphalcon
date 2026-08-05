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

namespace Phalcon\Tests\Unit\Queue\QueueFactory;

use Phalcon\Queue\Exceptions\Exception;
use Phalcon\Queue\QueueFactory;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class LoadTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-05
     */
    public function testQueueQueueFactoryLoadException(): void
    {
        $factory = new QueueFactory();

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "You must provide the 'adapter' option in the factory config parameter."
        );

        $factory->load([]);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-05
     */
    public function testQueueQueueFactoryLoadExceptionInvalidConfig(): void
    {
        $factory = new QueueFactory();

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Config must be array or Phalcon\Config\Config object'
        );

        $factory->load(1234);
    }
}
