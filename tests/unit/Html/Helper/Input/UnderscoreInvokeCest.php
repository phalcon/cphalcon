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
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Input\Color;
use Phalcon\Html\Helper\Input\Date;
use Phalcon\Html\Helper\Input\DateTime;
use Phalcon\Html\Helper\Input\DateTimeLocal;
use Phalcon\Html\Helper\Input\Email;
use Phalcon\Html\Helper\Input\File;
use Phalcon\Html\Helper\Input\Hidden;
use Phalcon\Html\Helper\Input\Image;
use Phalcon\Html\Helper\Input\Input;
use Phalcon\Html\Helper\Input\Month;
use Phalcon\Html\Helper\Input\Numeric;
use Phalcon\Html\Helper\Input\Password;
use Phalcon\Html\Helper\Input\Range;
use Phalcon\Html\Helper\Input\Search;
use Phalcon\Html\Helper\Input\Submit;
use Phalcon\Html\Helper\Input\Tel;
use Phalcon\Html\Helper\Input\Text;
use Phalcon\Html\Helper\Input\Textarea;
use Phalcon\Html\Helper\Input\Time;
use Phalcon\Html\Helper\Input\Url;
use Phalcon\Html\Helper\Input\Week;
use Phalcon\Html\TagFactory;
use UnitTester;

/**
 * Class UnderscoreInvokeCest
 *
 * @package Phalcon\Tests\Unit\Html\Helper\Input
 */
class UnderscoreInvokeCest
{
    /**
     * Tests Phalcon\Html\Helper\Input :: __invoke()
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
     * Tests Phalcon\Html\Helper\Input :: __invoke() - textarea
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
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
            'color'          => ['inputColor', Color::class],
            'date'           => ['inputDate', Date::class],
            'datetime'       => ['inputDateTime', DateTime::class],
            'datetime-local' => ['inputDateTimeLocal', DateTimeLocal::class],
            'email'          => ['inputEmail', Email::class],
            'file'           => ['inputFile', File::class],
            'hidden'         => ['inputHidden', Hidden::class],
            'image'          => ['inputImage', Image::class],
            'month'          => ['inputMonth', Month::class],
            'number'         => ['inputNumeric', Numeric::class],
            'password'       => ['inputPassword', Password::class],
            'range'          => ['inputRange', Range::class],
            'search'         => ['inputSearch', Search::class],
            'submit'         => ['inputSubmit', Submit::class],
            'tel'            => ['inputTel', Tel::class],
            'text'           => ['inputText', Text::class],
            'time'           => ['inputTime', Time::class],
            'url'            => ['inputUrl', Url::class],
            'week'           => ['inputWeek', Week::class],
        ];
    }
}
