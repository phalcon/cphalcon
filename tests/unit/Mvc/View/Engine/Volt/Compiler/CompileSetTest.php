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

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt\Compiler;

use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Tests\AbstractUnitTestCase;

class CompileSetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewEngineVoltCompilerCompileSet(): void
    {
        $volt = new Compiler();

        $source = [
            "type"        => 306,
            "assignments" => [
                [
                    "variable" => [
                        "type"  => 265,
                        "value" => "a",
                        "file"  => "eval code",
                        "line"  => 1,
                    ],
                    "op"       => 61,
                    "expr"     => [
                        "type" => 360,
                        "left" => [
                            [
                                "expr" => [
                                    "type"  => 258,
                                    "value" => "1",
                                    "file"  => "eval code",
                                    "line"  => 1,
                                ],
                                "name" => "first",
                                "file" => "eval code",
                                "line" => 1,
                            ],
                            [
                                "expr" => [
                                    "type"  => 258,
                                    "value" => "2",
                                    "file"  => "eval code",
                                    "line"  => 1,
                                ],
                                "name" => "second",
                                "file" => "eval code",
                                "line" => 1,
                            ],
                            [
                                "expr" => [
                                    "type"  => 258,
                                    "value" => "3",
                                    "file"  => "eval code",
                                    "line"  => 1,
                                ],
                                "name" => "third",
                                "file" => "eval code",
                                "line" => 1,
                            ],
                        ],
                        "file" => "eval code",
                        "line" => 1,
                    ],
                    "file"     => "eval code",
                    "line"     => 1,
                ],
            ],
        ];

        $expected = "<?php \$a = ['first' => 1, 'second' => 2, 'third' => 3]; ?>";
        $actual   = $volt->compileSet($source);
        $this->assertSame($expected, $actual);
    }
}
