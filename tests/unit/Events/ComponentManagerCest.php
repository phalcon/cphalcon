<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Unit\Events;

use Phalcon\Events\Manager;
use Phalcon\Tests\Fixtures\Events\ComponentWithEvents;
use UnitTester;

use function method_exists;

/**
 * Class ComponentManagerCest
 *
 * @package Phalcon\Tests\Unit\Events
 */
class ComponentManagerCest
{
    /**
     * Tests Phalcon\Events\EventsAwareTrait
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function eventsComponentManager(UnitTester $I)
    {
        $I->wantToTest('Events\EventsAwareTrait');

        $manager   = new Manager();
        $component = new ComponentWithEvents();

        $actual = method_exists($component, 'getEventsManager');
        $I->assertTrue($actual);
        $actual = method_exists($component, 'setEventsManager');
        $I->assertTrue($actual);

        $component->setEventsManager($manager);
        $actual = $component->getEventsManager();
        $I->assertSame($manager, $actual);
    }
}
