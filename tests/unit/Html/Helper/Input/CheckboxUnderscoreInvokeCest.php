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
use Phalcon\Html\Helper\Input\Checkbox;
use Phalcon\Html\Helper\Input\Radio;
use UnitTester;

class CheckboxUnderscoreInvokeCest
{
    /**
     * Tests Phalcon\Html\Helper\Input\Checkbox :: __invoke()
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @dataProvider getExamplesCheckbox
     * @since        2020-01-07
     */
    public function htmlHelperInputCheckboxUnderscoreInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Input\Checkbox - __invoke() - ' . $example['message']);

        $escaper = new Escaper();
        $helper  = new Checkbox($escaper);

        $result = $helper($example['name'], $example['value'], $example['attributes']);

        if (null !== $example['label']) {
            $result->label($example['label']);
        }

        $I->assertEquals(
            sprintf($example['render'], $example['render']),
            (string) $result
        );
    }

    /**
     * Tests Phalcon\Html\Helper\Input\Checkbox :: __invoke()
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @dataProvider getExamplesRadio
     * @since        2020-01-07
     */
    public function htmlHelperInputRadioUnderscoreInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Input\Radio - __invoke() - ' . $example['message']);

        $escaper = new Escaper();
        $helper  = new Radio($escaper);

        $result = $helper($example['name'], $example['value'], $example['attributes']);

        if (null !== $example['label']) {
            $result->label($example['label']);
        }

        $I->assertEquals(
            sprintf($example['render'], $example['render']),
            (string) $result
        );
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

    /**
     * @param string $type
     *
     * @return array
     */
    private function getExamples(string $type): array
    {
        return [
            [
                'message'    => 'only name',
                'name'       => 'x_name',
                'value'      => null,
                'attributes' => [],
                'label'      => null,
                'render'     => '<input type="'
                    . $type
                    . '" id="x_name" name="x_name" />',
            ],
            [
                'message'    => 'with label',
                'name'       => 'x_name',
                'value'      => null,
                'attributes' => [],
                'label'      => [],
                'render'     => '<label for="x_name"><input type="'
                    . $type
                    . '" id="x_name" name="x_name" /></label>',
            ],
            [
                'message'    => 'with label different id',
                'name'       => 'x_name',
                'value'      => null,
                'attributes' => [
                    'id' => 'x_id',
                ],
                'label'      => [],
                'render'     => '<label for="x_id"><input type="'
                    . $type
                    . '" id="x_id" name="x_name" /></label>',
            ],
            [
                'message'    => 'with label text',
                'name'       => 'x_name',
                'value'      => null,
                'attributes' => [
                    'id' => 'x_id',
                ],
                'label'      => [
                    "text" => "some text",
                ],
                'render'     => '<label for="x_id"><input type="'
                    . $type
                    . '" id="x_id" name="x_name" />some text</label>',
            ],
            [
                'message'    => 'with unchecked',
                'name'       => 'x_name',
                'value'      => null,
                'attributes' => [
                    'id'        => 'x_id',
                    'unchecked' => 'no',
                ],
                'label'      => [
                    "text" => "some text",
                ],
                'render'     => '<hidden name="x_name" value="no">' .
                    '<label for="x_id"><input type="'
                    . $type
                    . '" id="x_id" name="x_name" />some text</label>',
            ],
            [
                'message'    => 'with value and checked',
                'name'       => 'x_name',
                'value'      => "yes",
                'attributes' => [
                    'id'        => 'x_id',
                    'unchecked' => 'no',
                    'checked'   => 'yes',
                ],
                'label'      => [
                    "text" => "some text",
                ],
                'render'     => '<hidden name="x_name" value="no">' .
                    '<label for="x_id">' .
                    '<input type="'
                    . $type
                    . '" id="x_id" name="x_name" value="yes" checked="checked" />some text</label>',
            ],
            [
                'message'    => 'with value and label',
                'name'       => 'x_name',
                'value'      => "yes",
                'attributes' => [
                    'id' => 'x_id',
                ],
                'label'      => [
                    "text" => "some text",
                ],
                'render'     => '<label for="x_id">' .
                    '<input type="'
                    . $type
                    . '" id="x_id" name="x_name" value="yes" />some text</label>',
            ],
        ];
    }
}
