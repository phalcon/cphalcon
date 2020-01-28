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

namespace Phalcon\Test\Unit\Escaper;

use Phalcon\Escaper;
use UnitTester;

class SetDoubleEncodeCest
{
    /**
     * Tests Phalcon\Escaper :: setDoubleEncode()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function escaperSetDoubleEncode(UnitTester $I)
    {
        $I->wantToTest('Escaper - setDoubleEncode()');

        $escaper = new Escaper();

        $source = '<h1>&amp;</h1>';

        $I->assertEquals(
            '&lt;h1&gt;&amp;amp;&lt;/h1&gt;',
            $escaper->escapeHtml($source)
        );

        $escaper->setDoubleEncode(false);

        $I->assertEquals(
            '&lt;h1&gt;&amp;&lt;/h1&gt;',
            $escaper->escapeHtml($source)
        );
    }
}
