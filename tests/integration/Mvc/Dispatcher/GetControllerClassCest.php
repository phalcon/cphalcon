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

use Foo\IndexController;
use IntegrationTester;
use Phalcon\Tests\Integration\Mvc\Dispatcher\Helper\BaseDispatcher;

class GetControllerClassCest extends BaseDispatcher
{
    /**
     * Tests Phalcon\Mvc\Dispatcher :: getControllerClass()
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function mvcDispatcherGetControllerClass(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Dispatcher - getControllerClass()');

        $dispatcher = $this->getDispatcher();

        $dispatcher->setNamespaceName('Foo');
        $dispatcher->setControllerName('');
        $dispatcher->setActionName('');

        $I->assertEquals(
            'Foo',
            $dispatcher->getNamespaceName()
        );

        $I->assertEquals(
            '',
            $dispatcher->getControllerName()
        );

        $I->assertEquals(
            '',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            IndexController::class,
            $dispatcher->getControllerClass()
        );
    }
}
