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

namespace Phalcon\Test\Integration\Mvc\Dispatcher;

use IntegrationTester;
use Phalcon\Test\Integration\Mvc\Dispatcher\Helper\BaseDispatcher;

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
            \Foo\IndexController::class,
            $dispatcher->getControllerClass()
        );
    }
}
