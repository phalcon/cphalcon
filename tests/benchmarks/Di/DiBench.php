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

namespace Phalcon\Tests\Benchmarks\Di;

use Phalcon\Di\Di;
use Phalcon\Html\Escaper;
use PhpBench\Attributes\BeforeMethods;
use RuntimeException;

#[BeforeMethods('setUp')]
final class DiBench
{
    private Di $container;

    public function setUp(): void
    {
        $this->container = new Di();
        $this->container->setShared('escaper', Escaper::class);

        /**
         * Resolve the service once. The subject then measures the lookup of the shared instance.
         */
        $this->container->get('escaper');
    }

    public function benchGetShared(): void
    {
        if (!$this->container->get('escaper') instanceof Escaper) {
            throw new RuntimeException('Di::get() returned an unexpected value');
        }
    }
}
