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
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

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
     * Perform test for equals ("is" as a binary comparison operator)
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-04
     */
    public function testMvcViewEngineVoltParserExprIsComparison(): void
    {
        $source   = '{% if a is b %}c{% endif %}';
        $expected = [
            [
                'type' => 300,
                'expr' => [
                    'type' => 311,
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
                'true_statements' => [
                    [
                        'type' => 357,
                        'value' => 'c',
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
     * Perform test for not equals ("is not" as a binary comparison operator)
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-04
     */
    public function testMvcViewEngineVoltParserExprIsNotComparison(): void
    {
        $source   = '{% if a is not b %}c{% endif %}';
        $expected = [
            [
                'type' => 300,
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
                'true_statements' => [
                    [
                        'type' => 357,
                        'value' => 'c',
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
     * Perform conditional echo ("is" test inside a ternary)
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-04
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/14476
     */
    public function testMvcViewEngineVoltParserExprIsTernary(): void
    {
        $source   = '{{ uploadedPhoto is user.avatar ? \'checked="checked"\' : \'\' }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 366,
                    'ternary' => [
                        'type' => 311,
                        'left' => [
                            'type' => 265,
                            'value' => 'uploadedPhoto',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'right' => [
                            'type' => 46,
                            'left' => [
                                'type' => 265,
                                'value' => 'user',
                                'file' => 'eval code',
                                'line' => 1,
                            ],
                            'right' => [
                                'type' => 265,
                                'value' => 'avatar',
                                'file' => 'eval code',
                                'line' => 1,
                            ],
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'left' => [
                        'type' => 260,
                        'value' => 'checked="checked"',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 260,
                        'value' => '',
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
     * Perform conditional echo II ("is empty" test inside a ternary)
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-04
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/14476
     */
    public function testMvcViewEngineVoltParserExprIsEmptyTernary(): void
    {
        $source   = '{{ title is empty ? siteName : title }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 366,
                    'ternary' => [
                        'type' => 386,
                        'left' => [
                            'type' => 265,
                            'value' => 'title',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'left' => [
                        'type' => 265,
                        'value' => 'siteName',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 265,
                        'value' => 'title',
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
