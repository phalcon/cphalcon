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
use Phalcon\Events\Manager;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetEventsManagerTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testCliTaskGetSetEventsManager(): void
    {
        $eventsManager = new Manager();
        $task          = new Task();
        $task->setEventsManager($eventsManager);

        $expected = $eventsManager;
        $actual   = $task->getEventsManager();
        $this->assertSame($expected, $actual);
    }
}
