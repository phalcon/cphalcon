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
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeCookies;
use Phalcon\Tests\Unit\Auth\Fake\FakeRememberAdapter;
use Phalcon\Tests\Unit\Auth\Fake\FakeRequest;
use Phalcon\Tests\Unit\Auth\Fake\FakeSessionManager;
use Phalcon\Time\Clock\FrozenClock;

final class RememberExpiryTest extends AbstractUnitTestCase
{
    /**
     * Guards our own arithmetic: the remember cookie expiry is the injected
     * clock's UTC epoch plus the TTL (seconds).
     */
    public function testRememberCookieExpiryIsNowPlusTtl(): void
    {
        $security = new Security();
        $clock    = new FrozenClock(new DateTimeImmutable('@1700000000'));
        $config   = new SessionGuardConfig(null, null, null, 1209600);

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

        $cookies = new FakeCookies();
        $guard   = new Session(
            $adapter,
            new FakeRequest(),
            $cookies,
            new FakeSessionManager(),
            $config,
            $clock
        );

        $result = $guard->attempt(
            ['email' => 'alice@example.com', 'password' => 'secret'],
            true
        );

        $this->assertTrue($result);
        $this->assertSame(
            $clock->now()->getTimestamp() + $config->getRememberTtl(),
            $cookies->get($config->getRememberName())->getExpiration()
        );
    }
}
