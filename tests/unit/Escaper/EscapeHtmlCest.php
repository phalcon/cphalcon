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

class EscapeHtmlCest
{
    /**
     * Tests Phalcon\Escaper :: escapeHtml()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function escaperEscapeHtml(UnitTester $I)
    {
        $I->wantToTest("Escaper - escapeHtml()");
        $I->skipTest("Need implementation");
    }
}
