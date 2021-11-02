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

class SetHtmlQuoteTypeCest
{
    /**
     * Tests Phalcon\Escaper :: setHtmlQuoteType()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function escaperSetHtmlQuoteType(UnitTester $I)
    {
        $I->wantToTest('Escaper - setHtmlQuoteType()');

        $escaper = new Escaper();

        $escaper->setHtmlQuoteType(ENT_HTML401);

        $expected = 'That&#039;s right';
        $actual   = $escaper->attributes("That's right");
        $I->assertEquals($expected, $actual);
    }
}
