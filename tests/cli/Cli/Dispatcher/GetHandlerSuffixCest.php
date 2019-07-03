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

namespace Phalcon\Test\Cli\Cli\Dispatcher;

use CliTester;
use Phalcon\Cli\Dispatcher;
use Phalcon\Cli\Dispatcher\Exception;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class GetHandlerSuffixCest
{
    use DiTrait;

    public function _before(CliTester $I)
    {
        $this->setNewCliFactoryDefault();
    }

    /**
     * Tests Phalcon\Cli\Dispatcher :: getHandlerSuffix()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-01
     */
    public function cliDispatcherGetHandlerSuffix(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - getHandlerSuffix()');

        $dispatcher = new Dispatcher();

        $this->container->setShared('dispatcher', $dispatcher);

        $dispatcher->setDI(
            $this->container
        );

        $dispatcher->setTaskName('Index');

        $dispatcher->setTaskSuffix('Bleh');

        $I->expectThrowable(
            new Exception(
                'IndexBleh handler class cannot be loaded',
                Dispatcher::EXCEPTION_HANDLER_NOT_FOUND
            ),
            function () use ($dispatcher) {
                $dispatcher->dispatch();
            }
        );
    }
}
