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

use Phalcon\Contracts\Events\Enumerable;
use Phalcon\Events\Manager;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Listener\OneListener;
use Phalcon\Tests\Support\Listener\TwoListener;
use Phalcon\Tests\Unit\Events\Manager\Fake\SimpleSubscriber;

final class GetListenerMapTest extends AbstractUnitTestCase
{
    public function testGetListenerMapDropsTypeWhenLastListenerDetached(): void
    {
        $manager  = new Manager();
        $listener = new OneListener();

        $manager->attach('log', $listener);
        $manager->attach('db', $listener);

        $manager->detach('log', $listener);

        $this->assertSame(['db' => [$listener]], $manager->getListenerMap());

        $manager->detachAll('db');

        $this->assertSame([], $manager->getListenerMap());
    }

    public function testGetListenerMapImplementsEnumerable(): void
    {
        $manager = new Manager();

        $this->assertInstanceOf(Enumerable::class, $manager);
    }

    public function testGetListenerMapIncludesSubscriberTypes(): void
    {
        $manager    = new Manager();
        $listener   = new OneListener();
        $subscriber = new SimpleSubscriber();

        $manager->attach('log', $listener);
        $manager->addSubscriber($subscriber);

        $actual = $manager->getListenerMap();

        $this->assertCount(2, $actual);
        $this->assertArrayHasKey('log', $actual);
        $this->assertArrayHasKey('test:hello', $actual);
    }

    public function testGetListenerMapReturnsEachTypeOnce(): void
    {
        $manager = new Manager();
        $first   = new OneListener();
        $second  = new TwoListener();

        $manager->attach('log', $first);
        $manager->attach('log', $second);
        $manager->attach('db', $first);

        $actual = $manager->getListenerMap();

        $this->assertSame(['log' => [$first, $second], 'db' => [$first]], $actual);
    }

    public function testGetListenerMapReturnsEmptyArrayWhenNothingAttached(): void
    {
        $manager = new Manager();

        $this->assertSame([], $manager->getListenerMap());
    }
}
