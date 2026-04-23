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

namespace Phalcon\Tests\Unit\Html\TagFactory;

use Phalcon\Html\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Anchor;
use Phalcon\Html\Helper\Base;
use Phalcon\Html\Helper\Breadcrumbs;
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
use Phalcon\Tests\AbstractUnitTestCase;

use function uniqid;

/**
 * Class NewInstanceTest extends AbstractUnitTestCase
 *
 * @package Phalcon\Tests\Unit\Html\TagFactory
 */
final class NewInstanceTest extends AbstractUnitTestCase
{
    /**
     * Returns the example data
     */
    public static function getData(): array
    {
        return [
            ["a", Anchor::class],
            ["base", Base::class],
            ["body", Body::class],
            ["breadcrumbs", Breadcrumbs::class],
            ["button", Button::class],
            ["close", Close::class],
            ["element", Element::class],
            ["form", Form::class],
            ["img", Img::class],
            ["inputColor", Color::class],
            ["inputDate", Date::class],
            ["inputDateTime", DateTime::class],
            ["inputDateTimeLocal", DateTimeLocal::class],
            ["inputEmail", Email::class],
            ["inputFile", File::class],
            ["inputHidden", Hidden::class],
            ["inputImage", Image::class],
            ["inputInput", Input::class],
            ["inputMonth", Month::class],
            ["inputNumeric", Numeric::class],
            ["inputPassword", Password::class],
            ["inputRange", Range::class],
            ["inputSelect", Select::class],
            ["inputSearch", Search::class],
            ["inputSubmit", Submit::class],
            ["inputTel", Tel::class],
            ["inputText", Text::class],
            ["inputTextarea", Textarea::class],
            ["inputTime", Time::class],
            ["inputUrl", Url::class],
            ["inputWeek", Week::class],
            ["label", Label::class],
            ["link", Link::class],
            ["meta", Meta::class],
            ["ol", Ol::class],
            ["script", Script::class],
            ["style", Style::class],
            ["title", Title::class],
            ["ul", Ul::class],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFilterTagFactoryNewInstanceException(): void
    {
        $name = uniqid();
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Service ' . $name . ' is not registered');

        $escaper = new Escaper();
        $factory = new TagFactory($escaper);
        $factory->newInstance($name);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFilterTagFactoryNewInstanceExceptionProxy(): void
    {
        $name = uniqid();
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Service ' . $name . ' is not registered');

        $escaper = new Escaper();
        $factory = new TagFactory($escaper);
        $factory->$name();
    }

    /**
     * @dataProvider getData
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testFilterTagFactoryNewInstanceServices(
        string $name,
        string $class
    ): void {
        $escaper = new Escaper();
        $factory = new TagFactory($escaper);

        $service = $factory->newInstance($name);

        $this->assertInstanceOf($class, $service);
    }
}
