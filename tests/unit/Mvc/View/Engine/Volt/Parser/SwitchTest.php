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
use Phalcon\Mvc\View\Exception;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

final class SwitchTest extends AbstractUnitTestCase
{
    private Compiler $compiler;

    public function setUp(): void
    {
        $this->compiler = new Compiler();
    }

    /**
     * @return array<string, array{0: string, 1: string}>
     */
    public static function getSwitchExceptions(): array
    {
        return [
            'lack of endswitch' => [
                '{% switch foo %}',
                "Syntax error, unexpected EOF in eval code, there is a 'switch' block without 'endswitch'",
            ],
            'lack of switch' => [
                '{% case foo %}',
                'Unexpected CASE in eval code on line 1',
            ],
            'stray default' => [
                '{% default %}',
                'Syntax error, unexpected token DEFAULT(default) in eval code on line 1',
            ],
            'nested switch' => [
                "{% switch foo %}\n  {% switch %}\n  {% endswitch %}\n{% endswitch %}",
                'A nested switch detected. There is no nested switch-case '
                . 'statements support in eval code on line 2',
            ],
            'empty switch expression' => [
                "{% switch %}\n  {% case foo %}\n  {% break %}\n{% endswitch %}",
                'Syntax error, unexpected token %} in eval code on line 1',
            ],
        ];
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
     * Tests the "default" filter inside a case block of a switch
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-10
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16003
     */
    public function testMvcViewEngineVoltParserSwitchCaseDefaultFilter(): void
    {
        $source   = "{% switch x %}{% case 1 %}"
            . "{{ false|default('simple text') }}{% break %}{% endswitch %}";
        $expected = [
            [
                'type' => 411,
                'expr' => [
                    'type' => 265,
                    'value' => 'x',
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
                        'type' => 359,
                        'expr' => [
                            'type' => 124,
                            'left' => [
                                'type' => 262,
                                'file' => 'eval code',
                                'line' => 1,
                            ],
                            'right' => [
                                'type' => 350,
                                'name' => [
                                    'type' => 265,
                                    'value' => 'default',
                                    'file' => 'eval code',
                                    'line' => 1,
                                ],
                                'arguments' => [
                                    [
                                        'expr' => [
                                            'type' => 260,
                                            'value' => 'simple text',
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
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    [
                        'type' => 320,
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
     * Tests the "default" filter inside the {% default %} clause itself
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-10
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16003
     */
    public function testMvcViewEngineVoltParserSwitchDefaultClauseDefaultFilter(): void
    {
        $source   = "{% switch x %}{% default %}"
            . "{{ value|default('unknown') }}{% endswitch %}";
        $expected = [
            [
                'type' => 411,
                'expr' => [
                    'type' => 265,
                    'value' => 'x',
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'case_clauses' => [
                    [
                        'type' => 413,
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    [
                        'type' => 359,
                        'expr' => [
                            'type' => 124,
                            'left' => [
                                'type' => 265,
                                'value' => 'value',
                                'file' => 'eval code',
                                'line' => 1,
                            ],
                            'right' => [
                                'type' => 350,
                                'name' => [
                                    'type' => 265,
                                    'value' => 'default',
                                    'file' => 'eval code',
                                    'line' => 1,
                                ],
                                'arguments' => [
                                    [
                                        'expr' => [
                                            'type' => 260,
                                            'value' => 'unknown',
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

    /**
     * Tests recognize empty case clause
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-04
     */
    public function testMvcViewEngineVoltParserSwitchEmptyCase(): void
    {
        $source   = '{% switch foo%} {% case foo %} {% endswitch%}';
        $expected = [
            [
                'type' => 411,
                'expr' => [
                    'type' => 265,
                    'value' => 'foo',
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'case_clauses' => [
                    [
                        'type' => 357,
                        'value' => ' ',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    [
                        'type' => 412,
                        'expr' => [
                            'type' => 265,
                            'value' => 'foo',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    [
                        'type' => 357,
                        'value' => ' ',
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
     * Tests recognize empty case clause with empty default clause
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-04
     */
    public function testMvcViewEngineVoltParserSwitchEmptyCaseDefault(): void
    {
        $source   = '{% switch foo%} {% case foo %} {% default %} {% endswitch%}';
        $expected = [
            [
                'type' => 411,
                'expr' => [
                    'type' => 265,
                    'value' => 'foo',
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'case_clauses' => [
                    [
                        'type' => 357,
                        'value' => ' ',
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    [
                        'type' => 412,
                        'expr' => [
                            'type' => 265,
                            'value' => 'foo',
                            'file' => 'eval code',
                            'line' => 1,
                        ],
                        'file' => 'eval code',
                        'line' => 1,
                    ],
                    [
                        'type' => 357,
                        'value' => ' ',
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
                        'value' => ' ',
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
     * Tests switch-case parser exceptions: missing endswitch, missing switch,
     * stray default, nested switch and empty switch expression
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-04
     */
    #[DataProvider('getSwitchExceptions')]
    public function testMvcViewEngineVoltParserSwitchException(
        string $source,
        string $message
    ): void {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage($message);

        $this->compiler->parse($source);
    }

    /**
     * Tests recognize a multi-line switch with cases, break and default clause
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-04
     */
    public function testMvcViewEngineVoltParserSwitchMultiLine(): void
    {
        $source   = <<<'VOLT'
{% switch username %}
    {% case "Jim" %}
        Hello username
    {% case "Nik" %}
        {{ username }}!
        {% break %}
    {% default %}
        Who are you?
{% endswitch %}
VOLT;
        $expected = [
            [
                'type' => 411,
                'expr' => [
                    'type' => 265,
                    'value' => 'username',
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'case_clauses' => [
                    [
                        'type' => 357,
                        'value' => "\n    ",
                        'file' => 'eval code',
                        'line' => 2,
                    ],
                    [
                        'type' => 412,
                        'expr' => [
                            'type' => 260,
                            'value' => 'Jim',
                            'file' => 'eval code',
                            'line' => 2,
                        ],
                        'file' => 'eval code',
                        'line' => 4,
                    ],
                    [
                        'type' => 357,
                        'value' => "\n        Hello username\n    ",
                        'file' => 'eval code',
                        'line' => 4,
                    ],
                    [
                        'type' => 412,
                        'expr' => [
                            'type' => 260,
                            'value' => 'Nik',
                            'file' => 'eval code',
                            'line' => 4,
                        ],
                        'file' => 'eval code',
                        'line' => 5,
                    ],
                    [
                        'type' => 357,
                        'value' => "\n        ",
                        'file' => 'eval code',
                        'line' => 5,
                    ],
                    [
                        'type' => 359,
                        'expr' => [
                            'type' => 265,
                            'value' => 'username',
                            'file' => 'eval code',
                            'line' => 5,
                        ],
                        'file' => 'eval code',
                        'line' => 6,
                    ],
                    [
                        'type' => 357,
                        'value' => "!\n        ",
                        'file' => 'eval code',
                        'line' => 6,
                    ],
                    [
                        'type' => 320,
                        'file' => 'eval code',
                        'line' => 7,
                    ],
                    [
                        'type' => 357,
                        'value' => "\n    ",
                        'file' => 'eval code',
                        'line' => 7,
                    ],
                    [
                        'type' => 413,
                        'file' => 'eval code',
                        'line' => 9,
                    ],
                    [
                        'type' => 357,
                        'value' => "\n        Who are you?\n",
                        'file' => 'eval code',
                        'line' => 9,
                    ],
                ],
                'file' => 'eval code',
                'line' => 9,
            ],
        ];
        $actual   = $this->compiler->parse($source);
        $this->assertSame($expected, $actual);
    }
}
