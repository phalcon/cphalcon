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

use Phalcon\Http\Cookie\CookieInterface;

final class FakeCookie implements CookieInterface
{
    private int $expiration = 0;
    private string $name;
    private mixed $value;

    public function __construct(string $name, mixed $value = null)
    {
        $this->name  = $name;
        $this->value = $value;
    }

    public function delete(): void
    {
    }

    public function getDomain(): string
    {
        return '';
    }

    public function getExpiration(): int
    {
        return $this->expiration;
    }

    public function getHttpOnly(): bool
    {
        return false;
    }

    public function getName(): string
    {
        return $this->name;
    }

    public function getOptions(): array
    {
        return [];
    }

    public function getPath(): string
    {
        return '/';
    }

    public function getSecure(): bool
    {
        return false;
    }

    public function getValue(mixed $filters = null, mixed $defaultValue = null): mixed
    {
        return $this->value ?? $defaultValue;
    }

    public function isUsingEncryption(): bool
    {
        return false;
    }

    public function send(): CookieInterface
    {
        return $this;
    }

    public function setDomain(string $domain): CookieInterface
    {
        return $this;
    }

    public function setExpiration(int $expire): CookieInterface
    {
        $this->expiration = $expire;

        return $this;
    }

    public function setHttpOnly(bool $httpOnly): CookieInterface
    {
        return $this;
    }

    public function setOptions(array $options): CookieInterface
    {
        return $this;
    }

    public function setPath(string $path): CookieInterface
    {
        return $this;
    }

    public function setSecure(bool $secure): CookieInterface
    {
        return $this;
    }

    public function setValue(mixed $value): CookieInterface
    {
        $this->value = $value;

        return $this;
    }

    public function useEncryption(bool $useEncryption): CookieInterface
    {
        return $this;
    }
}
