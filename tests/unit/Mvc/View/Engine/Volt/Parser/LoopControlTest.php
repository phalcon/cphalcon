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

final class LoopControlTest extends AbstractUnitTestCase
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
    public function testMvcViewEngineVoltParserBreak(): void
    {
        $source   = '{% for item in items %}{% if item.skip %}{% break %}{% endif %}{{ item }}{% endfor %}';
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
                        'type' => 300,
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
                                'value' => 'skip',
                                'file' => 'eval code',
                                'line' => 1,
                            ],
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'true_statements' => [
                            [
                                'type' => 320,
                                'file' => 'eval code',
                                'line' => 1,
                            ],
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
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
    public function testMvcViewEngineVoltParserContinue(): void
    {
        $source   = '{% for item in items %}{% if item.skip %}{% continue %}{% endif %}{{ item }}{% endfor %}';
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
                        'type' => 300,
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
                                'value' => 'skip',
                                'file' => 'eval code',
                                'line' => 1,
                            ],
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'true_statements' => [
                            [
                                'type' => 319,
                                'file' => 'eval code',
                                'line' => 1,
                            ],
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
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
}
