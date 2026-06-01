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
use Phalcon\Auth\Guard\Config\TokenGuardConfig;
use Phalcon\Auth\Guard\Token;
use Phalcon\Contracts\Auth\AuthUser;
use Phalcon\Encryption\Security;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeRequest;

final class TokenTest extends AbstractUnitTestCase
{
    private Memory $adapter;
    private FakeRequest $request;

    protected function setUp(): void
    {
        $security = new Security();

        $this->adapter = new Memory(
            $security,
            new MemoryAdapterConfig([
                [
                    'id'        => 1,
                    'email'     => 'a@b',
                    'password'  => 'unused',
                    'api_token' => 'abcdef123',
                ],
            ])
        );

        $this->request = new FakeRequest();
    }

    public function testConfigThrowsWhenInputKeyEmpty(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/inputKey/');

        new TokenGuardConfig('', 'api_token');
    }

    public function testConfigThrowsWhenStorageKeyEmpty(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/storageKey/');

        new TokenGuardConfig('api_token', '');
    }

    public function testGetTokenForRequestUsesQueryParam(): void
    {
        $this->request->setQueryFake('api_token', 'abcdef123');

        $guard = new Token(
            $this->adapter,
            $this->request,
            new TokenGuardConfig('api_token', 'api_token')
        );

        $this->assertSame('abcdef123', $guard->getTokenForRequest());
    }

    public function testGetTokenForRequestUsesBearerHeader(): void
    {
        $this->request->setHeaderFake('Authorization', 'Bearer abcdef123');

        $guard = new Token(
            $this->adapter,
            $this->request,
            new TokenGuardConfig('api_token', 'api_token')
        );

        $this->assertSame('abcdef123', $guard->getTokenForRequest());
    }

    public function testGetTokenForRequestReturnsNullWhenAbsent(): void
    {
        $guard = new Token(
            $this->adapter,
            $this->request,
            new TokenGuardConfig('api_token', 'api_token')
        );

        $this->assertNull($guard->getTokenForRequest());
    }

    public function testUserResolvesViaAdapter(): void
    {
        $this->request->setQueryFake('api_token', 'abcdef123');

        $guard = new Token(
            $this->adapter,
            $this->request,
            new TokenGuardConfig('api_token', 'api_token')
        );

        $user = $guard->user();

        $this->assertInstanceOf(AuthUser::class, $user);
        $this->assertSame(1, $user->getAuthIdentifier());
    }

    public function testUserReturnsNullWhenTokenAbsent(): void
    {
        $guard = new Token(
            $this->adapter,
            $this->request,
            new TokenGuardConfig('api_token', 'api_token')
        );

        $this->assertNull($guard->user());
    }

    public function testValidateAcceptsKnownToken(): void
    {
        $guard = new Token(
            $this->adapter,
            $this->request,
            new TokenGuardConfig('api_token', 'api_token')
        );

        $this->assertTrue($guard->validate(['api_token' => 'abcdef123']));
    }

    public function testValidateRejectsUnknownToken(): void
    {
        $guard = new Token(
            $this->adapter,
            $this->request,
            new TokenGuardConfig('api_token', 'api_token')
        );

        $this->assertFalse($guard->validate(['api_token' => 'invalid-token']));
    }

    public function testValidateReturnsFalseWhenInputKeyMissing(): void
    {
        $guard = new Token(
            $this->adapter,
            $this->request,
            new TokenGuardConfig('api_token', 'api_token')
        );

        $this->assertFalse($guard->validate(['other' => 'something']));
    }

    public function testSetRequestReplacesRequest(): void
    {
        $guard = new Token(
            $this->adapter,
            $this->request,
            new TokenGuardConfig('api_token', 'api_token')
        );

        $other = new FakeRequest();
        $other->setQueryFake('api_token', 'abcdef123');

        $guard->setRequest($other);

        $this->assertSame('abcdef123', $guard->getTokenForRequest());
    }

    public function testGetTokenForRequestReturnsNullForEmptyBearerHeader(): void
    {
        $this->request->setHeaderFake('Authorization', 'Bearer ');

        $guard = new Token(
            $this->adapter,
            $this->request,
            new TokenGuardConfig('api_token', 'api_token')
        );

        $this->assertNull($guard->getTokenForRequest());
    }

    public function testUserCachesAfterFirstResolution(): void
    {
        $this->request->setQueryFake('api_token', 'abcdef123');

        $guard = new Token(
            $this->adapter,
            $this->request,
            new TokenGuardConfig('api_token', 'api_token')
        );

        $first  = $guard->user();
        $second = $guard->user();

        $this->assertNotNull($first);
        $this->assertSame($first, $second);
    }
}
