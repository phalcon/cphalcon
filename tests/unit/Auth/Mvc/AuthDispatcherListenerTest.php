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

namespace Phalcon\Tests\Unit\Auth\Mvc;

use Phalcon\Auth\Access\AccessLocator;
use Phalcon\Auth\Exception;
use Phalcon\Auth\Manager;
use Phalcon\Auth\Mvc\AuthDispatcherListener;
use Phalcon\Container\Container;
use Phalcon\Events\Event;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeAccess;
use Phalcon\Tests\Unit\Auth\Fake\FakeGuard;
use Phalcon\Tests\Unit\Auth\Fake\FakeRedirectAccess;

final class AuthDispatcherListenerTest extends AbstractUnitTestCase
{
    private Dispatcher $dispatcher;
    private Event $event;

    protected function setUp(): void
    {
        $this->dispatcher = new Dispatcher();
        $this->dispatcher->setActionName('index');
        $this->dispatcher->setControllerName('invoices');
        $this->dispatcher->setModuleName('admin');
        $this->dispatcher->setParams(['id' => 5]);

        $this->event = new Event('beforeExecuteRoute', $this->dispatcher, null, true);
    }

    public function testForwardsWhenDeniedAndRedirectTargetSet(): void
    {
        $manager = $this->buildManager();
        $access  = new FakeRedirectAccess();
        $access->setAllowed(false);
        $access->setTarget(['controller' => 'login', 'action' => 'index']);
        $manager->setAccess($access);

        $listener = new AuthDispatcherListener($manager);
        $result   = $listener->beforeExecuteRoute($this->event, $this->dispatcher);

        $this->assertFalse($result);
        $this->assertSame('login', $this->dispatcher->getControllerName());
        $this->assertSame('index', $this->dispatcher->getActionName());
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
        $this->assertSame('index', $access->getLastAction());
        $this->assertSame('invoices', $context['handler']);
        $this->assertSame('admin', $context['module']);
        $this->assertSame(['id' => 5], $context['params']);
    }

    public function testReturnsTrueWhenAllowed(): void
    {
        $manager = $this->buildManager();
        $access  = new FakeAccess();
        $access->setAllowed(true);
        $manager->setAccess($access);

        $listener = new AuthDispatcherListener($manager);
        $result   = $listener->beforeExecuteRoute($this->event, $this->dispatcher);

        $this->assertTrue($result);
    }

    public function testReturnsTrueWhenNoActiveAccess(): void
    {
        // No guard registered on purpose: the no-op path must not fetch one
        $manager  = new Manager(new AccessLocator(new Container()));
        $listener = new AuthDispatcherListener($manager);
        $result   = $listener->beforeExecuteRoute($this->event, $this->dispatcher);

        $this->assertTrue($result);
    }

    public function testThrowsWhenDeniedAndNoRedirectTarget(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage("Access denied for action 'index'");

        $manager = $this->buildManager();
        $access  = new FakeAccess();
        $access->setAllowed(false);
        $manager->setAccess($access);

        $listener = new AuthDispatcherListener($manager);
        $listener->beforeExecuteRoute($this->event, $this->dispatcher);
    }

    public function testThrowsWhenNoDefaultGuardAndAccessActive(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('No default guard');

        $manager = new Manager(new AccessLocator(new Container()));
        $access  = new FakeAccess();
        $access->setAllowed(true);
        $manager->setAccess($access);

        $listener = new AuthDispatcherListener($manager);
        $listener->beforeExecuteRoute($this->event, $this->dispatcher);
    }

    private function buildManager(): Manager
    {
        $manager = new Manager(new AccessLocator(new Container()));
        $manager->addGuard('web', new FakeGuard(), true);

        return $manager;
    }
}
