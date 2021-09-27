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
use Phalcon\Acl\Exception;
use Phalcon\Acl\Role;
use UnitTester;

/**
 * Class AddInheritCest
 *
 * @package Phalcon\Tests\Unit\Acl\Adapter\Memory
 */
class AddInheritCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addInherit()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddInherit(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addInherit()');

        $acl = new Memory();

        $acl->addRole(new Role('administrator'));
        $acl->addRole(new Role('apprentice'));

        $addedInherit = $acl->addInherit('administrator', 'apprentice');

        $I->assertTrue($addedInherit);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addInherit()
     *
     * @param UnitTester $I
     *
     * @author <jenovateurs>
     * @since  2019-12-05
     */
    public function aclAdapterMemoryAddInheritIsAllow(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addInherit() - check access');

        $acl = new Memory();

        //New role
        $acl->addRole(new Role('administrator'));
        $acl->addRole(new Role('apprentice'));

        //New Component
        $acl->addComponent(new Component('folder'), 'list');
        $acl->addComponent(new Component('folder'), 'add');

        //Add Inherit
        $actual = $acl->addInherit('administrator', 'apprentice');
        $I->assertTrue($actual);

        // Add Inherit twice to ensure that we have no duplicates
        $actual = $acl->addInherit('administrator', 'apprentice');
        $I->assertTrue($actual);

        //Allow access
        $acl->allow('apprentice', 'folder', 'list');
        $acl->allow('administrator', 'folder', 'add');

        //Check access
        $actual = $acl->isAllowed('apprentice', 'folder', 'list');
        $I->assertTrue($actual);

        $actual = $acl->isAllowed('administrator', 'folder', 'add');
        $I->assertTrue($actual);

        $actual = $acl->isAllowed('apprentice', 'folder', 'add');
        $I->assertFalse($actual);

        $actual = $acl->isAllowed('administrator', 'folder', 'list');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addInherit() - same name
     *
     * @param UnitTester $I
     *
     * @author  Phalcon Team <team@phalcon.io>
     * @since   2021-09-27
     */
    public function aclAdapterMemoryAddInheritSameName(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addInherit() - same name');

        $acl = new Memory();

        // New role
        $acl->addRole(new Role('administrator'));
        $acl->addRole(new Role('apprentice'));

        // New Component
        $acl->addComponent(new Component('folder'), 'list');
        $acl->addComponent(new Component('folder'), 'add');

        // Add Inherit
        $actual = $acl->addInherit('administrator', 'administrator');
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addInherit() - unknown role exception
     *
     * @param UnitTester $I
     *
     * @author  Phalcon Team <team@phalcon.io>
     * @since   2021-09-27
     */
    public function aclAdapterMemoryAddInheritUnknownRole(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addInherit() - unknown role exception');

        $I->expectThrowable(
            new Exception(
                "Role 'unknown' (to inherit) does not exist in the role list"
            ),
            function () {
                $acl = new Memory();

                // New role
                $acl->addRole(new Role('administrator'));

                //Add Inherit
                $actual = $acl->addInherit('administrator', 'unknown');
            }
        );
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addInherit() - infinite loop exception
     *
     * @param UnitTester $I
     *
     * @author  Phalcon Team <team@phalcon.io>
     * @since   2021-09-27
     */
    public function aclAdapterMemoryAddInheritInfiniteLoopException(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addInherit() - infinite loop exception');

        $I->expectThrowable(
            new Exception(
                "Role 'administrator' (to inherit) produces an infinite loop"
            ),
            function () {
                $acl = new Memory();

                $acl->addRole(new Role('administrator'));
                $acl->addRole(new Role('member'));
                $acl->addRole(new Role('guest'));

                $acl->addInherit('administrator', 'member');
                // Twice to ensure it gets ignored
                $acl->addInherit('administrator', 'member');
                $acl->addInherit('member', 'guest');
                $acl->addInherit('guest', 'administrator');
            }
        );
    }
}
