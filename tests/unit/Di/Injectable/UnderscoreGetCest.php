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

namespace Phalcon\Test\Unit\Di\Injectable;

use UnitTester;
use Phalcon\Events\Manager;
use Phalcon\Di\FactoryDefault;
use Phalcon\Test\Fixtures\Di\ComponentExtendingAbstractInjectable;

class UnderscoreGetCest
{
    /**
     * Unit Tests Phalcon\Di\Injectable :: __get()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-06-13
     */
    public function diInjectableUnderscoreGet(UnitTester $I)
    {
        $I->wantToTest('Di\Injectable - __get()');

        $di = new FactoryDefault();

        $crypt= $di->getShared('crypt');
        $di->setShared('testComponent', new ComponentExtendingAbstractInjectable());
        $testComponent = $di->get('testComponent');

        $cryptFromInjectable = $testComponent->crypt;
        $I->assertEquals($crypt, $cryptFromInjectable);

        //Issue 14269
        $eventsManager = $di->getShared('eventsManager');
        $I->assertInstanceOf('Phalcon\Events\Manager', $eventsManager);
        $eventsManagerFromInjectable = $testComponent->eventsManager;
        $I->assertEquals($eventsManager, $testComponent->getEventsManager());
        $I->assertEquals($eventsManager, $eventsManagerFromInjectable);

        $newEventManager = new Manager();
        $testComponent->setEventManager($newEventManager);
        $I->assertEquals($newEventManager, $testComponent->eventsManager);
        $I->assertEquals($newEventManager, $testComponent->getEventsManager());
    }
}
