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

namespace Phalcon\Tests\Unit\Auth\Access;

use Phalcon\Auth\Access\AccessLocator;
use Phalcon\Auth\Access\Auth;
use Phalcon\Auth\Access\Guest;
use Phalcon\Auth\Exception;
use Phalcon\Auth\Manager;
use Phalcon\Container\Container;
use Phalcon\Contracts\Auth\Access\Access;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeAccess;
use stdClass;

final class AccessLocatorTest extends AbstractUnitTestCase
{
    private Container $container;
    private Manager $manager;

    protected function setUp(): void
    {
        $this->container = new Container();
        $this->manager   = new Manager(new AccessLocator($this->container));

        $this->container->set(Auth::class, fn () => new Auth($this->manager));
        $this->container->set(Guest::class, fn () => new Guest($this->manager));
        $this->container->set(FakeAccess::class, fn () => new FakeAccess($this->manager));
    }

    public function testCustomMappingHonored(): void
    {
        $factory = new AccessLocator($this->container, ['admin' => FakeAccess::class]);
        $access  = $factory->newInstance('admin');

        $this->assertInstanceOf(FakeAccess::class, $access);
    }

    public function testNewInstanceReturnsAccess(): void
    {
        $factory = new AccessLocator($this->container);

        $auth  = $factory->newInstance('auth');
        $guest = $factory->newInstance('guest');

        $this->assertInstanceOf(Access::class, $auth);
        $this->assertInstanceOf(Access::class, $guest);
    }

    public function testNewInstanceReturnsAuth(): void
    {
        $factory = new AccessLocator($this->container);
        $access  = $factory->newInstance('auth');

        $this->assertInstanceOf(Auth::class, $access);
    }

    public function testNewInstanceReturnsGuest(): void
    {
        $factory = new AccessLocator($this->container);
        $access  = $factory->newInstance('guest');

        $this->assertInstanceOf(Guest::class, $access);
    }

    public function testRegisterAddsMapping(): void
    {
        $factory = new AccessLocator($this->container);
        $factory->register('custom', FakeAccess::class);

        $access = $factory->newInstance('custom');

        $this->assertInstanceOf(FakeAccess::class, $access);
    }

    public function testRegisterRejectsNonAccessClass(): void
    {
        $this->expectException(Exception::class);

        $factory = new AccessLocator($this->container);
        $factory->register('bad', stdClass::class);
    }

    public function testUnknownNameThrows(): void
    {
        $this->expectException(Exception::class);

        $factory = new AccessLocator($this->container);
        $factory->newInstance('unknown_access');
    }
}
