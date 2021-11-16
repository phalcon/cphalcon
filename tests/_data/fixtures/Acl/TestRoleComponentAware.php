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

use Phalcon\Acl\ComponentAwareInterface;
use Phalcon\Acl\RoleAwareInterface;

/**
 * Class TestRoleComponentAware
 *
 * @property int    $user
 * @property string $componentName
 * @property string $roleName
 */
class TestRoleComponentAware implements RoleAwareInterface, ComponentAwareInterface
{
    /**
     * @var int
     */
    protected int $user;

    /**
     * @var string
     */
    protected string $componentName;

    /**
     * @var string
     */
    protected string $roleName;

    /**
     * TestRoleComponentAware constructor.
     *
     * @param int    $user
     * @param string $componentName
     * @param string $roleName
     */
    public function __construct(int $user, string $componentName, string $roleName)
    {
        $this->user          = $user;
        $this->componentName = $componentName;
        $this->roleName      = $roleName;
    }

    /**
     * @return string
     */
    public function getComponentName(): string
    {
        return $this->componentName;
    }

    /**
     * @return string
     */
    public function getRoleName(): string
    {
        return $this->roleName;
    }

    /**
     * @return int
     */
    public function getUser(): int
    {
        return $this->user;
    }
}
