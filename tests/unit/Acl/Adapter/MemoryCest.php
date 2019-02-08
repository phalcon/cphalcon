<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Acl\Adapter;

use Phalcon\Acl;
use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Role;
use Phalcon\Acl\Component;
use UnitTester;

class MemoryCest
{
    /**
     * Tests the wildcard allow/deny
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclWildcardAllowDeny(UnitTester $I)
    {
        $acl = new Memory();
        $acl->setDefaultAction(Acl::DENY);

        $aclRoles = [
            'Admin'  => new Role('Admin'),
            'Users'  => new Role('Users'),
            'Guests' => new Role('Guests'),
        ];

        $aclComponents = [
            'welcome' => ['index', 'about'],
            'account' => ['index'],
        ];

        foreach ($aclRoles as $Role => $object) {
            $acl->addRole($object);
        }

        foreach ($aclComponents as $component => $actions) {
            $acl->addComponent(new Component($component), $actions);
        }
        $acl->allow("*", "welcome", "index");

        foreach ($aclRoles as $Role => $object) {
            $actual = $acl->isAllowed($Role, 'welcome', 'index');
            $I->assertTrue($actual);
        }

        $acl->deny("*", "welcome", "index");
        foreach ($aclRoles as $Role => $object) {
            $actual = $acl->isAllowed($Role, 'welcome', 'index');
            $I->assertFalse($actual);
        }
    }

    /**
     * Tests the ACL objects
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclObjects(UnitTester $I)
    {
        $acl          = new Memory();
        $aclRole = new Role('Administrators', 'Super User access');
        $aclComponent   = new Component('Customers', 'Customer management');

        $acl->setDefaultAction(Acl::DENY);

        $acl->addRole($aclRole);
        $acl->addComponent($aclComponent, ['search', 'destroy']);

        $acl->allow('Administrators', 'Customers', 'search');
        $acl->deny('Administrators', 'Customers', 'destroy');

        $expected = Acl::ALLOW;
        $actual   = $acl->isAllowed('Administrators', 'Customers', 'search');
        $I->assertEquals($expected, $actual);

        $acl          = new Memory();
        $aclRole = new Role('Administrators', 'Super User access');
        $aclComponent   = new Component('Customers', 'Customer management');

        $acl->setDefaultAction(Acl::DENY);

        $acl->addRole($aclRole);
        $acl->addComponent($aclComponent, ['search', 'destroy']);

        $acl->allow('Administrators', 'Customers', 'search');
        $acl->deny('Administrators', 'Customers', 'destroy');

        $expected = Acl::DENY;
        $actual   = $acl->isAllowed('Administrators', 'Customers', 'destroy');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests serializing the ACL
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclSerialize(UnitTester $I)
    {
        $filename = $I->getNewFileName('acl', 'log');

        $acl          = new Memory();
        $aclRole = new Role('Administrators', 'Super User access');
        $aclComponent   = new Component('Customers', 'Customer management');

        $acl->addRole($aclRole);
        $acl->addComponent($aclComponent, ['search', 'destroy']);

        $acl->allow('Administrators', 'Customers', 'search');
        $acl->deny('Administrators', 'Customers', 'destroy');

        $contents = serialize($acl);
        file_put_contents(cacheFolder($filename), $contents);

        $acl = null;

        $contents = file_get_contents(cacheFolder($filename));

        $I->safeDeleteFile(cacheFolder($filename));

        $acl    = unserialize($contents);
        $actual = ($acl instanceof Memory);
        $I->assertTrue($actual);

        $actual = $acl->isRole('Administrators');
        $I->assertTrue($actual);

        $actual = $acl->isComponent('Customers');
        $I->assertTrue($actual);

        $expected = Acl::ALLOW;
        $actual   = $acl->isAllowed('Administrators', 'Customers', 'search');
        $I->assertEquals($expected, $actual);

        $expected = Acl::DENY;
        $actual   = $acl->isAllowed('Administrators', 'Customers', 'destroy');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests negation of inherited Roles
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/65
     *
     * @author  Phalcon Team <team@phalconphp.com>
     * @since   2014-10-04
     */
    public function testAclNegationOfInheritedRoles(UnitTester $I)
    {
        $acl = new Memory;
        $acl->setDefaultAction(Acl::DENY);

        $acl->addRole('Guests');
        $acl->addRole('Members', 'Guests');

        $acl->addComponent('Login', ['help', 'index']);

        $acl->allow('Guests', 'Login', '*');
        $acl->deny('Guests', 'Login', ['help']);
        $acl->deny('Members', 'Login', ['index']);

        $actual = (bool) $acl->isAllowed('Members', 'Login', 'index');
        $I->assertFalse($actual);

        $actual = (bool) $acl->isAllowed('Guests', 'Login', 'index');
        $I->assertTrue($actual);

        $actual = (bool) $acl->isAllowed('Guests', 'Login', 'help');
        $I->assertFalse($actual);
    }

