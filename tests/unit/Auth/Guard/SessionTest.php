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
use Phalcon\Contracts\Auth\Guard\Guard;
use Phalcon\Auth\Guard\Session;
use Phalcon\Encryption\Security;
use Phalcon\Events\Manager as EventsManager;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeCookies;
use Phalcon\Tests\Unit\Auth\Fake\FakeRequest;
use Phalcon\Tests\Unit\Auth\Fake\FakeSessionManager;

final class SessionTest extends AbstractUnitTestCase
{
    private Memory $adapter;
    private FakeCookies $cookies;
    private FakeRequest $request;
    private FakeSessionManager $session;
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

        $this->session = new FakeSessionManager();
        $this->cookies = new FakeCookies();
        $this->request = new FakeRequest();
    }

    private function buildGuard(): Session
    {
        return new Session(
            $this->adapter,
            $this->request,
            $this->cookies,
            $this->session
        );
    }

    public function testCheckIsFalseWhenNotAuthenticated(): void
    {
        $guard = $this->buildGuard();

        $this->assertFalse($guard->check());
        $this->assertTrue($guard->guest());
    }

    public function testAttemptSucceedsWithValidCredentials(): void
    {
        $guard = $this->buildGuard();

        $result = $guard->attempt([
            'email'    => 'alice@example.com',
            'password' => 'secret',
        ]);

        $this->assertTrue($result);
        $this->assertTrue($guard->check());
        $this->assertSame(1, $guard->id());
    }

    public function testAttemptFailsWithInvalidCredentials(): void
    {
        $guard = $this->buildGuard();

        $result = $guard->attempt([
            'email'    => 'alice@example.com',
            'password' => 'wrong-password',
        ]);

        $this->assertFalse($result);
        $this->assertFalse($guard->check());
    }

    public function testAttemptFailsWithUnknownEmail(): void
    {
        $guard = $this->buildGuard();

        $result = $guard->attempt([
            'email'    => 'nobody@example.com',
            'password' => 'secret',
        ]);

        $this->assertFalse($result);
        $this->assertFalse($guard->check());
    }

    public function testLoginPersistsToSession(): void
    {
        $guard = $this->buildGuard();
        $user  = $this->adapter->retrieveById(1);

        $this->assertNotNull($user);

        $guard->login($user);

        $this->assertTrue($this->session->has($guard->getName()));
        $this->assertSame(1, $this->session->get($guard->getName()));
    }

    public function testLogoutClearsSession(): void
    {
        $guard = $this->buildGuard();
        $user  = $this->adapter->retrieveById(1);

        $this->assertNotNull($user);

        $guard->login($user);
        $this->assertTrue($guard->check());

        $guard->logout();

        $this->assertFalse($guard->check());
        $this->assertFalse($this->session->has($guard->getName()));
    }

    public function testOnceDoesNotPersist(): void
    {
        $guard = $this->buildGuard();

        $result = $guard->once([
            'email'    => 'alice@example.com',
            'password' => 'secret',
        ]);

        $this->assertTrue($result);
        $this->assertTrue($guard->check());
        $this->assertFalse($this->session->has($guard->getName()));
    }

    public function testEventsFiredOnLogin(): void
    {
        $guard = $this->buildGuard();

        $captured = [];

        $eventsManager = new EventsManager();
        $eventsManager->attach(
            'auth:beforeLogin',
            function () use (&$captured): void {
                $captured[] = 'auth:beforeLogin';
            }
        );
        $eventsManager->attach(
            'auth:afterLogin',
            function () use (&$captured): void {
                $captured[] = 'auth:afterLogin';
            }
        );

        $guard->setEventsManager($eventsManager);

        $user = $this->adapter->retrieveById(1);

        $this->assertNotNull($user);

        $guard->login($user);

        $this->assertSame(['auth:beforeLogin', 'auth:afterLogin'], $captured);
    }

    public function testEventsFiredOnLogout(): void
    {
        $guard = $this->buildGuard();

        $captured = [];

        $eventsManager = new EventsManager();
        $eventsManager->attach(
            'auth:beforeLogout',
            function () use (&$captured): void {
                $captured[] = 'auth:beforeLogout';
            }
        );
        $eventsManager->attach(
            'auth:afterLogout',
            function () use (&$captured): void {
                $captured[] = 'auth:afterLogout';
            }
        );

        $guard->setEventsManager($eventsManager);

        $user = $this->adapter->retrieveById(1);

        $this->assertNotNull($user);

        $guard->login($user);
        $guard->logout();

        $this->assertSame(['auth:beforeLogout', 'auth:afterLogout'], $captured);
    }

    public function testValidateDoesNotPersist(): void
    {
        $guard = $this->buildGuard();

        $result = $guard->validate([
            'email'    => 'alice@example.com',
            'password' => 'secret',
        ]);

        $this->assertTrue($result);
        $this->assertFalse($guard->check());
    }

    public function testViaRememberDefaultsFalse(): void
    {
        $guard = $this->buildGuard();

        $this->assertFalse($guard->viaRemember());
    }

    public function testGetAdapterReturnsAdapter(): void
    {
        $guard = $this->buildGuard();

        $this->assertSame($this->adapter, $guard->getAdapter());
    }

    public function testSetAdapterReplaces(): void
    {
        $guard = $this->buildGuard();

        $other = new Memory(
            $this->security,
            new MemoryAdapterConfig()
        );

        $guard->setAdapter($other);

        $this->assertSame($other, $guard->getAdapter());
    }

    public function testGetConfigReturnsConfig(): void
    {
        $guard  = $this->buildGuard();
        $config = $guard->getConfig();

        $this->assertNotNull($config);
    }

    public function testGetLastUserAttemptedAfterFailedValidate(): void
    {
        $guard = $this->buildGuard();

        $guard->validate(['email' => 'nobody@example.com']);

        $this->assertNull($guard->getLastUserAttempted());
    }

    public function testGetLastUserAttemptedAfterSuccessfulValidate(): void
    {
        $guard = $this->buildGuard();

        $guard->validate(['email' => 'alice@example.com', 'password' => 'secret']);

        $user = $guard->getLastUserAttempted();
        $this->assertNotNull($user);
        $this->assertSame(1, $user->getAuthIdentifier());
    }

    public function testHasUserReportsTrueAfterLogin(): void
    {
        $guard = $this->buildGuard();
        $user  = $this->adapter->retrieveById(1);

        $this->assertNotNull($user);
        $this->assertFalse($guard->hasUser());

        $guard->login($user);

        $this->assertTrue($guard->hasUser());
    }

    public function testIdReturnsNullWhenNotAuthenticated(): void
    {
        $guard = $this->buildGuard();

        $this->assertNull($guard->id());
    }

    public function testSetUserAssignsCurrent(): void
    {
        $guard = $this->buildGuard();
        $user  = $this->adapter->retrieveById(1);

        $this->assertNotNull($user);

        $guard->setUser($user);

        $this->assertTrue($guard->hasUser());
        $this->assertSame(1, $guard->id());
    }

    public function testGetNameAndRememberNameAreStable(): void
    {
        $guard = $this->buildGuard();

        $this->assertNotEmpty($guard->getName());
        $this->assertNotEmpty($guard->getRememberName());
        $this->assertNotSame($guard->getName(), $guard->getRememberName());
    }

    public function testLoginByIdSucceeds(): void
    {
        $guard = $this->buildGuard();

        $result = $guard->loginById(1);

        $this->assertNotFalse($result);
        $this->assertTrue($guard->check());
    }

    public function testLoginByIdReturnsFalseForUnknownUser(): void
    {
        $guard = $this->buildGuard();

        $this->assertFalse($guard->loginById(999));
    }

    public function testLoginThrowsWhenAdapterDoesNotSupportRemember(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/RememberAdapter/');

        $guard = $this->buildGuard();
        $user  = $this->adapter->retrieveById(1);

        $this->assertNotNull($user);

        $guard->login($user, true);
    }

    public function testUserResolvesFromSessionId(): void
    {
        $guard = $this->buildGuard();
        $user  = $this->adapter->retrieveById(1);

        $this->assertNotNull($user);

        $guard->login($user);

        $fresh = $this->buildGuard();

        $this->assertNotNull($fresh->user());
        $this->assertSame(1, $fresh->user()?->getAuthIdentifier());
    }

    public function testUserReturnsNullWhenSessionEmpty(): void
    {
        $guard = $this->buildGuard();

        $this->assertNull($guard->user());
    }

    public function testBasicReturnsTrueWhenAlreadyAuthenticated(): void
    {
        $guard = $this->buildGuard();
        $user  = $this->adapter->retrieveById(1);

        $this->assertNotNull($user);

        $guard->login($user);

        $this->assertTrue($guard->basic());
    }

    public function testBasicAttemptsFromHttpHeader(): void
    {
        $guard = $this->buildGuard();
        $this->request->setBasicAuthFake([
            'username' => 'alice@example.com',
            'password' => 'secret',
        ]);

        $this->assertTrue($guard->basic());
        $this->assertTrue($guard->check());
    }

    public function testBasicReturnsFalseWhenNoCredentials(): void
    {
        $guard = $this->buildGuard();
        $this->request->setBasicAuthFake(null);

        $this->assertFalse($guard->basic());
    }

    public function testOnceBasicSucceeds(): void
    {
        $guard = $this->buildGuard();
        $this->request->setBasicAuthFake([
            'username' => 'alice@example.com',
            'password' => 'secret',
        ]);

        $result = $guard->onceBasic();

        $this->assertNotFalse($result);
        $this->assertSame(1, $result->getAuthIdentifier());
    }

    public function testOnceBasicReturnsFalseWithoutCredentials(): void
    {
        $guard = $this->buildGuard();
        $this->request->setBasicAuthFake(null);

        $this->assertFalse($guard->onceBasic());
    }

    public function testOnceBasicReturnsFalseOnInvalidCredentials(): void
    {
        $guard = $this->buildGuard();
        $this->request->setBasicAuthFake([
            'username' => 'alice@example.com',
            'password' => 'wrong-password',
        ]);

        $this->assertFalse($guard->onceBasic());
    }

    public function testRememberLoginPersistsCookieAndRecallsUser(): void
    {
        $rememberAdapter = new \Phalcon\Tests\Unit\Auth\Fake\FakeRememberAdapter(
            $this->security,
            new MemoryAdapterConfig(
                [
                    [
                        'id'       => 1,
                        'email'    => 'alice@example.com',
                        'password' => $this->security->hash('secret'),
                    ],
                ],
                \Phalcon\Tests\Unit\Auth\Fake\FakeAuthUserModel::class
            )
        );

        $guard = new Session(
            $rememberAdapter,
            $this->request,
            $this->cookies,
            $this->session
        );

        $user = $rememberAdapter->retrieveById(1);
        $this->assertNotNull($user);

        $guard->login($user, true);

        $this->assertTrue($this->cookies->has($guard->getRememberName()));

        $rawValue = $this->cookies->get($guard->getRememberName())->getValue();
        $this->assertNotEmpty($rawValue);

        // Fresh guard, empty session — should recall via cookie.
        $emptySession = new FakeSessionManager();
        $fresh        = new Session(
            $rememberAdapter,
            $this->request,
            $this->cookies,
            $emptySession
        );

        $this->assertNotNull($fresh->user());
        $this->assertTrue($fresh->viaRemember());
    }

    public function testRecallerReturnsNullForEmptyCookieValue(): void
    {
        $guard = $this->buildGuard();

        // Cookie present but empty value.
        $this->cookies->set($guard->getRememberName(), '');

        $this->assertNull($guard->user());
    }

    public function testRecallerHandlesArrayCookieValue(): void
    {
        $rememberAdapter = new \Phalcon\Tests\Unit\Auth\Fake\FakeRememberAdapter(
            $this->security,
            new MemoryAdapterConfig(
                [['id' => 1, 'email' => 'a@b']],
                \Phalcon\Tests\Unit\Auth\Fake\FakeAuthUserModel::class
            )
        );

        $guard = new Session(
            $rememberAdapter,
            $this->request,
            $this->cookies,
            $this->session
        );

        $user = $rememberAdapter->retrieveById(1);
        $this->assertNotNull($user);

        $token = $rememberAdapter->createRememberToken($user);

        // Cookie set as a raw array payload (rather than the JSON string the
        // real flow uses). Recaller() handles the array branch and resolves
        // the user via the remember adapter.
        $this->cookies->set(
            $guard->getRememberName(),
            [
                'id'         => 1,
                'token'      => $token->getToken(),
                'user_agent' => '',
            ]
        );

        $this->assertNotNull($guard->user());
    }

    public function testRecallerReturnsNullForNonStringNonArrayCookieValue(): void
    {
        $guard = $this->buildGuard();

        // Cookie value that's neither string nor array — UserRemember cannot
        // parse it; recaller() bails.
        $this->cookies->set($guard->getRememberName(), 12345);

        $this->assertNull($guard->user());
    }

    public function testUserFromRecallerNullWhenAdapterNotRememberAdapter(): void
    {
        $guard = $this->buildGuard();

        // Memory (non-RememberAdapter) + cookie present → recaller() builds
        // a UserRemember, but userFromRecaller bails because the adapter
        // doesn't implement RememberAdapter.
        $this->cookies->set(
            $guard->getRememberName(),
            json_encode(['id' => 1, 'token' => 'tok', 'user_agent' => ''])
        );

        $this->assertNull($guard->user());
    }

    public function testUserFromRecallerNullWhenIdMissing(): void
    {
        $rememberAdapter = new \Phalcon\Tests\Unit\Auth\Fake\FakeRememberAdapter(
            $this->security,
            new MemoryAdapterConfig(
                [['id' => 1, 'email' => 'a@b']],
                \Phalcon\Tests\Unit\Auth\Fake\FakeAuthUserModel::class
            )
        );

        $guard = new Session(
            $rememberAdapter,
            $this->request,
            $this->cookies,
            $this->session
        );

        // Cookie payload missing the 'id' field.
        $this->cookies->set(
            $guard->getRememberName(),
            json_encode(['token' => 'tok', 'user_agent' => ''])
        );

        $this->assertNull($guard->user());
    }

    public function testLogoutCleansRememberCookieWhenPresent(): void
    {
        $rememberAdapter = new \Phalcon\Tests\Unit\Auth\Fake\FakeRememberAdapter(
            $this->security,
            new MemoryAdapterConfig(
                [
                    [
                        'id'       => 1,
                        'email'    => 'alice@example.com',
                        'password' => $this->security->hash('secret'),
                    ],
                ],
                \Phalcon\Tests\Unit\Auth\Fake\FakeAuthUserModel::class
            )
        );

        $guard = new Session(
            $rememberAdapter,
            $this->request,
            $this->cookies,
            $this->session
        );

        $user = $rememberAdapter->retrieveById(1);
        $this->assertNotNull($user);

        $guard->login($user, true);

        $rememberName = $guard->getRememberName();
        $this->assertTrue($this->cookies->has($rememberName));

        $guard->logout();

        $this->assertFalse($this->cookies->has($rememberName));
    }
}
