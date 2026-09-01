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

namespace Phalcon\Tests\Unit\Auth\Guard;

use DateTimeImmutable;
use Phalcon\Auth\Adapter\Config\MemoryAdapterConfig;
use Phalcon\Auth\Guard\Config\SessionGuardConfig;
use Phalcon\Auth\Guard\Session;
use Phalcon\Encryption\Security;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeCookies;
use Phalcon\Tests\Unit\Auth\Fake\FakeRememberAdapter;
use Phalcon\Tests\Unit\Auth\Fake\FakeRequest;
use Phalcon\Tests\Unit\Auth\Fake\FakeSessionManager;
use Phalcon\Time\Clock\FrozenClock;

final class SessionHardeningTest extends AbstractUnitTestCase
{
    /**
     * A successful login rotates the session id (anonymous -> authenticated)
     * to defeat session fixation (CWE-384).
     */
    public function testLoginRegeneratesSessionId(): void
    {
        $session = new FakeSessionManager();
        $config  = new SessionGuardConfig(null, null, null, 1209600);
        $guard   = $this->buildGuard($session, new FakeCookies(), $config);

        $result = $guard->attempt(
            ['email' => 'alice@example.com', 'password' => 'secret']
        );

        $this->assertTrue($result);
        $this->assertGreaterThanOrEqual(1, $session->regenerateIdCalls);
    }

    /**
     * Logout rotates the session id so the id that was authenticated cannot be
     * reused after sign-out (session fixation / reuse, CWE-384).
     */
    public function testLogoutRegeneratesSessionId(): void
    {
        $session = new FakeSessionManager();
        $config  = new SessionGuardConfig(null, null, null, 1209600);
        $guard   = $this->buildGuard($session, new FakeCookies(), $config);

        $guard->attempt(
            ['email' => 'alice@example.com', 'password' => 'secret']
        );

        $before = $session->regenerateIdCalls;
        $guard->logout();

        $this->assertGreaterThan($before, $session->regenerateIdCalls);
    }

    /**
     * The remember cookie is a bearer credential, so it must be httpOnly and
     * carry the Secure flag by default, whatever scheme the backend sees
     * (CWE-1004 / CWE-614).
     */
    public function testRememberCookieIsHttpOnly(): void
    {
        $cookies = new FakeCookies();
        $config  = new SessionGuardConfig(null, null, null, 1209600);
        $guard   = $this->buildGuard(new FakeSessionManager(), $cookies, $config);

        $result = $guard->attempt(
            ['email' => 'alice@example.com', 'password' => 'secret'],
            true
        );

        $this->assertTrue($result);

        $cookie = $cookies->get($config->getRememberName());
        $this->assertTrue($cookie->getHttpOnly());
        $this->assertTrue($cookie->getSecure());
    }

    /**
     * On a secure request the remember cookie must carry the secure flag so
     * the bearer credential never travels over a plaintext transport
     * (CWE-614).
     */
    public function testRememberCookieIsSecureOnSecureRequest(): void
    {
        $cookies = new FakeCookies();
        $request = new FakeRequest();
        $request->setSecureFake(true);

        $config = new SessionGuardConfig(null, null, null, 1209600);
        $guard  = $this->buildGuard(
            new FakeSessionManager(),
            $cookies,
            $config,
            null,
            $request
        );

        $result = $guard->attempt(
            ['email' => 'alice@example.com', 'password' => 'secret'],
            true
        );

        $this->assertTrue($result);

        $cookie = $cookies->get($config->getRememberName());
        $this->assertTrue($cookie->getSecure());
    }

    /**
     * Promotion from the remember cookie is a privilege change, so the session
     * id must rotate there too (CWE-384).
     */
    public function testUserFromRecallerRegeneratesSessionId(): void
    {
        $security = new Security();
        $adapter  = $this->buildAdapter($security);
        $cookies  = new FakeCookies();
        $config   = new SessionGuardConfig(null, null, null, 1209600);

        $guard = $this->buildGuard(
            new FakeSessionManager(),
            $cookies,
            $config,
            $adapter
        );

        $this->assertTrue(
            $guard->attempt(
                ['email' => 'alice@example.com', 'password' => 'secret'],
                true
            )
        );

        // A new session with no identity: only the remember cookie remains.
        $session = new FakeSessionManager();
        $guard   = $this->buildGuard($session, $cookies, $config, $adapter);

        $this->assertSame(0, $session->regenerateIdCalls);

        $user = $guard->user();

        $this->assertNotNull($user);
        $this->assertTrue($guard->viaRemember());
        $this->assertGreaterThanOrEqual(1, $session->regenerateIdCalls);
    }

    private function buildAdapter(Security $security): FakeRememberAdapter
    {
        return new FakeRememberAdapter(
            $security,
            new MemoryAdapterConfig([
                [
                    'id'       => 1,
                    'email'    => 'alice@example.com',
                    'password' => $security->hash('secret'),
                ],
            ])
        );
    }

    private function buildGuard(
        FakeSessionManager $session,
        FakeCookies $cookies,
        SessionGuardConfig $config,
        ?FakeRememberAdapter $adapter = null,
        ?FakeRequest $request = null
    ): Session {
        $clock = new FrozenClock(new DateTimeImmutable('@1700000000'));

        return new Session(
            $adapter ?? $this->buildAdapter(new Security()),
            $request ?? new FakeRequest(),
            $cookies,
            $session,
            $config,
            $clock
        );
    }
}
