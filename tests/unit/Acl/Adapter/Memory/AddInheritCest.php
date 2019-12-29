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

namespace Phalcon\Test\Unit\Acl\Adapter\Memory;

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Component;
use Phalcon\Acl\Role;
use UnitTester;

class AddInheritCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addInherit()
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
        $addedInherit = $acl->addInherit('administrator', 'apprentice');

        //Allow access
        $acl->allow(
            'apprentice',
            'folder',
            'list'
        );

        $acl->allow(
            'administrator',
            'folder',
            'add'
        );

        //Check access
        $apprenticeAccess = $acl->isAllowed(
            'apprentice',
            'folder',
            'list'
        );
        $I->assertTrue($apprenticeAccess);

        $administratorAccess = $acl->isAllowed(
            'administrator',
            'folder',
            'add'
        );

        $I->assertTrue($administratorAccess);

        $apprenticeNoAccess = $acl->isAllowed(
            'apprentice',
            'folder',
            'add'
        );

        $I->assertFalse($apprenticeNoAccess);

        $administratorAccessInherit = $acl->isAllowed(
            'administrator',
            'folder',
            'list'
        );

        $I->assertTrue($administratorAccessInherit);
    }
}
