<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Cli\Cli\Dispatcher;

use CliTester;
use Phalcon\Cli\Dispatcher;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;

/**
 * Class GetActiveTaskCest
 */
class GetActiveTaskCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: getActiveTask()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliDispatcherGetActiveTask(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - getActiveTask()');
        $dispatcher = new Dispatcher();
        $dispatcher->setDI(
            new DiFactoryDefault()
        );
        $dispatcher->setDefaultNamespace('Phalcon\Test\Fixtures\Tasks');
        $dispatcher->setTaskName("main");
        $dispatcher->dispatch();

        $I->assertInstanceOf('\Phalcon\Test\Fixtures\Tasks\MainTask', $dispatcher->getActiveTask());
    }
}
