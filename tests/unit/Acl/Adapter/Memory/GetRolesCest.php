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
use UnitTester;

/**
 * Class GetRolesCest
 *
 * @package Phalcon\Tests\Unit\Acl\Adapter\Memory
 */
class GetRolesCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getRoles()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryGetRoles(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getRoles()');

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
        $I->assertEquals($expected, $actual);
    }
}
