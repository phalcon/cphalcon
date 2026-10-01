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

namespace Phalcon\Tests\Benchmarks\Container;

use Phalcon\Container\Container;
use Phalcon\Container\ContainerFactory;
use Phalcon\Html\Escaper;
use PhpBench\Attributes\BeforeMethods;
use RuntimeException;

#[BeforeMethods('setUp')]
final class ContainerBench
{
    private Container $container;

    public function setUp(): void
    {
        $this->container = (new ContainerFactory())->newContainer();
        $this->container->set('escaper', Escaper::class);
        $this->container->get('escaper');
    }

    /**
     * A service with a class definition (the container of the ADR app).
     */
    public function benchGet(): void
    {
        if (!$this->container->get('escaper') instanceof Escaper) {
            throw new RuntimeException('Container::get() returned an unexpected value');
        }
    }
}
