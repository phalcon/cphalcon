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

namespace Phalcon\Tests\Unit\Acl\Adapter\Memory;

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Role;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetRolesTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAclAdapterMemoryGetRoles(): void
    {
        $acl   = new Memory();
        $role1 = new Role('Admin');
        $role2 = new Role('Guest');

        $acl->addRole($role1);
        $acl->addRole($role2);

        $expected = [
            'Admin' => $role1,
            'Guest' => $role2,
        ];
        $actual   = $acl->getRoles();
        $this->assertSame($expected, $actual);
    }
}
