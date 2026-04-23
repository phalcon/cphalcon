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

namespace Phalcon\Tests\Unit\Di\FactoryDefault\Cli;

use Phalcon\Config\Config;
use Phalcon\Di\FactoryDefault\Cli as Di;
use Phalcon\Tests\AbstractUnitTestCase;

final class LoadFromYamlTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDiFactorydefaultCliLoadFromYaml(): void
    {
        $di = new Di();

        // load php
        $di->loadFromYaml(supportDir('assets/Di/services.yml'));

        // there are 3 new + 13 from Default
        $this->assertCount(16, $di->getServices());

        // check some services
        $actual = $di->get('config');
        $this->assertInstanceOf(Config::class, $actual);

        $this->assertTrue($di->has('config'));
        $this->assertTrue($di->has('unit-test'));
        $this->assertTrue($di->has('component'));
    }
}
