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
 * Class GetHandlerClassCest
 */
class GetHandlerClassCest
{
    /**
     * Tests Phalcon\Dispatcher :: getHandlerClass()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dispatcherGetHandlerClass(UnitTester $I)
    {
        $I->wantToTest('Dispatcher - getHandlerClass()');

        $dispatcher = new Dispatcher();

        // test the handler name
        $dispatcher->setNamespaceName('');
        $dispatcher->setHandlerSuffix('');

        $dispatcher->setControllerName('hello');
        $actualHandler = $dispatcher->getHandlerClass();
        $I->assertEquals('Hello', $actualHandler);

        $dispatcher->setControllerName('hello-phalcon');
        $actualHandler = $dispatcher->getHandlerClass();
        $I->assertEquals('HelloPhalcon', $actualHandler);

        $dispatcher->setControllerName('hello_phalcon');
        $actualHandler = $dispatcher->getHandlerClass();
        $I->assertEquals('HelloPhalcon', $actualHandler);

        $dispatcher->setControllerName('HelloPhalcon');
        $actualHandler = $dispatcher->getHandlerClass();
        $I->assertEquals('HelloPhalcon', $actualHandler);

        $dispatcher->setControllerName('Hello\\Phalcon');
        $actualHandler = $dispatcher->getHandlerClass();
        $I->assertEquals('Hello\\Phalcon', $actualHandler);

        // test the suffix
        $dispatcher->setHandlerSuffix('Ctrl');

        $dispatcher->setControllerName('hello');
        $actualHandler = $dispatcher->getHandlerClass();
        $I->assertEquals('HelloCtrl', $actualHandler);

        $dispatcher->setControllerName('hello-phalcon');
        $actualHandler = $dispatcher->getHandlerClass();
        $I->assertEquals('HelloPhalconCtrl', $actualHandler);

        $dispatcher->setControllerName('hello_phalcon');
        $actualHandler = $dispatcher->getHandlerClass();
        $I->assertEquals('HelloPhalconCtrl', $actualHandler);

        $dispatcher->setControllerName('Hello\\Phalcon');
        $actualHandler = $dispatcher->getHandlerClass();
        $I->assertEquals('Hello\\PhalconCtrl', $actualHandler);

        $dispatcher->setControllerName('hello_ns\\Phalcon');
        $actualHandler = $dispatcher->getHandlerClass();
        $I->assertEquals('hello_ns\\PhalconCtrl', $actualHandler);

        // test the namespace
        $dispatcher->setNamespaceName('App');
        $dispatcher->setControllerName('hello');
        $actualHandler = $dispatcher->getHandlerClass();
        $I->assertEquals('App\\HelloCtrl', $actualHandler);

        $dispatcher->setNamespaceName('Ola\\');
        $dispatcher->setControllerName('phalcon');
        $actualHandler = $dispatcher->getHandlerClass();
        $I->assertEquals('Ola\\PhalconCtrl', $actualHandler);

    }
}
