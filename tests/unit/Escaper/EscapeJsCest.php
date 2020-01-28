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

class EscapeJsCest
{
    /**
     * Tests Phalcon\Escaper :: escapeJs()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-16
     */
    public function escaperEscapeJs(UnitTester $I)
    {
        $I->wantToTest('Escaper - escapeJs()');

        $escaper = new Escaper();

        $source = 'function createtoc () {'
            . "var h2s = document.getElementsByTagName('H2');"
            . "l = toc.appendChild(document.createElement('ol'));"
            . 'for (var i=0; i<h2s.length; i++) {'
            . 'var h2 = h2s[i].firstChild.innerHTML;'
            . "var h = document.createElement('li');"
            . 'l.appendChild(h);'
            . '}}';

        $expected = 'function createtoc () {'
            . 'var h2s \x3d document.getElementsByTagName(\x27H2\x27);'
            . 'l \x3d toc.appendChild(document.createElement(\x27ol\x27));'
            . 'for (var i\x3d0; i\x3ch2s.length; i++) {'
            . 'var h2 \x3d h2s[i].firstChild.innerHTML;'
            . 'var h \x3d document.createElement(\x27li\x27);'
            . 'l.appendChild(h);'
            . '}}';

        $I->assertEquals(
            $expected,
            $escaper->escapeJs($source)
        );
    }
}
