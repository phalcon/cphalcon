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
 * Class AddRoleCest
 *
 * @package Phalcon\Test\Unit\Acl\Adapter\Memory
 */
class AddRoleCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addRole()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddRole(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addRole()');
        $I->skipTest('Need implementation');
    }
}
