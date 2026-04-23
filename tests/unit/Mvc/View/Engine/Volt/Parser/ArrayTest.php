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

final class ArrayTest extends AbstractUnitTestCase
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
    public function testMvcViewEngineVoltParserExprArrayEmpty(): void
    {
        $source   = '{{ [] }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 360,
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
    public function testMvcViewEngineVoltParserExprArrayLiteral(): void
    {
        $source   = '{{ [1, 2, 3] }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 360,
                    'left' => [
                        [
                            'expr' => [
                                'type' => 258,
                                'value' => '1',
                                'file' => 'eval code',
                                'line' => 1,
                            ],
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        [
                            'expr' => [
                                'type' => 258,
                                'value' => '2',
                                'file' => 'eval code',
                                'line' => 1,
                            ],
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        [
                            'expr' => [
                                'type' => 258,
                                'value' => '3',
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
    public function testMvcViewEngineVoltParserExprArrayMixed(): void
    {
        $source   = '{{ [\'a\', \'b\', \'c\'] }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 360,
                    'left' => [
                        [
                            'expr' => [
                                'type' => 260,
                                'value' => 'a',
                                'file' => 'eval code',
                                'line' => 1,
                            ],
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        [
                            'expr' => [
                                'type' => 260,
                                'value' => 'b',
                                'file' => 'eval code',
                                'line' => 1,
                            ],
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        [
                            'expr' => [
                                'type' => 260,
                                'value' => 'c',
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
    public function testMvcViewEngineVoltParserExprHashEmpty(): void
    {
        $source   = '{{ {} }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 360,
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
    public function testMvcViewEngineVoltParserExprHashLiteral(): void
    {
        $source   = '{{ {\'key\': \'value\', \'num\': 42} }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
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
                        [
                            'expr' => [
                                'type' => 258,
                                'value' => '42',
                                'file' => 'eval code',
                                'line' => 1,
                            ],
                            'name' => 'num',
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
