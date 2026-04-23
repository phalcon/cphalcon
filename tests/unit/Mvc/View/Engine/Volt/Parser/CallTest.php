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

final class CallTest extends AbstractUnitTestCase
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
    public function testMvcViewEngineVoltParserCallNoArgs(): void
    {
        $source   = '{% call myMacro() %}{% endcall %}';
        $expected = [
            [
                'type' => 325,
                'name' => [
                    'type' => 265,
                    'value' => 'myMacro',
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
    public function testMvcViewEngineVoltParserCallWithArgs(): void
    {
        $source   = '{% call render(item) %}block content{% endcall %}';
        $expected = [
            [
                'type' => 325,
                'name' => [
                    'type' => 265,
                    'value' => 'render',
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'arguments' => [
                    [
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
                'caller' => [
                    [
                        'type' => 357,
                        'value' => 'block content',
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
