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

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Role;
use UnitTester;

/**
 * Class IsRoleCest
 */
class IsRoleCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isRole()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryIsRole(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isRole()');
        $acl          = new Memory();
        $aclRole = new Role('Administrators', 'Super User access');

        $acl->addRole($aclRole);

        $actual = $acl->isRole('Administrators');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isRole() - unknown
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryIsRoleUnknown(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isRole() - unknown');
        $acl          = new Memory();
        $aclRole = new Role('Administrators', 'Super User access');

        $acl->addRole($aclRole);

        $actual = $acl->isRole('unknown');
        $I->assertFalse($actual);
    }
}
