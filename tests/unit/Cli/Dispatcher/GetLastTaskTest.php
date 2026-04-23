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

namespace Phalcon\Tests\Unit\Cli\Dispatcher;

use Phalcon\Cli\Dispatcher;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Tasks\EchoTask;
use Phalcon\Tests\Support\Tasks\MainTask;

final class GetLastTaskTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testCliDispatcherGetLastTask(): void
    {
        $dispatcher = new Dispatcher();
        $dispatcher->setDI(new DiFactoryDefault());
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Support\Tasks');
        $dispatcher->setTaskName("main");
        $dispatcher->dispatch();

        $class  = MainTask::class;
        $actual = $dispatcher->getLastTask();
        $this->assertInstanceOf($class, $actual);

        $dispatcher->setTaskName("echo");
        $dispatcher->dispatch();

        $class  = EchoTask::class;
        $actual = $dispatcher->getLastTask();
        $this->assertInstanceOf($class, $actual);
    }
}
