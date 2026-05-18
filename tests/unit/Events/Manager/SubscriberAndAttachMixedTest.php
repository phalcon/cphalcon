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

final class SubscriberAndAttachMixedTest extends AbstractUnitTestCase
{
    public function testAttachBeforeAddSubscriberBothFire(): void
    {
        $manager          = new Manager();
        $simpleSubscriber = new SimpleSubscriber();
        $closureHit       = false;

        $manager->attach('test:hello', function () use (&$closureHit) {
            $closureHit = true;
        });
        $manager->addSubscriber($simpleSubscriber);

        $manager->fire('test:hello', $this);

        $this->assertTrue($closureHit);
        $this->assertSame(['hello'], $simpleSubscriber->calls);
        $this->assertCount(2, $manager->getListeners('test:hello'));
    }

    public function testRemoveSubscriberLeavesAttachListenerIntact(): void
    {
        $manager          = new Manager();
        $simpleSubscriber = new SimpleSubscriber();
        $closureHit       = false;
        $plainClosure     = function () use (&$closureHit) {
            $closureHit = true;
        };

        $manager->attach('test:hello', $plainClosure);
        $manager->addSubscriber($simpleSubscriber);
        $manager->removeSubscriber($simpleSubscriber);

        $manager->fire('test:hello', $this);

        $this->assertTrue(
            $closureHit,
            'attach() listener must survive removeSubscriber()'
        );
        $this->assertSame(
            [],
            $simpleSubscriber->calls,
            'Subscriber method must not fire after remove'
        );
    }
}
