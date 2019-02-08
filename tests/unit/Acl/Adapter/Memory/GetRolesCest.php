<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Acl\Adapter\Memory;

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Role;
use UnitTester;

/**
 * Class GetRolesCest
 */
class GetRolesCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getRoles()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryGetRoles(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getRoles()');
        $acl = new Memory();

        $role1 = new Role('Admin');
        $role2 = new Role('Guest');

        $acl->addRole($role1);
        $acl->addRole($role2);

        $expected = [$role1, $role2];
        $actual   = $acl->getRoles();
        $I->assertEquals($expected, $actual);
    }
}
