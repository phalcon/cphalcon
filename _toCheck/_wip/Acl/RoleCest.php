<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Acl;

use Phalcon\Acl\Role;
use UnitTester;

class RoleCest
{
    /**
     * Tests the creation of an Acl Role (name)
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-03
     */
    public function testAclRoleNameEmptyDescription(UnitTester $I)
    {
        $aclRole  = new Role('Administrators');
        $expected = 'Administrators';
        $actual   = $aclRole->getName();
        $I->assertEquals($expected, $actual);

        $actual = $aclRole->getDescription();
        $I->assertEmpty($actual);
    }

    /**
     * Tests the creation of an Acl Role (name/description)
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-03
     */
    public function testAclRoleNameDescription(UnitTester $I)
    {
        $aclRole = new Role('Administrators', 'Super-User role');

        $expected = 'Administrators';
        $actual   = $aclRole->getName();
        $I->assertEquals($expected, $actual);

        $actual   = $aclRole->getDescription();
        $expected = 'Super-User role';
        $I->assertEquals($expected, $actual);
    }
}
