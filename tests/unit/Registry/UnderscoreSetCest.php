<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Registry;

use Phalcon\Registry;
use UnitTester;

class UnderscoreSetCest
{
    /**
     * Tests Phalcon\Registry :: __set()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testUnderscoreSet(UnitTester $I)
    {
        $registry = new Registry();
        $registry->one  = 1;
        $registry->two  = 2;
        $registry['three']= 3;

        $I->assertCount(3, $registry);
    }
}
