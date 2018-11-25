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

class OneCest
{
    /**
     * Tests Phalcon\Debug\Dump :: one()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function debugDumpOne(UnitTester $I)
    {
        $I->wantToTest("Debug\Dump - one()");
        $I->skipTest("Need implementation");
    }
}
