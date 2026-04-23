<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and optioncense information, please view the
 * LICENSE.md file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Input;

use Phalcon\Html\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Input\Select;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;

use const PHP_EOL;

final class SelectUnderscoreInvokeTest extends AbstractUnitTestCase
{
    /**
     * @return array
     */
    public static function getExamples(): array
    {
        return [
            [
                '    ',
                PHP_EOL,
                null,
                ['id' => 'carsList'],
                [
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
                [],
                [],
                "<select id=\"carsList\">
    <option value=\"1\" class=\"active\">&gt; Ferrari</option>
    <option value=\"2\">&gt; Ford</option>
    <option value=\"3\">&gt; Dodge</option>
    <option value=\"4\">&gt; Toyota</option>
</select>",
            ],
            [
                '    ',
                PHP_EOL,
                null,
                ['id' => 'carsList'],
                [
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
                [],
                [],
                "<select id=\"carsList\">
    <option value=\"1\" class=\"active\">> Ferrari</option>
    <option value=\"2\">> Ford</option>
    <option value=\"3\">> Dodge</option>
    <option value=\"4\">> Toyota</option>
</select>",
            ],
            [
                '    ',
                PHP_EOL,
                null,
                ['id' => 'carsList'],
                [
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
                [
                    'Choose & Car...',
                    null,
                    [],
                    false,
                ],
                [],
                "<select id=\"carsList\">
    <option>Choose &amp; Car...</option>
    <option class=\"active\">&gt; Ferrari</option>
    <option>&gt; Ford</option>
    <option>&gt; Dodge</option>
    <option>&gt; Toyota</option>
</select>",
            ],
            [
                '    ',
                PHP_EOL,
                null,
                ['id' => 'carsList'],
                [
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
                [
                    'Choose & Car...',
                    null,
                    [],
                    true,
                ],
                [],
                "<select id=\"carsList\">
    <option>Choose & Car...</option>
    <option class=\"active\">> Ferrari</option>
    <option>> Ford</option>
    <option>> Dodge</option>
    <option>> Toyota</option>
</select>",
            ],
            [
                '--',
                '+',
                null,
                ['id' => 'carsList'],
                [
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
                [
                    'Choose & Car...',
                    null,
                    [],
                    false,
                ],
                [],
                "<select id=\"carsList\">+"
                . "--<option>Choose &amp; Car...</option>+"
                . "--<option class=\"active\">&gt; Ferrari</option>+"
                . "--<option>&gt; Ford</option>+"
                . "--<option>&gt; Dodge</option>+"
                . "--<option>&gt; Toyota</option>+"
                . "</select>",
            ],
            [
                '    ',
                PHP_EOL,
                null,
                ['id' => 'carsList'],
                [
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
                [],
                [],
                "<select id=\"carsList\">
    <option class=\"active\">> Ferrari</option>
    <option>> Ford</option>
    <option>> Dodge</option>
    <option>> Toyota</option>
</select>",
            ],
            [
                '    ',
                PHP_EOL,
                null,
                ['id' => 'carsList'],
                [
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
                [],
                [],
                "<select id=\"carsList\">
    <option class=\"active\">> Ferrari</option>
    <option>> Ford</option>
    <option>> Dodge</option>
    <option>> Toyota</option>
</select>",
            ],
            [
                '--',
                '+',
                null,
                ['id' => 'carsList'],
                [
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
                [
                    'Choose & Car...',
                    "0",
                    [],
                    true,
                ],
                [],
                "<select id=\"carsList\">+"
                . "--<option value=\"0\">Choose & Car...</option>+"
                . "--<option value=\"1\" class=\"active\">> Ferrari</option>+"
                . "--<option value=\"2\">> Ford</option>+"
                . "--<option value=\"3\">> Dodge</option>+"
                . "--<option value=\"4\">> Toyota</option>+"
                . "</select>",
            ],
            [
                '    ',
                PHP_EOL,
                null,
                ['id' => 'carsList'],
                [
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
                [
                    'Choose & Car...',
                    "0",
                    [],
                    true,
                ],
                [
                    'oneLabel',
                    [
                        'class' => 'form-input',
                    ],
                ],
                "<select id=\"carsList\">
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
                '    ',
                PHP_EOL,
                '3',
                ['id' => 'carsList'],
                [
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
                [
                    'Choose & Car...',
                    "0",
                    [],
                    true,
                ],
                [],
                "<select id=\"carsList\">
    <option value=\"0\">Choose & Car...</option>
    <option value=\"1\" class=\"active\">> Ferrari</option>
    <option value=\"2\">> Ford</option>
    <option value=\"3\" selected=\"selected\">> Dodge</option>
    <option value=\"4\">> Toyota</option>
</select>",
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testHtmlHelperInputUnderscoreInvoke(
        string $indent,
        string $delimiter,
        mixed $selected,
        array $attributes,
        array $add,
        array $placeholder,
        array $optgroup,
        string $expected
    ): void {
        $escaper = new Escaper();
        $helper  = new Select($escaper);

        $result = $helper($indent, $delimiter, $attributes);

        if (!empty($selected)) {
            $result->selected($selected);
        }

        if (!empty($optgroup)) {
            $result->optGroup($optgroup[0], $optgroup[1]);
        }

        if (!empty($placeholder)) {
            $result->addPlaceholder(
                $placeholder[0],
                $placeholder[1],
                $placeholder[2],
                $placeholder[3]
            );
        }

        foreach ($add as $addItem) {
            $result->add($addItem[0], $addItem[1], $addItem[2], $addItem[3]);
        }

        if (!empty($optgroup)) {
            $result->optGroup($optgroup[0], $optgroup[1]);
        }

        $actual = (string)$result;
        $this->assertSame($expected, $actual);

        $factory = new TagFactory($escaper);
        $locator = $factory->newInstance('inputSelect');

        $result = $locator($indent, $delimiter, $attributes);

        if (!empty($selected)) {
            $result->selected($selected);
        }

        if (!empty($optgroup)) {
            $result->optGroup($optgroup[0], $optgroup[1]);
        }

        if (!empty($placeholder)) {
            $result->addPlaceholder(
                $placeholder[0],
                $placeholder[1],
                $placeholder[2],
                $placeholder[3]
            );
        }

        foreach ($add as $addItem) {
            $result->add($addItem[0], $addItem[1], $addItem[2], $addItem[3]);
        }

        if (!empty($optgroup)) {
            $result->optGroup($optgroup[0], $optgroup[1]);
        }

        $actual = (string)$result;
        $this->assertSame($expected, $actual);
    }
}
