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

final class MacroTest extends AbstractUnitTestCase
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
    public function testMvcViewEngineVoltParserMacroNoParams(): void
    {
        $source   = '{% macro myMacro() %}content{% endmacro %}';
        $expected = [
            [
                'type' => 322,
                'name' => 'myMacro',
                'block_statements' => [
                    [
                        'type' => 357,
                        'value' => 'content',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
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
    public function testMvcViewEngineVoltParserMacroOneParam(): void
    {
        $source   = '{% macro greet(name) %}Hello {{ name }}{% endmacro %}';
        $expected = [
            [
                'type' => 322,
                'name' => 'greet',
                'parameters' => [
                    [
                        'variable' => 'name',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                ],
                'block_statements' => [
                    [
                        'type' => 357,
                        'value' => 'Hello ',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    [
                        'type' => 359,
                        'expr' => [
                            'type' => 265,
                            'value' => 'name',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
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
    public function testMvcViewEngineVoltParserMacroMultiParams(): void
    {
        $source   = '{% macro input(name, value) %}<input name="{{ name }}" value="{{ value }}">{% endmacro %}';
        $expected = [
            [
                'type' => 322,
                'name' => 'input',
                'parameters' => [
                    [
                        'variable' => 'name',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    [
                        'variable' => 'value',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                ],
                'block_statements' => [
                    [
                        'type' => 357,
                        'value' => '<input name="',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    [
                        'type' => 359,
                        'expr' => [
                            'type' => 265,
                            'value' => 'name',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    [
                        'type' => 357,
                        'value' => '" value="',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    [
                        'type' => 359,
                        'expr' => [
                            'type' => 265,
                            'value' => 'value',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    [
                        'type' => 357,
                        'value' => '">',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
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
    public function testMvcViewEngineVoltParserMacroDefaultInt(): void
    {
        $source   = '{% macro repeat(times = 1) %}{{ times }}{% endmacro %}';
        $expected = [
            [
                'type' => 322,
                'name' => 'repeat',
                'parameters' => [
                    [
                        'variable' => 'times',
                        'default' => [
                            'type' => 258,
                            'value' => '1',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                ],
                'block_statements' => [
                    [
                        'type' => 359,
                        'expr' => [
                            'type' => 265,
                            'value' => 'times',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
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
    public function testMvcViewEngineVoltParserMacroDefaultString(): void
    {
        $source   = '{% macro greet(name = \'World\') %}Hello {{ name }}{% endmacro %}';
        $expected = [
            [
                'type' => 322,
                'name' => 'greet',
                'parameters' => [
                    [
                        'variable' => 'name',
                        'default' => [
                            'type' => 260,
                            'value' => 'World',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                ],
                'block_statements' => [
                    [
                        'type' => 357,
                        'value' => 'Hello ',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    [
                        'type' => 359,
                        'expr' => [
                            'type' => 265,
                            'value' => 'name',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
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
    public function testMvcViewEngineVoltParserMacroDefaultNull(): void
    {
        $source   = '{% macro render(item = null) %}{{ item }}{% endmacro %}';
        $expected = [
            [
                'type' => 322,
                'name' => 'render',
                'parameters' => [
                    [
                        'variable' => 'item',
                        'default' => [
                            'type' => 261,
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                ],
                'block_statements' => [
                    [
                        'type' => 359,
                        'expr' => [
                            'type' => 265,
                            'value' => 'item',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
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
    public function testMvcViewEngineVoltParserMacroDefaultTrue(): void
    {
        $source   = '{% macro show(visible = true) %}{{ visible }}{% endmacro %}';
        $expected = [
            [
                'type' => 322,
                'name' => 'show',
                'parameters' => [
                    [
                        'variable' => 'visible',
                        'default' => [
                            'type' => 263,
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                ],
                'block_statements' => [
                    [
                        'type' => 359,
                        'expr' => [
                            'type' => 265,
                            'value' => 'visible',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
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
    public function testMvcViewEngineVoltParserMacroDefaultFalse(): void
    {
        $source   = '{% macro show(visible = false) %}{{ visible }}{% endmacro %}';
        $expected = [
            [
                'type' => 322,
                'name' => 'show',
                'parameters' => [
                    [
                        'variable' => 'visible',
                        'default' => [
                            'type' => 262,
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                ],
                'block_statements' => [
                    [
                        'type' => 359,
                        'expr' => [
                            'type' => 265,
                            'value' => 'visible',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                ],
                'file' => 'eval code',
                'line' => 1,
            ],
        ];
        $actual   = $this->compiler->parse($source);
        $this->assertSame($expected, $actual);
    }
}
