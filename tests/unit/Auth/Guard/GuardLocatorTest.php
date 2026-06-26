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

namespace Phalcon\Tests\Unit\Auth\Guard;

use Phalcon\Auth\Adapter\Config\MemoryAdapterConfig;
use Phalcon\Auth\Adapter\Memory;
use Phalcon\Auth\Exception;
use Phalcon\Auth\Guard\Config\TokenGuardConfig;
use Phalcon\Auth\Guard\GuardLocator;
use Phalcon\Auth\Guard\Session;
use Phalcon\Auth\Guard\Token;
use Phalcon\Container\Container;
use Phalcon\Contracts\Auth\Adapter\Adapter;
use Phalcon\Contracts\Auth\Guard\Guard;
use Phalcon\Encryption\Security;
use Phalcon\Http\RequestInterface;
use Phalcon\Http\Response\CookiesInterface;
use Phalcon\Session\ManagerInterface as SessionManagerInterface;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeCookies;
use Phalcon\Tests\Unit\Auth\Fake\FakeRequest;
use Phalcon\Tests\Unit\Auth\Fake\FakeSessionManager;
use stdClass;

final class GuardLocatorTest extends AbstractUnitTestCase
{
    private Container $container;

    protected function setUp(): void
    {
        $this->container = new Container();

        $adapter = new Memory(new Security(), new MemoryAdapterConfig());
        $request = new FakeRequest();
        $cookies = new FakeCookies();
        $session = new FakeSessionManager();

        $this->container->set(Adapter::class, fn () => $adapter);
        $this->container->set(RequestInterface::class, fn () => $request);
        $this->container->set(CookiesInterface::class, fn () => $cookies);
        $this->container->set(SessionManagerInterface::class, fn () => $session);
        $this->container->set(
            TokenGuardConfig::class,
            fn () => new TokenGuardConfig('api_token', 'api_token')
        );
    }

    public function testCustomMappingHonored(): void
    {
        $factory = new GuardLocator(
            $this->container,
            ['custom' => Session::class]
        );

        $this->assertInstanceOf(Session::class, $factory->newInstance('custom'));
    }

    public function testNewInstanceReturnsSession(): void
    {
        $factory = new GuardLocator($this->container);
        $guard   = $factory->newInstance('session');

        $this->assertInstanceOf(Session::class, $guard);
        $this->assertInstanceOf(Guard::class, $guard);
    }

    public function testNewInstanceReturnsToken(): void
    {
        $factory = new GuardLocator($this->container);
        $guard   = $factory->newInstance('token');

        $this->assertInstanceOf(Token::class, $guard);
    }

    public function testRegisterRejectsNonGuardClass(): void
    {
        $this->expectException(Exception::class);

        $factory = new GuardLocator($this->container);
        $factory->register('bad', stdClass::class);
    }

    public function testUnknownNameThrows(): void
    {
        $this->expectException(Exception::class);

        $factory = new GuardLocator($this->container);
        $factory->newInstance('unknown_guard');
    }
}
