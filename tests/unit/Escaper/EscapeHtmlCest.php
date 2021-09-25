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

namespace Phalcon\Tests\Unit\Escaper;

use Phalcon\Escaper;
use UnitTester;

class EscapeHtmlCest
{
    /**
     * Tests Phalcon\Escaper :: escapeHtml()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-12
     */
    public function escaperEscapeHtml(UnitTester $I)
    {
        $I->wantToTest('Escaper - escapeHtml()');

        $escaper = new Escaper();

        $I->assertEquals(
            '&lt;h1&gt;&lt;/h1&gt;',
            $escaper->escapeHtml('<h1></h1>')
        );
    }

    /**
     * Tests Phalcon\Escaper :: escapeHtml() - null
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-11-22
     */
    public function escaperEscapeHtmlNull(UnitTester $I)
    {
        $I->wantToTest('Escaper - escapeHtml() - null');

        $escaper = new Escaper();

        $I->assertEquals(
            '',
            $escaper->escapeHtml(null)
        );
    }
}
