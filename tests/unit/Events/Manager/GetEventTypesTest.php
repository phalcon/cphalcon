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
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Listener\OneListener;
use Phalcon\Tests\Support\Listener\TwoListener;
use Phalcon\Tests\Unit\Events\Manager\Fake\SimpleSubscriber;

final class GetEventTypesTest extends AbstractUnitTestCase
{
    public function testGetEventTypesDropsTypeWhenLastListenerDetached(): void
    {
        $manager  = new Manager();
        $listener = new OneListener();

        $manager->attach('log', $listener);
        $manager->attach('db', $listener);

        $manager->detach('log', $listener);

        $this->assertSame(['db'], $manager->getEventTypes());

        $manager->detachAll('db');

        $this->assertSame([], $manager->getEventTypes());
    }

    public function testGetEventTypesIncludesSubscriberTypes(): void
    {
        $manager    = new Manager();
        $listener   = new OneListener();
        $subscriber = new SimpleSubscriber();

        $manager->attach('log', $listener);
        $manager->addSubscriber($subscriber);

        $actual = $manager->getEventTypes();

        $this->assertCount(2, $actual);
        $this->assertContains('log', $actual);
        $this->assertContains('test:hello', $actual);
    }

    public function testGetEventTypesReturnsEmptyArrayWhenNothingAttached(): void
    {
        $manager = new Manager();

        $this->assertSame([], $manager->getEventTypes());
    }

    public function testGetEventTypesReturnsEachTypeOnce(): void
    {
        $manager = new Manager();
        $first   = new OneListener();
        $second  = new TwoListener();

        $manager->attach('log', $first);
        $manager->attach('log', $second);
        $manager->attach('db', $first);

        $this->assertSame(['log', 'db'], $manager->getEventTypes());
    }
}
