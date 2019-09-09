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

use Phalcon\Acl\RoleAware;

class RoleObject implements RoleAware
{
    /**
     * @var string
     */
    protected $roleName;

    public function __construct(string $roleName)
    {
        $this->roleName = $roleName;
    }

    public function getRoleName(): string
    {
        return $this->roleName;
    }
}
