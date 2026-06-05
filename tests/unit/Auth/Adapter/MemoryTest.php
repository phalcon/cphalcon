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

use Phalcon\Auth\Adapter\Config\MemoryAdapterConfig;
use Phalcon\Auth\Adapter\Memory;
use Phalcon\Contracts\Auth\AuthUser;
use Phalcon\Encryption\Security;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeAuthUserModel;

final class MemoryTest extends AbstractUnitTestCase
{
    private Security $security;
    private string $hashedPassword;

    protected function setUp(): void
    {
        $this->security       = new Security();
        $this->hashedPassword = $this->security->hash('secret123');
    }

    public function testRetrieveByCredentialsMatchesUser(): void
    {
        $adapter = new Memory(
            $this->security,
            new MemoryAdapterConfig([
                [
                    'id'       => 1,
                    'email'    => 'alice@example.com',
                    'password' => $this->hashedPassword,
                ],
            ])
        );

        $user = $adapter->retrieveByCredentials(['email' => 'alice@example.com']);

        $this->assertInstanceOf(AuthUser::class, $user);
        $this->assertSame(1, $user->getAuthIdentifier());
    }

    public function testRetrieveByCredentialsReturnsNullOnMiss(): void
    {
        $adapter = new Memory(
            $this->security,
            new MemoryAdapterConfig([
                [
                    'id'       => 1,
                    'email'    => 'alice@example.com',
                    'password' => $this->hashedPassword,
                ],
            ])
        );

        $user = $adapter->retrieveByCredentials(['email' => 'nobody@example.com']);

        $this->assertNull($user);
    }

    public function testRetrieveByCredentialsIgnoresPasswordKeyInLookup(): void
    {
        $adapter = new Memory(
            $this->security,
            new MemoryAdapterConfig([
                [
                    'id'       => 1,
                    'email'    => 'alice@example.com',
                    'password' => $this->hashedPassword,
                ],
            ])
        );

        $user = $adapter->retrieveByCredentials(
            [
                'email'    => 'alice@example.com',
                'password' => 'whatever',
            ]
        );

        $this->assertInstanceOf(AuthUser::class, $user);
        $this->assertSame(1, $user->getAuthIdentifier());
    }

    public function testRetrieveByIdReturnsUser(): void
    {
        $adapter = new Memory(
            $this->security,
            new MemoryAdapterConfig([
                [
                    'id'       => 42,
                    'email'    => 'bob@example.com',
                    'password' => $this->hashedPassword,
                ],
            ])
        );

        $user = $adapter->retrieveById(42);

        $this->assertInstanceOf(AuthUser::class, $user);
        $this->assertSame(42, $user->getAuthIdentifier());
    }

    public function testRetrieveByIdReturnsNullOnMiss(): void
    {
        $adapter = new Memory(
            $this->security,
            new MemoryAdapterConfig([
                [
                    'id'       => 1,
                    'email'    => 'alice@example.com',
                    'password' => $this->hashedPassword,
                ],
            ])
        );

        $user = $adapter->retrieveById(999);

        $this->assertNull($user);
    }

    public function testValidateCredentialsAcceptsCorrectPassword(): void
    {
        $adapter = new Memory(
            $this->security,
            new MemoryAdapterConfig([
                [
                    'id'       => 1,
                    'email'    => 'alice@example.com',
                    'password' => $this->hashedPassword,
                ],
            ])
        );

        $user = $adapter->retrieveById(1);

        $this->assertNotNull($user);

        $result = $adapter->validateCredentials($user, ['password' => 'secret123']);

        $this->assertTrue($result);
    }

    public function testValidateCredentialsRejectsWrongPassword(): void
    {
        $adapter = new Memory(
            $this->security,
            new MemoryAdapterConfig([
                [
                    'id'       => 1,
                    'email'    => 'alice@example.com',
                    'password' => $this->hashedPassword,
                ],
            ])
        );

        $user = $adapter->retrieveById(1);

        $this->assertNotNull($user);

        $result = $adapter->validateCredentials($user, ['password' => 'wrongpassword']);

        $this->assertFalse($result);
    }

    public function testValidateCredentialsReturnsFalseWhenNoPasswordKey(): void
    {
        $adapter = new Memory(
            $this->security,
            new MemoryAdapterConfig([
                [
                    'id'       => 1,
                    'email'    => 'alice@example.com',
                    'password' => $this->hashedPassword,
                ],
            ])
        );

        $user = $adapter->retrieveById(1);

        $this->assertNotNull($user);

        $result = $adapter->validateCredentials($user, ['email' => 'alice@example.com']);

        $this->assertFalse($result);
    }

    public function testRetrieveByCredentialsReturnsNullWhenOnlyPasswordKey(): void
    {
        $adapter = new Memory(
            $this->security,
            new MemoryAdapterConfig([
                [
                    'id'       => 1,
                    'email'    => 'alice@example.com',
                    'password' => $this->hashedPassword,
                ],
            ])
        );

        $user = $adapter->retrieveByCredentials(['password' => 'whatever']);

        $this->assertNull($user);
    }

    public function testRetrieveByCredentialsReturnsNullWhenEmptyCredentials(): void
    {
        $adapter = new Memory(
            $this->security,
            new MemoryAdapterConfig([
                [
                    'id'       => 1,
                    'email'    => 'alice@example.com',
                    'password' => $this->hashedPassword,
                ],
            ])
        );

        $this->assertNull($adapter->retrieveByCredentials([]));
    }

    public function testRetrieveByCredentialsSkipsRowMissingLookupKey(): void
    {
        $adapter = new Memory(
            $this->security,
            new MemoryAdapterConfig([
                ['id' => 1, 'password' => 'x'],
                ['id' => 2, 'email' => 'alice@example.com', 'password' => 'y'],
            ])
        );

        $user = $adapter->retrieveByCredentials(['email' => 'alice@example.com']);

        $this->assertNotNull($user);
        $this->assertSame(2, $user->getAuthIdentifier());
    }

    public function testGetConfigReturnsConfigObject(): void
    {
        $config  = new MemoryAdapterConfig();
        $adapter = new Memory($this->security, $config);

        $this->assertSame($config, $adapter->getConfig());
    }

    public function testGetModelReflectsConfig(): void
    {
        $adapter = new Memory(
            $this->security,
            new MemoryAdapterConfig([], 'App\\Models\\User')
        );

        $this->assertSame('App\\Models\\User', $adapter->getModel());
    }

    public function testHydrateUsesConfiguredModel(): void
    {
        $adapter = new Memory(
            $this->security,
            new MemoryAdapterConfig(
                [
                    [
                        'id'    => 1,
                        'email' => 'alice@example.com',
                    ],
                ],
                FakeAuthUserModel::class
            )
        );

        $user = $adapter->retrieveByCredentials(['email' => 'alice@example.com']);

        $this->assertInstanceOf(FakeAuthUserModel::class, $user);
        $this->assertSame(1, $user->getAuthIdentifier());
    }
}
