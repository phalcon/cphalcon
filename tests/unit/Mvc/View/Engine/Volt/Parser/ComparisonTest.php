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

final class ComparisonTest extends AbstractUnitTestCase
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
    public function testMvcViewEngineVoltParserExprEq(): void
    {
        $source   = '{{ a == b }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 272,
                    'left' => [
                        'type' => 265,
                        'value' => 'a',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 265,
                        'value' => 'b',
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
    public function testMvcViewEngineVoltParserExprNeq(): void
    {
        $source   = '{{ a != b }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 273,
                    'left' => [
                        'type' => 265,
                        'value' => 'a',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 265,
                        'value' => 'b',
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
    public function testMvcViewEngineVoltParserExprNeqAlt(): void
    {
        $source   = '{{ a <> b }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 273,
                    'left' => [
                        'type' => 265,
                        'value' => 'a',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 265,
                        'value' => 'b',
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
    public function testMvcViewEngineVoltParserExprIdentical(): void
    {
        $source   = '{{ a === b }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 274,
                    'left' => [
                        'type' => 265,
                        'value' => 'a',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 265,
                        'value' => 'b',
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
    public function testMvcViewEngineVoltParserExprNotidentical(): void
    {
        $source   = '{{ a !== b }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 275,
                    'left' => [
                        'type' => 265,
                        'value' => 'a',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 265,
                        'value' => 'b',
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
    public function testMvcViewEngineVoltParserExprLt(): void
    {
        $source   = '{{ a < b }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 60,
                    'left' => [
                        'type' => 265,
                        'value' => 'a',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 265,
                        'value' => 'b',
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
    public function testMvcViewEngineVoltParserExprGt(): void
    {
        $source   = '{{ a > b }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 62,
                    'left' => [
                        'type' => 265,
                        'value' => 'a',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 265,
                        'value' => 'b',
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
    public function testMvcViewEngineVoltParserExprLte(): void
    {
        $source   = '{{ a <= b }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 270,
                    'left' => [
                        'type' => 265,
                        'value' => 'a',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 265,
                        'value' => 'b',
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
    public function testMvcViewEngineVoltParserExprGte(): void
    {
        $source   = '{{ a >= b }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 271,
                    'left' => [
                        'type' => 265,
                        'value' => 'a',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 265,
                        'value' => 'b',
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
