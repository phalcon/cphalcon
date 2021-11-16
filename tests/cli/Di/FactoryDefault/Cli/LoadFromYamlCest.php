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

namespace Phalcon\Tests\Cli\Di\FactoryDefault\Cli;

use CliTester;
use Phalcon\Config\Config;
use Phalcon\Di\FactoryDefault\Cli as Di;

class LoadFromYamlCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: loadFromYaml()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diFactorydefaultCliLoadFromYaml(CliTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - loadFromYaml()');

        $di = new Di();

        // load php
        $di->loadFromYaml(dataDir('fixtures/Di/services.yml'));

        // there are 3 new + 11 from Default
        $I->assertCount(14, $di->getServices());

        // check some services
        $actual = $di->get('config');
        $I->assertInstanceOf(Config::class, $actual);

        $I->assertTrue($di->has('config'));
        $I->assertTrue($di->has('unit-test'));
        $I->assertTrue($di->has('component'));
    }
}
