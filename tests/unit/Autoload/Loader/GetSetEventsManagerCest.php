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

namespace Phalcon\Tests\Unit\Autoload\Loader;

use Phalcon\Autoload\Loader;
use Phalcon\Events\Manager;
use UnitTester;

class GetSetEventsManagerCest
{
    /**
     * Tests Phalcon\Autoload\Loader :: getEventsManager() / setEventsManager()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-19
     */
    public function autoloaderLoaderGetSetEventsManager(UnitTester $I)
    {
        $I->wantToTest('Autoload\Loader - getEventsManager() / setEventsManager()');

        $loader  = new Loader();
        $manager = new Manager();

        $loader->setEventsManager($manager);

        $class  = Manager::class;
        $actual = $loader->getEventsManager();
        $I->assertInstanceOf($class, $actual);
        $I->assertEquals($manager, $actual);
    }
}
