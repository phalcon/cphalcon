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

/**
 * Class SetHtmlQuoteTypeCest
 */
class SetHtmlQuoteTypeCest
{
    /**
     * Tests Phalcon\Escaper :: setHtmlQuoteType()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function escaperSetHtmlQuoteType(UnitTester $I)
    {
        $I->wantToTest("Escaper - setHtmlQuoteType()");
        $escaper = new Escaper();

        $escaper->setHtmlQuoteType(ENT_HTML401);
        $expected = "That&#039;s right";
        $actual   = $escaper->escapeHtmlAttr("That's right");
        $I->assertEquals($expected, $actual);
    }
}
