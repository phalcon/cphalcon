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

namespace Phalcon\Tests\Unit\Mvc\Controller;

use Phalcon\Events\Manager as EventsManager;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Controllers\ViewRequestController;
use Phalcon\Tests\Support\Traits\DiTrait;

class GetEventsManagerTest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @author Cameron Hall <me@chall.id.au>
     * @since  2019-10-03
     */
    public function testMvcControllerGetEventsManager(): void
    {
        $di = $this->newService('factoryDefault');

        $controller = new ViewRequestController();

        $controller->setDI($di);

        $this->assertInstanceOf(
            EventsManager::class,
            $controller->eventsManager
        );
    }
}
