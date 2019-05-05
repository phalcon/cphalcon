<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Escaper;

use Phalcon\Escaper;
use UnitTester;

class EscapeHtmlCest
{
    /**
     * Tests Phalcon\Escaper :: escapeHtml()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function escaperEscapeHtml(UnitTester $I)
    {
        $I->wantToTest("Escaper - escapeHtml()");

        $escaper = new Escaper();

        $I->assertEquals(
            '&lt;h1&gt;&lt;/h1&gt;',
            $escaper->escapeHtml("<h1></h1>")
        );
    }
}
