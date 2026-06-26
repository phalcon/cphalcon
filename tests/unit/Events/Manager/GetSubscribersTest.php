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

final class GetSubscribersTest extends AbstractUnitTestCase
{
    public function testGetSubscribersDoesNotIncludeRemoved(): void
    {
        $manager          = new Manager();
        $simpleSubscriber = new SimpleSubscriber();
        $multiSubscriber  = new MultiListenerSubscriber();

        $manager->addSubscriber($simpleSubscriber);
        $manager->addSubscriber($multiSubscriber);
        $manager->removeSubscriber($simpleSubscriber);

        $registered = $manager->getSubscribers();

        $this->assertCount(1, $registered);
        $this->assertSame($multiSubscriber, $registered[0]);
    }
    public function testGetSubscribersReturnsRegisteredInstances(): void
    {
        $manager = new Manager();

        $this->assertSame([], $manager->getSubscribers());

        $simpleSubscriber = new SimpleSubscriber();
        $multiSubscriber  = new MultiListenerSubscriber();

        $manager->addSubscriber($simpleSubscriber);
        $manager->addSubscriber($multiSubscriber);

        $registered = $manager->getSubscribers();

        $this->assertCount(2, $registered);
        $this->assertContains($simpleSubscriber, $registered);
        $this->assertContains($multiSubscriber, $registered);
    }
}
