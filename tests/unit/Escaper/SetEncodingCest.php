<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Escaper;

use UnitTester;

class SetEncodingCest
{
    /**
     * Tests Phalcon\Escaper :: setEncoding()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function escaperSetEncoding(UnitTester $I)
    {
        $I->wantToTest("Escaper - setEncoding()");
        $I->skipTest("Need implementation");
    }
}
