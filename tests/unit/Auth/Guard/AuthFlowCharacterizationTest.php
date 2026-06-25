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

use Phalcon\Auth\Adapter\Config\MemoryAdapterConfig;
use Phalcon\Auth\Guard\Config\SessionGuardConfig;
use Phalcon\Auth\Guard\Session;
use Phalcon\Encryption\Security;
use Phalcon\Events\Manager as EventsManager;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeCookies;
use Phalcon\Tests\Unit\Auth\Fake\FakeRememberAdapter;
use Phalcon\Tests\Unit\Auth\Fake\FakeRequest;
use Phalcon\Tests\Unit\Auth\Fake\FakeSessionManager;

final class AuthFlowCharacterizationTest extends AbstractUnitTestCase
{
    private FakeRememberAdapter $adapter;
    private SessionGuardConfig $config;
    private FakeCookies $cookies;
    private FakeRequest $request;
    private FakeSessionManager $session;

    protected function setUp(): void
    {
        $security = new Security();

        $this->adapter = new FakeRememberAdapter(
            $security,
            new MemoryAdapterConfig([
                [
                    'id'       => 1,
                    'email'    => 'alice@example.com',
                    'password' => $security->hash('secret'),
                ],
            ])
        );

        $this->config  = new SessionGuardConfig();
        $this->cookies = new FakeCookies();
        $this->request = new FakeRequest();
        $this->session = new FakeSessionManager();
    }

    public function testAttemptFiresAfterLoginAndPersistsSession(): void
    {
        $count  = 0;
        $events = new EventsManager();
        $events->attach('auth:afterLogin', function () use (&$count) {
            $count++;
        });

        $guard = $this->buildGuard();
        $guard->setEventsManager($events);

        $this->assertTrue(
            $guard->attempt(['email' => 'alice@example.com', 'password' => 'secret'])
        );
        $this->assertSame(1, $count);
        $this->assertSame(1, $this->session->get($this->config->getName()));
    }

    public function testLogoutClearsSessionAndUser(): void
    {
        $guard = $this->buildGuard();

        $this->assertTrue(
            $guard->attempt(['email' => 'alice@example.com', 'password' => 'secret'])
        );
        $this->assertTrue($guard->check());

        $guard->logout();

        $this->assertFalse($guard->check());
        $this->assertFalse($this->session->has($this->config->getName()));
    }

    public function testOnceFiresAfterLoginButDoesNotPersistSession(): void
    {
        $count  = 0;
        $events = new EventsManager();
        $events->attach('auth:afterLogin', function () use (&$count) {
            $count++;
        });

        $guard = $this->buildGuard();
        $guard->setEventsManager($events);

        $this->assertTrue(
            $guard->once(['email' => 'alice@example.com', 'password' => 'secret'])
        );
        $this->assertSame(1, $count);
        $this->assertTrue($guard->check());
        $this->assertFalse($this->session->has($this->config->getName()));
    }

    public function testStaleRecallerNeitherAuthenticatesNorWritesSession(): void
    {
        $guard = $this->buildGuard();

        // A remember cookie whose token was never issued (stale/forged).
        $this->cookies->set(
            $this->config->getRememberName(),
            (string) json_encode([
                'id'         => 1,
                'token'      => 'not-in-store',
                'user_agent' => '',
            ])
        );

        $this->assertNull($guard->user());
        $this->assertFalse($this->session->has($this->config->getName()));
    }

    private function buildGuard(): Session
    {
        return new Session(
            $this->adapter,
            $this->request,
            $this->cookies,
            $this->session,
            $this->config
        );
    }
}
