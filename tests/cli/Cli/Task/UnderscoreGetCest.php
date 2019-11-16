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

namespace Phalcon\Test\Cli\Cli\Task;

use CliTester;
use Phalcon\Events\Manager;
use Phalcon\Cli\Task;
use Phalcon\Di\FactoryDefault\Cli as CliDi;

class UnderscoreGetCest
{
    /**
     * Tests Phalcon\Cli\Task :: __get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliTaskUnderscoreGet(CliTester $I)
    {
        $I->wantToTest('Cli\Task - __get()');


        $task = new Task();
        $di = new CliDi();
        $task->setDi($di);

        $eventsManager = new Manager();
        $task->setEventsManager($eventsManager);

        $I->assertEquals($di, $task->di);
        $I->assertEquals($eventsManager, $task->eventsManager);
    }
}
