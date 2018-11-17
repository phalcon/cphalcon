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

class GetDescriptionCest
{
    /**
     * Tests Phalcon\Acl\Role :: getDescription()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testGetDescription(UnitTester $I)
    {
        $role = new Role('Administrators', 'The admin unit');

        $expected = 'The admin unit';
        $actual   = $role->getDescription();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Acl\Role :: getDescription() - empty
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testGetDescriptionEmpty(UnitTester $I)
    {
        $role = new Role('Administrators');

        $actual = $role->getDescription();
        $I->assertEmpty($actual);
    }
}
