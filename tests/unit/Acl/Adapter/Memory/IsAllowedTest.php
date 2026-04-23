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

use ArrayObject;
use Exception;
use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Component;
use Phalcon\Acl\Enum;
use Phalcon\Acl\Exception as AclException;
use Phalcon\Acl\Role;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Acl\Fake\Adapter\FakeMemory;
use Phalcon\Tests\Unit\Acl\Fake\TestComponentAware;
use Phalcon\Tests\Unit\Acl\Fake\TestRoleAware;
use Phalcon\Tests\Unit\Acl\Fake\TestRoleComponentAware;
use stdClass;

use function restore_error_handler;
use function set_error_handler;

final class IsAllowedTest extends AbstractUnitTestCase
{
    /**
     * @author  Phalcon Team <team@phalcon.io>
     * @since   2021-09-27
     */
    public function tearDown(): void
    {
        restore_error_handler();
    }

    /**
     * @issue   https://github.com/phalcon/cphalcon/issues/12573
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-01-25
     */
    public function testAclAdapterMemoryIsAllowedDefault(): void
    {
        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);

        $acl->addComponent(
            new Component('Post'),
            [
                'index',
                'update',
                'create',
            ]
        );
        $acl->addRole(new Role('Guests'));
        $acl->allow('Guests', 'Post', 'index');

        $actual = $acl->isAllowed('Guests', 'Post', 'index');
        $this->assertTrue($actual);

        $actual = $acl->isAllowed('Guests', 'Post', 'update');
        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAclAdapterMemoryIsAllowedDiamondInheritanceContinue(): void
    {
        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);

        $acl->addRole(new Role('A'));
        $acl->addRole(new Role('B'));
        $acl->addRole(new Role('C'));
        $acl->addRole(new Role('D'));
        $acl->addRole(new Role('X'));

        $acl->addComponent(new Component('Post'), ['update']);

        // X inherits B and C; B and C both inherit D (diamond)
        $acl->addInherit('X', 'B');
        $acl->addInherit('X', 'C');
        $acl->addInherit('B', 'D');
        $acl->addInherit('C', 'D');
        $acl->addInherit('A', 'X');

