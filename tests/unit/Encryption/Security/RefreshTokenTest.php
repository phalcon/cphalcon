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

namespace Phalcon\Tests\Unit\Encryption\Security;

use Phalcon\Encryption\Security;
use Phalcon\Session\Manager;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\RequiresPhpExtension;

#[RequiresPhpExtension('openssl')]
final class RefreshTokenTest extends AbstractUnitTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
    }

    /**
     * Default behaviour (autoRefresh = true) rotates the token on each new
     * Security instance even when a value already exists in the session.
     *
     * @issue https://github.com/phalcon/cphalcon/issues/14413
     */
    public function testAutoRefreshDefaultRotatesToken(): void
    {
        /** @var Manager $session */
        $session = $this->container->getShared('session');
        $session->start();

        $first = new Security();
        $first->setDI($this->container);
        $token1 = $first->getToken();
        $key1   = $first->getTokenKey();

        $second = new Security();
        $second->setDI($this->container);
        $token2 = $second->getToken();
        $key2   = $second->getTokenKey();

        $this->assertNotSame($token1, $token2);
        $this->assertNotSame($key1, $key2);

        $session->destroy();
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/14413
     */
    public function testAutoRefreshDisabledReusesSessionToken(): void
    {
        /** @var Manager $session */
        $session = $this->container->getShared('session');
        $session->start();

        // Prime the session with a token via the default behaviour.
        $first = new Security();
        $first->setDI($this->container);
        $tokenSeed = $first->getToken();
        $keySeed   = $first->getTokenKey();

        // A fresh Security instance with autoRefresh disabled must reuse the
        // existing session values rather than generate new ones.
        $second = new Security();
        $second->setDI($this->container);
        $second->setAutoRefresh(false);

        $this->assertSame($tokenSeed, $second->getToken());
        $this->assertSame($keySeed, $second->getTokenKey());

        // Repeated calls are stable too.
        $this->assertSame($tokenSeed, $second->getToken());
        $this->assertSame($keySeed, $second->getTokenKey());

        $session->destroy();
    }

    /**
     * When autoRefresh is disabled and no session value exists yet, the
     * first call still mints a new token and persists it.
     *
     * @issue https://github.com/phalcon/cphalcon/issues/14413
     */
    public function testAutoRefreshDisabledMintsFirstTokenWhenSessionEmpty(): void
    {
        /** @var Manager $session */
        $session = $this->container->getShared('session');
        $session->start();

        $security = new Security();
        $security->setDI($this->container);
        $security->setAutoRefresh(false);

        $token = $security->getToken();
        $key   = $security->getTokenKey();

        $this->assertNotNull($token);
        $this->assertNotNull($key);
        $this->assertSame($token, $security->getSessionToken());

        $session->destroy();
    }

    /**
     * `refreshToken()` rotates both values and persists them to the session
     * regardless of the autoRefresh flag.
     *
     * @issue https://github.com/phalcon/cphalcon/issues/14413
     */
    public function testRefreshTokenForcesRotationEvenWhenAutoRefreshDisabled(): void
    {
        /** @var Manager $session */
        $session = $this->container->getShared('session');
        $session->start();

        $security = new Security();
        $security->setDI($this->container);
        $security->setAutoRefresh(false);

        $tokenBefore = $security->getToken();
        $keyBefore   = $security->getTokenKey();

        $security->refreshToken();

        $tokenAfter = $security->getToken();
        $keyAfter   = $security->getTokenKey();

        $this->assertNotSame($tokenBefore, $tokenAfter);
        $this->assertNotSame($keyBefore, $keyAfter);

        // New values are reflected in the session.
        $this->assertSame($tokenAfter, $security->getSessionToken());

        $session->destroy();
    }

    /**
     * `setAutoRefresh()` is fluent.
     */
    public function testSetAutoRefreshIsFluent(): void
    {
        $security = new Security();
        $this->assertSame($security, $security->setAutoRefresh(false));
        $this->assertSame($security, $security->setAutoRefresh(true));
    }

    /**
     * `refreshToken()` is fluent.
     */
    public function testRefreshTokenIsFluent(): void
    {
        /** @var Manager $session */
        $session = $this->container->getShared('session');
        $session->start();

        $security = new Security();
        $security->setDI($this->container);

        $this->assertSame($security, $security->refreshToken());

        $session->destroy();
    }
}
