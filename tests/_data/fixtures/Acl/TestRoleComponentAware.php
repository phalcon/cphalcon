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

namespace Phalcon\Tests\Fixtures\Acl;

use Phalcon\Acl\ComponentAware;
use Phalcon\Acl\RoleAware;

/**
 * Class TestRoleComponentAware
 */
class TestRoleComponentAware implements RoleAware, ComponentAware
{
    /**
     * @var int
     */
    protected $user;

    /**
     * @var string
     */
    protected $componentName;

    /**
     * @var string
     */
    protected $roleName;

    public function __construct($user, string $componentName, string $roleName)
    {
        $this->user          = $user;
        $this->componentName = $componentName;
        $this->roleName      = $roleName;
    }

    public function getComponentName(): string
    {
        return $this->componentName;
    }

    public function getRoleName(): string
    {
        return $this->roleName;
    }

    /**
     * @return int
     */
    public function getUser()
    {
        return $this->user;
    }
}
