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

class AllowCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: allow()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAllow(UnitTester $I)
    {
        $I->wantToTest("Acl\Adapter\Memory - allow()");
        $I->skipTest("Need implementation");
    }
}
