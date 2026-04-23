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

final class DoTest extends AbstractUnitTestCase
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
    public function testMvcViewEngineVoltParserDo(): void
    {
        $source   = '{% do myFunction() %}';
        $expected = [
            [
                'type' => 316,
                'expr' => [
                    'type' => 350,
                    'name' => [
                        'type' => 265,
                        'value' => 'myFunction',
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
    public function testMvcViewEngineVoltParserDoMethod(): void
    {
        $source   = '{% do object.method(arg) %}';
        $expected = [
            [
                'type' => 316,
                'expr' => [
                    'type' => 350,
                    'name' => [
                        'type' => 46,
                        'left' => [
                            'type' => 265,
                            'value' => 'object',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'right' => [
                            'type' => 265,
                            'value' => 'method',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'arguments' => [
                        [
                            'expr' => [
                                'type' => 265,
                                'value' => 'arg',
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
}
