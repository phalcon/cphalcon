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

final class CacheTest extends AbstractUnitTestCase
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
    public function testMvcViewEngineVoltParserCacheSimple(): void
    {
        $source   = '{% cache \'sidebar\' %}{{ content }}{% endcache %}';
        $expected = [
            [
                'type' => 314,
                'expr' => [
                    'type' => 260,
                    'value' => 'sidebar',
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'block_statements' => [
                    [
                        'type' => 359,
                        'expr' => [
                            'type' => 265,
                            'value' => 'content',
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
    public function testMvcViewEngineVoltParserCacheLifetimeInt(): void
    {
        $source   = '{% cache \'sidebar\' 3600 %}{{ content }}{% endcache %}';
        $expected = [
            [
                'type' => 314,
                'expr' => [
                    'type' => 260,
                    'value' => 'sidebar',
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'lifetime' => [
                    'type' => 258,
                    'value' => '3600',
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'block_statements' => [
                    [
                        'type' => 359,
                        'expr' => [
                            'type' => 265,
                            'value' => 'content',
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
    public function testMvcViewEngineVoltParserCacheLifetimeVar(): void
    {
        $source   = '{% cache cacheKey lifetime %}{{ content }}{% endcache %}';
        $expected = [
            [
                'type' => 314,
                'expr' => [
                    'type' => 265,
                    'value' => 'cacheKey',
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'lifetime' => [
                    'type' => 265,
                    'value' => 'lifetime',
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'block_statements' => [
                    [
                        'type' => 359,
                        'expr' => [
                            'type' => 265,
                            'value' => 'content',
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
