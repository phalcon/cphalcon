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
use const ENT_HTML401;
use const ENT_HTML5;
use const ENT_XHTML;
use const ENT_XML1;

/**
 * Class EscapeHtmlAttrCest
 */
class EscapeHtmlAttrCest
{
    /**
     * Tests Phalcon\Escaper :: escapeHtmlAttr()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-16
     */
    public function escaperEscapeHtmlAttr(UnitTester $I)
    {
        $I->wantToTest("Escaper - escapeHtmlAttr()");
        $escaper = new Escaper();

        $escaper->setHtmlQuoteType(ENT_HTML401);
        $expected = "That&#039;s right";
        $actual   = $escaper->escapeHtmlAttr("That's right");
        $I->assertEquals($expected, $actual);

        $escaper->setHtmlQuoteType(ENT_XML1);
        $expected = "That&#039;s right";
        $actual   = $escaper->escapeHtmlAttr("That's right");
        $I->assertEquals($expected, $actual);

        $escaper->setHtmlQuoteType(ENT_XHTML);
        $expected = "That&#039;s right";
        $actual   = $escaper->escapeHtmlAttr("That's right");
        $I->assertEquals($expected, $actual);

        $escaper->setHtmlQuoteType(ENT_HTML5);
        $expected = "That&#039;s right";
        $actual   = $escaper->escapeHtmlAttr("That's right");
        $I->assertEquals($expected, $actual);
    }
}
