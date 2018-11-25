<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Crypt;

use UnitTester;

class DecryptCest
{
    /**
     * Tests Phalcon\Crypt :: decrypt()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cryptDecrypt(UnitTester $I)
    {
        $I->wantToTest("Crypt - decrypt()");
        $I->skipTest("Need implementation");
    }
}
