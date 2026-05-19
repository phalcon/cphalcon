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

use Phalcon\Events\Event;
use Phalcon\Events\Manager;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

final class FireQueueTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testEventsManagerFireQueue(): void
    {
        $manager = new Manager();
        $manager->collectResponses(true);

        $closureOne = function (Event $event, $source) {
            return 'first';
        };
        $closureTwo = function (Event $event, $source) {
            return 'second';
        };

        // Internal queue tuple format: [handler, type, priority, class].
        // type=0 marks a Closure handler.
        $queue = [
            [$closureOne, 0, 100, ''],
            [$closureTwo, 0, 100, ''],
        ];

        $source = new stdClass();
        $event  = new Event('demo:first', $source, null, true);

        $manager->fireQueue($queue, $event);

        $this->assertSame(['first', 'second'], $manager->getResponses());

        // After halt() fireQueue short-circuits and returns null
        $manager->halt();
        $this->assertNull($manager->fireQueue($queue, $event));
    }
}
