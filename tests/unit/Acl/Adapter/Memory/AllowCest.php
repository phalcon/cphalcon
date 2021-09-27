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

use Exception;
use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Component;
use Phalcon\Acl\Enum;
use Phalcon\Acl\Exception as AclException;
use Phalcon\Acl\Role;
use Phalcon\Tests\Fixtures\Acl\TestComponentAware;
use Phalcon\Tests\Fixtures\Acl\TestRoleAware;
use UnitTester;

/**
 * Class AllowCest
 *
 * @package Phalcon\Tests\Unit\Acl\Adapter\Memory
 */
class AllowCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: allow()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAllow(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - allow()');

        $acl = new Memory();

        $acl->setDefaultAction(Enum::DENY);
        $acl->addRole('Guests');
        $acl->addRole('Member');

        $acl->addComponent('Post', ['update']);
        $acl->allow('Member', 'Post', 'update');

        $actual = $acl->isAllowed('Guest', 'Post', 'update');
        $I->assertFalse($actual);

        $actual = $acl->isAllowed('Guest', 'Post', 'update');
        $I->assertFalse($actual);

        $actual = $acl->isAllowed('Member', 'Post', 'update');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: allow() - wildcard
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-16
     */
    public function aclAdapterMemoryAllowWildcard(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - allow() - wildcard');

        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);
        $acl->addRole('Member');
        $acl->addComponent('Post', ['update']);

        $acl->allow('Member', 'Post', '*');

        $actual = $acl->isAllowed('Member', 'Post', 'update');
        $I->assertTrue($actual);

        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);
        $acl->addRole('Member');
        $acl->addComponent('Post', ['update']);

        $acl->allow('Member', '*', '*');
        $actual = $acl->isAllowed('Member', 'Post', 'update');
        $I->assertTrue($actual);

        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);
        $acl->addRole('Member');
        $acl->addRole('Guest');
        $acl->addInherit('Guest', 'Member');
        $acl->addComponent('Post', ['update']);

        $acl->allow('Member', '*', '*');
        $actual = $acl->isAllowed('Guest', 'Post', 'update');
        $I->assertTrue($actual);

        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);

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
        $acl->allow('*', 'welcome', 'index');

        foreach ($aclRoles as $Role => $object) {
            $actual = $acl->isAllowed($Role, 'welcome', 'index');
            $I->assertTrue($actual);
        }

        $acl->deny('*', 'welcome', 'index');
        foreach ($aclRoles as $Role => $object) {
            $actual = $acl->isAllowed($Role, 'welcome', 'index');
            $I->assertFalse($actual);
        }
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: allow() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-16
     */
    public function aclAdapterMemoryAllowException(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - allow() - exception');

        $I->expectThrowable(
            new AclException(
                "Role 'Unknown' does not exist in the ACL"
            ),
            function () {
                $acl = new Memory();
                $acl->setDefaultAction(Enum::DENY);
                $acl->addRole('Member');
                $acl->addComponent('Post', ['update']);
                $acl->allow('Unknown', 'Post', 'update');
            }
        );

        $I->expectThrowable(
            new AclException(
                "Component 'Unknown' does not exist in the ACL"
            ),
            function () {
                $acl = new Memory();
                $acl->setDefaultAction(Enum::DENY);
                $acl->addRole('Member');
                $acl->addComponent('Post', ['update']);
                $acl->allow('Member', 'Unknown', 'update');
            }
        );

        $I->expectThrowable(
            new AclException(
                "Access 'Unknown' does not exist in component 'Post'"
            ),
            function () {
                $acl = new Memory();
                $acl->setDefaultAction(Enum::DENY);
                $acl->addRole('Member');
                $acl->addComponent('Post', ['update']);
                $acl->allow('Member', 'Post', 'Unknown');
            }
        );

        $I->expectThrowable(
            new AclException(
                "Access 'Unknown' does not exist in component 'Post'"
            ),
            function () {
                $acl = new Memory();
                $acl->setDefaultAction(Enum::DENY);
                $acl->addRole('Member');
                $acl->addComponent('Post', ['update']);
                $acl->allow('Member', 'Post', ['Unknown']);
            }
        );
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: allow() - function
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/11235
     *
     * @param UnitTester $I
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2015-12-16
     */
    public function aclAdapterMemoryAllowFunction(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - allow() - function');

        $acl = new Memory();

        $acl->setDefaultAction(Enum::DENY);

        $acl->addRole('Guests');
        $acl->addRole('Members', 'Guests');
        $acl->addRole('Admins', 'Members');

        $acl->addComponent(
            'Post',
            ['update']
        );

        $guest         = new TestRoleAware(1, 'Guests');
        $member        = new TestRoleAware(2, 'Members');
        $anotherMember = new TestRoleAware(3, 'Members');
        $admin         = new TestRoleAware(4, 'Admins');
        $model         = new TestComponentAware(2, 'Post');

        $acl->deny('Guests', 'Post', 'update');

        $acl->allow(
            'Members',
            'Post',
            'update',
            function (TestRoleAware $user, TestComponentAware $model) {
                return $user->getId() == $model->getUser();
            }
        );

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
     * Tests Phalcon\Acl\Adapter\Memory :: allow() - function exception
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/11235
     *
     * @param UnitTester $I
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2016-06-05
     */
    public function aclAdapterMemoryAllowFunctionException(UnitTester $I)
    {
        $errorMessage = "You did not provide any parameters when 'Guests' can "
            . "'update' 'Post'. We will use default action when no arguments.";

        $code   = 0;
        $actual = '';
        try {
            $acl = new Memory();
            $acl->setDefaultAction(Enum::ALLOW);
            $acl->setNoArgumentsDefaultAction(Enum::DENY);

            $acl->addRole('Guests');
            $acl->addRole('Members', 'Guests');
            $acl->addRole('Admins', 'Members');
            $acl->addComponent('Post', ['update']);

            $guest         = new TestRoleAware(1, 'Guests');
            $member        = new TestRoleAware(2, 'Members');
            $anotherMember = new TestRoleAware(3, 'Members');
            $admin         = new TestRoleAware(4, 'Admins');
            $model         = new TestComponentAware(2, 'Post');

            $acl->allow(
                'Guests',
                'Post',
                'update',
                function ($parameter) {
                    return $parameter % 2 == 0;
                }
            );

            $acl->allow(
                'Members',
                'Post',
                'update',
                function ($parameter) {
                    return $parameter % 2 == 0;
                }
            );

            $acl->allow('Admins', 'Post', 'update');

            $I->assertFalse(
                $acl->isAllowed($guest, $model, 'update')
            );

            $I->assertFalse(
                $acl->isAllowed($member, $model, 'update')
            );

            $I->assertFalse(
                $acl->isAllowed($anotherMember, $model, 'update')
            );

            $I->assertTrue(
                $acl->isAllowed($admin, $model, 'update')
            );
        } catch (Exception $ex) {
            $actual = $ex->getMessage();
            $code   = $ex->getCode();
        }

        $I->assertStringContainsString($errorMessage, $actual);
        $I->assertEquals(1024, $code);
    }
}
