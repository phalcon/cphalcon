<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Firewall;

class BindingRole extends RoleObject
{
    protected $id;

    public function __construct($roleName, $id)
    {
        parent::__construct($roleName);

        $this->id = $id;
    }

    public function getId()
    {
        return $this->id;
    }

    public function setId($id): BindingRole
    {
        $this->id = $id;

        return $this;
    }
}
