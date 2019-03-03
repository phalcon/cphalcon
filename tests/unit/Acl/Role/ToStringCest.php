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

namespace Phalcon\Test\Unit\Acl\Role;

use Phalcon\Acl\Role;
use UnitTester;

/**
 * Class ToStringCest
 */
class ToStringCest
{
    /**
     * Tests Phalcon\Acl\Role :: __toString()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclRoleToString(UnitTester $I)
    {
        $I->wantToTest('Acl\Role - __toString()');
        $role = new Role('Administrator');

        $expected = 'Administrator';
        $actual   = $role->__toString();
        $I->assertEquals($expected, $actual);

        $expected = 'Administrator';
        $actual   = (string) $role;
        $I->assertEquals($expected, $actual);
    }
}
