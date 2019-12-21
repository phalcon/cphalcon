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

namespace Phalcon\Test\Unit\Di;

use Phalcon\Config;
use Phalcon\Di;
use UnitTester;

class LoadFromPhpCest
{
    /**
     * Unit Tests Phalcon\Di :: loadFromPhp()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function diLoadFromPhp(UnitTester $I)
    {
        $I->wantToTest('Di - loadFromPhp()');

        $di = new Di();

        // load php
        $di->loadFromPhp(dataDir('fixtures/Di/services.php'));

        // there are 3
        $I->assertCount(3, $di->getServices());

        // check some services
        $actual = $di->get('config');
        $I->assertInstanceOf(Config::class, $actual);

        $I->assertTrue($di->has('config'));
        $I->assertTrue($di->has('unit-test'));
        $I->assertTrue($di->has('component'));
    }
}
