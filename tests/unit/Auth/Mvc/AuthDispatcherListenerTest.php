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
use Phalcon\Tests\Unit\Auth\Fake\FakeRedirectAccess;

final class AuthDispatcherListenerTest extends AbstractUnitTestCase
{
    private Dispatcher $dispatcher;
    private Event $event;

    protected function setUp(): void
    {
        $this->dispatcher = new Dispatcher();
        $this->dispatcher->setActionName('index');

        $this->event = new Event('beforeExecuteRoute', $this->dispatcher, null, true);
    }

    public function testForwardsWhenDeniedAndRedirectTargetSet(): void
    {
        $manager  = new Manager(new AccessLocator(new Container()));
        $access   = new FakeRedirectAccess($manager);
        $access->setAllowed(false);
        $access->setTarget(['controller' => 'login', 'action' => 'index']);
        $manager->setAccess($access);

        $listener = new AuthDispatcherListener($manager);
        $result   = $listener->beforeExecuteRoute($this->event, $this->dispatcher);

        $this->assertFalse($result);
        $this->assertSame('login', $this->dispatcher->getControllerName());
        $this->assertSame('index', $this->dispatcher->getActionName());
    }

    public function testReturnsTrueWhenAllowed(): void
    {
        $manager = new Manager(new AccessLocator(new Container()));
        $access  = new FakeAccess($manager);
        $access->setAllowed(true);
        $manager->setAccess($access);

        $listener = new AuthDispatcherListener($manager);
        $result   = $listener->beforeExecuteRoute($this->event, $this->dispatcher);

        $this->assertTrue($result);
    }

    public function testReturnsTrueWhenNoActiveAccess(): void
    {
        $manager  = new Manager(new AccessLocator(new Container()));
        $listener = new AuthDispatcherListener($manager);
        $result   = $listener->beforeExecuteRoute($this->event, $this->dispatcher);

        $this->assertTrue($result);
    }

    public function testThrowsWhenDeniedAndNoRedirectTarget(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage("Access denied for action 'index'");

        $manager = new Manager(new AccessLocator(new Container()));
        $access  = new FakeAccess($manager);
        $access->setAllowed(false);
        $manager->setAccess($access);

        $listener = new AuthDispatcherListener($manager);
        $listener->beforeExecuteRoute($this->event, $this->dispatcher);
    }
}
