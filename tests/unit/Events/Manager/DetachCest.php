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

namespace Phalcon\Tests\Unit\Events\Manager;

use Codeception\Example;
use Phalcon\Events\Exception;
use Phalcon\Events\Manager;
use stdClass;
use UnitTester;

class DetachCest
{
    /**
     * Tests detach handler by using an Object
     *
     * @dataProvider booleanProvider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     * @issue        12882
     */
    public function eventsManagerDetach(UnitTester $I, Example $example)
    {
        $enablePriorities = $example[0];

        $eventType = 'test:detachable';
        $manager   = new Manager();
        $manager->enablePriorities($enablePriorities);

        $handlerOne = function () {
            echo __METHOD__;
        };
        $handlerTwo = new stdClass();
        $manager->attach($eventType, $handlerOne);

        $events = $I->getProtectedProperty($manager, 'events');

        $I->assertCount(1, $events);
        $I->assertArrayHasKey($eventType, $events);
        $I->assertCount(1, $events[$eventType]);

        $manager->detach($eventType, $handlerTwo);
        $events = $I->getProtectedProperty($manager, 'events');

        $I->assertCount(1, $events);
        $I->assertArrayHasKey($eventType, $events);
        $I->assertCount(1, $events[$eventType]);

        $manager->detach($eventType, $handlerOne);
        $events = $I->getProtectedProperty($manager, 'events');

        $I->assertCount(1, $events);
        $I->assertArrayHasKey($eventType, $events);
        $I->assertCount(0, $events[$eventType]);
    }

    /**
     * Tests detach handler by using an Object - exception
     *
     * @dataProvider booleanProvider
     *
     * @param UnitTester $I
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function eventsManagerDetachException(UnitTester $I)
    {
        $I->wantToTest('Events\Manager - detach()');

        $I->expectThrowable(
            new Exception('Event handler must be an Object or Callable'),
            function () {
                $manager = new Manager();
                $manager->detach('test:detachable', false);
            }
        );
    }

    /**
     * @return array
     */
    private function booleanProvider(): array
    {
        return [
            [true],
            [false],
        ];
    }
}
