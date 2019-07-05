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

use UnitTester;

class SetHtmlQuoteTypeCest
{
    /**
     * Tests Phalcon\Escaper :: setHtmlQuoteType()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function escaperSetHtmlQuoteType(UnitTester $I)
    {
        $I->wantToTest('Escaper - setHtmlQuoteType()');

        $escaper = new Escaper();

        $escaper->setHtmlQuoteType(ENT_HTML401);

        $I->assertEquals(
            'That&#039;s right',
            $escaper->escapeHtmlAttr("That's right")
        );
    }
}
