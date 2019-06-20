<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Di;

use Phalcon\Config\Config;
use Phalcon\Di;
use Phalcon\Test\Module\UnitTest;
use UnitTester;

class LoadFromPhpCest
{
    /**
     * Unit Tests Phalcon\Di :: loadFromPhp()
     *
     * @author Phalcon Team <team@phalconphp.com>
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
