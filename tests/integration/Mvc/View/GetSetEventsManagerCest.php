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

namespace Phalcon\Tests\Integration\Mvc\View;

use IntegrationTester;
use Phalcon\Mvc\View;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

/**
 * Class GetSetEventsManagerCest
 */
class GetSetEventsManagerCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\View :: getEventsManager()/setEventsManager()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcViewGetSetEventsManager(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View - getEventsManager()/setEventsManager()');

        $manager = $this->newService('eventsManager');
        $view    = new View();

        $view->setEventsManager($manager);

        $actual = $view->getEventsManager();
        $I->assertEquals($manager, $actual);
    }
}
