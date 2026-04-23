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

final class SwitchTest extends AbstractUnitTestCase
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
    public function testMvcViewEngineVoltParserSwitchCase(): void
    {
        $source   = '{% switch status %}{% case 1 %}Active{% case 2 %}Pending{% default %}Unknown{% endswitch %}';
        $expected = [
            [
                'type' => 411,
                'expr' => [
                    'type' => 265,
                    'value' => 'status',
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'case_clauses' => [
                    [
                        'type' => 412,
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
                        'type' => 357,
                        'value' => 'Active',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    [
                        'type' => 412,
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
                        'type' => 357,
                        'value' => 'Pending',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    [
                        'type' => 413,
                        'file' => 'eval code',
                        'line' => 1,
                    ],
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
    public function testMvcViewEngineVoltParserSwitchEmpty(): void
    {
        $source   = '{% switch status %}{% endswitch %}';
        $expected = [
            [
                'type' => 411,
                'expr' => [
                    'type' => 265,
                    'value' => 'status',
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
