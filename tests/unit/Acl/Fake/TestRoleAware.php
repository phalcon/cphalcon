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

use Phalcon\Acl\RoleAwareInterface;

class TestRoleAware implements RoleAwareInterface
{
    /**
     * @param int    $id
     * @param string $roleName
     */
    public function __construct(
        protected int $id,
        protected string $roleName
    ) {
    }

    /**
     * @return int
     */
    public function getId(): int
    {
        return $this->id;
    }

    public function getRoleName(): string
    {
        return $this->roleName;
    }
}
