<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and optioncense information, please view the
 * LICENSE.md file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Input;

use Codeception\Example;
use Phalcon\Html\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Input\Select;
use Phalcon\Html\TagFactory;
use UnitTester;

use const PHP_EOL;

/**
 * Class SelectUnderscoreInvokeCest
 *
 * @package Phalcon\Tests\Unit\Html\Helper\Input
 */
class SelectUnderscoreInvokeCest
{
    /**
     * Tests Phalcon\Html\Helper\Input\Select :: __invoke()
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
    public function htmlHelperInputUnderscoreInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Input\Select - __invoke() - ' . $example['message']);

        $escaper = new Escaper();
        $helper  = new Select($escaper);

        $result = $helper($example['indent'], $example['delimiter'], $example['attributes']);

        if (!empty($example['selected'])) {
            $result->selected($example['selected']);
        }

        if (!empty($example['optgroup'])) {
            $result->optGroup($example['optgroup'][0], $example['optgroup'][1]);
        }

        if (!empty($example['placeholder'])) {
            $result->addPlaceholder(
                $example['placeholder'][0],
                $example['placeholder'][1],
                $example['placeholder'][2],
                $example['placeholder'][3]
            );
        }

        foreach ($example['add'] as $add) {
            $result->add($add[0], $add[1], $add[2], $add[3]);
        }

        if (!empty($example['optgroup'])) {
            $result->optGroup($example['optgroup'][0], $example['optgroup'][1]);
        }

        $expected = $example['result'];
        $actual   = (string) $result;
        $I->assertEquals($expected, $actual);

        $factory = new TagFactory($escaper);
        $locator = $factory->newInstance('inputSelect');

        $result = $locator($example['indent'], $example['delimiter'], $example['attributes']);

        if (!empty($example['selected'])) {
            $result->selected($example['selected']);
        }

        if (!empty($example['optgroup'])) {
            $result->optGroup($example['optgroup'][0], $example['optgroup'][1]);
        }

        if (!empty($example['placeholder'])) {
            $result->addPlaceholder(
                $example['placeholder'][0],
                $example['placeholder'][1],
                $example['placeholder'][2],
                $example['placeholder'][3]
            );
        }

        foreach ($example['add'] as $add) {
            $result->add($add[0], $add[1], $add[2], $add[3]);
        }

        if (!empty($example['optgroup'])) {
            $result->optGroup($example['optgroup'][0], $example['optgroup'][1]);
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
                'message'     => 'base',
                'indent'      => '    ',
                'delimiter'   => PHP_EOL,
                'selected'    => null,
                'attributes'  => ['id' => 'carsList'],
                'add'         => [
                    [
                        "> Ferrari",
                        "1",
                        ["class" => "active"],
                        false,
                    ],
                    [
                        "> Ford",
                        "2",
                        [],
                        false,
                    ],
                    [
                        "> Dodge",
                        "3",
                        [],
                        false,
                    ],
                    [
                        "> Toyota",
                        "4",
                        [],
                        false,
                    ],
                ],
                'placeholder' => [],
                'optgroup'    => [],
                'result'      => "<select id=\"carsList\">
    <option value=\"1\" class=\"active\">&gt; Ferrari</option>
    <option value=\"2\">&gt; Ford</option>
    <option value=\"3\">&gt; Dodge</option>
    <option value=\"4\">&gt; Toyota</option>
</select>",
            ],
            [
                'message'     => 'raw',
                'indent'      => '    ',
                'delimiter'   => PHP_EOL,
                'selected'    => null,
                'attributes'  => ['id' => 'carsList'],
                'add'         => [
                    [
                        "> Ferrari",
                        "1",
                        ["class" => "active"],
                        true,
                    ],
                    [
                        "> Ford",
                        "2",
                        [],
                        true,
                    ],
                    [
                        "> Dodge",
                        "3",
                        [],
                        true,
                    ],
                    [
                        "> Toyota",
                        "4",
                        [],
                        true,
                    ],
                ],
                'placeholder' => [],
                'optgroup'    => [],
                'result'      => "<select id=\"carsList\">
    <option value=\"1\" class=\"active\">> Ferrari</option>
    <option value=\"2\">> Ford</option>
    <option value=\"3\">> Dodge</option>
    <option value=\"4\">> Toyota</option>
</select>",
            ],
            [
                'message'     => 'base placeholder',
                'indent'      => '    ',
                'delimiter'   => PHP_EOL,
                'selected'    => null,
                'attributes'  => ['id' => 'carsList'],
                'add'         => [
                    [
                        "> Ferrari",
                        null,
                        ["class" => "active"],
                        false,
                    ],
                    [
                        "> Ford",
                        null,
                        [],
                        false,
                    ],
                    [
                        "> Dodge",
                        null,
                        [],
                        false,
                    ],
                    [
                        "> Toyota",
                        null,
                        [],
                        false,
                    ],
                ],
                'placeholder' => [
                    'Choose & Car...',
                    null,
                    [],
                    false,
                ],
                'optgroup'    => [],
                'result'      => "<select id=\"carsList\">
    <option>Choose &amp; Car...</option>
    <option class=\"active\">&gt; Ferrari</option>
    <option>&gt; Ford</option>
    <option>&gt; Dodge</option>
    <option>&gt; Toyota</option>
</select>",
            ],
            [
                'message'     => 'raw placeholder',
                'indent'      => '    ',
                'delimiter'   => PHP_EOL,
                'selected'    => null,
                'attributes'  => ['id' => 'carsList'],
                'add'         => [
                    [
                        "> Ferrari",
                        null,
                        ["class" => "active"],
                        true,
                    ],
                    [
                        "> Ford",
                        null,
                        [],
                        true,
                    ],
                    [
                        "> Dodge",
                        null,
                        [],
                        true,
                    ],
                    [
                        "> Toyota",
                        null,
                        [],
                        true,
                    ],
                ],
                'placeholder' => [
                    'Choose & Car...',
                    null,
                    [],
                    true,
                ],
                'optgroup'    => [],
                'result'      => "<select id=\"carsList\">
    <option>Choose & Car...</option>
    <option class=\"active\">> Ferrari</option>
    <option>> Ford</option>
    <option>> Dodge</option>
    <option>> Toyota</option>
</select>",
            ],
            [
                'message'     => 'indent and delimiter',
                'indent'      => '--',
                'delimiter'   => '+',
                'selected'    => null,
                'attributes'  => ['id' => 'carsList'],
                'add'         => [
                    [
                        "> Ferrari",
                        null,
                        ["class" => "active"],
                        false,
                    ],
                    [
                        "> Ford",
                        null,
                        [],
                        false,
                    ],
                    [
                        "> Dodge",
                        null,
                        [],
                        false,
                    ],
                    [
                        "> Toyota",
                        null,
                        [],
                        false,
                    ],
                ],
                'placeholder' => [
                    'Choose & Car...',
                    null,
                    [],
                    false,
                ],
                'optgroup'    => [],
                'result'      => "<select id=\"carsList\">+"
                    . "--<option>Choose &amp; Car...</option>+"
                    . "--<option class=\"active\">&gt; Ferrari</option>+"
                    . "--<option>&gt; Ford</option>+"
                    . "--<option>&gt; Dodge</option>+"
                    . "--<option>&gt; Toyota</option>+"
                    . "</select>",
            ],
            [
                'message'     => 'base',
                'indent'      => '    ',
                'delimiter'   => PHP_EOL,
                'selected'    => null,
                'attributes'  => ['id' => 'carsList'],
                'add'         => [
                    [
                        "> Ferrari",
                        null,
                        ["class" => "active"],
                        true,
                    ],
                    [
                        "> Ford",
                        null,
                        [],
                        true,
                    ],
                    [
                        "> Dodge",
                        null,
                        [],
                        true,
                    ],
                    [
                        "> Toyota",
                        null,
                        [],
                        true,
                    ],
                ],
                'placeholder' => [],
                'optgroup'    => [],
                'result'      => "<select id=\"carsList\">
    <option class=\"active\">> Ferrari</option>
    <option>> Ford</option>
    <option>> Dodge</option>
    <option>> Toyota</option>
</select>",
            ],
            [
                'message'     => 'raw',
                'indent'      => '    ',
                'delimiter'   => PHP_EOL,
                'selected'    => null,
                'attributes'  => ['id' => 'carsList'],
                'add'         => [
                    [
                        "> Ferrari",
                        null,
                        ["class" => "active"],
                        true,
                    ],
                    [
                        "> Ford",
                        null,
                        [],
                        true,
                    ],
                    [
                        "> Dodge",
                        null,
                        [],
                        true,
                    ],
                    [
                        "> Toyota",
                        null,
                        [],
                        true,
                    ],
                ],
                'placeholder' => [],
                'optgroup'    => [],
                'result'      => "<select id=\"carsList\">
    <option class=\"active\">> Ferrari</option>
    <option>> Ford</option>
    <option>> Dodge</option>
    <option>> Toyota</option>
</select>",
            ],
            [
                'message'     => 'indent and delimiter',
                'indent'      => '--',
                'delimiter'   => '+',
                'selected'    => null,
                'attributes'  => ['id' => 'carsList'],
                'add'         => [
                    [
                        "> Ferrari",
                        "1",
                        ["class" => "active"],
                        true,
                    ],
                    [
                        "> Ford",
                        "2",
                        [],
                        true,
                    ],
                    [
                        "> Dodge",
                        "3",
                        [],
                        true,
                    ],
                    [
                        "> Toyota",
                        "4",
                        [],
                        true,
                    ],
                ],
                'placeholder' => [
                    'Choose & Car...',
                    "0",
                    [],
                    true,
                ],
                'optgroup'    => [],
                'result'      => "<select id=\"carsList\">+"
                    . "--<option value=\"0\">Choose & Car...</option>+"
                    . "--<option value=\"1\" class=\"active\">> Ferrari</option>+"
                    . "--<option value=\"2\">> Ford</option>+"
                    . "--<option value=\"3\">> Dodge</option>+"
                    . "--<option value=\"4\">> Toyota</option>+"
                    . "</select>",
            ],
            [
                'message'     => 'optgroup',
                'indent'      => '    ',
                'delimiter'   => PHP_EOL,
                'selected'    => null,
                'attributes'  => ['id' => 'carsList'],
                'add'         => [
                    [
                        "> Ferrari",
                        "1",
                        ["class" => "active"],
                        true,
                    ],
                    [
                        "> Ford",
                        "2",
                        [],
                        true,
                    ],
                    [
                        "> Dodge",
                        "3",
                        [],
                        true,
                    ],
                    [
                        "> Toyota",
                        "4",
                        [],
                        true,
                    ],
                ],
                'placeholder' => [
                    'Choose & Car...',
                    "0",
                    [],
                    true,
                ],
                'optgroup'    => [
                    'oneLabel',
                    [
                        'class' => 'form-input',
                    ],
                ],
                'result'      => "<select id=\"carsList\">
    <optgroup class=\"form-input\" label=\"oneLabel\">
        <option value=\"0\">Choose & Car...</option>
        <option value=\"1\" class=\"active\">> Ferrari</option>
        <option value=\"2\">> Ford</option>
        <option value=\"3\">> Dodge</option>
        <option value=\"4\">> Toyota</option>
    </optgroup>
</select>",
            ],
            [
                'message'     => 'selected',
                'indent'      => '    ',
                'delimiter'   => PHP_EOL,
                'selected'    => '3',
                'attributes'  => ['id' => 'carsList'],
                'add'         => [
                    [
                        "> Ferrari",
                        "1",
                        ["class" => "active"],
                        true,
                    ],
                    [
                        "> Ford",
                        "2",
                        [],
                        true,
                    ],
                    [
                        "> Dodge",
                        "3",
                        [],
                        true,
                    ],
                    [
                        "> Toyota",
                        "4",
                        [],
                        true,
                    ],
                ],
                'placeholder' => [
                    'Choose & Car...',
                    "0",
                    [],
                    true,
                ],
                'optgroup'    => [],
                'result'      => "<select id=\"carsList\">
    <option value=\"0\">Choose & Car...</option>
    <option value=\"1\" class=\"active\">> Ferrari</option>
    <option value=\"2\">> Ford</option>
    <option value=\"3\" selected=\"selected\">> Dodge</option>
    <option value=\"4\">> Toyota</option>
</select>",
            ],
        ];
    }
}
