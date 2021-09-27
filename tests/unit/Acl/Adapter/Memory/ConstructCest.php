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
use Phalcon\Acl\Component;
use Phalcon\Acl\Enum;
use Phalcon\Acl\Role;
use UnitTester;

use function cacheDir;
use function file_get_contents;
use function serialize;
use function unserialize;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Acl\Adapter\Memory
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: __construct() - constants
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryConstructConstants(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - __construct() - constants');

        $I->assertEquals(1, Enum::ALLOW);
        $I->assertEquals(0, Enum::DENY);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryConstruct(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - __construct()');

        $acl = new Memory();

        $I->assertInstanceOf(Memory::class, $acl);
    }

    /**
     * Tests serializing the ACL
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testAclSerialize(UnitTester $I)
    {
        /** @var string $filename */
        $filename = $I->getNewFileName('acl', 'log');

        $acl          = new Memory();
        $aclRole      = new Role('Administrators', 'Super User access');
        $aclComponent = new Component('Customers', 'Customer management');

        $acl->addRole($aclRole);
        $acl->addComponent($aclComponent, ['search', 'destroy']);

        $acl->allow('Administrators', 'Customers', 'search');
        $acl->deny('Administrators', 'Customers', 'destroy');

        $I->writeToFile(cacheDir($filename), serialize($acl));

        $acl      = null;
        $contents = file_get_contents(cacheDir($filename));
        $I->safeDeleteFile(cacheDir($filename));

        $acl = unserialize($contents);

        $I->assertInstanceOf(Memory::class, $acl);
        $actual = $acl->isRole('Administrators');
        $I->assertTrue($actual);
        $actual = $acl->isComponent('Customers');
        $I->assertTrue($actual);
        $actual = $acl->isAllowed('Administrators', 'Customers', 'search');
        $I->assertTrue($actual);
        $actual = $acl->isAllowed('Administrators', 'Customers', 'destroy');
        $I->assertFalse($actual);
    }

    /**
     * Tests negation of inherited Roles
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/65
     *
     * @param UnitTester $I
     *
     * @author  Phalcon Team <team@phalcon.io>
     * @since   2014-10-04
     */
    public function testAclNegationOfInheritedRoles(UnitTester $I)
    {
        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);

        $acl->addRole('Guests');
        $acl->addRole('Members', 'Guests');

        $acl->addComponent('Login', ['help', 'index']);

        $acl->allow('Guests', 'Login', '*');
        $acl->deny('Guests', 'Login', ['help']);
        $acl->deny('Members', 'Login', ['index']);

        $I->assertFalse(
            $acl->isAllowed('Members', 'Login', 'index')
        );

        $I->assertTrue(
            $acl->isAllowed('Guests', 'Login', 'index')
        );

        $I->assertFalse(
            $acl->isAllowed('Guests', 'Login', 'help')
        );
    }

    /**
     * Tests function in Acl Allow Method
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/12004
     *
     * @param UnitTester $I
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2016-07-22
     */
    public function testIssue12004(UnitTester $I)
    {
        $acl = new Memory();

        $acl->setDefaultAction(
            Enum::DENY
        );

        $roleGuest      = new Role('guest');
        $roleUser       = new Role('user');
        $roleAdmin      = new Role('admin');
        $roleSuperAdmin = new Role('superadmin');

        $acl->addRole($roleGuest);
        $acl->addRole($roleUser, $roleGuest);
        $acl->addRole($roleAdmin, $roleUser);
        $acl->addRole($roleSuperAdmin, $roleAdmin);

        $acl->addComponent('payment', ['paypal', 'facebook',]);

        $acl->allow($roleGuest->getName(), 'payment', 'paypal');
        $acl->allow($roleGuest->getName(), 'payment', 'facebook');
        $acl->allow($roleUser->getName(), 'payment', '*');

        $I->assertTrue(
            $acl->isAllowed($roleUser->getName(), 'payment', 'notSet')
        );

        $I->assertTrue(
            $acl->isAllowed($roleUser->getName(), 'payment', '*')
        );

        $I->assertTrue(
            $acl->isAllowed($roleAdmin->getName(), 'payment', 'notSet')
        );

        $I->assertTrue(
            $acl->isAllowed($roleAdmin->getName(), 'payment', '*')
        );
    }

    /**
     * Tests acl with adding new rule for Role after adding wildcard rule
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/2648
     *
     * @param UnitTester $I
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2016-10-01
     */
    public function testWildCardLastRole(UnitTester $I)
    {
        $acl = new Memory();

        $acl->addRole(
            new Role('Guests')
        );

        $acl->addComponent(
            new Component('Post'),
            [
                'index',
                'update',
                'create',
            ]
        );

        $acl->allow('Guests', 'Post', 'create');
        $acl->allow('*', 'Post', 'index');
        $acl->allow('Guests', 'Post', 'update');

        $I->assertTrue(
            $acl->isAllowed('Guests', 'Post', 'create')
        );

        $I->assertTrue(
            $acl->isAllowed('Guests', 'Post', 'index')
        );

        $I->assertTrue(
            $acl->isAllowed('Guests', 'Post', 'update')
        );
    }

    /**
     * Tests adding wildcard rule second time
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/2648
     *
     * @param UnitTester $I
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2016-10-01
     */
    public function testWildCardSecondTime(UnitTester $I)
    {
        $acl = new Memory();

        $acl->addRole(
            new Role('Guests')
        );

        $acl->addComponent(
            new Component('Post'),
            [
                'index',
                'update',
                'create',
            ]
        );

        $acl->allow('Guests', 'Post', 'create');
        $acl->allow('*', 'Post', 'index');
        $acl->allow('*', 'Post', 'update');

        $I->assertTrue(
            $acl->isAllowed('Guests', 'Post', 'create')
        );

        $I->assertTrue(
            $acl->isAllowed('Guests', 'Post', 'index')
        );

        $I->assertTrue(
            $acl->isAllowed('Guests', 'Post', 'update')
        );
    }

    /**
     * Tests negation of multiple inherited Roles
     *
     * @param UnitTester $I
     *
     * @author  cq-z <64899484@qq.com>
     * @since   2018-10-10
     */
    public function testAclNegationOfMultipleInheritedRoles(UnitTester $I)
    {
        $acl = new Memory();

        $acl->setDefaultAction(
            Enum::DENY
        );

        $acl->addRole('Guests');
        $acl->addRole('Guests2');

        $acl->addRole(
            'Members',
            [
                'Guests',
                'Guests2',
            ]
        );

        $acl->addComponent(
            'Login',
            [
                'help',
                'index',
            ]
        );

        $acl->allow('Guests', 'Login', '*');
        $acl->deny('Guests2', 'Login', ['help']);
        $acl->deny('Members', 'Login', ['index']);

        $I->assertFalse(
            $acl->isAllowed('Members', 'Login', 'index')
        );

        $I->assertTrue(
            $acl->isAllowed('Guests', 'Login', 'help')
        );

        $I->assertTrue(
            $acl->isAllowed('Members', 'Login', 'help')
        );
    }

    /**
     * Tests negation of multilayer inherited Roles
     *
     * @param UnitTester $I
     *
     * @author  cq-z <64899484@qq.com>
     * @since   2018-10-10
     */
    public function testAclNegationOfMultilayerInheritedRoles(UnitTester $I)
    {
        $acl = new Memory();

        $acl->setDefaultAction(Enum::DENY);
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

        $I->assertTrue(
            $acl->isAllowed('Members', 'Login', 'index')
        );

        $I->assertFalse(
            $acl->isAllowed('Members', 'Login', 'help')
        );

        $I->assertFalse(
            $acl->isAllowed('Members', 'Logout', 'help')
        );

        $I->assertTrue(
            $acl->isAllowed('Members', 'Login', 'index')
        );
    }
}
