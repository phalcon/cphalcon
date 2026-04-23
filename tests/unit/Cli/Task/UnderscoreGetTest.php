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
use Phalcon\Di\FactoryDefault\Cli as CliDi;
use Phalcon\Events\Manager;
use Phalcon\Tests\AbstractUnitTestCase;

final class UnderscoreGetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testCliTaskUnderscoreGet(): void
    {
        $task      = new Task();
        $container = new CliDi();
        $task->setDi($container);

        $eventsManager = new Manager();
        $task->setEventsManager($eventsManager);

        $this->assertSame($container, $task->di);

        $class  = Manager::class;
        $actual = $task->eventsManager;
        $this->assertInstanceOf($class, $actual);
    }
}
