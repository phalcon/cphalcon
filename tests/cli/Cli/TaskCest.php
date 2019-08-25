<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Cli\Cli;

use CliTester;
use EchoTask;
use MainTask;
use Phalcon\Registry;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class TaskCest
{
    use DiTrait;

    public function _before(CliTester $I)
    {
        $this->setNewCliFactoryDefault();
    }

    public function testMainTask(CliTester $I)
    {
        /**
         * @todo Check the loader
         */
        require_once dataDir('fixtures/tasks/MainTask.php');

        $this->container['registry'] = function () {
            $registry = new Registry();

            $registry->data = 'data';

            return $registry;
        };

        $task = new MainTask();

        $task->setDI(
            $this->container
        );

        $I->assertEquals(
            'data',
            $task->requestRegistryAction()
        );

        $I->assertEquals(
            'Hello !',
            $task->helloAction()
        );

        $I->assertEquals(
            'Hello World!',
            $task->helloAction('World')
        );
    }

    public function testEchoTask(CliTester $I)
    {
        /**
         * @todo Check the loader
         */
        require_once dataDir('fixtures/tasks/EchoTask.php');

        $task = new EchoTask();

        $task->setDI(
            $this->container
        );

        $I->assertEquals(
            'echoMainAction',
            $task->mainAction()
        );
    }
}
