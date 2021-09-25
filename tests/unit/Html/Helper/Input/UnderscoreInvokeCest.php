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
use Phalcon\Escaper;
use Phalcon\Factory\Exception as ExceptionAlias;
use Phalcon\Html\Helper\Input\Input;
use Phalcon\Html\Helper\Input\Textarea;
use Phalcon\Html\TagFactory;
use UnitTester;

class UnderscoreInvokeCest
{
    /**
     * Tests Phalcon\Html\Helper\Input :: __invoke()
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @throws ExceptionAlias
     *
     * @dataProvider getExamples
     * @since        2020-01-07
     */
    public function htmlHelperInputUnderscoreInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Input - __invoke() - ' . $example['message']);
        $classes = $this->getClasses();

        foreach ($classes as $name => $class) {
            $escaper = new Escaper();
            $helper  = new $class[1]($escaper);

            $result = $helper($example['name'], $example['value'], $example['attributes']);

            if (isset($example["newValue"])) {
                $result->setValue($example['newValue']);
            }

            $expected = sprintf($example['render'], $name);
            $actual   = (string) $result;
            $I->assertEquals($expected, $actual);

            $factory = new TagFactory($escaper);
            $locator = $factory->newInstance($class[0]);
            $result  = $locator($example['name'], $example['value'], $example['attributes']);

            if (isset($example["newValue"])) {
                $result->setValue($example['newValue']);
            }

            $actual = (string) $result;
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Phalcon\Html\Helper\Input :: __invoke() - input
     *
     * @param UnitTester $I
     *
     * @since  2020-01-07
     */
    public function htmlHelperInputUnderscoreInvokeInput(UnitTester $I)
    {
        $I->wantToTest('Html\Helper\Input - __invoke() - input week');

        $escaper = new Escaper();
        $helper  = new Input($escaper);

        $helper->setType('week');
        $result = $helper('x_name');

        $I->assertEquals(
            '<input type="week" id="x_name" name="x_name" />',
            (string) $result
        );
    }

    /**
     * Tests Phalcon\Html\Helper\Input :: __invoke() - textarea
     *
     * @param UnitTester $I
     *
     * @throws ExceptionAlias
     * @since  2020-01-07
     */
    public function htmlHelperInputUnderscoreInvokeTextarea(UnitTester $I)
    {
        $I->wantToTest('Html\Helper\Input - __invoke() - textarea');

        $escaper = new Escaper();
        $helper  = new Textarea($escaper);

        $result = $helper(
            'x_name',
            'test text area',
            [
                'cols' => "10",
                'rows' => "5",
            ]
        );

        $expected = '<textarea id="x_name" name="x_name" cols="10" rows="5">' .
            'test text area</textarea>';
        $actual   = (string) $result;
        $I->assertEquals($expected, $actual);

        $factory = new TagFactory($escaper);
        $locator = $factory->newInstance('inputTextarea');
        $result  = $locator(
            'x_name',
            'test text area',
            [
                'cols' => "10",
                'rows' => "5",
            ]
        );

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
                'message'    => 'only name',
                'name'       => 'x_name',
                'value'      => null,
                'attributes' => [],
                'newValue'   => null,
                'render'     => '<input type="%s" id="x_name" name="x_name" />',
            ],
            [
                'message'    => 'name and id',
                'name'       => 'x_name',
                'value'      => null,
                'attributes' => [
                    'id' => 'x_new_id',
                ],
                'newValue'   => null,
                'render'     => '<input type="%s" id="x_new_id" name="x_name" />',
            ],
            [
                'message'    => 'name and id initial value',
                'name'       => 'x_name',
                'value'      => "24",
                'attributes' => [
                    'id' => 'x_new_id',
                ],
                'newValue'   => null,
                'render'     => '<input type="%s" id="x_new_id" name="x_name" value="24" />',
            ],
            [
                'message'    => 'name and id initial value set value',
                'name'       => 'x_name',
                'value'      => "24",
                'attributes' => [
                    'id' => 'x_new_id',
                ],
                'newValue'   => "48",
                'render'     => '<input type="%s" id="x_new_id" name="x_name" value="48" />',
            ],
        ];
    }

    /**
     * @return array
     */
    private function getClasses(): array
    {
        return [
            'color'          => [
                'inputColor',
                'Phalcon\\Html\\Helper\\Input\\Color',
            ],
            'date'           => [
                'inputDate',
                'Phalcon\\Html\\Helper\\Input\\Date',
            ],
            'datetime'       => [
                'inputDateTime',
                'Phalcon\\Html\\Helper\\Input\\DateTime',
            ],
            'datetime-local' => [
                'inputDateTimeLocal',
                'Phalcon\\Html\\Helper\\Input\\DateTimeLocal',
            ],
            'email'          => [
                'inputEmail',
                'Phalcon\\Html\\Helper\\Input\\Email',
            ],
            'file'           => [
                'inputFile',
                'Phalcon\\Html\\Helper\\Input\\File',
            ],
            'hidden'         => [
                'inputHidden',
                'Phalcon\\Html\\Helper\\Input\\Hidden',
            ],
            'image'          => [
                'inputImage',
                'Phalcon\\Html\\Helper\\Input\\Image',
            ],
            'month'          => [
                'inputMonth',
                'Phalcon\\Html\\Helper\\Input\\Month',
            ],
            'numeric'        => [
                'inputNumeric',
                'Phalcon\\Html\\Helper\\Input\\Numeric',
            ],
            'password'       => [
                'inputPassword',
                'Phalcon\\Html\\Helper\\Input\\Password',
            ],
            'range'          => [
                'inputRange',
                'Phalcon\\Html\\Helper\\Input\\Range',
            ],
            'search'         => [
                'inputSearch',
                'Phalcon\\Html\\Helper\\Input\\Search',
            ],
            'submit'         => [
                'inputSubmit',
                'Phalcon\\Html\\Helper\\Input\\Submit',
            ],
            'tel'            => [
                'inputTel',
                'Phalcon\\Html\\Helper\\Input\\Tel',
            ],
            'text'           => [
                'inputText',
                'Phalcon\\Html\\Helper\\Input\\Text',
            ],
            'time'           => [
                'inputTime',
                'Phalcon\\Html\\Helper\\Input\\Time',
            ],
            'url'            => [
                'inputUrl',
                'Phalcon\\Html\\Helper\\Input\\Url',
            ],
            'week'           => [
                'inputWeek',
                'Phalcon\\Html\\Helper\\Input\\Week',
            ],
        ];
    }
}
