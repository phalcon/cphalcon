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

final class IsTest extends AbstractUnitTestCase
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
    public function testMvcViewEngineVoltParserExprIsDefined(): void
    {
        $source   = '{{ var is defined }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 363,
                    'left' => [
                        'type' => 265,
                        'value' => 'var',
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
    public function testMvcViewEngineVoltParserExprIsNotDefined(): void
    {
        $source   = '{{ var is not defined }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 362,
                    'left' => [
                        'type' => 265,
                        'value' => 'var',
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
    public function testMvcViewEngineVoltParserExprIsEmpty(): void
    {
        $source   = '{{ var is empty }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 386,
                    'left' => [
                        'type' => 265,
                        'value' => 'var',
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
    public function testMvcViewEngineVoltParserExprIsNotEmpty(): void
    {
        $source   = '{{ var is not empty }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 392,
                    'left' => [
                        'type' => 265,
                        'value' => 'var',
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
    public function testMvcViewEngineVoltParserExprIsEven(): void
    {
        $source   = '{{ number is even }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 387,
                    'left' => [
                        'type' => 265,
                        'value' => 'number',
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
    public function testMvcViewEngineVoltParserExprIsNotEven(): void
    {
        $source   = '{{ number is not even }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 393,
                    'left' => [
                        'type' => 265,
                        'value' => 'number',
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
    public function testMvcViewEngineVoltParserExprIsOdd(): void
    {
        $source   = '{{ number is odd }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 388,
                    'left' => [
                        'type' => 265,
                        'value' => 'number',
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
    public function testMvcViewEngineVoltParserExprIsNotOdd(): void
    {
        $source   = '{{ number is not odd }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 394,
                    'left' => [
                        'type' => 265,
                        'value' => 'number',
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
    public function testMvcViewEngineVoltParserExprIsNumeric(): void
    {
        $source   = '{{ var is numeric }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 389,
                    'left' => [
                        'type' => 265,
                        'value' => 'var',
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
    public function testMvcViewEngineVoltParserExprIsNotNumeric(): void
    {
        $source   = '{{ var is not numeric }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 395,
                    'left' => [
                        'type' => 265,
                        'value' => 'var',
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
    public function testMvcViewEngineVoltParserExprIsScalar(): void
    {
        $source   = '{{ var is scalar }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 390,
                    'left' => [
                        'type' => 265,
                        'value' => 'var',
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
    public function testMvcViewEngineVoltParserExprIsNotScalar(): void
    {
        $source   = '{{ var is not scalar }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 396,
                    'left' => [
                        'type' => 265,
                        'value' => 'var',
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
    public function testMvcViewEngineVoltParserExprIsIterable(): void
    {
        $source   = '{{ var is iterable }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 391,
                    'left' => [
                        'type' => 265,
                        'value' => 'var',
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
    public function testMvcViewEngineVoltParserExprIsNotIterable(): void
    {
        $source   = '{{ var is not iterable }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 397,
                    'left' => [
                        'type' => 265,
                        'value' => 'var',
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
