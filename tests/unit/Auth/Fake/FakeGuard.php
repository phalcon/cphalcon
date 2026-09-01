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

namespace Phalcon\Tests\Unit\Auth\Fake;

use Phalcon\Contracts\Auth\Adapter\Adapter;
use Phalcon\Contracts\Auth\AuthUser;
use Phalcon\Contracts\Auth\Guard\Guard;

/**
 * Minimal Guard stand-in: holds an optional user; check()/guest() derive
 * from its presence.
 */
final class FakeGuard implements Guard
{
    private ?AuthUser $user = null;

    /**
     * @param array<string, mixed> $options
     */
    public static function fromOptions(
        Adapter $adapter,
        $container,
        array $options
    ): static {
        return new static();
    }

    public function check(): bool
    {
        return $this->user !== null;
    }

    public function getLastUserAttempted(): ?AuthUser
    {
        return null;
    }

    public function guest(): bool
    {
        return $this->user === null;
    }

    public function hasUser(): bool
    {
        return $this->user !== null;
    }

    public function id(): int | string | null
    {
        return $this->user?->getAuthIdentifier();
    }

    public function setUser(AuthUser $user): static
    {
        $this->user = $user;

        return $this;
    }

    public function user(): ?AuthUser
    {
        return $this->user;
    }

    public function validate(array $credentials = []): bool
    {
        return false;
    }
}
