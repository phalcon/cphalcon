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

namespace Phalcon\Test\Integration\Mvc\Dispatcher;

use IntegrationTester;
use Phalcon\Test\Integration\Mvc\Dispatcher\Helper\BaseDispatcher;
use Phalcon\Test\Integration\Mvc\Dispatcher\Helper\DispatcherTestDefaultController;
use Phalcon\Test\Integration\Mvc\Dispatcher\Helper\DispatcherTestDefaultTwoController;

class GetLastControllerCest extends BaseDispatcher
{
    /**
     * Tests Phalcon\Mvc\Dispatcher :: getLastController()
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function mvcDispatcherGetLastController(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Dispatcher - getLastController()');

        $dispatcher = $this->getDispatcher();

        $dispatcher->dispatch();

        $I->assertInstanceOf(
            DispatcherTestDefaultController::class,
            $dispatcher->getLastController()
        );
    }

    /**
     * Tests the last handler on a forward
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testLastHandlerForward(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Dispatcher - getLastController() with a forward');

        $dispatcher = $this->getDispatcher();

        $dispatcher->setActionName('forwardExternal');

        $dispatcher->dispatch();

        $I->assertInstanceOf(
            DispatcherTestDefaultTwoController::class,
            $dispatcher->getLastController()
        );
    }
}
