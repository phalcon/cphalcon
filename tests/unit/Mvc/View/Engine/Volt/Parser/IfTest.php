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

final class IfTest extends AbstractUnitTestCase
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
    public function testMvcViewEngineVoltParserIfSimple(): void
    {
        $source   = '{% if active %}Yes{% endif %}';
        $expected = [
            [
                'type' => 300,
                'expr' => [
                    'type' => 265,
                    'value' => 'active',
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'true_statements' => [
                    [
                        'type' => 357,
                        'value' => 'Yes',
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
    public function testMvcViewEngineVoltParserIfElse(): void
    {
        $source   = '{% if active %}Yes{% else %}No{% endif %}';
        $expected = [
            [
                'type' => 300,
                'expr' => [
                    'type' => 265,
                    'value' => 'active',
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'true_statements' => [
                    [
                        'type' => 357,
                        'value' => 'Yes',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                ],
                'false_statements' => [
                    [
                        'type' => 357,
                        'value' => 'No',
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
    public function testMvcViewEngineVoltParserIfElseif(): void
    {
        $source   = '{% if status == 1 %}Active{% elseif status == 0 %}Inactive{% endif %}';
        $expected = [
            [
                'type' => 300,
                'expr' => [
                    'type' => 272,
                    'left' => [
                        'type' => 265,
                        'value' => 'status',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 258,
                        'value' => '1',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'true_statements' => [
                    [
                        'type' => 357,
                        'value' => 'Active',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    [
                        'type' => 302,
                        'expr' => [
                            'type' => 272,
                            'left' => [
                                'type' => 265,
                                'value' => 'status',
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
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    [
                        'type' => 357,
                        'value' => 'Inactive',
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
    public function testMvcViewEngineVoltParserIfElseifElse(): void
    {
        $source   = '{% if status == 1 %}Active{% elseif status == 2 %}Pending{% else %}Unknown{% endif %}';
        $expected = [
            [
                'type' => 300,
                'expr' => [
                    'type' => 272,
                    'left' => [
                        'type' => 265,
                        'value' => 'status',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 258,
                        'value' => '1',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'true_statements' => [
                    [
                        'type' => 357,
                        'value' => 'Active',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    [
                        'type' => 302,
                        'expr' => [
                            'type' => 272,
                            'left' => [
                                'type' => 265,
                                'value' => 'status',
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
                    [
                        'type' => 357,
                        'value' => 'Pending',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                ],
                'false_statements' => [
                    [
                        'type' => 357,
                        'value' => 'Unknown',
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
    public function testMvcViewEngineVoltParserIfEmptyBody(): void
    {
        $source   = '{% if condition %}{% endif %}';
        $expected = [
            [
                'type' => 300,
                'expr' => [
                    'type' => 265,
                    'value' => 'condition',
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
