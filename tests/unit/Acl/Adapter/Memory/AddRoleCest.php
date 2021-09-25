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
use Phalcon\Acl\Exception;
use Phalcon\Acl\Role;
use UnitTester;

class AddRoleCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addRole() - string
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddRoleString(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addRole() - string');

        $acl = new Memory();

        $role = new Role('Administrators', 'Super User access');

        $I->assertTrue(
            $acl->addRole('Administrators')
        );
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addRole() - object
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddRoleObject(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addRole() - object');

        $acl = new Memory();

        $role = new Role('Administrators', 'Super User access');

        $I->assertTrue(
            $acl->addRole($role)
        );
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addRole() - twice string
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddRoleTwiceString(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addRole() - twice string');

        $acl = new Memory();

        $role = new Role('Administrators', 'Super User access');

        $I->assertTrue(
            $acl->addRole('Administrators')
        );

        $I->assertFalse(
            $acl->addRole('Administrators')
        );
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addRole() - twice object
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddRoleTwiceObject(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addRole() - twice object');

        $acl = new Memory();

        $role = new Role('Administrators', 'Super User access');

        $I->assertTrue(
            $acl->addRole($role)
        );

        $I->assertFalse(
            $acl->addRole($role)
        );
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addRole() - numeric key
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddRoleNumericKey(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addRole() - numeric key');

        $acl = new Memory();

        $role = new Role('11', 'Super User access');

        $I->assertTrue(
            $acl->addRole('11')
        );

        $I->assertTrue(
            $acl->isRole('11')
        );
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addRole() - exception
     *
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddRoleException(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addRole() - numeric key');

        $I->expectThrowable(
            new Exception(
                'Role must be either a string or implement RoleInterface'
            ),
            function () {
                $acl = new Memory();
                $acl->addRole(true);
            }
        );
    }
}
