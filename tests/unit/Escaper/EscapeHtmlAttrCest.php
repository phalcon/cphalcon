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

class EscapeHtmlAttrCest
{
    /**
     * Tests Phalcon\Escaper :: escapeHtmlAttr()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function escaperEscapeHtmlAttr(UnitTester $I)
    {
        $I->wantToTest("Escaper - escapeHtmlAttr()");
        $I->skipTest("Need implementation");
    }
}
