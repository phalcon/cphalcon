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

namespace Phalcon\Test\Cli\Cli\Dispatcher;

use CliTester;
use Phalcon\Cli\Dispatcher;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;

class GetLastTaskCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: getLastTask()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliDispatcherGetLastTask(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - getLastTask()');
        $dispatcher = new Dispatcher();
        $dispatcher->setDI(
            new DiFactoryDefault()
        );
        $dispatcher->setDefaultNamespace('Phalcon\Test\Fixtures\Tasks');
        $dispatcher->setTaskName("main");
        $dispatcher->dispatch();

        $I->assertInstanceOf('\Phalcon\Test\Fixtures\Tasks\MainTask', $dispatcher->getLastTask());

        $dispatcher->setTaskName("echo");
        $dispatcher->dispatch();

        $I->assertInstanceOf('\Phalcon\Test\Fixtures\Tasks\EchoTask', $dispatcher->getLastTask());
    }
}
