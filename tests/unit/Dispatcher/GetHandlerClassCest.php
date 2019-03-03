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

use Codeception\Example;
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
     * @param array $entry
     * @dataProvider getTestCases
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dispatcherGetHandlerClass(UnitTester $I, Example $entry)
    {
        $I->wantToTest('Dispatcher - getHandlerClass()');

        $dispatcher = new Dispatcher();

        // test the handler name
        $dispatcher->setNamespaceName($entry[0]);
        $dispatcher->setControllerName($entry[1]);
        $dispatcher->setHandlerSuffix($entry[2]);
        $actualHandler = $dispatcher->getHandlerClass();
        $I->assertEquals($entry[3], $actualHandler);
    }

    private function getTestCases()
    {
        return [
            ['', 'hello', '', 'Hello'],
            ['', 'hello-phalcon', '', 'HelloPhalcon'],
            ['', 'hello_phalcon', '', 'HelloPhalcon'],
            ['', 'HelloPhalcon', '', 'HelloPhalcon'],
            ['', 'Hello\\Phalcon', '', 'Hello\\Phalcon'],
            ['', 'non_std\\Phalcon', '', 'non_std\\Phalcon'],
            // include the suffix
            ['', 'hello', 'Ctrl', 'HelloCtrl'],
            ['', 'hello-phalcon', 'Ctrl', 'HelloPhalconCtrl'],
            ['', 'hello_phalcon', 'Ctrl', 'HelloPhalconCtrl'],
            ['', 'HelloPhalcon', 'Ctrl', 'HelloPhalconCtrl'],
            ['', 'Hello\\Phalcon', 'Ctrl', 'Hello\\PhalconCtrl'],
            // include the namespace
            ['Ola', 'hello', 'Ctrl', 'Ola\\HelloCtrl'],
            ['Ola', 'hello-phalcon', 'Ctrl', 'Ola\\HelloPhalconCtrl'],
            ['ola\\', 'hello_phalcon', 'Ctrl', 'ola\\HelloPhalconCtrl'],
            ['ola_phalcon\\', 'HelloPhalcon', 'Ctrl', 'ola_phalcon\\HelloPhalconCtrl'],
            ['Ola\\', 'Hello\\Phalcon', 'Ctrl', 'Ola\\Hello\\PhalconCtrl'],
        ];
    }
}
