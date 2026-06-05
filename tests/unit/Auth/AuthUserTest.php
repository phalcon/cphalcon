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

use Phalcon\Auth\AuthUser;
use Phalcon\Auth\Exception;
use Phalcon\Tests\AbstractUnitTestCase;

final class AuthUserTest extends AbstractUnitTestCase
{
    public function testConstructorThrowsWhenIdMissing(): void
    {
        $this->expectException(Exception::class);

        new AuthUser(['email' => 'a@b']);
    }

    public function testConstructorThrowsWhenIdNotScalar(): void
    {
        $this->expectException(Exception::class);

        new AuthUser(['id' => ['nested']]);
    }

    public function testGetAuthIdentifierReturnsIntId(): void
    {
        $user = new AuthUser(['id' => 7]);

        $this->assertSame(7, $user->getAuthIdentifier());
    }

    public function testGetAuthIdentifierReturnsStringId(): void
    {
        $user = new AuthUser(['id' => 'abc-123']);

        $this->assertSame('abc-123', $user->getAuthIdentifier());
    }

    public function testGetAuthPasswordReturnsEmptyWhenMissing(): void
    {
        $user = new AuthUser(['id' => 1]);

        $this->assertSame('', $user->getAuthPassword());
    }

    public function testGetAuthPasswordReturnsEmptyWhenNonString(): void
    {
        $user = new AuthUser(['id' => 1, 'password' => 12345]);

        $this->assertSame('', $user->getAuthPassword());
    }

    public function testGetAuthPasswordReturnsString(): void
    {
        $user = new AuthUser(['id' => 1, 'password' => 'hashed-secret']);

        $this->assertSame('hashed-secret', $user->getAuthPassword());
    }

    public function testToArrayReturnsUnderlyingData(): void
    {
        $data = ['id' => 1, 'email' => 'a@b', 'role' => 'admin'];
        $user = new AuthUser($data);

        $this->assertSame($data, $user->toArray());
    }
}
