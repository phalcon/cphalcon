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

final class HtmlTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEscaperHtml(): void
    {
        $escaper = new Escaper();

        $expected = '&lt;h1&gt;&lt;/h1&gt;';
        $actual   = $escaper->html('<h1></h1>');
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEscaperHtmlNull(): void
    {
        $escaper  = new Escaper();
        $expected = '';
        $actual   = $escaper->html(null);
        $this->assertSame($expected, $actual);

        $escaper  = new Escaper();
        $expected = '0';
        $actual   = $escaper->html('0');
        $this->assertSame($expected, $actual);
    }
}
