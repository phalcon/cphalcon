<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Input;

use Phalcon\Html\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Doctype;
use Phalcon\Html\Helper\Input\Color;
use Phalcon\Html\Helper\Input\Date;
use Phalcon\Html\Helper\Input\DateTime;
use Phalcon\Html\Helper\Input\DateTimeLocal;
use Phalcon\Html\Helper\Input\Email;
use Phalcon\Html\Helper\Input\File;
use Phalcon\Html\Helper\Input\Hidden;
use Phalcon\Html\Helper\Input\Image;
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
use Phalcon\Tests\AbstractUnitTestCase;

use function sprintf;

final class UnderscoreInvokeTest extends AbstractUnitTestCase
{
    /**
     * @return array
     */
    public static function getClasses(): array
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

    /**
     * @return array
     */
    public static function getExamples(): array
    {
        return [
            [
                'x_name',
                null,
                [],
                null,
                '<input type="%s" id="x_name" name="x_name">',
                '<input type="%s" id="x_name" name="x_name" />',
            ],
            [
                'x_name',
                null,
                [
                    'id' => 'x_new_id',
                ],
                null,
                '<input type="%s" id="x_new_id" name="x_name">',
                '<input type="%s" id="x_new_id" name="x_name" />',
            ],
            [
                'x_name',
                "24",
                [
                    'id' => 'x_new_id',
                ],
                null,
                '<input type="%s" id="x_new_id" name="x_name" value="24">',
                '<input type="%s" id="x_new_id" name="x_name" value="24" />',
            ],
            [
                'x_name',
                "24",
                [
                    'id' => 'x_new_id',
                ],
                "48",
                '<input type="%s" id="x_new_id" name="x_name" value="48">',
                '<input type="%s" id="x_new_id" name="x_name" value="48" />',
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
        string $name,
        ?string $value,
        array $attributes,
        mixed $newValue,
        string $render,
        string $renderXhtml
    ): void {
        $classes = $this->getClasses();

        foreach ($classes as $className => $class) {
            $escaper = new Escaper();
            $doctype = new Doctype();
            $helper  = new $class[1]($escaper, $doctype);

            $result = $helper($name, $value, $attributes);

            if (null !== $newValue) {
                $result->setValue($newValue);
            }

            $expected = sprintf($render, $className);
            $actual   = (string)$result;
            $this->assertSame($expected, $actual);

            $doctype(Doctype::XHTML5);

            $result = $helper($name, $value, $attributes);

            if (null !== $newValue) {
                $result->setValue($newValue);
            }

            $expected = sprintf($renderXhtml, $className);
            $actual   = (string)$result;
            $this->assertSame($expected, $actual);

            /**
             * TagFactory
             */
            $factory = new TagFactory($escaper);
            $doctype = $factory->newInstance('doctype');
            $locator = $factory->newInstance($class[0]);
            $result  = $locator($name, $value, $attributes);

            if (null !== $newValue) {
                $result->setValue($newValue);
            }

            $expected = sprintf($render, $className);
            $actual   = (string)$result;
            $this->assertSame($expected, $actual);

            $doctype(Doctype::XHTML5);

            $result  = $locator($name, $value, $attributes);

            if (null !== $newValue) {
                $result->setValue($newValue);
            }

            $expected = sprintf($renderXhtml, $className);
            $actual   = (string)$result;
            $this->assertSame($expected, $actual);
        }
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testHtmlHelperInputUnderscoreInvokeTextarea(): void
    {
        $escaper = new Escaper();
        $doctype = new Doctype();
        $helper  = new Textarea($escaper, $doctype);

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
        $actual   = (string)$result;
        $this->assertSame($expected, $actual);

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

        $actual = (string)$result;
        $this->assertSame($expected, $actual);
    }
}
