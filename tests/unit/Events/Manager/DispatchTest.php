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
use Phalcon\Tests\Unit\Events\Manager\Fake\InvokableListener;
use Phalcon\Tests\Unit\Events\Manager\Fake\NamedListener;
use Phalcon\Tests\Unit\Events\Manager\Fake\StoppableEvent;
use stdClass;

final class DispatchTest extends AbstractUnitTestCase
{
    public function testDispatchByArrayNameResolvesPlainObjectMethod(): void
    {
        $listener = new NamedListener();
        $manager  = new Manager();
        $manager->attach('Sample:onSomething', $listener);

        $manager->dispatch(new stdClass(), ['Sample', 'onSomething']);

        $this->assertSame(['onSomething'], $listener->calls);
    }
    public function testDispatchByClassName(): void
    {
        $called  = false;
        $manager = new Manager();
        $manager->attach(stdClass::class, function () use (&$called) {
            $called = true;
        });

        $manager->dispatch(new stdClass());

        $this->assertTrue($called);
    }

    public function testDispatchByStringName(): void
    {
        $called  = false;
        $manager = new Manager();
        $manager->attach('custom:name', function () use (&$called) {
            $called = true;
        });

        $manager->dispatch(new stdClass(), 'custom:name');

        $this->assertTrue($called);
    }

    public function testDispatchInvokableObject(): void
    {
        $listener = new InvokableListener();
        $manager  = new Manager();
        $manager->attach('Sample', $listener);

        $manager->dispatch(new stdClass(), 'Sample');

        $this->assertSame(['__invoke'], $listener->calls);
    }

    public function testDispatchReturnsNullWhenNoMatch(): void
    {
        $manager = new Manager();
        $manager->attach('known', function () {
            return 'called';
        });

        $this->assertNull($manager->dispatch(new stdClass(), 'unknown'));
    }

    public function testStoppableEventStopsPropagation(): void
    {
        $order   = [];
        $manager = new Manager();
        $manager->attach(StoppableEvent::class, function (StoppableEvent $event) use (&$order) {
            $order[] = 'first';
            $event->stop();
        });
        $manager->attach(StoppableEvent::class, function () use (&$order) {
            $order[] = 'second';
        });

        $manager->dispatch(new StoppableEvent());

        $this->assertSame(['first'], $order);
    }
}
