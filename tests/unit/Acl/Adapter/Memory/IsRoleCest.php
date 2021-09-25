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
use Phalcon\Acl\Role;
use UnitTester;

class IsRoleCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isRole()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryIsRole(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isRole()');

        $acl     = new Memory();
        $aclRole = new Role('Administrators', 'Super User access');

        $acl->addRole($aclRole);

        $I->assertTrue(
            $acl->isRole('Administrators')
        );
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isRole() - unknown
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryIsRoleUnknown(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isRole() - unknown');

        $acl     = new Memory();
        $aclRole = new Role('Administrators', 'Super User access');

        $acl->addRole($aclRole);

        $I->assertFalse(
            $acl->isRole('unknown')
        );
    }
}
