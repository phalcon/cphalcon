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
use Phalcon\Http\Response\CookiesInterface;

final class FakeCookies implements CookiesInterface
{
    /**
     * @var array<string, FakeCookie>
     */
    private array $store = [];

    public function delete(string $name): bool
    {
        unset($this->store[$name]);

        return true;
    }

    public function get(string $name): CookieInterface
    {
        return $this->store[$name] ?? new FakeCookie($name);
    }

    public function has(string $name): bool
    {
        return array_key_exists($name, $this->store);
    }

    public function isUsingEncryption(): bool
    {
        return false;
    }

    public function reset(): CookiesInterface
    {
        $this->store = [];

        return $this;
    }

    public function send(): bool
    {
        return true;
    }

    public function set(
        string $name,
        mixed $value = null,
        int $expire = 0,
        string $path = '/',
        bool $secure = false,
        string $domain = '',
        bool $httpOnly = false,
        array $options = []
    ): CookiesInterface {
        $cookie = new FakeCookie($name, $value);
        $cookie->setExpiration($expire);

        $this->store[$name] = $cookie;

        return $this;
    }

    public function useEncryption(bool $useEncryption): CookiesInterface
    {
        return $this;
    }
}
