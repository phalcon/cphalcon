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

final class ForTest extends AbstractUnitTestCase
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
    public function testMvcViewEngineVoltParserForSimple(): void
    {
        $source   = '{% for item in items %}{{ item }}{% endfor %}';
        $expected = [
            [
                'type' => 304,
                'variable' => 'item',
                'expr' => [
                    'type' => 265,
                    'value' => 'items',
                    'file' => 'eval code',
                    'line' => 1,
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
    public function testMvcViewEngineVoltParserForIf(): void
    {
        $source   = '{% for item in items if item.active %}{{ item.name }}{% endfor %}';
        $expected = [
            [
                'type' => 304,
                'variable' => 'item',
                'expr' => [
                    'type' => 265,
                    'value' => 'items',
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'if_expr' => [
                    'type' => 46,
                    'left' => [
                        'type' => 265,
                        'value' => 'item',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 265,
                        'value' => 'active',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'block_statements' => [
                    [
                        'type' => 359,
                        'expr' => [
                            'type' => 46,
                            'left' => [
                                'type' => 265,
                                'value' => 'item',
                                'file' => 'eval code',
                                'line' => 1,
                            ],
                            'right' => [
                                'type' => 265,
                                'value' => 'name',
                                'file' => 'eval code',
                                'line' => 1,
                            ],
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
    public function testMvcViewEngineVoltParserForKeyValue(): void
    {
        $source   = '{% for key, value in map %}{{ key }}: {{ value }}{% endfor %}';
        $expected = [
            [
                'type' => 304,
                'variable' => 'value',
                'key' => 'key',
                'expr' => [
                    'type' => 265,
                    'value' => 'map',
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'block_statements' => [
                    [
                        'type' => 359,
                        'expr' => [
                            'type' => 265,
                            'value' => 'key',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    [
                        'type' => 357,
                        'value' => ': ',
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
    public function testMvcViewEngineVoltParserForKeyValueIf(): void
    {
        $source   = '{% for key, value in map if value > 0 %}{{ key }}{% endfor %}';
        $expected = [
            [
                'type' => 304,
                'variable' => 'value',
                'key' => 'key',
                'expr' => [
                    'type' => 265,
                    'value' => 'map',
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'if_expr' => [
                    'type' => 62,
                    'left' => [
                        'type' => 265,
                        'value' => 'value',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 258,
                        'value' => '0',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'block_statements' => [
                    [
                        'type' => 359,
                        'expr' => [
                            'type' => 265,
                            'value' => 'key',
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
    public function testMvcViewEngineVoltParserForElsefor(): void
    {
        $source   = '{% for item in items %}{{ item }}{% elsefor %}No items{% endfor %}';
        $expected = [
            [
                'type' => 304,
                'variable' => 'item',
                'expr' => [
                    'type' => 265,
                    'value' => 'items',
                    'file' => 'eval code',
                    'line' => 1,
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
                    [
                        'type' => 321,
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    [
                        'type' => 357,
                        'value' => 'No items',
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
