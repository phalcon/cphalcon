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

final class SetDoubleEncodeTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEscaperSetDoubleEncode(): void
    {
        $escaper = new Escaper();

        $source = '<h1>&amp;</h1>';

        $expected = '&lt;h1&gt;&amp;amp;&lt;/h1&gt;';
        $actual   = $escaper->html($source);
        $this->assertSame($expected, $actual);

        $escaper->setDoubleEncode(false);

        $expected = '&lt;h1&gt;&amp;&lt;/h1&gt;';
        $actual   = $escaper->html($source);
        $this->assertSame($expected, $actual);
    }
}
