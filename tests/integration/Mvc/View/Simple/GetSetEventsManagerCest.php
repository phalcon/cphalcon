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

namespace Phalcon\Test\Integration\Mvc\View\Simple;

use IntegrationTester;
use Phalcon\Mvc\View\Simple;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class GetSetEventsManagerCest
 */
class GetSetEventsManagerCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\View\Simple :: getEventsManager()/setEventsManager()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcViewSimpleGetSetEventsManager(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Simple - getEventsManager()/setEventsManager()');

        $manager = $this->newService('eventsManager');
        $view    = new Simple();

        $view->setEventsManager($manager);

        $actual = $view->getEventsManager();
        $I->assertEquals($manager, $actual);
    }
}
