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

namespace Phalcon\Test\Unit\Html\TagFactory;

use Codeception\Example;
use Phalcon\Escaper;
use Phalcon\Factory\Exception;
use Phalcon\Html\Helper\Anchor;
use Phalcon\Html\Helper\Base;
use Phalcon\Html\Helper\Body;
use Phalcon\Html\Helper\Button;
use Phalcon\Html\Helper\Close;
use Phalcon\Html\Helper\Element;
use Phalcon\Html\Helper\Form;
use Phalcon\Html\Helper\Img;
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
use Phalcon\Html\Helper\Input\Select;
use Phalcon\Html\Helper\Input\Submit;
use Phalcon\Html\Helper\Input\Tel;
use Phalcon\Html\Helper\Input\Text;
use Phalcon\Html\Helper\Input\Textarea;
use Phalcon\Html\Helper\Input\Time;
use Phalcon\Html\Helper\Input\Url;
use Phalcon\Html\Helper\Input\Week;
use Phalcon\Html\Helper\Label;
use Phalcon\Html\Helper\Link;
use Phalcon\Html\Helper\Meta;
use Phalcon\Html\Helper\Ol;
use Phalcon\Html\Helper\Script;
use Phalcon\Html\Helper\Style;
use Phalcon\Html\Helper\Title;
use Phalcon\Html\Helper\Ul;
use Phalcon\Html\TagFactory;
use UnitTester;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Tag\TagFactory :: newInstance() - services
     *
     * @dataProvider getData
     */
    public function filterTagFactoryNewInstanceServices(UnitTester $I, Example $example)
    {
        $I->wantToTest('Tag\TagLocatorFactory - newInstance() - services ' . $example[0]);
        $escaper = new Escaper();
        $factory = new TagFactory($escaper);
        $service = $factory->newInstance($example[0]);

        $class = $example[1];
        $I->assertInstanceOf($class, $service);
    }

    /**
     * Tests Phalcon\Storage\SerializerFactory :: newInstance() - exception
     *
     * @throws Exception
     * @since  2019-05-04
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function filterTagFactoryNewInstanceException(UnitTester $I)
    {
        $I->wantToTest('Tag\TagFactory - newInstance() - exception');

        $I->expectThrowable(
            new Exception('Service unknown is not registered'),
            function () {
                $escaper = new Escaper();
                $factory = new TagFactory($escaper);
                $service = $factory->newInstance('unknown');
            }
        );
    }

    /**
     * Returns the example data
     */
    private function getData(): array
    {
        return [
            ["a",                  Anchor::class],
            ["base",               Base::class],
            ["body",               Body::class],
            ["button",             Button::class],
            ["close",              Close::class],
            ["element",            Element::class],
            ["form",               Form::class],
            ["img",                Img::class],
            ["inputColor",         Color::class],
            ["inputDate",          Date::class],
            ["inputDateTime",      DateTime::class],
            ["inputDateTimeLocal", DateTimeLocal::class],
            ["inputEmail",         Email::class],
            ["inputFile",          File::class],
            ["inputHidden",        Hidden::class],
            ["inputImage",         Image::class],
            ["inputInput",         Input::class],
            ["inputMonth",         Month::class],
            ["inputNumeric",       Numeric::class],
            ["inputPassword",      Password::class],
            ["inputRange",         Range::class],
            ["inputSelect",        Select::class],
            ["inputSearch",        Search::class],
            ["inputSubmit",        Submit::class],
            ["inputTel",           Tel::class],
            ["inputText",          Text::class],
            ["inputTextarea",      Textarea::class],
            ["inputTime",          Time::class],
            ["inputUrl",           Url::class],
            ["inputWeek",          Week::class],
            ["label",              Label::class],
            ["link",               Link::class],
            ["meta",               Meta::class],
            ["ol",                 Ol::class],
            ["script",             Script::class],
            ["style",              Style::class],
            ["title",              Title::class],
            ["ul",                 Ul::class],
        ];
    }
}
