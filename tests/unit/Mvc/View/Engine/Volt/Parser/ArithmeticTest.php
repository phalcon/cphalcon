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

final class ArithmeticTest extends AbstractUnitTestCase
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
    public function testMvcViewEngineVoltParserExprAdd(): void
    {
        $source   = '{{ 1 + 2 }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 43,
                    'left' => [
                        'type' => 258,
                        'value' => '1',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 258,
                        'value' => '2',
                        'file' => 'eval code',
                        'line' => 1,
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
    public function testMvcViewEngineVoltParserExprSub(): void
    {
        $source   = '{{ 5 - 3 }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 45,
                    'left' => [
                        'type' => 258,
                        'value' => '5',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 258,
                        'value' => '3',
                        'file' => 'eval code',
                        'line' => 1,
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
    public function testMvcViewEngineVoltParserExprMul(): void
    {
        $source   = '{{ 4 * 3 }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 42,
                    'left' => [
                        'type' => 258,
                        'value' => '4',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 258,
                        'value' => '3',
                        'file' => 'eval code',
                        'line' => 1,
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
    public function testMvcViewEngineVoltParserExprDiv(): void
    {
        $source   = '{{ 10 / 2 }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 47,
                    'left' => [
                        'type' => 258,
                        'value' => '10',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 258,
                        'value' => '2',
                        'file' => 'eval code',
                        'line' => 1,
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
    public function testMvcViewEngineVoltParserExprMod(): void
    {
        $source   = '{{ 10 % 3 }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 37,
                    'left' => [
                        'type' => 258,
                        'value' => '10',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 258,
                        'value' => '3',
                        'file' => 'eval code',
                        'line' => 1,
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
    public function testMvcViewEngineVoltParserExprPow(): void
    {
        $source   = '{{ 2 * * 8 }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 278,
                    'left' => [
                        'type' => 258,
                        'value' => '2',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 258,
                        'value' => '8',
                        'file' => 'eval code',
                        'line' => 1,
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
    public function testMvcViewEngineVoltParserExprIntDiv(): void
    {
        $source   = '{{ 10 / / 3 }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 37,
                    'left' => [
                        'type' => 258,
                        'value' => '10',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 258,
                        'value' => '3',
                        'file' => 'eval code',
                        'line' => 1,
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
    public function testMvcViewEngineVoltParserExprUnaryMinus(): void
    {
        $source   = '{{ -value }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 368,
                    'right' => [
                        'type' => 265,
                        'value' => 'value',
                        'file' => 'eval code',
                        'line' => 1,
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
    public function testMvcViewEngineVoltParserExprUnaryPlus(): void
    {
        $source   = '{{ +value }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 369,
                    'right' => [
                        'type' => 265,
                        'value' => 'value',
                        'file' => 'eval code',
                        'line' => 1,
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
    public function testMvcViewEngineVoltParserExprIncr(): void
    {
        $source   = '{{ value++ }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 279,
                    'left' => [
                        'type' => 265,
                        'value' => 'value',
                        'file' => 'eval code',
                        'line' => 1,
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
    public function testMvcViewEngineVoltParserExprDecr(): void
    {
        $source   = '{{ value-- }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 280,
                    'left' => [
                        'type' => 265,
                        'value' => 'value',
                        'file' => 'eval code',
                        'line' => 1,
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
