<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Ul;

use Codeception\Example;
use Phalcon\Html\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Ul;
use Phalcon\Html\TagFactory;
use UnitTester;

use const PHP_EOL;

/**
 * Class UnderscoreInvokeCest
 *
 * @package Phalcon\Tests\Unit\Html\Helper\Ul
 */
class UnderscoreInvokeCest
{
    /**
     * Tests Phalcon\Html\Helper\Ul :: __invoke()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @throws Exception
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function htmlHelperUlUnderscoreInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Ul - __invoke() ' . $example['message']);

        $escaper = new Escaper();
        $helper  = new Ul($escaper);

        $result = $helper($example['indent'], $example['delimiter'], $example['attributes']);
        foreach ($example['add'] as $add) {
            $result->add($add[0], $add[1], $add[2]);
        }

        $expected = $example['result'];
        $actual   = (string) $result;
        $I->assertEquals($expected, $actual);

        $factory = new TagFactory($escaper);
        $locator = $factory->newInstance('ul');

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
                'indent'     => '    ',
                'delimiter'  => PHP_EOL,
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
                'result'     => "<ul id=\"carsList\">
    <li class=\"active\">&gt; Ferrari</li>
    <li>&gt; Ford</li>
    <li>&gt; Dodge</li>
    <li>&gt; Toyota</li>
</ul>",
            ],
            [
                'message'    => 'raw',
                'indent'     => '    ',
                'delimiter'  => PHP_EOL,
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
                'result'     => "<ul id=\"carsList\">
    <li class=\"active\">&gt; Ferrari</li>
    <li>&gt; Ford</li>
    <li>&gt; Dodge</li>
    <li>&gt; Toyota</li>
</ul>",
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
                'result'     => "<ul id=\"carsList\">+--<li class=\"active\">&gt; Ferrari</li>+"
                    . "--<li>&gt; Ford</li>+--<li>&gt; Dodge</li>+--<li>&gt; Toyota</li>+</ul>",
            ],
            [
                'message'    => 'base',
                'indent'     => '    ',
                'delimiter'  => PHP_EOL,
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
                'result'     => "<ul id=\"carsList\">
    <li class=\"active\">> Ferrari</li>
    <li>> Ford</li>
    <li>> Dodge</li>
    <li>> Toyota</li>
</ul>",
            ],
            [
                'message'    => 'raw',
                'indent'     => '    ',
                'delimiter'  => PHP_EOL,
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
                'result'     => "<ul id=\"carsList\">
    <li class=\"active\">> Ferrari</li>
    <li>> Ford</li>
    <li>> Dodge</li>
    <li>> Toyota</li>
</ul>",
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
                'result'     => "<ul id=\"carsList\">+--<li class=\"active\">> Ferrari</li>+"
                    . "--<li>> Ford</li>+--<li>> Dodge</li>+--<li>> Toyota</li>+</ul>",
            ],
        ];
    }
}
