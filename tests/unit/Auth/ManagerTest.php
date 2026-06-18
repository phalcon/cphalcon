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

namespace Phalcon\Tests\Unit\Auth;

use Phalcon\Acl\Adapter\AdapterInterface as AclAdapterInterface;
use Phalcon\Acl\Adapter\Memory as AclMemory;
use Phalcon\Auth\Access\Acl as AclAccess;
use Phalcon\Auth\Access\AccessLocator;
use Phalcon\Auth\Access\Auth;
use Phalcon\Auth\Adapter\Config\MemoryAdapterConfig;
use Phalcon\Auth\Adapter\Memory;
use Phalcon\Auth\Exception;
use Phalcon\Auth\Exceptions\DoesNotImplement;
use Phalcon\Auth\Guard\Session;
use Phalcon\Auth\Manager;
use Phalcon\Container\Container;
use Phalcon\Di\Di;
use Phalcon\Encryption\Security;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeAccess;
use Phalcon\Tests\Unit\Auth\Fake\FakeCookies;
use Phalcon\Tests\Unit\Auth\Fake\FakeGuard;
use Phalcon\Tests\Unit\Auth\Fake\FakeRequest;
use Phalcon\Tests\Unit\Auth\Fake\FakeSessionManager;

final class ManagerTest extends AbstractUnitTestCase
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
        return new Manager(new AccessLocator(new Container()));
    }

    public function testAccessInstantiatesAuthGate(): void
    {
        $manager = $this->buildManager();
        $guard   = $this->buildGuard();
        $manager->addGuard('web', $guard, true);
        $manager->addAccessList(['auth' => Auth::class]);
        $manager->access('auth');

        $this->assertInstanceOf(Auth::class, $manager->getAccess());
    }

    public function testAccessInstantiatesCustomGate(): void
    {
        $manager = $this->buildManager();
        $manager->addAccessList(['admin' => FakeAccess::class]);
        $manager->access('admin');

        $this->assertInstanceOf(FakeAccess::class, $manager->getAccess());
    }

    public function testAccessResolvesAclGateOnLegacyDi(): void
    {
        $di = new Di();
        $di->set(
            AclAccess::class,
            fn () => new AclAccess(new AclMemory())
        );

        $manager = new Manager(new AccessLocator($di));
        $manager->access('acl');

        $this->assertInstanceOf(AclAccess::class, $manager->getAccess());
    }

    public function testAccessResolvesAclGateWithAutowiring(): void
    {
        $container = new Container();
        $container->bind(AclAdapterInterface::class, AclMemory::class);

        $manager = new Manager(new AccessLocator($container));
        $manager->access('acl');

        $this->assertInstanceOf(AclAccess::class, $manager->getAccess());
    }

    public function testAccessResolvesDefaultWithoutExplicitRegistration(): void
    {
        $manager = $this->buildManager();
        $manager->access('auth');

        $this->assertInstanceOf(Auth::class, $manager->getAccess());
    }

    public function testAccessResolvesUnregisteredBinaryGateOnLegacyDi(): void
    {
        $manager = new Manager(new AccessLocator(new Di()));
        $manager->access('auth');

        $this->assertInstanceOf(Auth::class, $manager->getAccess());
    }

    public function testAccessThrowsForUnknownName(): void
    {
        $this->expectException(Exception::class);

        $manager = $this->buildManager();
        $manager->access('nonexistent');
    }

    public function testAccessThrowsWhenClassDoesNotExist(): void
    {
        $this->expectException(Exception::class);

        $manager = $this->buildManager();
        $manager->addAccessList(['x' => 'NoSuchClass\\DoesNotExist']);
        $manager->access('x');
    }

    public function testAccessYieldsFreshInstancePerCall(): void
    {
        $manager = $this->buildManager();
        $manager->access('auth');
        $manager->only('admin');

        $manager->access('auth');

        $this->assertSame([], $manager->getAccess()->getOnlyActions());
    }

    public function testAddAccessListMerges(): void
    {
        $manager = $this->buildManager();
        $manager->addAccessList(['auth' => Auth::class]);
        $manager->addAccessList(['admin' => FakeAccess::class]);

        $list = $manager->getAccessList();

        $this->assertArrayHasKey('auth', $list);
        $this->assertArrayHasKey('admin', $list);
        $this->assertSame(Auth::class, $list['auth']);
        $this->assertSame(FakeAccess::class, $list['admin']);
    }

    public function testAddGuardRegistersByName(): void
    {
        $guard   = $this->buildGuard();
        $manager = $this->buildManager();
        $manager->addGuard('web', $guard);

        $this->assertArrayHasKey('web', $manager->getGuards());
    }

    public function testAddGuardWithIsDefaultSetsDefault(): void
    {
        $guard   = $this->buildGuard();
        $manager = $this->buildManager();
        $manager->addGuard('web', $guard, true);

        $this->assertSame($guard, $manager->getDefaultGuard());
    }

    public function testCheckForwardsToDefaultGuard(): void
    {
        $guard   = $this->buildGuard();
        $manager = $this->buildManager();
        $manager->addGuard('web', $guard, true);

        $this->assertSame($guard->check(), $manager->check());
        $this->assertFalse($manager->check());
    }

    public function testExceptSetsOnActiveAccess(): void
    {
        $guard   = $this->buildGuard();
        $manager = $this->buildManager();
        $manager->addGuard('web', $guard, true);
        $manager->addAccessList(['auth' => Auth::class]);
        $manager->access('auth');
        $manager->except('a', 'b');

        $this->assertSame(['a', 'b'], $manager->getAccess()->getExceptActions());
    }

    public function testExceptThrowsWithoutActiveAccess(): void
    {
        $this->expectException(Exception::class);

        $manager = $this->buildManager();
        $manager->except('login');
    }

    public function testGuardReturnsByName(): void
    {
        $guard   = $this->buildGuard();
        $manager = $this->buildManager();
        $manager->addGuard('web', $guard);

        $this->assertSame($guard, $manager->guard('web'));
    }

    public function testGuardReturnsDefault(): void
    {
        $guard   = $this->buildGuard();
        $manager = $this->buildManager();
        $manager->addGuard('web', $guard, true);

        $this->assertSame($guard, $manager->guard());
    }

    public function testGuardThrowsForUnknownName(): void
    {
        $this->expectException(Exception::class);

        $manager = $this->buildManager();
        $manager->guard('nonexistent');
    }

    public function testGuardThrowsWhenNoDefaultSet(): void
    {
        $this->expectException(Exception::class);

        $manager = $this->buildManager();
        $manager->guard();
    }

    public function testIdForwardsToDefaultGuard(): void
    {
        $guard   = $this->buildGuard();
        $manager = $this->buildManager();
        $manager->addGuard('web', $guard, true);

        $this->assertNull($manager->id());
    }

    public function testOnlySetsOnActiveAccess(): void
    {
        $guard   = $this->buildGuard();
        $manager = $this->buildManager();
        $manager->addGuard('web', $guard, true);
        $manager->addAccessList(['auth' => Auth::class]);
        $manager->access('auth');
        $manager->only('admin', 'dashboard');

        $this->assertSame(['admin', 'dashboard'], $manager->getAccess()->getOnlyActions());
    }

    public function testOnlyThrowsWithoutActiveAccess(): void
    {
        $this->expectException(Exception::class);

        $manager = $this->buildManager();
        $manager->only('admin');
    }

    public function testUserForwardsToDefaultGuard(): void
    {
        $guard   = $this->buildGuard();
        $manager = $this->buildManager();
        $manager->addGuard('web', $guard, true);

        $this->assertNull($manager->user());
    }

    public function testCheckForwardsToDefaultGuardThroughManager(): void
    {
        $guard   = $this->buildGuard();
        $manager = $this->buildManager();
        $manager->addGuard('web', $guard, true);

        $this->assertFalse($manager->check());
    }

    public function testAttemptForwardsToDefaultGuard(): void
    {
        $guard   = $this->buildGuard();
        $manager = $this->buildManager();
        $manager->addGuard('web', $guard, true);

        $this->assertTrue($manager->attempt([
            'email'    => 'alice@example.com',
            'password' => 'secret',
        ]));
    }

    public function testAttemptThrowsWhenGuardNotStateful(): void
    {
        $this->expectException(Exception::class);

        $manager = $this->buildManager();
        $guard   = new \Phalcon\Auth\Guard\Token(
            $this->adapter,
            new FakeRequest(),
            new \Phalcon\Auth\Guard\Config\TokenGuardConfig('api_token', 'api_token')
        );
        $manager->addGuard('api', $guard, true);

        $manager->attempt(['api_token' => 'x']);
    }

    public function testValidateForwardsToDefaultGuard(): void
    {
        $guard   = $this->buildGuard();
        $manager = $this->buildManager();
        $manager->addGuard('web', $guard, true);

        $this->assertTrue($manager->validate([
            'email'    => 'alice@example.com',
            'password' => 'secret',
        ]));
    }

    public function testLogoutForwardsToDefaultGuard(): void
    {
        $guard   = $this->buildGuard();
        $manager = $this->buildManager();
        $manager->addGuard('web', $guard, true);

        $manager->attempt([
            'email'    => 'alice@example.com',
            'password' => 'secret',
        ]);

        $this->assertTrue($manager->check());

        $manager->logout();

        $this->assertFalse($manager->check());
    }

    public function testLogoutThrowsWhenGuardNotStateful(): void
    {
        $this->expectException(Exception::class);

        $manager = $this->buildManager();
        $guard   = new \Phalcon\Auth\Guard\Token(
            $this->adapter,
            new FakeRequest(),
            new \Phalcon\Auth\Guard\Config\TokenGuardConfig('api_token', 'api_token')
        );
        $manager->addGuard('api', $guard, true);

        $manager->logout();
    }

    public function testSetAccessAssigns(): void
    {
        $manager = $this->buildManager();
        $access  = new FakeAccess();
        $manager->setAccess($access);

        $this->assertSame($access, $manager->getAccess());
    }

    public function testAttemptThrowsWhenDefaultGuardNotStateful(): void
    {
        $this->expectException(DoesNotImplement::class);
        $this->expectExceptionMessageMatches('/GuardStateful/');

        $manager = $this->buildManager();
        $manager->addGuard('web', new FakeGuard(), true);

        $manager->attempt(['email' => 'alice@example.com']);
    }

    public function testLogoutThrowsWhenDefaultGuardNotStateful(): void
    {
        $this->expectException(DoesNotImplement::class);
        $this->expectExceptionMessageMatches('/GuardStateful/');

        $manager = $this->buildManager();
        $manager->addGuard('web', new FakeGuard(), true);

        $manager->logout();
    }

    public function testSetDefaultGuardAssigns(): void
    {
        $guard   = $this->buildGuard();
        $manager = $this->buildManager();

        $manager->setDefaultGuard($guard);

        $this->assertSame($guard, $manager->getDefaultGuard());
    }
}
