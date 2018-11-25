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

class GetEncodingCest
{
    /**
     * Tests Phalcon\Escaper :: getEncoding()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function escaperGetEncoding(UnitTester $I)
    {
        $I->wantToTest("Escaper - getEncoding()");
        $I->skipTest("Need implementation");
    }
}
