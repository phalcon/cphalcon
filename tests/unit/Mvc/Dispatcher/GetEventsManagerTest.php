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

namespace Phalcon\Tests\Unit\Mvc\Dispatcher;

use Phalcon\Events\Manager as EventsManager;
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\BaseDispatcher;

class GetEventsManagerTest extends BaseDispatcher
{
    /**
     * Tests Phalcon\Mvc\Dispatcher :: getEventsManager()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcDispatcherGetEventsManager(): void
    {
        $dispatcher = $this->getDispatcher();
        $this->assertInstanceOf(
            EventsManager::class,
            $dispatcher->getEventsManager()
        );
    }
}
