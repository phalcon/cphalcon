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

namespace Phalcon\Tests\Cli\Cli\Task;

use CliTester;
use Phalcon\Cli\Task;
use Phalcon\Events\Manager;

class GetSetEventsManagerCest
{
    /**
     * Tests Phalcon\Cli\Task :: getEventsManager()/setEventsManager()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliTaskGetSetEventsManager(CliTester $I)
    {
        $I->wantToTest('Cli\Task - getEventsManager()/setEventsManager()');
        $eventsManager = new Manager();
        $task          = new Task();
        $task->setEventsManager($eventsManager);

        $expected = $eventsManager;
        $actual   = $task->getEventsManager();
        $I->assertSame($expected, $actual);
    }
}
