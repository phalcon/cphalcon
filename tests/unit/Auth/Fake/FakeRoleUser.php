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

use Phalcon\Acl\RoleAwareInterface;
use Phalcon\Contracts\Auth\AuthUser;

/**
 * AuthUser carrying an ACL role, for the Acl access gate tests.
 */
final class FakeRoleUser implements AuthUser, RoleAwareInterface
{
    public function __construct(
        private int | string $id = 1,
        private string $role = 'admins'
    ) {
    }

    public function getAuthIdentifier(): int | string
    {
        return $this->id;
    }

    public function getAuthPassword(): string
    {
        return '';
    }

    public function getRoleName(): string
    {
        return $this->role;
    }
}
