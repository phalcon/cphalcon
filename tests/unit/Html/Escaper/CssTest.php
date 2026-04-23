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
use Phalcon\Tests\AbstractUnitTestCase;

final class CssTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEscaperCss(): void
    {
        $escaper = new Escaper();

        $source   = ".émotion { background: url('http://phalcon.io/a.php?c=d&e=f'); }";
        $expected = '\2e \e9 motion\20 \7b \20 background\3a \20 url\28 '
            . '\27 http\3a \2f \2f phalcon\2e io\2f a\2e php'
            . '\3f c\3d d\26 e\3d f\27 \29 \3b \20 \7d ';

        $actual = $escaper->css($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testEscaperCssEmptyStringReturnsEmpty(): void
    {
        $escaper = new Escaper();
        $actual  = $escaper->css('');
        $this->assertSame('', $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testEscaperCssNullCodepointBreaksLoop(): void
    {
        $escaper = new Escaper();
        // chr(0) encodes to U+0000 in UTF-32; escapeMulti breaks on it
        $actual  = $escaper->css("\x00");
        $this->assertSame('', $actual);
    }
}
