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

final class TernaryTest extends AbstractUnitTestCase
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
    public function testMvcViewEngineVoltParserExprTernary(): void
    {
        $source   = '{{ condition ? \'yes\' : \'no\' }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 366,
                    'ternary' => [
                        'type' => 265,
                        'value' => 'condition',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'left' => [
                        'type' => 260,
                        'value' => 'yes',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 260,
                        'value' => 'no',
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
    public function testMvcViewEngineVoltParserExprTernaryVar(): void
    {
        $source   = '{{ active ? activeLabel : inactiveLabel }}';
        $expected = [
            [
                'type' => 359,
                'expr' => [
                    'type' => 366,
                    'ternary' => [
                        'type' => 265,
                        'value' => 'active',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'left' => [
                        'type' => 265,
                        'value' => 'activeLabel',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    'right' => [
                        'type' => 265,
                        'value' => 'inactiveLabel',
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
