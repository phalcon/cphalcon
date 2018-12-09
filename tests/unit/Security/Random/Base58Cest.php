<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Security\Random;

use UnitTester;

class Base58Cest
{
    /**
     * Tests Phalcon\Security\Random :: base58()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function securityRandomBase58(UnitTester $I)
    {
        $I->wantToTest("Security\Random - base58()");
        $I->skipTest("Need implementation");
    }
}
