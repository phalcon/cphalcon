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
use Phalcon\Html\Helper\Input\Generic;
use Phalcon\Html\Helper\Input\Textarea;
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
            'color'          => ['inputColor', 'color'],
            'date'           => ['inputDate', 'date'],
            'datetime'       => ['inputDateTime', 'datetime'],
            'datetime-local' => ['inputDateTimeLocal', 'datetime-local'],
            'email'          => ['inputEmail', 'email'],
            'file'           => ['inputFile', 'file'],
            'hidden'         => ['inputHidden', 'hidden'],
            'image'          => ['inputImage', 'image'],
            'month'          => ['inputMonth', 'month'],
            'number'         => ['inputNumeric', 'number'],
            'password'       => ['inputPassword', 'password'],
            'range'          => ['inputRange', 'range'],
            'search'         => ['inputSearch', 'search'],
            'submit'         => ['inputSubmit', 'submit'],
            'tel'            => ['inputTel', 'tel'],
            'text'           => ['inputText', 'text'],
            'time'           => ['inputTime', 'time'],
            'url'            => ['inputUrl', 'url'],
            'week'           => ['inputWeek', 'week'],
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
            $helper  = new Generic($escaper, $doctype, $class[1]);

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
