<?php

namespace Phalcon\Test\Unit\Cli;

use Phalcon\Di\FactoryDefault\Cli as CliFactoryDefault;
use Phalcon\Registry;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Cli\TaskTest
 * Tests the \Phalcon\Cli\Task component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Cli
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class TaskTest extends UnitTest
{
    public function testTasks()
    {
        $this->specify(
            "CLI Tasks don't return the expected results",
            function () {
                $di = new CliFactoryDefault();

                $di["registry"] = function () {
                    $registry = new Registry();

                    $registry->data = "data";

                    return $registry;
                };

                $task = new \MainTask();
                $task->setDI($di);

                expect($task->requestRegistryAction())->equals("data");
                expect($task->helloAction())->equals("Hello !");
                expect($task->helloAction(["World"]))->equals("Hello World!");

                $task2 = new \EchoTask();
                $task2->setDI($di);
                expect($task2->mainAction())->equals("echoMainAction");
            }
        );
    }
}
