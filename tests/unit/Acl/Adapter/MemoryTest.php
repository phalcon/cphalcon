<?php

namespace Phalcon\Test\Unit\Acl\Adapter;

use Phalcon\Acl;
use Phalcon\Acl\Role;
use Phalcon\Acl\Resource;
use Phalcon\Test\Acl\TestResourceAware;
use Phalcon\Test\Acl\TestRoleAware;
use Phalcon\Test\Acl\TestRoleResourceAware;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Acl\Adapter\Memory;

/**
 * \Phalcon\Test\Unit\Acl\Adapter\MemoryTest
 * Tests for \Phalcon\Acl\Adapter\Memory component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Acl\Adapter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class MemoryTest extends UnitTest
{
    /**
     * Tests the ACL constants
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-03
     */
    public function testAclConstants()
    {
        $this->specify(
            "The ACL constants are not correct",
            function () {
                expect(Acl::ALLOW)->equals(1);
                expect(Acl::DENY)->equals(0);
            }
        );
    }

    /**
     * Tests the setDefaultAction
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclDefaultAction()
    {
        $this->specify(
            'The Acl\Adapter\Memory does not get/set the default action correctly',
            function () {
                $acl = new Memory();

                $acl->setDefaultAction(Acl::ALLOW);

                $expected = Acl::ALLOW;
                $actual   = $acl->getDefaultAction();
                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests the addRole
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclAddRoleExists()
    {
        $this->specify(
            'Adding a ACL\Role in the ACL does not exist',
            function () {
                $acl     = new Memory();
                $aclRole = new Role('Administrators', 'Super User access');

                $acl->addRole($aclRole);

                $actual = $acl->isRole('Administrators');
                expect($actual)->true();
            }
        );
    }

    /**
     * Tests the addRole for the same role twice
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclAddRoleTwiceReturnsFalse()
    {
        $this->specify(
            'Acl\Role added twice returns true',
            function () {
                $acl     = new Memory();
                $aclRole = new Role('Administrators', 'Super User access');

                $acl->addRole($aclRole);
                $actual = $acl->addRole($aclRole);

                expect($actual)->false();
            }
        );
    }

    /**
     * Tests the addRole for the same role twice by key
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclAddRoleTwiceByKeyReturnsFalse()
    {
        $this->specify(
            'Acl\Role added twice by key returns true',
            function () {
                $acl     = new Memory();
                $aclRole = new Role('Administrators', 'Super User access');

                $acl->addRole($aclRole);
                $actual = $acl->addRole('Administrators');

                expect($actual)->false();
            }
        );
    }

    /**
     * Tests the wildcard allow/deny
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclWildcardAllowDeny()
    {
        $this->specify(
            'Acl\Role added twice by key returns true',
            function () {
                $acl     = new Memory();
                $acl->setDefaultAction(Acl::DENY);

                $aclRoles  = [
                    'Admin'  => new Role('Admin'),
                    'Users'  => new Role('Users'),
                    'Guests' => new Role('Guests')
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
                    expect($acl->isAllowed($role, 'welcome', 'index'))->true();
                }

                $acl->deny("*", "welcome", "index");
                foreach ($aclRoles as $role => $object) {
                    expect($acl->isAllowed($role, 'welcome', 'index'))->false();
                }
            }
        );
    }

    /**
     * Tests the isRole with wrong keyword
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclIsRoleWithWrongKeyReturnsFalse()
    {
        $this->specify(
            'Acl\Role added with wrong key returns true in isRole',
            function () {
                $acl     = new Memory();

                $actual = $acl->isRole('Wrong');

                expect($actual)->false();
            }
        );
    }

    /**
     * Tests the role name
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclRoleName()
    {
        $this->specify(
            'Acl\Role does not exist in Acl',
            function () {
                $acl     = new Memory();
                $aclRole = new Role('Administrators', 'Super User access');

                $acl->addRole($aclRole);

                $actual = $acl->isRole('Administrators');

                expect($actual)->true();
            }
        );
    }

    /**
     * Tests the addResource
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclAddResourceExists()
    {
        $this->specify(
            'Acl\Resource does not exist in Acl',
            function () {
                $acl         = new Memory();
                $aclResource = new Resource('Customers', 'Customer management');

                $actual = $acl->addResource($aclResource, 'search');

                expect($actual)->true();
            }
        );
    }

    /**
     * Tests the resource name
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclResourceName()
    {
        $this->specify(
            'Acl\Resource by name does not exist in the acl',
            function () {
                $acl         = new Memory();
                $aclResource = new Resource('Customers', 'Customer management');

                $acl->addResource($aclResource, 'search');

                $actual = $acl->isResource('Customers');

                expect($actual)->true();
            }
        );
    }

    /**
     * Tests the ACL objects default action
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclObjectsWithDefaultAction()
    {
        $this->specify(
            'Acl with default action search does not return correct results',
            function () {
                $acl         = new Memory();
                $aclRole     = new Role('Administrators', 'Super User access');
                $aclResource = new Resource('Customers', 'Customer management');

                $acl->setDefaultAction(Acl::DENY);

                $acl->addRole($aclRole);
                $acl->addResource($aclResource, ['search', 'destroy']);

                $expected = Acl::DENY;
                $actual   = $acl->isAllowed('Administrators', 'Customers', 'search');
                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            'Acl with default action destroy does not return correct results',
            function () {
                $acl         = new Memory();
                $aclRole     = new Role('Administrators', 'Super User access');
                $aclResource = new Resource('Customers', 'Customer management');

                $acl->setDefaultAction(Acl::DENY);

                $acl->addRole($aclRole);
                $acl->addResource($aclResource, ['search', 'destroy']);

                $expected = Acl::DENY;
                $actual   = $acl->isAllowed('Administrators', 'Customers', 'destroy');
                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests the ACL objects
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclObjects()
    {
        $this->specify(
            'Acl search does not return correct results',
            function () {
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
                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            'Acl destroy does not return correct results',
            function () {
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
                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests serializing the ACL
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclSerialize()
    {
        $this->specify(
            'Acl serialization/unserialization does not return a correct object back',
            function () {
                $filename    = $this->tester->getNewFileName('acl', 'log');

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

                $this->tester->cleanFile(PATH_CACHE, $filename);

                $acl = unserialize($contents);
                $actual = ($acl instanceof Memory);
                expect($actual)->true();

                $actual = $acl->isRole('Administrators');
                expect($actual)->true();

                $actual = $acl->isResource('Customers');
                expect($actual)->true();

                $expected = Acl::ALLOW;
                $actual   = $acl->isAllowed('Administrators', 'Customers', 'search');
                expect($actual)->equals($expected);

                $expected = Acl::DENY;
                $actual   = $acl->isAllowed('Administrators', 'Customers', 'destroy');
                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests negation of inherited roles
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/65
     *
     * @author  Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since   2014-10-04
     */
    public function testAclNegationOfInheritedRoles()
    {
        $this->specify(
            'Negation of inherited roles does not return the correct result',
            function () {
                $acl = new Memory;
                $acl->setDefaultAction(Acl::DENY);

                $acl->addRole('Guests');
                $acl->addRole('Members', 'Guests');

                $acl->addResource('Login', ['help', 'index']);

                $acl->allow('Guests', 'Login', '*');
                $acl->deny('Guests', 'Login', ['help']);
                $acl->deny('Members', 'Login', ['index']);

                $actual = (bool)$acl->isAllowed('Members', 'Login', 'index');
                expect($actual)->false();

                $actual = (bool)$acl->isAllowed('Guests', 'Login', 'index');
                expect($actual)->true();

                $actual = (bool)$acl->isAllowed('Guests', 'Login', 'help');
                expect($actual)->false();
            }
        );
    }

    /**
     * Tests ACL Resources with numeric values
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/1513
     *
     * @author  Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since   2014-10-04
     */
    public function testAclResourcesWithNumericValues()
    {
        $this->specify(
            'ACL Resources with numeric values are not set properly',
            function () {
                $acl = new Memory;
                $acl->setDefaultAction(Acl::DENY);

                $acl->addRole(new Role('11'));
                $acl->addResource(new Resource('11'), ['index']);

                $actual = $acl->isResource('11');
                expect($actual)->true();
            }
        );
    }

    /**
     * Tests function in Acl Allow Method
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/11235
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2015-12-16
     */
    public function testAclAllowFunction()
    {
        $this->specify(
            'The function in allow should be called and isAllowed should return correct values when using function in allow method',
            function () {
                $acl = new Memory;
                $acl->setDefaultAction(Acl::DENY);
                $acl->addRole('Guests');
                $acl->addRole('Members', 'Guests');
                $acl->addRole('Admins', 'Members');
                $acl->addResource('Post', ['update']);

                $guest = new TestRoleAware(1, 'Guests');
                $member = new TestRoleAware(2, 'Members');
                $anotherMember = new TestRoleAware(3, 'Members');
                $admin = new TestRoleAware(4, 'Admins');
                $model = new TestResourceAware(2, 'Post');

                $acl->deny('Guests', 'Post', 'update');
                $acl->allow('Members', 'Post', 'update', function (TestRoleAware $user, TestResourceAware $model) {
                    return $user->getId() == $model->getUser();
                });
                $acl->allow('Admins', 'Post', 'update');

                expect($acl->isAllowed($guest, $model, 'update'))->false();
                expect($acl->isAllowed($member, $model, 'update'))->true();
                expect($acl->isAllowed($anotherMember, $model, 'update'))->false();
                expect($acl->isAllowed($admin, $model, 'update'))->true();
            }
        );
    }

    /**
     * Tests function in Acl Allow Method
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/12004
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2016-07-22
     */
    public function testIssue12004()
    {
        $this->specify(
            'Wildcard inheritance should work correctly.',
            function () {
                $acl = new Memory();

                $acl->setDefaultAction(Acl::DENY);

                $roleGuest = new Role("guest");
                $roleUser = new Role("user");
                $roleAdmin = new Role("admin");
                $roleSuperAdmin = new Role("superadmin");

                $acl->addRole($roleGuest);
                $acl->addRole($roleUser, $roleGuest);
                $acl->addRole($roleAdmin, $roleUser);
                $acl->addRole($roleSuperAdmin, $roleAdmin);

                $acl->addResource("payment", ["paypal", "facebook", ]);

                $acl->allow($roleGuest->getName(), "payment", "paypal");
                $acl->allow($roleGuest->getName(), "payment", "facebook");

                $acl->allow($roleUser->getName(), "payment", "*");

                expect($acl->isAllowed($roleUser->getName(), "payment", "notSet"))->true();
                expect($acl->isAllowed($roleUser->getName(), "payment", "*"))->true();
                expect($acl->isAllowed($roleAdmin->getName(), "payment", "notSet"))->true();
                expect($acl->isAllowed($roleAdmin->getName(), "payment", "*"))->true();
            }
        );
    }

    /**
     * Tests function in Acl Allow Method without arguments
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/12094
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2016-06-05
     */
    public function testAclAllowFunctionNoArguments()
    {
        $this->specify(
            'The function in allow should be called and isAllowed should return correct values when using function in allow method',
            function () {
                $acl = new Memory;
                $acl->setDefaultAction(Acl::ALLOW);
                $acl->setNoArgumentsDefaultAction(Acl::DENY);
                $acl->addRole('Guests');
                $acl->addRole('Members', 'Guests');
                $acl->addRole('Admins', 'Members');
                $acl->addResource('Post', ['update']);

                $guest = new TestRoleAware(1, 'Guests');
                $member = new TestRoleAware(2, 'Members');
                $anotherMember = new TestRoleAware(3, 'Members');
                $admin = new TestRoleAware(4, 'Admins');
                $model = new TestResourceAware(2, 'Post');

                $acl->allow('Guests', 'Post', 'update', function ($parameter) {
                    return $parameter % 2 == 0;
                });
                $acl->allow('Members', 'Post', 'update', function ($parameter) {
                    return $parameter % 2 == 0;
                });
                $acl->allow('Admins', 'Post', 'update');

                expect(@$acl->isAllowed($guest, $model, 'update'))->false();
                expect(@$acl->isAllowed($member, $model, 'update'))->false();
                expect(@$acl->isAllowed($anotherMember, $model, 'update'))->false();
                expect(@$acl->isAllowed($admin, $model, 'update'))->true();
            }
        );
    }

    /**
     * Tests function in Acl Allow Method without arguments
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/12094
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2016-06-05
     */
    public function testAclAllowFunctionNoArgumentsWithWarning()
    {
        $this->specify(
            'The function in allow should be called and isAllowed should return correct values when using function in allow method',
            function () {
                $acl = new Memory;
                $acl->setDefaultAction(Acl::ALLOW);
                $acl->setNoArgumentsDefaultAction(Acl::DENY);
                $acl->addRole('Guests');
                $acl->addRole('Members', 'Guests');
                $acl->addRole('Admins', 'Members');
                $acl->addResource('Post', ['update']);

                $guest = new TestRoleAware(1, 'Guests');
                $member = new TestRoleAware(2, 'Members');
                $anotherMember = new TestRoleAware(3, 'Members');
                $admin = new TestRoleAware(4, 'Admins');
                $model = new TestResourceAware(2, 'Post');

                $acl->allow('Guests', 'Post', 'update', function ($parameter) {
                    return $parameter % 2 == 0;
                });
                $acl->allow('Members', 'Post', 'update', function ($parameter) {
                    return $parameter % 2 == 0;
                });
                $acl->allow('Admins', 'Post', 'update');

                expect($acl->isAllowed($guest, $model, 'update'))->false();
                expect($acl->isAllowed($member, $model, 'update'))->false();
                expect($acl->isAllowed($anotherMember, $model, 'update'))->false();
                expect($acl->isAllowed($admin, $model, 'update'))->true();
            },
            [
                'throws' => [
                    \PHPUnit_Framework_Exception::class,
                    "You didn't provide any parameters when check Guests can update Post. We will use default action when no arguments."
                ]
            ]
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
    public function testWildCardLastRole()
    {
        $this->specify(
            "Cant add acl rule to existing role after adding wildcard rule",
            function () {
                $acl = new Memory();
                $acl->addRole(new Role("Guests"));
                $acl->addResource(new Resource('Post'), ['index', 'update', 'create']);

                $acl->allow('Guests', 'Post', 'create');
                $acl->allow('*', 'Post', 'index');
                $acl->allow('Guests', 'Post', 'update');

                expect($acl->isAllowed('Guests', 'Post', 'create'))->true();
                expect($acl->isAllowed('Guests', 'Post', 'index'))->true();
                expect($acl->isAllowed('Guests', 'Post', 'update'))->true();
            }
        );
    }

    /**
     * Tests adding wildcard rule second time
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/2648
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2016-10-01
     */
    public function testWildCardSecondTime()
    {
        $this->specify(
            "Can't add acl rule to existing wildcard role",
            function () {
                $acl = new Memory();
                $acl->addRole(new Role("Guests"));
                $acl->addResource(new Resource('Post'), ['index', 'update', 'create']);

                $acl->allow('Guests', 'Post', 'create');
                $acl->allow('*', 'Post', 'index');
                $acl->allow('*', 'Post', 'update');

                expect($acl->isAllowed('Guests', 'Post', 'create'))->true();
                expect($acl->isAllowed('Guests', 'Post', 'index'))->true();
                expect($acl->isAllowed('Guests', 'Post', 'update'))->true();
            }
        );
    }

    /**
     * Tests adding wildcard rule second time
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/12573
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-01-25
     */
    public function testDefaultAction()
    {
        $this->specify(
            "Default access doesn't work as expected",
            function () {
                $acl = new Memory();
                $acl->setDefaultAction(Acl::DENY);
                $acl->addResource(new Acl\Resource('Post'), ['index', 'update', 'create']);
                $acl->addRole(new Role('Guests'));

                $acl->allow('Guests', 'Post', 'index');
                expect($acl->isAllowed('Guests', 'Post', 'index'))->true();
                expect($acl->isAllowed('Guests', 'Post', 'update'))->false();
            }
        );
    }

    /**
     * Tests role and resource objects as isAllowed parameters
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-02-15
     */
    public function testRoleResourceObjects()
    {
        $this->specify(
            "Role and Resource objects doesn't work with isAllowed method",
            function () {
                $acl = new Memory();
                $acl->setDefaultAction(Acl::DENY);
                $role = new Role('Guests');
                $resource = new Resource('Post');
                $acl->addRole($role);
                $acl->addResource($resource, ['index', 'update', 'create']);

                $acl->allow('Guests', 'Post', 'index');

                expect($acl->isAllowed($role, $resource, 'index'))->true();
                expect($acl->isAllowed($role, $resource, 'update'))->false();
            }
        );
    }

    /**
     * Tests role and resource objects as isAllowed parameters of the same class
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-02-15
     */
    public function testRoleResourceSameClassObjects()
    {
        $acl = new Memory();
        $acl->setDefaultAction(Acl::DENY);
        $role = new TestRoleResourceAware(1, 'User', 'Admin');
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
        expect($acl->isAllowed($role, $resource, 'update'))->false();
        expect($acl->isAllowed($role, $role, 'update'))->true();
        expect($acl->isAllowed($resource, $resource, 'update'))->true();
    }
}
