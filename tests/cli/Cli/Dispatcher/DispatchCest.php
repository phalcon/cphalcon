<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Cli\Cli\Dispatcher;

use CliTester;
use Phalcon\Cli\Dispatcher;
use Phalcon\Cli\Dispatcher\Exception;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class DispatchCest
{
    use DiTrait;

    public function _before(CliTester $I)
    {
        $this->setNewCliFactoryDefault();
    }

    /**
     * Tests Phalcon\Cli\Dispatcher :: dispatch()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliDispatcherDispatch(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - dispatch()');

        $I->skipTest('Need implementation');
    }

    public function testFakeNamespace(CliTester $I)
    {
        $dispatcher = new Dispatcher();

        $dispatcher->setDI(
            $this->container
        );

        $dispatcher->setDefaultNamespace('Dummy\\');
        $dispatcher->setTaskName('main');
        $dispatcher->setActionName('hello');

        $dispatcher->setParams(
            ['World']
        );

        $I->expectThrowable(
            new Exception(
                'Dummy\MainTask handler class cannot be loaded',
                Exception::EXCEPTION_HANDLER_NOT_FOUND
            ),
            function () use ($dispatcher) {
                $dispatcher->dispatch();
            }
        );
    }
}
