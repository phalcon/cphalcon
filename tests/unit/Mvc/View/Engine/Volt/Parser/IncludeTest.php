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

final class IncludeTest extends AbstractUnitTestCase
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
    public function testMvcViewEngineVoltParserInclude(): void
    {
        $source   = '{% include \'partial.volt\' %}';
        $expected = [
            [
                'type' => 313,
                'path' => [
                    'type' => 260,
                    'value' => 'partial.volt',
                    'file' => 'eval code',
                    'line' => 1,
                ],
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
    public function testMvcViewEngineVoltParserIncludeWith(): void
    {
        $source   = '{% include \'partial.volt\' with vars %}';
        $expected = [
            [
                'type' => 313,
                'path' => [
                    'type' => 260,
                    'value' => 'partial.volt',
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'params' => [
                    'type' => 265,
                    'value' => 'vars',
                    'file' => 'eval code',
                    'line' => 1,
                ],
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
    public function testMvcViewEngineVoltParserIncludeWithHash(): void
    {
        $source   = '{% include \'partial.volt\' with {\'key\': \'value\'} %}';
        $expected = [
            [
                'type' => 313,
                'path' => [
                    'type' => 260,
                    'value' => 'partial.volt',
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'params' => [
                    'type' => 360,
                    'left' => [
                        [
                            'expr' => [
                                'type' => 260,
                                'value' => 'value',
                                'file' => 'eval code',
                                'line' => 1,
                            ],
                            'name' => 'key',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                    ],
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'file' => 'eval code',
                'line' => 1,
            ],
        ];
        $actual   = $this->compiler->parse($source);
        $this->assertSame($expected, $actual);
    }
}
