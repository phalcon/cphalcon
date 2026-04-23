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

use Phalcon\Events\Exception;
use Phalcon\Events\Manager;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

final class DetachTest extends AbstractUnitTestCase
{
    /**
     * @return array
     */
    public static function booleanProvider(): array
    {
        return [
            [true],
            [false],
        ];
    }

    /**
     * @dataProvider booleanProvider
     *
     * @issue 12882
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEventsManagerDetach(
        bool $enablePriorities
    ): void {
        $eventType = 'test:detachable';
        $manager   = new Manager();
        $manager->enablePriorities($enablePriorities);

        $handlerOne = function () {
            echo __METHOD__;
        };
        $handlerTwo = new stdClass();
        $manager->attach($eventType, $handlerOne);

        $events = $this->getProtectedProperty($manager, 'events');

        $this->assertCount(1, $events);
        $this->assertArrayHasKey($eventType, $events);
        $this->assertCount(1, $events[$eventType]);

        $manager->detach($eventType, $handlerTwo);
        $events = $this->getProtectedProperty($manager, 'events');

        $this->assertCount(1, $events);
        $this->assertArrayHasKey($eventType, $events);
        $this->assertCount(1, $events[$eventType]);

        $manager->detach($eventType, $handlerOne);
        $events = $this->getProtectedProperty($manager, 'events');

        $this->assertCount(1, $events);
        $this->assertArrayHasKey($eventType, $events);
        $this->assertCount(0, $events[$eventType]);
    }
}
