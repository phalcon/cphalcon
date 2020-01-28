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
use Phalcon\Mvc\Dispatcher\Exception;
use Phalcon\Test\Integration\Mvc\Dispatcher\Helper\BaseDispatcher;

class GetHandlerSuffixCest extends BaseDispatcher
{
    /**
     * Tests Phalcon\Mvc\Dispatcher :: getHandlerSuffix()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-01
     */
    public function mvcDispatcherGetHandlerSuffix(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Dispatcher - getHandlerSuffix()');

        $dispatcher = $this->getDispatcher();

        $dispatcher->setControllerName('Index');

        $dispatcher->setControllerSuffix('Bleh');

        $I->expectThrowable(
            new Exception(
                'Phalcon\Test\Integration\Mvc\Dispatcher\Helper\IndexBleh handler class cannot be loaded',
                Exception::EXCEPTION_HANDLER_NOT_FOUND
            ),
            function () use ($dispatcher) {
                $dispatcher->dispatch();
            }
        );
    }
}
