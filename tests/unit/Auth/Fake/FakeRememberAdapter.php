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

use Phalcon\Auth\Adapter\Config\MemoryAdapterConfig;
use Phalcon\Auth\Adapter\Memory;
use Phalcon\Contracts\Auth\Adapter\RememberAdapter;
use Phalcon\Contracts\Auth\AuthUser;
use Phalcon\Contracts\Auth\RememberToken;
use Phalcon\Contracts\Encryption\Security\Security;

/**
 * Memory adapter that also supports remember-me. Used to drive Session guard
 * tests for the remember-cookie path without bringing in a real database.
 */
final class FakeRememberAdapter extends Memory implements RememberAdapter
{
    /**
     * Adapter-level token store keyed by token value, so token entries
     * survive across the fresh user instances Memory hydrates on each call.
     *
     * @var array<string, FakeRememberToken>
     */
    private array $tokenStore = [];

    public function __construct(Security $hasher, MemoryAdapterConfig $config)
    {
        parent::__construct($hasher, $config);
    }

    public function createRememberToken(AuthUser $user): RememberToken
    {
        $token              = 'test-token-' . $user->getAuthIdentifier();
        $entry              = new FakeRememberToken($token);
        $this->tokenStore[$token] = $entry;

        return $entry;
    }

    public function retrieveByToken(
        $id,
        string $token,
        ?string $userAgent = null
    ): ?AuthUser {
        if (!isset($this->tokenStore[$token])) {
            return null;
        }

        return $this->retrieveById($id);
    }
}
