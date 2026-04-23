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
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Acl\Fake\TestComponentAware;
use Phalcon\Tests\Unit\Acl\Fake\TestRoleAware;

use function restore_error_handler;
use function set_error_handler;

final class AllowTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAclAdapterMemoryAllow(): void
    {
        $acl = new Memory();

        $acl->setDefaultAction(Enum::DENY);
        $acl->addRole('Guests');
        $acl->addRole('Member');

        $acl->addComponent('Post', ['update']);
        $acl->allow('Member', 'Post', 'update');

        $actual = $acl->isAllowed('Guest', 'Post', 'update');
        $this->assertFalse($actual);

        $actual = $acl->isAllowed('Member', 'Post', 'update');
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-16
     */
    public function testAclAdapterMemoryAllowExceptionAccessUnknown(): void
    {
        $this->expectException(AclException::class);
        $this->expectExceptionMessage(
            "Access 'Unknown' does not exist in component 'Post'"
        );

        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);
        $acl->addRole('Member');
        $acl->addComponent('Post', ['update']);
        $acl->allow('Member', 'Post', 'Unknown');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-16
     */
    public function testAclAdapterMemoryAllowExceptionAccessUnknownArray(): void
    {
        $this->expectException(AclException::class);
        $this->expectExceptionMessage(
            "Access 'Unknown' does not exist in component 'Post'"
        );

        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);
        $acl->addRole('Member');
        $acl->addComponent('Post', ['update']);
        $acl->allow('Member', 'Post', ['Unknown']);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-16
     */
    public function testAclAdapterMemoryAllowExceptionComponentUnknown(): void
    {
        $this->expectException(AclException::class);
        $this->expectExceptionMessage(
            "Component 'Unknown' does not exist in the ACL"
        );

        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);
        $acl->addRole('Member');
        $acl->addComponent('Post', ['update']);
        $acl->allow('Member', 'Unknown', 'update');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-16
     */
    public function testAclAdapterMemoryAllowExceptionRoleUnknown(): void
    {
        $this->expectException(AclException::class);
        $this->expectExceptionMessage(
            "Role 'Unknown' does not exist in the ACL"
        );

        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);
        $acl->addRole('Member');
        $acl->addComponent('Post', ['update']);
        $acl->allow('Unknown', 'Post', 'update');
    }

    /**
     * @issue   https://github.com/phalcon/cphalcon/issues/11235
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2015-12-16
     */
    public function testAclAdapterMemoryAllowFunction(): void
    {
        $acl = new Memory();

        $acl->setDefaultAction(Enum::DENY);

        $acl->addRole('Guests');
        $acl->addRole('Members', 'Guests');
        $acl->addRole('Admins', 'Members');

        $acl->addComponent('Post', ['update']);

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
        $this->assertFalse($actual);

        $actual = $acl->isAllowed($member, $model, 'update');
        $this->assertTrue($actual);

        $actual = $acl->isAllowed($anotherMember, $model, 'update');
        $this->assertFalse($actual);

        $actual = $acl->isAllowed($admin, $model, 'update');
        $this->assertTrue($actual);
    }

    /**
     * @issue   https://github.com/phalcon/cphalcon/issues/11235
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2016-06-05
     */
    public function testAclAdapterMemoryAllowFunctionException(): void
    {
        set_error_handler(
            function ($errno, $errstr) {
                throw new Exception($errstr);
            }
        );

        $errorMessage = "You did not provide any parameters when 'Guests' can "
            . "'update' 'Post'. We will use default action when no arguments.";
        $this->expectException(Exception::class);
        $this->expectExceptionMessage($errorMessage);

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

        $actual = $acl->isAllowed($guest, $model, 'update');
        $this->assertFalse($actual);

        $actual = $acl->isAllowed($member, $model, 'update');
        $this->assertFalse($actual);

        $actual = $acl->isAllowed($anotherMember, $model, 'update');
        $this->assertFalse($actual);

        $actual = $acl->isAllowed($admin, $model, 'update');
        $this->assertTrue($actual);

        restore_error_handler();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-16
     */
    public function testAclAdapterMemoryAllowWildcardAction(): void
    {
        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);
        $acl->addRole('Member');
        $acl->addComponent('Post', ['update']);

        $acl->allow('Member', 'Post', '*');

        $actual = $acl->isAllowed('Member', 'Post', 'update');
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-16
     */
    public function testAclAdapterMemoryAllowWildcardComponent(): void
    {
        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);
        $acl->addRole('Member');
        $acl->addComponent('Post', ['update']);

        $acl->allow('Member', '*', '*');

        $actual = $acl->isAllowed('Member', 'Post', 'update');
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-16
     */
    public function testAclAdapterMemoryAllowWildcardComponentInherited(): void
    {
        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);
        $acl->addRole('Member');
        $acl->addRole('Guest');
        $acl->addInherit('Guest', 'Member');
        $acl->addComponent('Post', ['update']);

        $acl->allow('Member', '*', '*');

        $actual = $acl->isAllowed('Guest', 'Post', 'update');
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-16
     */
    public function testAclAdapterMemoryAllowWildcardRole(): void
    {
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
            $this->assertTrue($actual);
        }

        $acl->deny('*', 'welcome', 'index');

        foreach ($aclRoles as $Role => $object) {
            $actual = $acl->isAllowed($Role, 'welcome', 'index');
            $this->assertFalse($actual);
        }
    }
}
