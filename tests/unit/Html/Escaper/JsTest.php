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
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class JsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEscaperJs(): void
    {
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

        $actual = $escaper->js($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * Backslash must be neutralized so it cannot escape the delimiter of a
     * surrounding JavaScript string literal (string breakout / XSS).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-22
     */
    public function testEscaperJsNeutralizesBackslashPreventingStringBreakout(): void
    {
        $escaper = new Escaper();
        $bs      = chr(92); // a single backslash

        // a lone backslash must become an escaped (doubled) backslash
        $this->assertSame($bs . $bs, $escaper->js($bs));

        // a trailing backslash must not escape a following delimiter
        $this->assertSame('x' . $bs . $bs, $escaper->js('x' . $bs));

        // the classic breakout payload stays inert: backslash doubled, the
        // quote hex-escaped
        $this->assertSame(
            $bs . $bs . '\x27;alert(1)//',
            $escaper->js($bs . "';alert(1)//")
        );
    }
}
