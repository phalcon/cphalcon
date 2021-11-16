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

namespace Phalcon\Tests\Integration\Mvc\Dispatcher;

use IntegrationTester;
use Phalcon\Tests\Integration\Mvc\Dispatcher\Helper\BaseDispatcher;
use Phalcon\Tests\Integration\Mvc\Dispatcher\Helper\DispatcherTestDefaultController;

class CallActionMethodCest extends BaseDispatcher
{
    /**
     * Tests Phalcon\Mvc\Dispatcher :: callActionMethod()
     * Tests directly calling controller's action via the dispatcher manually
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function mvcDispatcherCallActionMethod(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Dispatcher - callActionMethod()');

        $multiply = [5, 6];

        $controller = new DispatcherTestDefaultController();

        $controller->setDI(
            $this->getDI()
        );

        $returnValue = $this->getDispatcher()->callActionMethod(
            $controller,
            'multiplyAction',
            $multiply
        )
        ;

        $I->assertEquals(30, $returnValue);

        $I->assertEquals(
            ['multiplyAction'],
            $this->getDispatcherListener()->getTrace()
        );
    }
}
