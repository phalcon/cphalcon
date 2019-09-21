<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Di\Injectable;

use Phalcon\Di\FactoryDefault;
use Phalcon\Di\Injectable;
use Phalcon\Events\Manager;
use UnitTester;

class GetEventsManagerCest
{
    /**
     * Unit Tests Phalcon\Di\Injectable :: getEventsManager()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function diInjectableGetEventsManager(UnitTester $I)
    {
        $I->wantToTest('Di\Injectable - getEventsManager()');

        $di = new FactoryDefault();
        $I->assertNull(
            $di->getInternalEventsManager()
        );


        $injectable = new class extends Injectable {
        };

        // Prove they are the same object. <---- Works
        $I->assertEquals(
            spl_object_hash($injectable->eventsManager),
            spl_object_hash($di->getEventsManager())
        );

        $newManager = new Manager();
        $injectable->setEventsManager($newManager);

        // Prove they are the same object. <---- Fails
        $I->assertEquals(
            spl_object_hash($injectable->eventsManager),
            spl_object_hash($newManager)
        );

        // Prove they are the same object. <---- Works
        $I->assertEquals(
            spl_object_hash($injectable->getEventsManager()),
            spl_object_hash($newManager)
        );
    }
}
