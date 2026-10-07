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
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use stdClass;

final class FireAllTest extends AbstractUnitTestCase
{
    /**
     * A type listener and a fully-qualified listener: both responses, type
     * first.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-06
     */
    public function testEventsManagerFireAllBothQueues(): void
    {
        $manager = new Manager();

        $manager->attach('some', function () {
            return 'type';
        });
        $manager->attach('some:event', function () {
            return 'full';
        });

        $actual = $manager->fireAll('some:event', new stdClass());

        $this->assertSame(['type', 'full'], $actual);
    }

    /**
     * Only a fully-qualified listener: its response.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-06
     */
    public function testEventsManagerFireAllFullQueueOnly(): void
    {
        $manager = new Manager();

        $manager->attach('some:event', function () {
            return 'full';
        });

        $actual = $manager->fireAll('some:event', new stdClass());

        $this->assertSame(['full'], $actual);
    }

    /**
     * A type listener that stops the event: the fully-qualified listener
     * does not run.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-06
     */
    public function testEventsManagerFireAllTypeQueueStopSkipsFullQueue(): void
    {
        $manager = new Manager();

        $manager->attach('some', function (Event $event) {
            $event->stop();

            return 'type';
        });
        $manager->attach('some:event', function () {
            return 'full';
        });

        $actual = $manager->fireAll('some:event', new stdClass());

        $this->assertSame(['type'], $actual);
    }
}
