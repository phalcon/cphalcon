<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Debug\Dump;

use UnitTester;

class AllCest
{
    /**
     * Tests Phalcon\Debug\Dump :: all()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function debugDumpAll(UnitTester $I)
    {
        $I->wantToTest("Debug\Dump - all()");
        $I->skipTest("Need implementation");
    }
}
