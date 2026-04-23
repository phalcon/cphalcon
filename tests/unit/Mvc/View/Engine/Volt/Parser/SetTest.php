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

final class SetTest extends AbstractUnitTestCase
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
    public function testMvcViewEngineVoltParserSetAssign(): void
    {
        $source   = '{% set name = \'John\' %}';
        $expected = [
            [
                'type' => 306,
                'assignments' => [
                    [
                        'variable' => [
                            'type' => 265,
                            'value' => 'name',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'op' => 61,
                        'expr' => [
                            'type' => 260,
                            'value' => 'John',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                ],
            ],
        ];
        $actual   = $this->compiler->parse($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-10
     */
    public function testMvcViewEngineVoltParserSetAssignExpr(): void
    {
        $source   = '{% set total = price * qty %}';
        $expected = [
            [
                'type' => 306,
                'assignments' => [
                    [
                        'variable' => [
                            'type' => 265,
                            'value' => 'total',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'op' => 61,
                        'expr' => [
                            'type' => 42,
                            'left' => [
                                'type' => 265,
                                'value' => 'price',
                                'file' => 'eval code',
                                'line' => 1,
                            ],
                            'right' => [
                                'type' => 265,
                                'value' => 'qty',
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
            ],
        ];
        $actual   = $this->compiler->parse($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-10
     */
    public function testMvcViewEngineVoltParserSetAddAssign(): void
    {
        $source   = '{% set counter += 1 %}';
        $expected = [
            [
                'type' => 306,
                'assignments' => [
                    [
                        'variable' => [
                            'type' => 265,
                            'value' => 'counter',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'op' => 281,
                        'expr' => [
                            'type' => 258,
                            'value' => '1',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                ],
            ],
        ];
        $actual   = $this->compiler->parse($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-10
     */
    public function testMvcViewEngineVoltParserSetSubAssign(): void
    {
        $source   = '{% set counter -= 1 %}';
        $expected = [
            [
                'type' => 306,
                'assignments' => [
                    [
                        'variable' => [
                            'type' => 265,
                            'value' => 'counter',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'op' => 282,
                        'expr' => [
                            'type' => 258,
                            'value' => '1',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                ],
            ],
        ];
        $actual   = $this->compiler->parse($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-10
     */
    public function testMvcViewEngineVoltParserSetMulAssign(): void
    {
        $source   = '{% set value *= 2 %}';
        $expected = [
            [
                'type' => 306,
                'assignments' => [
                    [
                        'variable' => [
                            'type' => 265,
                            'value' => 'value',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'op' => 283,
                        'expr' => [
                            'type' => 258,
                            'value' => '2',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                ],
            ],
        ];
        $actual   = $this->compiler->parse($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-10
     */
    public function testMvcViewEngineVoltParserSetDivAssign(): void
    {
        $source   = '{% set value /= 2 %}';
        $expected = [
            [
                'type' => 306,
                'assignments' => [
                    [
                        'variable' => [
                            'type' => 265,
                            'value' => 'value',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'op' => 284,
                        'expr' => [
                            'type' => 258,
                            'value' => '2',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                ],
            ],
        ];
        $actual   = $this->compiler->parse($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-10
     */
    public function testMvcViewEngineVoltParserSetMulti(): void
    {
        $source   = '{% set a = 1, b = 2, c = 3 %}';
        $expected = [
            [
                'type' => 306,
                'assignments' => [
                    [
                        'variable' => [
                            'type' => 265,
                            'value' => 'a',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'op' => 61,
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
                        'variable' => [
                            'type' => 265,
                            'value' => 'b',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'op' => 61,
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
                        'variable' => [
                            'type' => 265,
                            'value' => 'c',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'op' => 61,
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
            ],
        ];
        $actual   = $this->compiler->parse($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-10
     */
    public function testMvcViewEngineVoltParserSetArrayAccess(): void
    {
        $source   = '{% set items[0] = \'first\' %}';
        $expected = [
            [
                'type' => 306,
                'assignments' => [
                    [
                        'variable' => [
                            'type' => 361,
                            'left' => [
                                'type' => 265,
                                'value' => 'items',
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
                        'op' => 61,
                        'expr' => [
                            'type' => 260,
                            'value' => 'first',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                ],
            ],
        ];
        $actual   = $this->compiler->parse($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-10
     */
    public function testMvcViewEngineVoltParserSetDotAccess(): void
    {
        $source   = '{% set user.name = \'John\' %}';
        $expected = [
            [
                'type' => 306,
                'assignments' => [
                    [
                        'variable' => [
                            'type' => 46,
                            'left' => [
                                'type' => 265,
                                'value' => 'user',
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
                        'op' => 61,
                        'expr' => [
                            'type' => 260,
                            'value' => 'John',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                ],
            ],
        ];
        $actual   = $this->compiler->parse($source);
        $this->assertSame($expected, $actual);
    }
}
