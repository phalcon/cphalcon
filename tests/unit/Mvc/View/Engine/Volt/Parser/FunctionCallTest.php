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

final class FunctionCallTest extends AbstractUnitTestCase
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
    public function testMvcViewEngineVoltParserExprFuncNoArgs(): void
    {
        $source   = '{{ myFunc() }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 350,
                    'name' => [
                        'type' => 265,
                        'value' => 'myFunc',
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
    public function testMvcViewEngineVoltParserExprFuncOneArg(): void
    {
        $source   = '{{ upper(name) }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 350,
                    'name' => [
                        'type' => 265,
                        'value' => 'upper',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'arguments' => [
                        [
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
    public function testMvcViewEngineVoltParserExprFuncMultiArgs(): void
    {
        $source   = '{{ slice(text, 0, 50) }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 350,
                    'name' => [
                        'type' => 265,
                        'value' => 'slice',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'arguments' => [
                        [
                            'expr' => [
                                'type' => 265,
                                'value' => 'text',
                                'file' => 'eval code',
                                'line' => 1,
                            ],
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        [
                            'expr' => [
                                'type' => 258,
                                'value' => '0',
                                'file' => 'eval code',
                                'line' => 1,
                            ],
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        [
                            'expr' => [
                                'type' => 258,
                                'value' => '50',
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
    public function testMvcViewEngineVoltParserExprFuncNamedArgs(): void
    {
        $source   = '{{ myFunc(\'key\': value) }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 350,
                    'name' => [
                        'type' => 265,
                        'value' => 'myFunc',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'arguments' => [
                        [
                            'expr' => [
                                'type' => 265,
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

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-10
     */
    public function testMvcViewEngineVoltParserExprParentheses(): void
    {
        $source   = '{{ (1 + 2) * 3 }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 42,
                    'left' => [
                        'type' => 356,
                        'left' => [
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
}
