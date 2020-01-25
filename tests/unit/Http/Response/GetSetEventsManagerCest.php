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

namespace Phalcon\Test\Unit\Http\Response;

use Phalcon\Http\Response;
use Phalcon\Events\Manager;
use UnitTester;

class GetSetEventsManagerCest
{
    /**
     * Unit Tests Phalcon\Http\Response :: getEventsManager() / setEventsManager()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-17
     */
    public function httpResponseGetSetEventsManager(UnitTester $I)
    {
        $I->wantToTest('Http\Response - getEventsManager() / setEventsManager()');

        $oResponse = new Response();
        $oManager = new Manager();

        $oResponse->setEventsManager($oManager);

        $oActual = $oResponse->getEventsManager();

        $I->assertInstanceOf(
            Manager::class,
            $oActual
        );

        $I->assertEquals($oManager, $oActual);
    }
}
