<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Ol;

use Codeception\Example;
use Phalcon\Html\Escaper;
use Phalcon\Factory\Exception as ExceptionAlias;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Ol;
use Phalcon\Html\TagFactory;
use UnitTester;

use const PHP_EOL;

class UnderscoreInvokeCest
{
    /**
     * Tests Phalcon\Html\Helper\Ol :: __invoke()
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @throws ExceptionAlias
     * @throws Exception
     *
     * @dataProvider getExamples
     * @since        2020-01-06
     */
    public function htmlHelperOlUnderscoreInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Ol - __invoke() ' . $example['message']);

        $escaper = new Escaper();
        $helper  = new Ol($escaper);

        $result = $helper($example['indent'], $example['delimiter'], $example['attributes']);
        foreach ($example['add'] as $add) {
            $result->add($add[0], $add[1], $add[2]);
        }

        $expected = $example['result'];
        $actual   = (string) $result;
        $I->assertEquals($expected, $actual);

        $factory = new TagFactory($escaper);
        $locator = $factory->newInstance('ol');

        $result = $locator($example['indent'], $example['delimiter'], $example['attributes']);
        foreach ($example['add'] as $add) {
            $result->add($add[0], $add[1], $add[2]);
        }

        $actual = (string) $result;
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            [
                'message'    => 'base',
                'indent'     => null,
                'delimiter'  => null,
                'attributes' => ['id' => 'carsList'],
                'add'        => [
                    [
                        "> Ferrari",
                        ["class" => "active"],
                        false,
                    ],
                    [
                        "> Ford",
                        [],
                        false,
                    ],
                    [
                        "> Dodge",
                        [],
                        false,
                    ],
                    [
                        "> Toyota",
                        [],
                        false,
                    ],
                ],
                'result'     => "<ol id=\"carsList\">" . PHP_EOL .
                    "    <li class=\"active\">&gt; Ferrari</li>" . PHP_EOL .
                    "    <li>&gt; Ford</li>" . PHP_EOL .
                    "    <li>&gt; Dodge</li>" . PHP_EOL .
                    "    <li>&gt; Toyota</li>" . PHP_EOL .
                    "</ol>",
            ],
            [
                'message'    => 'raw',
                'indent'     => null,
                'delimiter'  => null,
                'attributes' => ['id' => 'carsList'],
                'add'        => [
                    [
                        "> Ferrari",
                        ["class" => "active"],
                        false,
                    ],
                    [
                        "> Ford",
                        [],
                        false,
                    ],
                    [
                        "> Dodge",
                        [],
                        false,
                    ],
                    [
                        "> Toyota",
                        [],
                        false,
                    ],
                ],
                'result'     => "<ol id=\"carsList\">" . PHP_EOL .
                    "    <li class=\"active\">&gt; Ferrari</li>" . PHP_EOL .
                    "    <li>&gt; Ford</li>" . PHP_EOL .
                    "    <li>&gt; Dodge</li>" . PHP_EOL .
                    "    <li>&gt; Toyota</li>" . PHP_EOL .
                    "</ol>",
            ],
            [
                'message'    => 'indent and delimiter',
                'indent'     => '--',
                'delimiter'  => '+',
                'attributes' => ['id' => 'carsList'],
                'add'        => [
                    [
                        "> Ferrari",
                        ["class" => "active"],
                        false,
                    ],
                    [
                        "> Ford",
                        [],
                        false,
                    ],
                    [
                        "> Dodge",
                        [],
                        false,
                    ],
                    [
                        "> Toyota",
                        [],
                        false,
                    ],
                ],
                'result'     => "<ol id=\"carsList\">+--<li class=\"active\">&gt; Ferrari</li>+"
                    . "--<li>&gt; Ford</li>+--<li>&gt; Dodge</li>+--<li>&gt; Toyota</li>+</ol>",
            ],
            [
                'message'    => 'base',
                'indent'     => null,
                'delimiter'  => null,
                'attributes' => ['id' => 'carsList'],
                'add'        => [
                    [
                        "> Ferrari",
                        ["class" => "active"],
                        true,
                    ],
                    [
                        "> Ford",
                        [],
                        true,
                    ],
                    [
                        "> Dodge",
                        [],
                        true,
                    ],
                    [
                        "> Toyota",
                        [],
                        true,
                    ],
                ],
                'result'     => "<ol id=\"carsList\">" . PHP_EOL .
                    "    <li class=\"active\">> Ferrari</li>" . PHP_EOL .
                    "    <li>> Ford</li>" . PHP_EOL .
                    "    <li>> Dodge</li>" . PHP_EOL .
                    "    <li>> Toyota</li>" . PHP_EOL .
                    "</ol>",
            ],
            [
                'message'    => 'raw',
                'indent'     => null,
                'delimiter'  => null,
                'attributes' => ['id' => 'carsList'],
                'add'        => [
                    [
                        "> Ferrari",
                        ["class" => "active"],
                        true,
                    ],
                    [
                        "> Ford",
                        [],
                        true,
                    ],
                    [
                        "> Dodge",
                        [],
                        true,
                    ],
                    [
                        "> Toyota",
                        [],
                        true,
                    ],
                ],
                'result'     => "<ol id=\"carsList\">" . PHP_EOL .
                    "    <li class=\"active\">> Ferrari</li>" . PHP_EOL .
                    "    <li>> Ford</li>" . PHP_EOL .
                    "    <li>> Dodge</li>" . PHP_EOL .
                    "    <li>> Toyota</li>" . PHP_EOL .
                    "</ol>",
            ],
            [
                'message'    => 'indent and delimiter',
                'indent'     => '--',
                'delimiter'  => '+',
                'attributes' => ['id' => 'carsList'],
                'add'        => [
                    [
                        "> Ferrari",
                        ["class" => "active"],
                        true,
                    ],
                    [
                        "> Ford",
                        [],
                        true,
                    ],
                    [
                        "> Dodge",
                        [],
                        true,
                    ],
                    [
                        "> Toyota",
                        [],
                        true,
                    ],
                ],
                'result'     => "<ol id=\"carsList\">+--<li class=\"active\">> Ferrari</li>+"
                    . "--<li>> Ford</li>+--<li>> Dodge</li>+--<li>> Toyota</li>+</ol>",
            ],
        ];
    }
}
