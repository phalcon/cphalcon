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

use Phalcon\Acl;
use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Component;
use Phalcon\Acl\Role;
use Phalcon\Test\Fixtures\Acl\TestRoleComponentAware;
use UnitTester;

class IsAllowedCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isAllowed() - default
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/12573
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-01-25
     */
    public function aclAdapterMemoryIsAllowedDefault(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isAllowed() - default');

        $acl = new Memory();

        $acl->setDefaultAction(
            Acl::DENY
        );

        $acl->addComponent(
            new Component('Post'),
            [
                'index',
                'update',
                'create',
            ]
        );

        $acl->addRole(
            new Role('Guests')
        );

        $acl->allow('Guests', 'Post', 'index');

        $I->assertTrue(
            $acl->isAllowed('Guests', 'Post', 'index')
        );

        $I->assertFalse(
            $acl->isAllowed('Guests', 'Post', 'update')
        );
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isAllowed() - objects
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-02-15
     */
    public function aclAdapterMemoryIsAllowedObjects(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isAllowed() - objects');

        $acl = new Memory();

        $acl->setDefaultAction(
            Acl::DENY
        );

        $role = new Role('Guests');

        $component = new Component('Post');

        $acl->addRole($role);

        $acl->addComponent(
            $component,
            [
                'index',
                'update',
                'create',
            ]
        );

        $acl->allow('Guests', 'Post', 'index');

        $I->assertTrue(
            $acl->isAllowed($role, $component, 'index')
        );

        $I->assertFalse(
            $acl->isAllowed($role, $component, 'update')
        );
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isAllowed() - same class
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-02-15
     */
    public function aclAdapterMemoryIsAllowedSameClass(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isAllowed() - same class');

        $acl = new Memory();

        $acl->setDefaultAction(
            Acl::DENY
        );

        $role      = new TestRoleComponentAware(1, 'User', 'Admin');
        $component = new TestRoleComponentAware(2, 'User', 'Admin');

        $acl->addRole('Admin');

        $acl->addComponent(
            'User',
            ['update']
        );

        $acl->allow(
            'Admin',
            'User',
            ['update'],
            function (TestRoleComponentAware $admin, TestRoleComponentAware $user) {
                return $admin->getUser() == $user->getUser();
            }
        );

        $I->assertFalse(
            $acl->isAllowed($role, $component, 'update')
        );

        $I->assertTrue(
            $acl->isAllowed($role, $role, 'update')
        );

        $I->assertTrue(
            $acl->isAllowed($component, $component, 'update')
        );
    }
}
