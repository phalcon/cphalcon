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

namespace Phalcon\Test\Cli\Cli\Task;

use CliTester;
use Phalcon\Events\Manager;
use Phalcon\Cli\Task;

class GetEventsManagerCest
{
    /**
     * Tests Phalcon\Cli\Task :: getEventsManager()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliTaskGetEventsManager(CliTester $I)
    {
        $I->wantToTest('Cli\Task - getEventsManager()');
        $eventsManager = new Manager();
        $task = new Task();
        $task->setEventsManager($eventsManager);
        $I->assertEquals($eventsManager, $task->getEventsManager());
    }
}
