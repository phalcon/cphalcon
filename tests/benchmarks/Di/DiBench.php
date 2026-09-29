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
use Phalcon\Di\FactoryDefault;
use Phalcon\Html\Escaper;
use PhpBench\Attributes\BeforeMethods;
use PhpBench\Attributes\Revs;
use RuntimeException;

#[BeforeMethods('setUp')]
final class DiBench
{
    private Di $container;

    public function setUp(): void
    {
        $this->container = new Di();
        $this->container->setShared('escaper', Escaper::class);
        $this->container->set('escaperNew', Escaper::class);

        /**
         * Resolve the service once. The subject then measures the lookup of the shared instance.
         */
        $this->container->get('escaper');
    }

    /**
     * The default container of each request: all the services of FactoryDefault.
     */
    #[Revs(200)]
    public function benchFactoryDefault(): void
    {
        Di::reset();
        $container = new FactoryDefault();

        if (!$container->has('router')) {
            throw new RuntimeException('FactoryDefault has no router service');
        }
    }

    /**
     * A service that is not shared: a new instance for each call.
     */
    public function benchGetNew(): void
    {
        if (!$this->container->get('escaperNew') instanceof Escaper) {
            throw new RuntimeException('Di::get() returned an unexpected value');
        }
    }

    public function benchGetShared(): void
    {
        if (!$this->container->get('escaper') instanceof Escaper) {
            throw new RuntimeException('Di::get() returned an unexpected value');
        }
    }
}
