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

namespace Phalcon\Tests\Unit\Dispatcher;

use Phalcon\Events\Manager;
use Phalcon\Mvc\Dispatcher;
use UnitTester;

class GetSetEventsManagerCest
{
    /**
     * Tests Phalcon\Dispatcher :: getEventsManager()/setEventsManager()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-17
     */
    public function dispatcherGetSetEventsManager(UnitTester $I)
    {
        $I->wantToTest('Dispatcher - getEventsManager() / setEventsManager()');

        $dispatcher = new Dispatcher();
        $manager    = new Manager();

        $dispatcher->setEventsManager($manager);

        $actual = $dispatcher->getEventsManager();
        $I->assertEquals($manager, $actual);

        $class  = Manager::class;
        $I->assertInstanceOf($class, $actual);
    }
}
