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

use Codeception\Util\Stub;
use Exception;
use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Component;
use Phalcon\Acl\Enum;
use Phalcon\Acl\Exception as AclException;
use Phalcon\Acl\Role;
use Phalcon\Tests\Fixtures\Acl\TestComponentAware;
use Phalcon\Tests\Fixtures\Acl\TestRoleAware;
use Phalcon\Tests\Fixtures\Acl\TestRoleComponentAware;
use stdClass;
use UnitTester;

/**
 * Class IsAllowedCest
 *
 * @package Phalcon\Tests\Unit\Acl\Adapter\Memory
 */
class IsAllowedCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isAllowed() - default
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/12573
     *
     * @param UnitTester $I
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-01-25
     */
    public function aclAdapterMemoryIsAllowedDefault(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isAllowed() - default');

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
        $I->assertTrue($actual);

        $actual = $acl->isAllowed('Guests', 'Post', 'update');
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isAllowed() - objects
     *
     * @param UnitTester $I
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-02-15
     */
    public function aclAdapterMemoryIsAllowedObjects(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isAllowed() - objects');

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
        $I->assertTrue($actual);

        $actual = $acl->isAllowed($role, $component, 'update');
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isAllowed() - same class
     *
     * @param UnitTester $I
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-02-15
     */
    public function aclAdapterMemoryIsAllowedSameClass(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isAllowed() - same class');

        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);

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

        $actual = $acl->isAllowed($role, $component, 'update');
        $I->assertFalse($actual);

        $actual = $acl->isAllowed($role, $role, 'update');
        $I->assertTrue($actual);

        $actual = $acl->isAllowed($component, $component, 'update');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isAllowed() - function no parameters
     *
     * @param UnitTester $I
     *
     * @author  Phalcon Team <team@phalcon.io>
     * @since   2019-06-16
     */
    public function aclAdapterMemoryIsAllowedFunctionNoParameters(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isAllowed() - no parameters');

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
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isAllowed() - function more
     * parameters
     *
     * @param UnitTester $I
     *
     * @author  Phalcon Team <team@phalcon.io>
     * @since   2021-09-27
     */
    public function aclAdapterMemoryIsAllowedFunctionMoreParameters(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isAllowed() - more parameters');

        $errorMessage = "Number of parameters in array is higher than the "
            . "number of parameters in defined function when checking if "
            . "'Members' can 'update' 'Post'. Extra parameters will be ignored. ";

        $code   = 0;
        $actual = '';
        try {
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
        } catch (Exception $ex) {
            $actual = $ex->getMessage();
            $code   = $ex->getCode();
        }

        $I->assertStringContainsString($errorMessage, $actual);
        $I->assertEquals(512, $code);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isAllowed() - function not enough
     * parameters
     *
     * @param UnitTester $I
     *
     * @author  Phalcon Team <team@phalcon.io>
     * @since   2019-06-16
     */
    public function aclAdapterMemoryIsAllowedFunctionNotEnoughParameters(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isAllowed() - not enough parameters');

        $I->expectThrowable(
            new AclException(
                'You did not provide all necessary parameters for the ' .
                'defined function when checking if "Members" can "update" for "Post".'
            ),
            function () use ($I) {
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
        );
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isAllowed() - exception
     *
     * @param UnitTester $I
     *
     * @author  Phalcon Team <team@phalcon.io>
     * @since   2019-06-16
     */
    public function aclAdapterMemoryIsAllowedException(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isAllowed() - exception');

        $I->expectThrowable(
            new AclException(
                'Object passed as roleName must implement ' .
                'Phalcon\Acl\RoleAwareInterface or Phalcon\Acl\RoleInterface'
            ),
            function () {
                $acl = new Memory();
                $acl->setDefaultAction(Enum::DENY);
                $acl->addRole('Member');
                $acl->addComponent('Post', ['update']);
                $acl->allow('Member', 'Post', 'update');
                $acl->isAllowed(new stdClass(), 'Post', 'update');
            }
        );

        $I->expectThrowable(
            new AclException(
                'Object passed as componentName must implement ' .
                'Phalcon\Acl\ComponentAwareInterface or Phalcon\Acl\ComponentInterface'
            ),
            function () {
                $acl = new Memory();
                $acl->setDefaultAction(Enum::DENY);
                $acl->addRole('Member');
                $acl->addComponent('Post', ['update']);
                $acl->allow('Member', 'Post', 'update');
                $acl->isAllowed('Member', new stdClass(), 'update');
            }
        );
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isAllowed() - fireEvent returns false
     *
     * @param UnitTester $I
     *
     * @author  Phalcon Team <team@phalcon.io>
     * @since   2021-09-27
     */
    public function aclAdapterMemoryIsAllowedFireEventFalse(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isAllowed() - fireEvent returns false');

        $acl = Stub::make(
            Memory::class,
            [
                'fireEvent' => false,
            ]
        );

        $acl->addRole('Member');
        $acl->addComponent('Post', ['update']);
        $acl->allow('Member', 'Post', 'update');
        $actual = $acl->isAllowed('Member', 'Post', 'update');

        $I->assertFalse($actual);
    }
}
