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

use Phalcon\Events\Manager;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Events\Manager\Fake\SimpleSubscriber;

final class AddSubscriberTest extends AbstractUnitTestCase
{
    public function testAddSubscriberSimpleStringForm(): void
    {
        $manager    = new Manager();
        $subscriber = new SimpleSubscriber();

        $manager->addSubscriber($subscriber);

        $listeners = $manager->getListeners('test:hello');
        $this->assertCount(1, $listeners);
        $this->assertSame([$subscriber, 'onHello'], $listeners[0]);

        $manager->fire('test:hello', $this);

        $this->assertSame(['hello'], $subscriber->calls);
    }
}
