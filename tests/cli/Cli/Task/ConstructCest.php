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

namespace Phalcon\Test\Cli\Cli\Task;

use CliTester;
use Phalcon\Cli\Task;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;
use Phalcon\Registry;
use Phalcon\Test\Fixtures\Tasks\EchoTask;
use Phalcon\Test\Fixtures\Tasks\MainTask;
use Phalcon\Test\Fixtures\Tasks\OnConstructTask;

class ConstructCest
{
    /**
     * Tests Phalcon\Cli\Task :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliTaskConstruct(CliTester $I)
    {
        $I->wantToTest('Cli\Task - __construct()');
        $task = new Task();
        $I->assertInstanceOf(Task::class, $task);

        $task = new OnConstructTask();
        $I->assertTrue($task->onConstructExecuted);
    }

    public function extendTask(CliTester $I)
    {
        $di             = new DiFactoryDefault();
        $di['registry'] = function () {
            $registry = new Registry();

            $registry->data = 'data';

            return $registry;
        };

        $task = new MainTask();
        $task->setDI($di);

        $I->assertEquals('data', $task->requestRegistryAction());
        $I->assertEquals('Hello !', $task->helloAction());
        $I->assertEquals('Hello World!', $task->helloAction('World'));
    }

    public function echoTask(CliTester $I)
    {
        $task = new EchoTask();
        $di   = new DiFactoryDefault();

        $task->setDI($di);

        $I->assertEquals('echoMainAction', $task->mainAction());
    }
}
