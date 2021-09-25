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

namespace Phalcon\Tests\Unit\Acl\Role;

use Phalcon\Acl\Role;
use UnitTester;

class GetDescriptionCest
{
    /**
     * Tests Phalcon\Acl\Role :: getDescription()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclRoleGetDescription(UnitTester $I)
    {
        $I->wantToTest('Acl\Role - getDescription()');

        $role = new Role('Administrators', 'The admin unit');

        $I->assertEquals(
            'The admin unit',
            $role->getDescription()
        );
    }

    /**
     * Tests Phalcon\Acl\Role :: getDescription() - empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclRoleGetDescriptionEmpty(UnitTester $I)
    {
        $I->wantToTest('Acl\Role - getDescription()');

        $role = new Role('Administrators');

        $I->assertEmpty(
            $role->getDescription()
        );
    }
}
