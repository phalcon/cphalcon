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

use Codeception\Example;
use Phalcon\Mvc\Dispatcher;
use UnitTester;

class GetActiveMethodCest
{
    /**
     * Tests Phalcon\Dispatcher :: getActiveMethod()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider dispatcherGetActiveMethodProvider
     */
    public function dispatcherGetActiveMethod(UnitTester $I, Example $example)
    {
        $I->wantToTest('Dispatcher - getActiveMethod()');

        $dispatcher = new Dispatcher();

        $dispatcher->setActionSuffix('Action');


        $dispatcher->setActionName(
            $example['actionName']
        );

        $I->assertEquals(
            $example['expected'],
            $dispatcher->getActiveMethod()
        );
    }

    private function dispatcherGetActiveMethodProvider(): array
    {
        return [
            [
                'actionName' => 'hello-phalcon',
                'expected'   => 'helloPhalconAction',
            ],

            [
                'actionName' => 'home_page',
                'expected'   => 'homePageAction',
            ],

            [
                'actionName' => 'secondPage',
                'expected'   => 'secondPageAction',
            ],

            [
                'actionName' => 'ThirdPage',
                'expected'   => 'thirdPageAction',
            ],
        ];
    }
}
