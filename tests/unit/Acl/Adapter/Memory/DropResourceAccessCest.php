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

use UnitTester;

class DropResourceAccessCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: dropResourceAccess()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryDropResourceAccess(UnitTester $I)
    {
        $I->wantToTest("Acl\Adapter\Memory - dropResourceAccess()");
        $I->skipTest("Need implementation");
    }
}
