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
use Phalcon\Auth\Adapter\Memory;
use Phalcon\Auth\Guard\Session;
use Phalcon\Encryption\Security;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeCookies;
use Phalcon\Tests\Unit\Auth\Fake\FakeRequest;
use Phalcon\Tests\Unit\Auth\Fake\FakeSessionManager;

final class CredentialTimingTest extends AbstractUnitTestCase
{
    /**
     * A login attempt for a real account (wrong password) and one for an
     * unknown account must perform the same number of password-hash checks,
     * so response time does not reveal whether the account exists.
     */
    public function testFoundAndNotFoundPerformEqualHashWork(): void
    {
        $hasher = new class extends Security {
            public int $checkHashCalls = 0;

            public function checkHash(
                string $password,
                string $passwordHash,
                int $maxPassLength = 0
            ): bool {
                $this->checkHashCalls++;

                return parent::checkHash($password, $passwordHash, $maxPassLength);
            }
        };

        $adapter = new Memory(
            $hasher,
            new MemoryAdapterConfig([
                [
                    'id'       => 1,
                    'email'    => 'alice@example.com',
                    'password' => $hasher->hash('secret'),
                ],
            ])
        );

        $guard = new Session(
            $adapter,
            new FakeRequest(),
            new FakeCookies(),
            new FakeSessionManager()
        );

        // Existing account, wrong password.
        $hasher->checkHashCalls = 0;
        $guard->attempt(['email' => 'alice@example.com', 'password' => 'wrong']);
        $foundChecks = $hasher->checkHashCalls;

        // Unknown account.
        $hasher->checkHashCalls = 0;
        $guard->attempt(['email' => 'nobody@example.com', 'password' => 'wrong']);
        $missingChecks = $hasher->checkHashCalls;

        $this->assertSame(1, $foundChecks);
        $this->assertSame(
            $foundChecks,
            $missingChecks,
            'not-found path must perform the same hash work as a found-but-wrong-password path'
        );
    }
}
