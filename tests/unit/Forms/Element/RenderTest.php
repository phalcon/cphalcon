<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Forms\Element;

use Phalcon\Forms\Element\Check;
use Phalcon\Forms\Element\Date;
use Phalcon\Forms\Element\Email;
use Phalcon\Forms\Element\File;
use Phalcon\Forms\Element\Hidden;
use Phalcon\Forms\Element\Numeric;
use Phalcon\Forms\Element\Password;
use Phalcon\Forms\Element\Radio;
use Phalcon\Forms\Element\Select;
use Phalcon\Forms\Element\Submit;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Element\TextArea;
use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\Doctype;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

use function uniqid;

final class RenderTest extends AbstractUnitTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
    }

    /**
     * @return string[][]
     */
    public static function getExamples(): array
    {
        $htmlLine   = 'id=":name:" name=":name:" class="alert alert-warning"';
        $attributes = ['class' => 'alert alert-warning'];
        return [
            [
                Check::class,
                '<input type="checkbox" id=":name:" name=":name:" />',
                $attributes,
                '<input type="checkbox" ' . $htmlLine . ' />',
            ],
            [
                Date::class,
                '<input type="date" id=":name:" name=":name:" />',
                $attributes,
                '<input type="date" ' . $htmlLine . ' />',
            ],
            [
                Email::class,
                '<input type="email" id=":name:" name=":name:" />',
                $attributes,
                '<input type="email" ' . $htmlLine . ' />',
            ],
            [
                File::class,
                '<input type="file" id=":name:" name=":name:" />',
                $attributes,
                '<input type="file" ' . $htmlLine . ' />',
            ],
            [
                Hidden::class,
                '<input type="hidden" id=":name:" name=":name:" />',
                $attributes,
                '<input type="hidden" ' . $htmlLine . ' />',
            ],
            [
                Numeric::class,
                '<input type="number" id=":name:" name=":name:" />',
                $attributes,
                '<input type="number" ' . $htmlLine . ' />',
            ],
            [
                Password::class,
                '<input type="password" id=":name:" name=":name:" />',
                $attributes,
                '<input type="password" ' . $htmlLine . ' />',
            ],
            [
                Radio::class,
                '<input type="radio" id=":name:" name=":name:" />',
                $attributes,
                '<input type="radio" ' . $htmlLine . ' />',
            ],
            [
                Select::class,
                '<select id=":name:" name=":name:">' . PHP_EOL . '</select>',
                $attributes,
                '<select ' . $htmlLine . '>' . PHP_EOL . '</select>',
            ],
            [
                Submit::class,
                '<input type="submit" id=":name:" name=":name:" />',
                $attributes,
                '<input type="submit" ' . $htmlLine . ' />',
            ],
            [
                Text::class,
                '<input type="text" id=":name:" name=":name:" />',
                $attributes,
                '<input type="text" ' . $htmlLine . ' />',
            ],
            [
                TextArea::class,
                '<textarea id=":name:" name=":name:"></textarea>',
                $attributes,
                '<textarea ' . $htmlLine . '></textarea>',
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-12-05
     */
    public function testFormsElementRender(
        string $class,
        string $subject1,
        array $attributes,
        string $subject2
    ): void {
        $name    = uniqid();
        $factory = new TagFactory(new Escaper());
        /**
         * Make them all XHTML
         */
        $doctype = $factory->newInstance('doctype');
        $doctype(Doctype::XHTML5);

        $object  = new $class($name);
        $object->setTagFactory($factory);

        $expected = str_replace(":name:", $name, $subject1);
        $actual   = $object->render();

        $this->assertSame($expected, $actual);

        $actual = (string)$object;
        $this->assertSame($expected, $actual);

        /**
         * With attributes
         */
        $object->setAttributes($attributes);

        $expected = str_replace(":name:", $name, $subject2);
        $actual   = $object->render();

        $this->assertSame($expected, $actual);

        $actual = (string)$object;
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testFormsElementRenderValueFromAttributes(): void
    {
        $name    = uniqid();
        $factory = new TagFactory(new Escaper());
        $doctype = $factory->newInstance('doctype');
        $doctype(Doctype::XHTML5);

        $element = new Text($name);
        $element->setTagFactory($factory);
        $element->setDefault('original-value');

        $expected = sprintf(
            '<input type="text" id="%s" name="%s" value="overridden" />',
            $name,
            $name
        );
        $actual   = $element->render(['value' => 'overridden']);

        $this->assertSame($expected, $actual);
    }
}
