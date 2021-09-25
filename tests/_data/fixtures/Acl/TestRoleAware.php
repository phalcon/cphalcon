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

use Phalcon\Acl\RoleAware;

/**
 * Class TestRoleAware
 */
class TestRoleAware implements RoleAware
{
    /**
     * @var int
     */
    protected $id;

    /**
     * @var string
     */
    protected $roleName;

    public function __construct($id, string $roleName)
    {
        $this->id       = $id;
        $this->roleName = $roleName;
    }

    /**
     * @return int
     */
    public function getId()
    {
        return $this->id;
    }

    public function getRoleName(): string
    {
        return $this->roleName;
    }
}
