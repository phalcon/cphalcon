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

use Phalcon\Acl\RoleAwareInterface;

/**
 * Class TestRoleAware
 *
 * @property int    $id
 * @property string $roleName
 */
class TestRoleAware implements RoleAwareInterface
{
    /**
     * @var int
     */
    protected int $id;

    /**
     * @var string
     */
    protected string $roleName;

    /**
     * TestRoleAware constructor.
     *
     * @param int    $id
     * @param string $roleName
     */
    public function __construct(int $id, string $roleName)
    {
        $this->id       = $id;
        $this->roleName = $roleName;
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
