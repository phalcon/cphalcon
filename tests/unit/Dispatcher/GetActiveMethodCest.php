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

namespace Phalcon\Test\Unit\Dispatcher;

use UnitTester;
use Phalcon\Mvc\Dispatcher;

/**
 * Class GetActiveMethodCest
 */
class GetActiveMethodCest
{
    /**
     * Tests Phalcon\Dispatcher :: getActiveMethod()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dispatcherGetActiveMethod(UnitTester $I)
    {
        $I->wantToTest('Dispatcher - getActiveMethod()');

        $dispatcher = new Dispatcher();

        $dispatcher->setActionSuffix('Action');

        $dispatcher->setActionName('hello-phalcon');
        $actualMethod = $dispatcher->getActiveMethod();
        $I->assertEquals('helloPhalconAction', $actualMethod);

        $dispatcher->setActionName('home_page');
        $actualMethod = $dispatcher->getActiveMethod();
        $I->assertEquals('homePageAction', $actualMethod);

        $dispatcher->setActionName('secondPage');
        $actualMethod = $dispatcher->getActiveMethod();
        $I->assertEquals('secondPageAction', $actualMethod);

        $dispatcher->setActionName('ThirdPage');
        $actualMethod = $dispatcher->getActiveMethod();
        $I->assertEquals('thirdPageAction', $actualMethod);
    }
}