    /**
     * Tests function in Acl Allow Method
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/12004
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2016-07-22
     */
    public function testIssue12004(UnitTester $I)
    {
        $acl = new Memory();

        $acl->setDefaultAction(Acl::DENY);

        $RoleGuest      = new Role("guest");
        $RoleUser       = new Role("user");
        $RoleAdmin      = new Role("admin");
        $RoleSuperAdmin = new Role("superadmin");

        $acl->addRole($RoleGuest);
        $acl->addRole($RoleUser, $RoleGuest);
        $acl->addRole($RoleAdmin, $RoleUser);
        $acl->addRole($RoleSuperAdmin, $RoleAdmin);

        $acl->addComponent("payment", ["paypal", "facebook",]);

        $acl->allow($RoleGuest->getName(), "payment", "paypal");
        $acl->allow($RoleGuest->getName(), "payment", "facebook");
        $acl->allow($RoleUser->getName(), "payment", "*");

        $actual = $acl->isAllowed($RoleUser->getName(), "payment", "notSet");
        $I->assertTrue($actual);
        $actual = $acl->isAllowed($RoleUser->getName(), "payment", "*");
        $I->assertTrue($actual);
        $actual = $acl->isAllowed($RoleAdmin->getName(), "payment", "notSet");
        $I->assertTrue($actual);
        $actual = $acl->isAllowed($RoleAdmin->getName(), "payment", "*");
        $I->assertTrue($actual);
    }

    /**
     * Tests acl with adding new rule for Role after adding wildcard rule
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/2648
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2016-10-01
     */
    public function testWildCardLastRole(UnitTester $I)
    {
        $acl = new Memory();
        $acl->addRole(new Role("Guests"));
        $acl->addComponent(new Component('Post'), ['index', 'update', 'create']);

        $acl->allow('Guests', 'Post', 'create');
        $acl->allow('*', 'Post', 'index');
        $acl->allow('Guests', 'Post', 'update');

        $actual = $acl->isAllowed('Guests', 'Post', 'create');
        $I->assertTrue($actual);
        $actual = $acl->isAllowed('Guests', 'Post', 'index');
        $I->assertTrue($actual);
        $actual = $acl->isAllowed('Guests', 'Post', 'update');
        $I->assertTrue($actual);
    }

    /**
     * Tests adding wildcard rule second time
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/2648
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2016-10-01
     */
    public function testWildCardSecondTime(UnitTester $I)
    {
        $acl = new Memory();
        $acl->addRole(new Role("Guests"));
        $acl->addComponent(new Component('Post'), ['index', 'update', 'create']);

        $acl->allow('Guests', 'Post', 'create');
        $acl->allow('*', 'Post', 'index');
        $acl->allow('*', 'Post', 'update');

        $actual = $acl->isAllowed('Guests', 'Post', 'create');
        $I->assertTrue($actual);
        $actual = $acl->isAllowed('Guests', 'Post', 'index');
        $I->assertTrue($actual);
        $actual = $acl->isAllowed('Guests', 'Post', 'update');
        $I->assertTrue($actual);
    }


    /**
     * Tests negation of multiple inherited Roles
     *
     *
     * @author  cq-z <64899484@qq.com>
     * @since   2018-10-10
     */
    public function testAclNegationOfMultipleInheritedRoles(UnitTester $I)
    {
        $acl = new Memory;
        $acl->setDefaultAction(Acl::DENY);

        $acl->addRole('Guests');
        $acl->addRole('Guests2');
        $acl->addRole('Members', ['Guests', 'Guests2']);

        $acl->addComponent('Login', ['help', 'index']);

        $acl->allow('Guests', 'Login', '*');
        $acl->deny('Guests2', 'Login', ['help']);
        $acl->deny('Members', 'Login', ['index']);

        $actual = (bool) $acl->isAllowed('Members', 'Login', 'index');
        $I->assertFalse($actual);

        $actual = (bool) $acl->isAllowed('Guests', 'Login', 'help');
        $I->assertTrue($actual);

        $actual = (bool) $acl->isAllowed('Members', 'Login', 'help');
        $I->assertTrue($actual);
    }

    /**
     * Tests negation of multilayer inherited Roles
     *
     *
     * @author  cq-z <64899484@qq.com>
     * @since   2018-10-10
     */
    public function testAclNegationOfMultilayerInheritedRoles(UnitTester $I)
    {
        $acl = new Memory;
        $acl->setDefaultAction(Acl::DENY);

        $acl->addRole('Guests1');
        $acl->addRole('Guests12', 'Guests1');
        $acl->addRole('Guests2');
        $acl->addRole('Guests22', 'Guests2');
        $acl->addRole('Members', ['Guests12', 'Guests22']);

        $acl->addComponent('Login', ['help', 'index']);
        $acl->addComponent('Logout', ['help', 'index']);

        $acl->allow('Guests1', 'Login', '*');
        $acl->deny('Guests12', 'Login', ['help']);

        $acl->deny('Guests2', 'Logout', '*');
        $acl->allow('Guests22', 'Logout', ['index']);

        $actual = (bool) $acl->isAllowed('Members', 'Login', 'index');
        $I->assertTrue($actual);

        $actual = (bool) $acl->isAllowed('Members', 'Login', 'help');
        $I->assertFalse($actual);

        $actual = (bool) $acl->isAllowed('Members', 'Logout', 'help');
        $I->assertFalse($actual);

        $actual = (bool) $acl->isAllowed('Members', 'Login', 'index');
        $I->assertTrue($actual);
    }
}
