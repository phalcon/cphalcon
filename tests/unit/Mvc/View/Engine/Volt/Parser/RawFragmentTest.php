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

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt\Parser;

use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Tests\AbstractUnitTestCase;

final class RawFragmentTest extends AbstractUnitTestCase
{
    private Compiler $compiler;

    public function setUp(): void
    {
        $this->compiler = new Compiler();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-10
     */
    public function testMvcViewEngineVoltParserRawText(): void
    {
        $source   = 'Hello World';
        $expected = [
            [
                'type' => 357,
                'value' => 'Hello World',
                'file' => 'eval code',
                'line' => 1,
            ],
        ];
        $actual   = $this->compiler->parse($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-10
     */
    public function testMvcViewEngineVoltParserRawTextMultiline(): void
    {
        $source   = "Line one
Line two";
        $expected = [
            [
                'type' => 357,
                'value' => "Line one
Line two",
                'file' => 'eval code',
                'line' => 2,
            ],
        ];
        $actual   = $this->compiler->parse($source);
        $this->assertSame($expected, $actual);
    }
}
