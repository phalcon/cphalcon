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

use UnitTester;

/**
 * Class GetRolesCest
 */
class GetRolesCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getRoles()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function aclAdapterMemoryGetRoles(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getRoles()');
        $I->skipTest('Need implementation');
    }
}
