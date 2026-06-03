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

use Phalcon\Contracts\Auth\AuthUser;

/**
 * AuthUser-only stand-in (no AuthRemember). Drives the Model-adapter branch
 * that bails when a hydrated user does not implement AuthRemember.
 */
class FakeAuthUserNoRemember implements AuthUser
{
    /**
     * @var array<int, array<string, mixed>>
     */
    public static array $rows = [];

    public int | string $id = 0;

    public string $password = '';

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
     * @param array<string, mixed> $row
     */
    public function __construct(array $row = [])
    {
        $this->assign($row);
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

    /**
     * @param array{conditions?: string, bind?: array<string, mixed>}|string $parameters
     */
    public static function findFirst(array | string $parameters = []): static | false
    {
        if (is_string($parameters)) {
            return false;
        }

        $bind = $parameters['bind'] ?? [];

        if (!is_array($bind)) {
            return false;
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
                return new static($row);
            }
        }

        return false;
    }

    public function getAuthIdentifier(): int | string
    {
        return $this->id;
    }

    public function getAuthPassword(): string
    {
        return $this->password;
    }
}
