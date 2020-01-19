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

namespace Phalcon\Test\Unit\Dispatcher;

use Phalcon\Events\Manager;
use Phalcon\Mvc\Dispatcher;
use UnitTester;

class GetSetEventsManagerCest
{
    /**
     * Tests Phalcon\Dispatcher :: getEventsManager() / setEventsManager()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-17
     */
    public function dispatcherGetSetEventsManager(UnitTester $I)
    {
        $I->wantToTest('Dispatcher - getEventsManager() / setEventsManager()');

        $oDispatcher = new Dispatcher();
        $oManager = new Manager();

        $oDispatcher->setEventsManager($oManager);

        $oActual = $oDispatcher->getEventsManager();

        $I->assertInstanceOf(
            Manager::class,
            $oActual
        );

        $I->assertEquals($oManager, $oActual);
    }
}