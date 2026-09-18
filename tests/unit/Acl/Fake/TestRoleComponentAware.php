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

namespace Phalcon\Tests\Unit\Acl\Fake;

use Phalcon\Acl\ComponentAwareInterface;
use Phalcon\Acl\RoleAwareInterface;

class TestRoleComponentAware implements RoleAwareInterface, ComponentAwareInterface
{
    public function __construct(
        protected int $user,
        protected string $componentName,
        protected string $roleName
    ) {
    }

    public function getComponentName(): string
    {
        return $this->componentName;
    }

    public function getRoleName(): string
    {
        return $this->roleName;
    }

    public function getUser(): int
    {
        return $this->user;
    }
}
