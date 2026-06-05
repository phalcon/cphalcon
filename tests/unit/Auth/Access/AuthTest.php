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
use Phalcon\Auth\Adapter\Config\MemoryAdapterConfig;
use Phalcon\Auth\Adapter\Memory;
use Phalcon\Auth\Guard\Session;
use Phalcon\Auth\Manager;
use Phalcon\Container\Container;
use Phalcon\Encryption\Security;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeCookies;
use Phalcon\Tests\Unit\Auth\Fake\FakeRequest;
use Phalcon\Tests\Unit\Auth\Fake\FakeSessionManager;

final class AuthTest extends AbstractUnitTestCase
{
    private Memory $adapter;
    private Security $security;

    protected function setUp(): void
    {
        $this->security = new Security();

        $this->adapter = new Memory(
            $this->security,
            new MemoryAdapterConfig([
                [
                    'id'       => 1,
                    'email'    => 'alice@example.com',
                    'password' => $this->security->hash('secret'),
                ],
            ])
        );
    }

    private function buildGuard(): Session
    {
        return new Session(
            $this->adapter,
            new FakeRequest(),
            new FakeCookies(),
            new FakeSessionManager()
        );
    }

    private function buildManager(): Manager
    {
        $container = new Container();
        $manager   = new Manager(new AccessLocator($container));

        $container->set(Auth::class, fn () => new Auth($manager));

        return $manager;
    }

    public function testAllowedIfWhenAuthenticated(): void
    {
        $guard   = $this->buildGuard();
        $manager = $this->buildManager();
        $manager->addGuard('web', $guard, true);

        $user = $this->adapter->retrieveById(1);
        $this->assertNotNull($user);

        $guard->login($user);

        $access = new Auth($manager);

        $this->assertTrue($access->allowedIf());
    }

    public function testAllowedIfWhenNotAuthenticated(): void
    {
        $guard   = $this->buildGuard();
        $manager = $this->buildManager();
        $manager->addGuard('web', $guard, true);

        $access = new Auth($manager);

        $this->assertFalse($access->allowedIf());
    }

    public function testIsAllowedHonorsExceptActions(): void
    {
        $guard   = $this->buildGuard();
        $manager = $this->buildManager();
        $manager->addGuard('web', $guard, true);

        // Not logged in - allowedIf() is false
        $access = new Auth($manager);
        $access->setExceptActions(['login']);

        $this->assertTrue($access->isAllowed('login'));
        $this->assertFalse($access->isAllowed('dashboard'));
    }

    public function testIsAllowedHonorsOnlyActions(): void
    {
        $guard   = $this->buildGuard();
        $manager = $this->buildManager();
        $manager->addGuard('web', $guard, true);

        $user = $this->adapter->retrieveById(1);
        $this->assertNotNull($user);

        $guard->login($user);

        // Logged in - allowedIf() is true
        $access = new Auth($manager);
        $access->setOnlyActions(['admin']);

        $this->assertFalse($access->isAllowed('home'));
        $this->assertTrue($access->isAllowed('admin'));
    }
}
