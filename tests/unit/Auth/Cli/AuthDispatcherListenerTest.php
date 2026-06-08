<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Auth\Cli;

use Phalcon\Auth\Access\AccessLocator;
use Phalcon\Auth\Cli\AuthDispatcherListener;
use Phalcon\Auth\Exception;
use Phalcon\Auth\Manager;
use Phalcon\Cli\Dispatcher;
use Phalcon\Container\Container;
use Phalcon\Events\Event;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeAccess;
use Phalcon\Tests\Unit\Auth\Fake\FakeGuard;

final class AuthDispatcherListenerTest extends AbstractUnitTestCase
{
    private Dispatcher $dispatcher;
    private Event $event;

    protected function setUp(): void
    {
        $this->dispatcher = new Dispatcher();
        $this->dispatcher->setActionName('list');
        $this->dispatcher->setTaskName('main');
        $this->dispatcher->setParams(['limit' => 10]);

        $this->event = new Event(
            'beforeExecuteRoute',
            $this->dispatcher,
            null,
            true
        );
    }

    public function testPassesGuardAndContextToTheGate(): void
    {
        $manager = $this->buildManager();
        $access  = new FakeAccess();
        $access->setAllowed(true);
        $manager->setAccess($access);

        $listener = new AuthDispatcherListener($manager);
        $listener->beforeExecuteRoute($this->event, $this->dispatcher);

        $context = $access->getLastContext();

        $this->assertSame($manager->guard(), $access->getLastGuard());
        $this->assertSame('list', $access->getLastAction());
        $this->assertSame('main', $context['handler']);
        $this->assertSame(['limit' => 10], $context['params']);
        $this->assertArrayNotHasKey('module', $context);
    }

    public function testReturnsTrueWhenAllowed(): void
    {
        $manager = $this->buildManager();
        $access  = new FakeAccess();
        $access->setAllowed(true);
        $manager->setAccess($access);

        $listener = new AuthDispatcherListener($manager);

        $this->assertTrue(
            $listener->beforeExecuteRoute($this->event, $this->dispatcher)
        );
    }

    public function testReturnsTrueWhenNoActiveAccess(): void
    {
        $manager  = new Manager(new AccessLocator(new Container()));
        $listener = new AuthDispatcherListener($manager);

        $this->assertTrue(
            $listener->beforeExecuteRoute($this->event, $this->dispatcher)
        );
    }

    public function testThrowsWhenDenied(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches("/'list'/");

        $manager = $this->buildManager();
        $access  = new FakeAccess();
        $access->setAllowed(false);
        $manager->setAccess($access);

        $listener = new AuthDispatcherListener($manager);
        $listener->beforeExecuteRoute($this->event, $this->dispatcher);
    }

    private function buildManager(): Manager
    {
        $manager = new Manager(new AccessLocator(new Container()));
        $manager->addGuard('cli', new FakeGuard(), true);

        return $manager;
    }
}
