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

namespace Phalcon\Tests\Unit\Mvc\Application;

use Phalcon\Di\Di;
use Phalcon\Events\Manager as EventsManager;
use Phalcon\Mvc\Application;
use Phalcon\Tests\AbstractUnitTestCase;

class GetEventsManagerTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcApplicationGetEventsManager(): void
    {
        $container     = new Di();
        $application   = new Application($container);
        $eventsManager = new EventsManager();
        $application->setEventsManager($eventsManager);

        $this->assertSame($eventsManager, $application->getEventsManager());
    }
}
