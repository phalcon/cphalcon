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
use Phalcon\Di\FactoryDefault\Cli as CliDi;
use Phalcon\Events\Manager;

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

        $task      = new Task();
        $container = new CliDi();
        $task->setDi($container);

        $eventsManager = new Manager();
        $task->setEventsManager($eventsManager);

        $expected = $container;
        $actual   = $task->di;
        $I->assertSame($expected, $actual);

        $class  = Manager::class;
        $actual = $task->eventsManager;
        $I->assertInstanceOf($class, $actual);
    }
}
