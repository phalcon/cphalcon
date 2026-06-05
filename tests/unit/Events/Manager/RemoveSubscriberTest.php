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
use Phalcon\Tests\Unit\Events\Manager\Fake\MultiListenerSubscriber;
use Phalcon\Tests\Unit\Events\Manager\Fake\SimpleSubscriber;

final class RemoveSubscriberTest extends AbstractUnitTestCase
{
    public function testRemoveSubscriberDetachesSimpleForm(): void
    {
        $manager          = new Manager();
        $simpleSubscriber = new SimpleSubscriber();

        $manager->addSubscriber($simpleSubscriber);
        $this->assertCount(1, $manager->getListeners('test:hello'));

        $manager->removeSubscriber($simpleSubscriber);

        $this->assertCount(0, $manager->getListeners('test:hello'));

        $manager->fire('test:hello', $this);
        $this->assertSame([], $simpleSubscriber->calls);
    }

    public function testRemoveSubscriberDetachesMultiListenerForm(): void
    {
        $manager         = new Manager();
        $multiSubscriber = new MultiListenerSubscriber();

        $manager->addSubscriber($multiSubscriber);
        $this->assertCount(3, $manager->getListeners('test:multi'));

        $manager->removeSubscriber($multiSubscriber);

        $this->assertCount(0, $manager->getListeners('test:multi'));
    }

    public function testRemoveSubscriberIsIdempotent(): void
    {
        $manager          = new Manager();
        $simpleSubscriber = new SimpleSubscriber();

        // Never added - must not throw.
        $manager->removeSubscriber($simpleSubscriber);

        $manager->addSubscriber($simpleSubscriber);
        $manager->removeSubscriber($simpleSubscriber);
        // Double-remove - must not throw.
        $manager->removeSubscriber($simpleSubscriber);

        $this->assertCount(0, $manager->getListeners('test:hello'));
    }
}