        // Traversal: A→X→B,C→D (from B), D (from C — second occurrence hits continue L971)
        $actual = $acl->isAllowed('A', 'Post', 'update');
        $this->assertFalse($actual);
    }

    /**
     * @author  Phalcon Team <team@phalcon.io>
     * @since   2022-12-09
     */
    public function testAclAdapterMemoryIsAllowedDocumentationExample(): void
    {
        $acl = new Memory();

        $acl->addRole('manager');
        $acl->addRole('accounting');
        $acl->addRole('guest');

        $acl->addComponent(
            'admin',
            ['dashboard', 'users', 'view']
        );
        $acl->addComponent(
            'reports',
            ['list', 'add', 'view']
        );
        $acl->addComponent(
            'session',
            ['login', 'logout']
        );

        $acl->allow('manager', 'admin', 'dashboard');
        $acl->allow('manager', 'reports', ['list', 'add']);
        $acl->allow('accounting', 'reports', '*');
        $acl->allow('*', 'session', '*');

        // true - defined explicitly
        $actual = $acl->isAllowed('manager', 'admin', 'dashboard');
        $this->assertTrue($actual);

        // true - defined with wildcard
        $actual = $acl->isAllowed('manager', 'session', 'login');
        $this->assertTrue($actual);

        // true - defined with wildcard
        $actual = $acl->isAllowed('accounting', 'reports', 'view');
        $this->assertTrue($actual);

        // false - defined explicitly
        $actual = $acl->isAllowed('guest', 'reports', 'view');
        $this->assertFalse($actual);

        // false - default access level
        $actual = $acl->isAllowed('guest', 'reports', 'add');
        $this->assertFalse($actual);
    }

    /**
     * @author  Phalcon Team <team@phalcon.io>
     * @since   2019-06-16
     */
    public function testAclAdapterMemoryIsAllowedExceptionComponent(): void
    {
        $this->expectException(AclException::class);
        $this->expectExceptionMessage(
            'Object passed as componentName must implement ' .
            'Phalcon\Acl\ComponentAwareInterface or Phalcon\Acl\ComponentInterface'
        );

        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);
        $acl->addRole('Member');
        $acl->addComponent('Post', ['update']);
        $acl->allow('Member', 'Post', 'update');
        $acl->isAllowed('Member', new stdClass(), 'update');
    }

    /**
     * @author  Phalcon Team <team@phalcon.io>
     * @since   2019-06-16
     */
    public function testAclAdapterMemoryIsAllowedExceptionRole(): void
    {
        $this->expectException(AclException::class);
        $this->expectExceptionMessage(
            'Object passed as roleName must implement ' .
            'Phalcon\Acl\RoleAwareInterface or Phalcon\Acl\RoleInterface'
        );

        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);
        $acl->addRole('Member');
        $acl->addComponent('Post', ['update']);
        $acl->allow('Member', 'Post', 'update');
        $acl->isAllowed(new stdClass(), 'Post', 'update');
    }

    /**
     * @author  Phalcon Team <team@phalcon.io>
     * @since   2021-09-27
     */
    public function testAclAdapterMemoryIsAllowedFireEventFalse(): void
    {
        $acl = new FakeMemory();

        $acl->addRole('Member');
        $acl->addComponent('Post', ['update']);
        $acl->allow('Member', 'Post', 'update');
        $actual = $acl->isAllowed('Member', 'Post', 'update');

        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-14
     */
    public function testAclAdapterMemoryIsAllowedFunctionMoreParameters(): void
    {
        set_error_handler(
            function ($errno, $errstr) {
                throw new Exception($errstr);
            }
        );

        $errorMessage = "Number of parameters in array is higher than the "
            . "number of parameters in defined function when checking if "
            . "'Members' can 'update' 'Post'. Extra parameters will be ignored.";
        $this->expectException(Exception::class);
        $this->expectExceptionMessage($errorMessage);

        $acl = new Memory();
        $acl->setDefaultAction(Enum::ALLOW);
        $acl->setNoArgumentsDefaultAction(Enum::DENY);

        $acl->addRole('Members');
        $acl->addComponent('Post', ['update']);

        $member = new TestRoleAware(2, 'Members');
        $model  = new TestComponentAware(2, 'Post');

        $acl->allow(
            'Members',
            'Post',
            'update',
            function ($parameter) {
                return $parameter % 2 == 0;
            }
        );

        $acl->isAllowed(
            $member,
            $model,
            'update',
            [
                'parameter' => 1,
                'one'       => 2,
            ]
        );
    }

    /**
     * @author  Phalcon Team <team@phalcon.io>
     * @since   2019-06-16
     */
    public function testAclAdapterMemoryIsAllowedFunctionNoParameters(): void
    {
        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);

        $acl->addRole('Admin');
        $acl->addComponent('User', ['update']);
        $acl->allow(
            'Admin',
            'User',
            ['update'],
            function () {
                return true;
            }
        );

        $actual = $acl->isAllowed('Admin', 'User', 'update');
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAclAdapterMemoryIsAllowedFunctionNoParamsRequired(): void
    {
        $acl = new Memory();
        $acl->setDefaultAction(Enum::ALLOW);
        $acl->setNoArgumentsDefaultAction(Enum::DENY);

        $acl->addRole('Admin');
        $acl->addComponent('Post', ['update']);
        $acl->allow(
            'Admin',
            'Post',
            'update',
            function ($param) {
                return true;
            }
        );

        // No parameters provided; function has 1 required param
        // trigger_error is called, then returns noArgumentsDefaultAction (DENY)
        $actual = @$acl->isAllowed('Admin', 'Post', 'update');
        $this->assertFalse($actual);
    }

    /**
     * @author  Phalcon Team <team@phalcon.io>
     * @since   2019-06-16
     */
    public function testAclAdapterMemoryIsAllowedFunctionNotEnoughParameters(): void
    {
        $this->expectException(AclException::class);
        $this->expectExceptionMessage(
            "You did not provide all necessary parameters for the " .
            "defined function when checking if 'Members' can 'update' for 'Post'."
        );

        $acl = new Memory();

        $acl->setDefaultAction(Enum::ALLOW);
        $acl->setNoArgumentsDefaultAction(Enum::DENY);

        $acl->addRole('Members');
        $acl->addComponent('Post', ['update']);

        $member = new TestRoleAware(2, 'Members');
        $model  = new TestComponentAware(2, 'Post');

        $acl->allow(
            'Members',
            'Post',
            'update',
            function ($parameter, $value) {
                return $parameter % $value == 0;
            }
        );

        $acl->isAllowed(
            $member,
            $model,
            'update',
            [
                'parameter' => 1,
                'one'       => 2,
            ]
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAclAdapterMemoryIsAllowedFunctionOptionalParamNoArgs(): void
    {
        $acl = new Memory();
        $acl->setDefaultAction(Enum::ALLOW);

        $acl->addRole('Admin');
        $acl->addComponent('Post', ['update']);
        $acl->allow(
            'Admin',
            'Post',
            'update',
            function ($param = null) {
                return true;
            }
        );

        // No parameters provided; function has 0 required params → call_user_func($funcAccess)
        $actual = $acl->isAllowed('Admin', 'Post', 'update');
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAclAdapterMemoryIsAllowedFunctionWrongClassException(): void
    {
        $this->expectException(AclException::class);
        $this->expectExceptionMessage(
            'Your passed parameter does not have the same class as the parameter ' .
            'in defined function when checking if Admin can update Post. ' .
            'Class passed: ArrayObject , Class in defined function: stdClass.'
        );

        $acl = new Memory();
        $acl->setDefaultAction(Enum::ALLOW);

        $acl->addRole('Admin');
        $acl->addComponent('Post', ['update']);
        $acl->allow(
            'Admin',
            'Post',
            'update',
            function (stdClass $param) {
                return true;
            }
        );

        $acl->isAllowed('Admin', 'Post', 'update', ['param' => new ArrayObject()]);
    }

    /**
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-02-15
     */
    public function testAclAdapterMemoryIsAllowedObjects(): void
    {
        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);

        $role      = new Role('Guests');
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

        $actual = $acl->isAllowed($role, $component, 'index');
        $this->assertTrue($actual);

        $actual = $acl->isAllowed($role, $component, 'update');
        $this->assertFalse($actual);
    }

    /**
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-02-15
     */
    public function testAclAdapterMemoryIsAllowedSameClass(): void
    {
        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);

        $role      = new TestRoleComponentAware(1, 'User', 'Admin');
        $component = new TestRoleComponentAware(2, 'User', 'Admin');

        $acl->addRole('Admin');
        $acl->addComponent('User', ['update']);
        $acl->allow(
            'Admin',
            'User',
            ['update'],
            function (
                TestRoleComponentAware $admin,
                TestRoleComponentAware $user
            ) {
                return $admin->getUser() == $user->getUser();
            }
        );

        $actual = $acl->isAllowed($role, $component, 'update');
        $this->assertFalse($actual);

        $actual = $acl->isAllowed($role, $role, 'update');
        $this->assertTrue($actual);

        $actual = $acl->isAllowed($component, $component, 'update');
        $this->assertTrue($actual);
    }
}
