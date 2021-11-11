<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Escaper;

use Phalcon\Html\Escaper;
use UnitTester;

class HtmlCest
{
    /**
     * Tests Phalcon\Escaper :: escapeHtml()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function escaperHtml(UnitTester $I)
    {
        $I->wantToTest('Escaper - html()');

        $escaper  = new Escaper();

        $expected = '&lt;h1&gt;&lt;/h1&gt;';
        $actual   = $escaper->html('<h1></h1>');
        $I->assertEquals($expected, $actual);

        $actual = $escaper->escapeHtml('<h1></h1>');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Escaper :: escapeHtml() - null
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function escaperHtmlNull(UnitTester $I)
    {
        $I->wantToTest('Escaper - html() - null');

        $escaper = new Escaper();

        $escaper  = new Escaper();
        $expected = '';
        $actual   = $escaper->html(null);
        $I->assertEquals($expected, $actual);
    }
}
