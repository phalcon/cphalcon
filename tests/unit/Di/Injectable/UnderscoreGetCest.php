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
use Phalcon\Di;
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

        $container = Di::getDefault();

        $crypt= $container->getShared('crypt');
        $container->setShared('testComponent', new ComponentExtendingAbstractInjectable());
        $testComponent = $container->get('testComponent');

        $cryptFromInjectable = $testComponent->crypt;
        $I->assertEquals($crypt, $cryptFromInjectable);

        //Issue 14269
        $eventsManager = $container->getShared('eventsManager');
        $I->assertInstanceOf('Phalcon\Events\Manager', $eventsManager);
        $eventsManagerFromInjectable = $testComponent->eventsManager;
        $I->assertEquals($eventsManager, $eventsManagerFromInjectable);
    }
}
