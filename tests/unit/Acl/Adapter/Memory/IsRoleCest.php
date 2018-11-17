<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Acl\Adapter\Memory;

use Phalcon\Acl;
use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Role;
use UnitTester;

class IsRoleCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isRole()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testIsRole(UnitTester $I)
    {
        $acl     = new Memory();
        $aclRole = new Role('Administrators', 'Super User access');

        $acl->addRole($aclRole);

        $actual = $acl->isRole('Administrators');
        $I->assertTrue($actual);
    }
}
