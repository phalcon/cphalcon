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

namespace Phalcon\Tests\Unit\Cli\Task;

use Phalcon\Cli\Task;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;
use Phalcon\Support\Registry;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Tasks\EchoTask;
use Phalcon\Tests\Support\Tasks\MainTask;
use Phalcon\Tests\Support\Tasks\OnConstructTask;

final class ConstructTest extends AbstractUnitTestCase
{
    public function testEchoTask(): void
    {
        $task = new EchoTask();
        $di   = new DiFactoryDefault();

        $task->setDI($di);

        $expected = 'echoMainAction';
        $actual   = $task->mainAction();
        $this->assertSame($expected, $actual);
    }

    public function testExtendTask(): void
    {
        $di             = new DiFactoryDefault();
        $di['registry'] = function () {
            $registry = new Registry();

            $registry->data = 'data';

            return $registry;
        };

        $task = new MainTask();
        $task->setDI($di);

        $expected = 'data';
        $actual   = $task->requestRegistryAction();
        $this->assertSame($expected, $actual);

        $expected = 'Hello !';
        $actual   = $task->helloAction();
        $this->assertSame($expected, $actual);

        $expected = 'Hello World!';
        $actual   = $task->helloAction('World');
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testCliTaskConstruct(): void
    {
        $task = new Task();

        $class = Task::class;
        $this->assertInstanceOf($class, $task);

        $task = new OnConstructTask();

        $actual = $task->onConstructExecuted;
        $this->assertTrue($actual);
    }
}
