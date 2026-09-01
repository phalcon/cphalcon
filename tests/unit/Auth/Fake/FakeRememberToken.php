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

use Phalcon\Contracts\Auth\RememberToken;

final class FakeRememberToken implements RememberToken
{
    public bool $deleted = false;

    public function __construct(
        private readonly string $token,
        private readonly string $userAgent = '',
    ) {
    }

    public function delete(): bool
    {
        $this->deleted = true;

        return true;
    }

    public function getToken(): string
    {
        return $this->token;
    }

    public function getUserAgent(): ?string
    {
        return $this->userAgent === '' ? null : $this->userAgent;
    }
}
