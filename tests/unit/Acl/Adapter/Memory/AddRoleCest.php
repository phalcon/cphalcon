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
 * Class AddRoleCest
 */
class AddRoleCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addRole() - string
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddRoleString(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addRole() - string');
        $acl       = new Memory();
        $role = new Role('Administrators', 'Super User access');

        $actual = $acl->addRole('Administrators');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addRole() - object
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddRoleObject(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addRole() - object');
        $acl       = new Memory();
        $role = new Role('Administrators', 'Super User access');

        $actual = $acl->addRole($role);
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addRole() - twice string
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddRoleTwiceString(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addRole() - twice string');
        $acl       = new Memory();
        $role = new Role('Administrators', 'Super User access');

        $actual = $acl->addRole('Administrators');
        $I->assertTrue($actual);
        $actual = $acl->addRole('Administrators');
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addRole() - twice object
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddRoleTwiceObject(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addRole() - twice object');
        $acl       = new Memory();
        $role = new Role('Administrators', 'Super User access');

        $actual = $acl->addRole($role);
        $I->assertTrue($actual);
        $actual = $acl->addRole($role);
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addRole() - numeric key
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddRoleNumericKey(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addRole() - numeric key');
        $acl       = new Memory();
        $role = new Role('11', 'Super User access');

        $actual = $acl->addRole('11');
        $I->assertTrue($actual);
        $actual = $acl->isRole('11');
        $I->assertTrue($actual);
    }
}
