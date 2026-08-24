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
     * The remember cookie is a bearer credential, so it must be httpOnly and
     * carry the request's transport security (CWE-1004 / CWE-614).
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
        $this->assertFalse($cookie->getSecure());
    }

    private function buildGuard(
        FakeSessionManager $session,
        FakeCookies $cookies,
        SessionGuardConfig $config
    ): Session {
        $security = new Security();
        $clock    = new FrozenClock(new DateTimeImmutable('@1700000000'));

        $adapter = new FakeRememberAdapter(
            $security,
            new MemoryAdapterConfig([
                [
                    'id'       => 1,
                    'email'    => 'alice@example.com',
                    'password' => $security->hash('secret'),
                ],
            ])
        );

        return new Session(
            $adapter,
            new FakeRequest(),
            $cookies,
            $session,
            $config,
            $clock
        );
    }
}
