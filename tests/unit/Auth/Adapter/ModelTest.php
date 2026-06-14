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

namespace Phalcon\Tests\Unit\Auth\Adapter;

use Phalcon\Auth\Adapter\Config\ModelAdapterConfig;
use Phalcon\Auth\Adapter\Model;
use Phalcon\Auth\Exception;
use Phalcon\Auth\Exceptions\DoesNotImplement;
use Phalcon\Encryption\Security;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeAuthUserModel;
use Phalcon\Tests\Unit\Auth\Fake\FakeAuthUserNoRemember;
use Phalcon\Tests\Unit\Auth\Fake\FakeNotAuthUserModel;

final class ModelTest extends AbstractUnitTestCase
{
    private Model $adapter;
    private Security $security;

    protected function setUp(): void
    {
        $this->security = new Security();

        FakeAuthUserModel::$rows = [
            [
                'id'       => 1,
                'email'    => 'alice@example.com',
                'password' => $this->security->hash('secret'),
            ],
            [
                'id'       => 2,
                'email'    => 'bob@example.com',
                'password' => $this->security->hash('hunter2'),
            ],
        ];

        $this->adapter = new Model(
            $this->security,
            new ModelAdapterConfig(FakeAuthUserModel::class)
        );
    }

    protected function tearDown(): void
    {
        FakeAuthUserModel::$rows    = [];
        FakeNotAuthUserModel::$rows = [];
    }

    public function testRetrieveByIdReturnsUser(): void
    {
        $user = $this->adapter->retrieveById(1);

        $this->assertInstanceOf(FakeAuthUserModel::class, $user);
        $this->assertSame(1, $user->getAuthIdentifier());
    }

    public function testRetrieveByIdThrowsWhenModelDoesNotImplementAuthUser(): void
    {
        $this->expectException(DoesNotImplement::class);
        $this->expectExceptionMessageMatches('/AuthUser/');

        FakeNotAuthUserModel::$rows = [
            ['id' => 1, 'email' => 'alice@example.com'],
        ];

        $adapter = new Model(
            $this->security,
            new ModelAdapterConfig(FakeNotAuthUserModel::class)
        );

        $adapter->retrieveById(1);
    }

    public function testRetrieveByIdReturnsNullOnMiss(): void
    {
        $this->assertNull($this->adapter->retrieveById(999));
    }

    public function testRetrieveByCredentialsMatchesUser(): void
    {
        $user = $this->adapter->retrieveByCredentials([
            'email' => 'alice@example.com',
        ]);

        $this->assertInstanceOf(FakeAuthUserModel::class, $user);
        $this->assertSame(1, $user->getAuthIdentifier());
    }

    public function testRetrieveByCredentialsIgnoresPasswordField(): void
    {
        $user = $this->adapter->retrieveByCredentials([
            'email'    => 'bob@example.com',
            'password' => 'whatever',
        ]);

        $this->assertNotNull($user);
        $this->assertSame(2, $user->getAuthIdentifier());
    }

    public function testRetrieveByCredentialsReturnsNullForOnlyPassword(): void
    {
        $this->assertNull(
            $this->adapter->retrieveByCredentials(['password' => 'x'])
        );
    }

    public function testRetrieveByCredentialsReturnsNullOnMiss(): void
    {
        $this->assertNull(
            $this->adapter->retrieveByCredentials(['email' => 'nobody@example.com'])
        );
    }

    public function testValidateCredentialsAcceptsCorrectPassword(): void
    {
        $user = $this->adapter->retrieveById(1);
        $this->assertNotNull($user);

        $this->assertTrue(
            $this->adapter->validateCredentials($user, ['password' => 'secret'])
        );
    }

    public function testValidateCredentialsRejectsWrongPassword(): void
    {
        $user = $this->adapter->retrieveById(1);
        $this->assertNotNull($user);

        $this->assertFalse(
            $this->adapter->validateCredentials($user, ['password' => 'nope'])
        );
    }

    public function testCreateRememberTokenIssuesToken(): void
    {
        $user = $this->adapter->retrieveById(1);
        $this->assertInstanceOf(FakeAuthUserModel::class, $user);

        $token = $this->adapter->createRememberToken($user);

        $this->assertNotEmpty($token->getToken());
        $this->assertArrayHasKey($token->getToken(), $user->rememberTokens);
    }

    public function testCreateRememberTokenThrowsWhenUserNotAuthRemember(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/AuthRemember/');

        $user = new FakeAuthUserNoRemember(['id' => 1]);

        $this->adapter->createRememberToken($user);
    }

    public function testRetrieveByTokenReturnsUser(): void
    {
        $user = $this->adapter->retrieveById(1);
        $this->assertInstanceOf(FakeAuthUserModel::class, $user);

        $token = $this->adapter->createRememberToken($user);

        // Re-seed fixture so subsequent retrieveById hydrates a fresh instance
        // that still answers getRememberToken() - store the token entry in the
        // re-hydrated instance via the fixture row.
        FakeAuthUserModel::$rows[0]['rememberTokens'] = [
            $token->getToken() => $token,
        ];

        $resolved = $this->adapter->retrieveByToken(1, $token->getToken());

        $this->assertNotNull($resolved);
        $this->assertSame(1, $resolved->getAuthIdentifier());
    }

    public function testRetrieveByTokenReturnsNullForUnknownUser(): void
    {
        $this->assertNull(
            $this->adapter->retrieveByToken(999, 'any-token')
        );
    }

    public function testRetrieveByTokenReturnsNullWhenUserLacksAuthRemember(): void
    {
        // Re-bind adapter to a model class that does NOT implement AuthRemember.
        FakeAuthUserNoRemember::$rows = [
            ['id' => 1, 'email' => 'alice@example.com'],
        ];

        $adapter = new Model(
            $this->security,
            new ModelAdapterConfig(FakeAuthUserNoRemember::class)
        );

        $this->assertNull($adapter->retrieveByToken(1, 'any-token'));
    }

    public function testRetrieveByTokenReturnsNullWhenTokenNotFound(): void
    {
        $this->assertNull(
            $this->adapter->retrieveByToken(1, 'no-such-token')
        );
    }

    public function testRetrieveByTokenReturnsNullWhenUserAgentMismatch(): void
    {
        $user = $this->adapter->retrieveById(1);
        $this->assertInstanceOf(FakeAuthUserModel::class, $user);

        // Inject a token entry with a specific user-agent into the fixture.
        $tokenValue                                   = 'ua-test-token';
        FakeAuthUserModel::$rows[0]['rememberTokens'] = [
            $tokenValue => new \Phalcon\Tests\Unit\Auth\Fake\FakeRememberToken(
                $tokenValue,
                'phpunit-agent'
            ),
        ];

        $this->assertNull(
            $this->adapter->retrieveByToken(1, $tokenValue, 'different-agent')
        );
    }
}
