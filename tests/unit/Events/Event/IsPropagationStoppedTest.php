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

namespace Phalcon\Tests\Unit\Events\Event;

use Phalcon\Contracts\Events\Stoppable;
use Phalcon\Events\Event;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

final class IsPropagationStoppedTest extends AbstractUnitTestCase
{
    public function testFreshEventIsNotStopped(): void
    {
        $event = new Event('test:hello', new stdClass());

        $this->assertInstanceOf(Stoppable::class, $event);
        $this->assertFalse($event->isStopped());
        $this->assertFalse($event->isPropagationStopped());
    }

    public function testStopFlipsBothFlags(): void
    {
        $event = new Event('test:hello', new stdClass());

        $event->stop();

        $this->assertTrue($event->isStopped());
        $this->assertTrue($event->isPropagationStopped());
    }
}
