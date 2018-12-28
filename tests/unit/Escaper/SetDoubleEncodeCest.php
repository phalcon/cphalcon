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
 * Class SetDoubleEncodeCest
 */
class SetDoubleEncodeCest
{
    /**
     * Tests Phalcon\Escaper :: setDoubleEncode()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function escaperSetDoubleEncode(UnitTester $I)
    {
        $I->wantToTest("Escaper - setDoubleEncode()");
        $escaper = new Escaper();

        $source   = "<h1>&amp;</h1>";
        $expected = '&lt;h1&gt;&amp;amp;&lt;/h1&gt;';
        $actual   = $escaper->escapeHtml($source);
        $I->assertEquals($expected, $actual);

        $escaper->setDoubleEncode(false);

        $expected = '&lt;h1&gt;&amp;&lt;/h1&gt;';
        $actual   = $escaper->escapeHtml($source);
        $I->assertEquals($expected, $actual);
    }
}
