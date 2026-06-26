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

namespace Phalcon\Tests\Unit\Auth\Fake;

use Phalcon\Contracts\Auth\AuthRemember;
use Phalcon\Contracts\Auth\AuthUser;
use Phalcon\Contracts\Auth\RememberToken;

/**
 * Lightweight stand-in for an application user model. Implements both
 * AuthUser and AuthRemember so it can drive Memory/Stream tests that exercise
 * model hydration, plus the Model adapter tests via static fixtures.
 *
 * @phpstan-import-type AuthCredentials from \Phalcon\Contracts\Auth\Adapter\Adapter
 */
class FakeAuthUserModel implements AuthUser, AuthRemember
{
    /**
     * Static fixture rows used by findFirst() to simulate Phalcon Model lookups.
     *
     * @var array<int, array<string, mixed>>
     */
    public static array $rows = [];

    public int | string $id = 0;

    public string $password = '';

    /**
     * Per-instance remember tokens keyed by token value.
     *
     * @var array<string, RememberToken>
     */
    public array $rememberTokens = [];

    /**
     * Absorbs arbitrary row columns (e.g. email) without triggering
     * dynamic-property deprecation warnings.
     *
     * @var array<string, mixed>
     */
    private array $extra = [];

    public function __get(string $name): mixed
    {
        return $this->extra[$name] ?? null;
    }

    public function __isset(string $name): bool
    {
        return isset($this->extra[$name]);
    }

    public function __set(string $name, mixed $value): void
    {
        $this->extra[$name] = $value;
    }

    /**
     * Mimics Phalcon\Mvc\Model::findFirst with the array form used by the
     * Model adapter: ['conditions' => '...', 'bind' => [...]].
     *
     * @param array{0?: string, conditions?: string, bind?: array<string, mixed>}|string $parameters
     */
    public static function findFirst(array | string $parameters = []): static | null
    {
        if (is_string($parameters)) {
            return null;
        }

        $bind = $parameters['bind'] ?? [];

        if (!is_array($bind)) {
            return null;
        }

        foreach (self::$rows as $row) {
            $matches = true;

            foreach ($bind as $key => $value) {
                if (!isset($row[$key]) || $row[$key] !== $value) {
                    $matches = false;
                    break;
                }
            }

            if ($matches) {
                $instance = new static();
                $instance->assign($row);

                return $instance;
            }
        }

        return null;
    }

    /**
     * @param array<string, mixed> $row
     */
    public function assign(array $row): void
    {
        foreach ($row as $key => $value) {
            $this->{$key} = $value;
        }
    }

    public function createRememberToken(
        string $token,
        ?string $userAgent = null
    ): RememberToken {
        $entry                       = new FakeRememberToken($token, $userAgent ?? '');
        $this->rememberTokens[$token] = $entry;

        return $entry;
    }

    public function getAuthIdentifier(): int | string
    {
        return $this->id;
    }

    public function getAuthPassword(): string
    {
        return $this->password;
    }

    public function getRememberToken(string $token): ?RememberToken
    {
        return $this->rememberTokens[$token] ?? null;
    }
}
