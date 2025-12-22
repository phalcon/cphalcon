<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Input;

use Codeception\Example;
use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\Doctype;
use Phalcon\Html\Helper\Input\Checkbox;
use Phalcon\Html\Helper\Input\Radio;
use UnitTester;

/**
 * Class CheckboxUnderscoreInvokeCest
 *
 * @package Phalcon\Tests\Unit\Html\Helper\Input
 */
class CheckboxUnderscoreInvokeCest
{
    /**
     * Tests Phalcon\Html\Helper\Input\Checkbox :: __invoke()
     *
     * @dataProvider getExamplesCheckbox
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function htmlHelperInputCheckboxUnderscoreInvoke(UnitTester $I, Example $example)
    {
        $name        = $example[0];
        $value       = $example[1];
        $attributes  = $example[2];
        $label       = $example[3];
        $render      = $example[4];
        $renderXhtml = $example[5];

        $escaper = new Escaper();
        $doctype = new Doctype();
        $helper  = new Checkbox($escaper, $doctype);

        $result = $helper($name, $value, $attributes);

        if (null !== $label) {
            $result->label($label);
        }

        $expected = $render;
        $actual   = (string)$result;
        $I->assertSame($expected, $actual);

        $doctype(Doctype::XHTML5);
        $result = $helper($name, $value, $attributes);

        if (null !== $label) {
            $result->label($label);
        }

        $expected = $renderXhtml;
        $actual   = (string)$result;
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Helper\Input\Checkbox :: __invoke()
     *
     * @dataProvider getExamplesRadio
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function htmlHelperInputRadioUnderscoreInvoke(UnitTester $I, Example $example)
    {
        $name        = $example[0];
        $value       = $example[1];
        $attributes  = $example[2];
        $label       = $example[3];
        $render      = $example[4];
        $renderXhtml = $example[5];

        $escaper = new Escaper();
        $doctype = new Doctype();
        $helper  = new Radio($escaper, $doctype);

        $result = $helper($name, $value, $attributes);

        if (null !== $label) {
            $result->label($label);
        }

        $expected = $render;
        $actual   = (string)$result;
        $I->assertSame($expected, $actual);

        $doctype(Doctype::XHTML5);
        $result = $helper($name, $value, $attributes);

        if (null !== $label) {
            $result->label($label);
        }

        $expected = $renderXhtml;
        $actual   = (string)$result;
        $I->assertSame($expected, $actual);
    }

    /**
     * @param string $type
     *
     * @return array
     */
    private function getExamples(string $type): array
    {
        return [
            [
                'x_name',
                null,
                [],
                null,
                '<input type="'
                . $type
                . '" id="x_name" name="x_name">',
                '<input type="'
                . $type
                . '" id="x_name" name="x_name" />',
            ],
            [
                'x_name',
                null,
                [],
                [],
                '<label for="x_name"><input type="'
                . $type
                . '" id="x_name" name="x_name"></label>',
                '<label for="x_name"><input type="'
                . $type
                . '" id="x_name" name="x_name" /></label>',
            ],
            [
                'x_name',
                null,
                [
                    'id' => 'x_id',
                ],
                [],
                '<label for="x_id"><input type="'
                . $type
                . '" id="x_id" name="x_name"></label>',
                '<label for="x_id"><input type="'
                . $type
                . '" id="x_id" name="x_name" /></label>',
            ],
            [
                'x_name',
                null,
                [
                    'id' => 'x_id',
                ],
                [
                    "text" => "some text",
                ],
                '<label for="x_id"><input type="'
                . $type
                . '" id="x_id" name="x_name">some text</label>',
                '<label for="x_id"><input type="'
                . $type
                . '" id="x_id" name="x_name" />some text</label>',
            ],
            [
                'x_name',
                null,
                [
                    'id'        => 'x_id',
                    'unchecked' => 'no',
                ],
                [
                    "text" => "some text",
                ],
                '<hidden name="x_name" value="no">' .
                '<label for="x_id"><input type="'
                . $type
                . '" id="x_id" name="x_name">some text</label>',
                '<hidden name="x_name" value="no">' .
                '<label for="x_id"><input type="'
                . $type
                . '" id="x_id" name="x_name" />some text</label>',
            ],
            [
                'x_name',
                "yes",
                [
                    'id'        => 'x_id',
                    'unchecked' => 'no',
                    'checked'   => 'yes',
                ],
                [
                    "text" => "some text",
                ],
                '<hidden name="x_name" value="no">' .
                '<label for="x_id">' .
                '<input type="'
                . $type
                . '" id="x_id" name="x_name" value="yes" checked="checked">some text</label>',
                '<hidden name="x_name" value="no">' .
                '<label for="x_id">' .
                '<input type="'
                . $type
                . '" id="x_id" name="x_name" value="yes" checked="checked" />some text</label>',
            ],
            [
                'x_name',
                "yes",
                [
                    'id' => 'x_id',
                ],
                [
                    "text" => "some text",
                ],
                '<label for="x_id">' .
                '<input type="'
                . $type
                . '" id="x_id" name="x_name" value="yes">some text</label>',
                '<label for="x_id">' .
                '<input type="'
                . $type
                . '" id="x_id" name="x_name" value="yes" />some text</label>',
            ],
        ];
    }

    /**
     * @return array
     */
    private function getExamplesCheckbox(): array
    {
        return $this->getExamples('checkbox');
    }

    /**
     * @return array
     */
    private function getExamplesRadio(): array
    {
        return $this->getExamples('radio');
    }
}
