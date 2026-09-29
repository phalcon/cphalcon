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

namespace Phalcon\Tests\Benchmarks\Events;

use Phalcon\Events\Manager;
use PhpBench\Attributes\BeforeMethods;
use RuntimeException;

#[BeforeMethods('setUp')]
final class ManagerBench
{
    private Manager $manager;

    public function setUp(): void
    {
        $this->manager = new Manager();
        $this->manager->attach(
            'bench:run',
            function (): bool {
                return true;
            }
        );
    }

    /**
     * An event with 1 listener.
     */
    public function benchFire(): void
    {
        if (true !== $this->manager->fire('bench:run', $this)) {
            throw new RuntimeException('fire() returned an unexpected value');
        }
    }

    /**
     * An event with no listener (the manager has listeners for other events only).
     */
    public function benchFireNoListener(): void
    {
        if (null !== $this->manager->fire('bench:none', $this)) {
            throw new RuntimeException('fire() returned an unexpected value');
        }
    }
}
