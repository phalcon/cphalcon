<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Acl\Role;

use Phalcon\Acl\Role;
use UnitTester;

class GetNameCest
{
    /**
     * Tests Phalcon\Acl\Role :: getName()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testGetName(UnitTester $I)
    {
        $role = new Role('Administrators');

        $expected = 'Administrators';
        $actual   = $role->getName();
        $I->assertEquals($expected, $actual);
    }
}
