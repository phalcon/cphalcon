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

namespace Phalcon\Tests\Unit\Dispatcher;

use Phalcon\Events\Manager;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetEventsManagerTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-17
     */
    public function testDispatcherGetSetEventsManager(): void
    {
        $dispatcher = new Dispatcher();
        $manager    = new Manager();

        $dispatcher->setEventsManager($manager);

        $actual = $dispatcher->getEventsManager();
        $this->assertSame($manager, $actual);

        $class = Manager::class;
        $this->assertInstanceOf($class, $actual);
    }
}
