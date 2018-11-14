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
use Phalcon\Acl\Resource;
use Phalcon\Acl\Role;

use Phalcon\Test\Fixtures\Acl\TestResourceAware;
use Phalcon\Test\Fixtures\Acl\TestRoleAware;
use Phalcon\Test\Fixtures\Acl\TestRoleResourceAware;
use PHPUnit\Framework\Exception;
use UnitTester;

class MemoryCest
{
    /**
     * Tests the ACL constants
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-03
     */
    public function testAclConstants(UnitTester $I)
    {
        $I->assertEquals(1, Acl::ALLOW);
        $I->assertEquals(0, Acl::DENY);
    }

    /**
     * Tests the setDefaultAction
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclDefaultAction(UnitTester $I)
    {
        $acl = new Memory();

        $acl->setDefaultAction(Acl::ALLOW);

        $expected = Acl::ALLOW;
        $actual   = $acl->getDefaultAction();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the addRole
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclAddRoleExists(UnitTester $I)
    {
        $acl     = new Memory();
        $aclRole = new Role('Administrators', 'Super User access');

        $acl->addRole($aclRole);

        $actual = $acl->isRole('Administrators');
        $I->assertTrue($actual);
    }

    /**
     * Tests the addRole for the same role twice
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclAddRoleTwiceReturnsFalse(UnitTester $I)
    {
        $acl     = new Memory();
        $aclRole = new Role('Administrators', 'Super User access');

        $acl->addRole($aclRole);
        $actual = $acl->addRole($aclRole);
        $I->assertFalse($actual);
    }

    /**
     * Tests the addRole for the same role twice by key
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclAddRoleTwiceByKeyReturnsFalse(UnitTester $I)
    {
        $acl     = new Memory();
        $aclRole = new Role('Administrators', 'Super User access');

        $acl->addRole($aclRole);
        $actual = $acl->addRole('Administrators');
        $I->assertFalse($actual);
    }

    /**
     * Tests the wildcard allow/deny
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
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

        $aclResources = [
            'welcome' => ['index', 'about'],
            'account' => ['index'],
        ];

        foreach ($aclRoles as $role => $object) {
            $acl->addRole($object);
        }

        foreach ($aclResources as $resource => $actions) {
            $acl->addResource(new Resource($resource), $actions);
        }
        $acl->allow("*", "welcome", "index");

        foreach ($aclRoles as $role => $object) {
            $actual = $acl->isAllowed($role, 'welcome', 'index');
            $I->assertTrue($actual);
        }

        $acl->deny("*", "welcome", "index");
        foreach ($aclRoles as $role => $object) {
            $actual = $acl->isAllowed($role, 'welcome', 'index');
            $I->assertFalse($actual);
        }
    }

    /**
     * Tests the isRole with wrong keyword
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclIsRoleWithWrongKeyReturnsFalse(UnitTester $I)
    {
        $acl    = new Memory();
        $actual = $acl->isRole('Wrong');
        $I->assertFalse($actual);
    }

    /**
     * Tests the role name
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclRoleName(UnitTester $I)
    {
        $acl     = new Memory();
        $aclRole = new Role('Administrators', 'Super User access');

        $acl->addRole($aclRole);
        $actual = $acl->isRole('Administrators');
        $I->assertTrue($actual);
    }

    /**
     * Tests the addResource
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclAddResourceExists(UnitTester $I)
    {
        $acl         = new Memory();
        $aclResource = new Resource('Customers', 'Customer management');

        $actual = $acl->addResource($aclResource, 'search');
        $I->assertTrue($actual);
    }

    /**
     * Tests the resource name
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclResourceName(UnitTester $I)
    {
        $acl         = new Memory();
        $aclResource = new Resource('Customers', 'Customer management');

        $acl->addResource($aclResource, 'search');
        $actual = $acl->isResource('Customers');
        $I->assertTrue($actual);
    }

    /**
     * Tests the ACL objects default action
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclObjectsWithDefaultAction(UnitTester $I)
    {
        $acl         = new Memory();
        $aclRole     = new Role('Administrators', 'Super User access');
        $aclResource = new Resource('Customers', 'Customer management');

        $acl->setDefaultAction(Acl::DENY);

        $acl->addRole($aclRole);
        $acl->addResource($aclResource, ['search', 'destroy']);

        $expected = Acl::DENY;
        $actual   = $acl->isAllowed('Administrators', 'Customers', 'search');
        $I->assertEquals($expected, $actual);

        $acl         = new Memory();
        $aclRole     = new Role('Administrators', 'Super User access');
        $aclResource = new Resource('Customers', 'Customer management');

        $acl->setDefaultAction(Acl::DENY);

        $acl->addRole($aclRole);
        $acl->addResource($aclResource, ['search', 'destroy']);

        $expected = Acl::DENY;
        $actual   = $acl->isAllowed('Administrators', 'Customers', 'destroy');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the ACL objects
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclObjects(UnitTester $I)
    {
        $acl         = new Memory();
        $aclRole     = new Role('Administrators', 'Super User access');
        $aclResource = new Resource('Customers', 'Customer management');

        $acl->setDefaultAction(Acl::DENY);

        $acl->addRole($aclRole);
        $acl->addResource($aclResource, ['search', 'destroy']);

        $acl->allow('Administrators', 'Customers', 'search');
        $acl->deny('Administrators', 'Customers', 'destroy');

        $expected = Acl::ALLOW;
        $actual   = $acl->isAllowed('Administrators', 'Customers', 'search');
        $I->assertEquals($expected, $actual);

        $acl         = new Memory();
        $aclRole     = new Role('Administrators', 'Super User access');
        $aclResource = new Resource('Customers', 'Customer management');

        $acl->setDefaultAction(Acl::DENY);

        $acl->addRole($aclRole);
        $acl->addResource($aclResource, ['search', 'destroy']);

        $acl->allow('Administrators', 'Customers', 'search');
        $acl->deny('Administrators', 'Customers', 'destroy');

        $expected = Acl::DENY;
        $actual   = $acl->isAllowed('Administrators', 'Customers', 'destroy');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests serializing the ACL
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclSerialize(UnitTester $I)
    {
        $filename = $I->getNewFileName('acl', 'log');

        $acl         = new Memory();
        $aclRole     = new Role('Administrators', 'Super User access');
        $aclResource = new Resource('Customers', 'Customer management');

        $acl->addRole($aclRole);
        $acl->addResource($aclResource, ['search', 'destroy']);

        $acl->allow('Administrators', 'Customers', 'search');
        $acl->deny('Administrators', 'Customers', 'destroy');

        $contents = serialize($acl);
        file_put_contents(PATH_CACHE . $filename, $contents);

        $acl = null;

        $contents = file_get_contents(PATH_CACHE . $filename);

        $I->cleanFile(PATH_CACHE, $filename);

        $acl    = unserialize($contents);
        $actual = ($acl instanceof Memory);
        $I->assertTrue($actual);

        $actual = $acl->isRole('Administrators');
        $I->assertTrue($actual);

        $actual = $acl->isResource('Customers');
        $I->assertTrue($actual);

        $expected = Acl::ALLOW;
        $actual   = $acl->isAllowed('Administrators', 'Customers', 'search');
        $I->assertEquals($expected, $actual);

        $expected = Acl::DENY;
        $actual   = $acl->isAllowed('Administrators', 'Customers', 'destroy');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests negation of inherited roles
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/65
     *
     * @author  Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since   2014-10-04
     */
    public function testAclNegationOfInheritedRoles(UnitTester $I)
    {
        $acl = new Memory;
        $acl->setDefaultAction(Acl::DENY);

        $acl->addRole('Guests');
        $acl->addRole('Members', 'Guests');

        $acl->addResource('Login', ['help', 'index']);

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
     * Tests ACL Resources with numeric values
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/1513
     *
     * @author  Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since   2014-10-04
     */
    public function testAclResourcesWithNumericValues(UnitTester $I)
    {
        $acl = new Memory;
        $acl->setDefaultAction(Acl::DENY);

        $acl->addRole(new Role('11'));
        $acl->addResource(new Resource('11'), ['index']);

        $actual = $acl->isResource('11');
        $I->assertTrue($actual);
    }

    /**
     * Tests function in Acl Allow Method
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/11235
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2015-12-16
     */
    public function testAclAllowFunction(UnitTester $I)
    {
        $acl = new Memory;
        $acl->setDefaultAction(Acl::DENY);
        $acl->addRole('Guests');
        $acl->addRole('Members', 'Guests');
        $acl->addRole('Admins', 'Members');
        $acl->addResource('Post', ['update']);

        $guest         = new TestRoleAware(1, 'Guests');
        $member        = new TestRoleAware(2, 'Members');
        $anotherMember = new TestRoleAware(3, 'Members');
        $admin         = new TestRoleAware(4, 'Admins');
        $model         = new TestResourceAware(2, 'Post');

        $acl->deny('Guests', 'Post', 'update');
        $acl->allow('Members', 'Post', 'update', function (TestRoleAware $user, TestResourceAware $model) {
            return $user->getId() == $model->getUser();
        });
        $acl->allow('Admins', 'Post', 'update');

        $actual = $acl->isAllowed($guest, $model, 'update');
        $I->assertFalse($actual);

        $actual = $acl->isAllowed($member, $model, 'update');
        $I->assertTrue($actual);

        $actual = $acl->isAllowed($anotherMember, $model, 'update');
        $I->assertFalse($actual);

        $actual = $acl->isAllowed($admin, $model, 'update');
        $I->assertTrue($actual);
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

        $roleGuest      = new Role("guest");
        $roleUser       = new Role("user");
        $roleAdmin      = new Role("admin");
        $roleSuperAdmin = new Role("superadmin");

        $acl->addRole($roleGuest);
        $acl->addRole($roleUser, $roleGuest);
        $acl->addRole($roleAdmin, $roleUser);
        $acl->addRole($roleSuperAdmin, $roleAdmin);

        $acl->addResource("payment", ["paypal", "facebook",]);

        $acl->allow($roleGuest->getName(), "payment", "paypal");
        $acl->allow($roleGuest->getName(), "payment", "facebook");
        $acl->allow($roleUser->getName(), "payment", "*");

        $actual = $acl->isAllowed($roleUser->getName(), "payment", "notSet");
        $I->assertTrue($actual);
        $actual = $acl->isAllowed($roleUser->getName(), "payment", "*");
        $I->assertTrue($actual);
        $actual = $acl->isAllowed($roleAdmin->getName(), "payment", "notSet");
        $I->assertTrue($actual);
        $actual = $acl->isAllowed($roleAdmin->getName(), "payment", "*");
        $I->assertTrue($actual);
    }

    /**
     * Tests function in Acl Allow Method without arguments
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/12094
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2016-06-05
     */
    public function testAclAllowFunctionNoArguments(UnitTester $I)
    {
        $acl = new Memory;
        $acl->setDefaultAction(Acl::ALLOW);
        $acl->setNoArgumentsDefaultAction(Acl::DENY);
        $acl->addRole('Guests');
        $acl->addRole('Members', 'Guests');
        $acl->addRole('Admins', 'Members');
        $acl->addResource('Post', ['update']);

        $guest         = new TestRoleAware(1, 'Guests');
        $member        = new TestRoleAware(2, 'Members');
        $anotherMember = new TestRoleAware(3, 'Members');
        $admin         = new TestRoleAware(4, 'Admins');
        $model         = new TestResourceAware(2, 'Post');

        $acl->allow('Guests', 'Post', 'update', function ($parameter) {
            return $parameter % 2 == 0;
        });
        $acl->allow('Members', 'Post', 'update', function ($parameter) {
            return $parameter % 2 == 0;
        });
        $acl->allow('Admins', 'Post', 'update');

        $actual = @$acl->isAllowed($guest, $model, 'update');
        $I->assertFalse($actual);
        $actual = @$acl->isAllowed($member, $model, 'update');
        $I->assertFalse($actual);
        $actual = @$acl->isAllowed($anotherMember, $model, 'update');
        $I->assertFalse($actual);
        $actual = @$acl->isAllowed($admin, $model, 'update');
        $I->assertTrue($actual);
    }

    /**
     * Tests function in Acl Allow Method without arguments
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12094
     * @author                   Wojciech Slawski <jurigag@gmail.com>
     * @since                    2016-06-05
     */
    public function testAclAllowFunctionNoArgumentsWithWarning(UnitTester $I)
    {
        $I->expectThrowable(
            new Exception(
                "You didn't provide any parameters when check Guests can " .
                "update Post. We will use default action when no arguments.",
                1024
            ),
            function () {
                $acl = new Memory;
                $acl->setDefaultAction(Acl::ALLOW);
                $acl->setNoArgumentsDefaultAction(Acl::DENY);
                $acl->addRole('Guests');
                $acl->addRole('Members', 'Guests');
                $acl->addRole('Admins', 'Members');
                $acl->addResource('Post', ['update']);

                $guest         = new TestRoleAware(1, 'Guests');
                $member        = new TestRoleAware(2, 'Members');
                $anotherMember = new TestRoleAware(3, 'Members');
                $admin         = new TestRoleAware(4, 'Admins');
                $model         = new TestResourceAware(2, 'Post');

                $acl->allow('Guests', 'Post', 'update', function ($parameter) {
                    return $parameter % 2 == 0;
                });
                $acl->allow('Members', 'Post', 'update', function ($parameter) {
                    return $parameter % 2 == 0;
                });
                $acl->allow('Admins', 'Post', 'update');

                $actual = $acl->isAllowed($guest, $model, 'update');
                $I->assertFalse($actual);
                $actual = $acl->isAllowed($member, $model, 'update');
                $I->assertFalse($actual);
                $actual = $acl->isAllowed($anotherMember, $model, 'update');
                $I->assertFalse($actual);
                $actual = $acl->isAllowed($admin, $model, 'update');
                $I->assertTrue($actual);
            }
        );
    }

    /**
     * Tests acl with adding new rule for role after adding wildcard rule
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
        $acl->addResource(new Resource('Post'), ['index', 'update', 'create']);

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
        $acl->addResource(new Resource('Post'), ['index', 'update', 'create']);

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
     * Tests adding wildcard rule second time
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/12573
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-01-25
     */
    public function testDefaultAction(UnitTester $I)
    {
        $acl = new Memory();
        $acl->setDefaultAction(Acl::DENY);
        $acl->addResource(new Acl\Resource('Post'), ['index', 'update', 'create']);
        $acl->addRole(new Role('Guests'));

        $acl->allow('Guests', 'Post', 'index');
        $actual = $acl->isAllowed('Guests', 'Post', 'index');
        $I->assertTrue($actual);
        $actual = $acl->isAllowed('Guests', 'Post', 'update');
        $I->assertFalse($actual);
    }

    /**
     * Tests role and resource objects as isAllowed parameters
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-02-15
     */
    public function testRoleResourceObjects(UnitTester $I)
    {
        $acl = new Memory();
        $acl->setDefaultAction(Acl::DENY);
        $role     = new Role('Guests');
        $resource = new Resource('Post');
        $acl->addRole($role);
        $acl->addResource($resource, ['index', 'update', 'create']);

        $acl->allow('Guests', 'Post', 'index');

        $actual = $acl->isAllowed($role, $resource, 'index');
        $I->assertTrue($actual);
        $actual = $acl->isAllowed($role, $resource, 'update');
        $I->assertFalse($actual);
    }

    /**
     * Tests role and resource objects as isAllowed parameters of the same class
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-02-15
     */
    public function testRoleResourceSameClassObjects(UnitTester $I)
    {
        $acl = new Memory();
        $acl->setDefaultAction(Acl::DENY);
        $role     = new TestRoleResourceAware(1, 'User', 'Admin');
        $resource = new TestRoleResourceAware(2, 'User', 'Admin');
        $acl->addRole('Admin');
        $acl->addResource('User', ['update']);
        $acl->allow(
            'Admin',
            'User',
            ['update'],
            function (TestRoleResourceAware $admin, TestRoleResourceAware $user) {
                return $admin->getUser() == $user->getUser();
            }
        );

        $actual = $acl->isAllowed($role, $resource, 'update');
        $I->assertFalse($actual);
        $actual = $acl->isAllowed($role, $role, 'update');
        $I->assertTrue($actual);
        $actual = $acl->isAllowed($resource, $resource, 'update');
        $I->assertTrue($actual);
    }

    /**
     * Tests negation of multiple inherited roles
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

        $acl->addResource('Login', ['help', 'index']);

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
     * Tests negation of multilayer inherited roles
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

        $acl->addResource('Login', ['help', 'index']);
        $acl->addResource('Logout', ['help', 'index']);

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
