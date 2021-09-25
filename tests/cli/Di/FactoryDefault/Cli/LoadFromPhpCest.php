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
use Phalcon\Config;
use Phalcon\Di\FactoryDefault\Cli as Di;

class LoadFromPhpCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: loadFromPhp()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diFactorydefaultCliLoadFromPhp(CliTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - loadFromPhp()');

        $di = new Di();

        // load php
        $di->loadFromPhp(dataDir('fixtures/Di/services.php'));

        // there are 3 new + 10 from Default
        $I->assertCount(13, $di->getServices());

        // check some services
        $actual = $di->get('config');
        $I->assertInstanceOf(Config::class, $actual);

        $I->assertTrue($di->has('config'));
        $I->assertTrue($di->has('unit-test'));
        $I->assertTrue($di->has('component'));
    }
}
