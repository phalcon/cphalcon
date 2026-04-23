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
use Phalcon\Html\Escaper\EscaperInterface;

use const ENT_HTML401;
use const ENT_QUOTES;
use const ENT_SUBSTITUTE;

final class GetSetFlagsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEscaperGetSetFlags(): void
    {
        $escaper = new Escaper();

        $expected = ENT_QUOTES | ENT_SUBSTITUTE | ENT_HTML401;
        $actual   = $escaper->getFlags();
        $this->assertSame($expected, $actual);

        $expected = 'That&#039;s right';
        $actual   = $escaper->attributes("That's right");
        $this->assertSame($expected, $actual);

        $escaper->setFlags(ENT_HTML401);

        $expected = ENT_HTML401;
        $actual   = $escaper->getFlags();
        $this->assertSame($expected, $actual);

        $escaper->setFlags(ENT_QUOTES | ENT_SUBSTITUTE | ENT_HTML401);
        $expected = 'That&#039;s right';
        $actual   = $escaper->attributes("That's right");
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testEscaperSetHtmlQuoteType(): void
    {
        $escaper = new Escaper();

        $actual = $escaper->setHtmlQuoteType(ENT_HTML401);
        $this->assertInstanceOf(EscaperInterface::class, $actual);

        $expected = ENT_HTML401;
        $actual   = $escaper->getFlags();
        $this->assertSame($expected, $actual);
    }
}
