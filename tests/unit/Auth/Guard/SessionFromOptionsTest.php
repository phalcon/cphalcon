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
use Phalcon\Auth\Guard\Session;
use Phalcon\Container\Container;
use Phalcon\Container\Exceptions\Exception as ContainerException;
use Phalcon\Di\Di;
use Phalcon\Encryption\Security;
use Phalcon\Http\RequestInterface;
use Phalcon\Http\Response\CookiesInterface;
use Phalcon\Session\ManagerInterface as SessionManagerInterface;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeCookies;
use Phalcon\Tests\Unit\Auth\Fake\FakeRequest;
use Phalcon\Tests\Unit\Auth\Fake\FakeSessionManager;

final class SessionFromOptionsTest extends AbstractUnitTestCase
{
    private Memory $adapter;
    private Container $container;

    protected function setUp(): void
    {
        $this->adapter = new Memory(
            new Security(),
            new MemoryAdapterConfig([])
        );

        $this->container = new Container();
        $this->container->set(RequestInterface::class, fn () => new FakeRequest());
        $this->container->set(CookiesInterface::class, fn () => new FakeCookies());
        $this->container->set(SessionManagerInterface::class, fn () => new FakeSessionManager());
    }

    public function testFromOptionsAppliesNameAndRememberName(): void
    {
        $guard = Session::fromOptions(
            $this->adapter,
            $this->container,
            [
                'name'         => 'session_admin',
                'rememberName' => 'rmem_admin',
            ]
        );

        $this->assertSame('session_admin', $guard->getName());
        $this->assertSame('rmem_admin', $guard->getRememberName());
    }

    public function testFromOptionsAppliesSuffix(): void
    {
        $guard = Session::fromOptions(
            $this->adapter,
            $this->container,
            ['suffix' => 'web']
        );

        $this->assertSame('auth_web', $guard->getName());
        $this->assertSame('remember_web', $guard->getRememberName());
    }

    public function testFromOptionsFallsBackToShortNamesOnDi(): void
    {
        $di = new Di();
        $di->set('request', fn () => new FakeRequest());
        $di->set('cookies', fn () => new FakeCookies());
        $di->set('session', fn () => new FakeSessionManager());

        $guard = Session::fromOptions($this->adapter, $di, []);

        $this->assertInstanceOf(Session::class, $guard);
    }

    public function testFromOptionsResolvesServicesFromContainer(): void
    {
        $guard = Session::fromOptions($this->adapter, $this->container, []);

        $this->assertInstanceOf(Session::class, $guard);
    }

    public function testFromOptionsThrowsWhenCookiesMissing(): void
    {
        $this->expectException(ContainerException::class);
        $this->expectExceptionMessageMatches('/Session guard requires service.*CookiesInterface/');

        $emptyContainer = new Container();
        $emptyContainer->set(RequestInterface::class, fn () => new FakeRequest());

        Session::fromOptions($this->adapter, $emptyContainer, []);
    }

    public function testFromOptionsThrowsWhenRequestMissing(): void
    {
        $this->expectException(ContainerException::class);
        $this->expectExceptionMessageMatches('/Session guard requires service.*RequestInterface/');

        Session::fromOptions($this->adapter, new Container(), []);
    }
}
