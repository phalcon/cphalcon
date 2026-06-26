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

namespace Phalcon\Tests\Unit\Auth\Micro;

use Phalcon\Auth\Access\AccessLocator;
use Phalcon\Auth\Exception;
use Phalcon\Auth\Manager;
use Phalcon\Auth\Micro\AuthMicroListener;
use Phalcon\Container\Container;
use Phalcon\Di\FactoryDefault;
use Phalcon\Events\Event;
use Phalcon\Mvc\Micro;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeAccess;
use Phalcon\Tests\Unit\Auth\Fake\FakeGuard;

final class AuthMicroListenerTest extends AbstractUnitTestCase
{
    public function testContextCarriesComponentNameAndParams(): void
    {
        $app = $this->buildApp();
        $app->map('/invoices/{id:[0-9]+}', fn () => 'ok')->setName('invoices-view');
        $app->getRouter()->handle('/invoices/5');

        $manager = $this->buildManager();
        $access  = new FakeAccess();
        $access->setAllowed(true);
        $manager->setAccess($access);

        $listener = new AuthMicroListener($manager, 'Api');
        $event    = new Event('beforeExecuteRoute', $app);

        $this->assertTrue($listener->beforeExecuteRoute($event, $app));
        $this->assertSame('invoices-view', $access->getLastAction());
        $this->assertSame('Api', $access->getLastContext()['handler']);
        $this->assertSame('5', $access->getLastContext()['params']['id'] ?? null);
    }

    public function testReturnsTrueWhenAllowed(): void
    {
        $app = $this->buildApp();
        $app->map('/invoices/view', fn () => 'ok')->setName('invoices-view');
        $app->getRouter()->handle('/invoices/view');

        $manager = $this->buildManager();
        $access  = new FakeAccess();
        $access->setAllowed(true);
        $manager->setAccess($access);

        $listener = new AuthMicroListener($manager);
        $event    = new Event('beforeExecuteRoute', $app);

        $this->assertTrue($listener->beforeExecuteRoute($event, $app));
        $this->assertSame('Micro', $access->getLastContext()['handler']);
    }

    public function testReturnsTrueWhenNoActiveAccess(): void
    {
        $app = $this->buildApp();
        $app->map('/invoices/view', fn () => 'ok')->setName('invoices-view');
        $app->getRouter()->handle('/invoices/view');

        // No guard registered on purpose: the no-op path must not fetch one
        $manager  = new Manager(new AccessLocator(new Container()));
        $listener = new AuthMicroListener($manager);
        $event    = new Event('beforeExecuteRoute', $app);

        $this->assertTrue($listener->beforeExecuteRoute($event, $app));
    }

    public function testThrowsWhenDenied(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage("Access denied for route 'invoices-view'");

        $app = $this->buildApp();
        $app->map('/invoices/view', fn () => 'ok')->setName('invoices-view');
        $app->getRouter()->handle('/invoices/view');

        $manager = $this->buildManager();
        $access  = new FakeAccess();
        $access->setAllowed(false);
        $manager->setAccess($access);

        $listener = new AuthMicroListener($manager);
        $listener->beforeExecuteRoute(new Event('beforeExecuteRoute', $app), $app);
    }

    public function testUsesPatternWhenRouteUnnamed(): void
    {
        $app = $this->buildApp();
        $app->map('/invoices/view', fn () => 'ok');
        $app->getRouter()->handle('/invoices/view');

        $manager = $this->buildManager();
        $access  = new FakeAccess();
        $access->setAllowed(true);
        $manager->setAccess($access);

        $listener = new AuthMicroListener($manager);
        $listener->beforeExecuteRoute(new Event('beforeExecuteRoute', $app), $app);

        $this->assertSame('/invoices/view', $access->getLastAction());
    }

    private function buildApp(): Micro
    {
        return new Micro(new FactoryDefault());
    }

    private function buildManager(): Manager
    {
        $manager = new Manager(new AccessLocator(new Container()));
        $manager->addGuard('web', new FakeGuard(), true);

        return $manager;
    }
}
