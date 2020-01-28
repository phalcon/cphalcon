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

namespace Phalcon\Test\Integration\Mvc\Controller;

use IntegrationTester;
use Phalcon\Events\Manager as EventsManager;
use Phalcon\Test\Controllers\ViewRequestController;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class GetEventsManagerCest
 */
class GetEventsManagerCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\Controller :: getEventsManager()
     *
     * @author Cameron Hall <me@chall.id.au>
     * @since  2019-10-03
     */
    public function mvcControllerGetEventsManager(IntegrationTester $I)
    {
        $di = $this->newFactoryDefault();

        $controller = new ViewRequestController();

        $controller->setDI($di);

        $I->assertInstanceOf(
            EventsManager::class,
            $controller->eventsManager
        );
    }
}
