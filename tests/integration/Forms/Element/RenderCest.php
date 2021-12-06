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

namespace Phalcon\Tests\Integration\Forms\Element;

use Codeception\Example;
use IntegrationTester;
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
use Phalcon\Html\TagFactory;

use function uniqid;

class RenderCest
{
//    /**
//     * Tests Phalcon\Forms\Element\Check :: render() with parameters
//     *
//     * @author Sid Roberts <https://github.com/SidRoberts>
//     * @since  2019-05-23
//     */
//    public function formsElementCheckRenderWithParameters(IntegrationTester $I)
//    {
//        $I->wantToTest('Forms\Element\Check - render() with parameters');
//
//        $element = new Check(
//            'fantastic',
//            [
//                'class' => 'fancy',
//            ]
//        );
//
//        $I->assertSame(
//            '<input type="checkbox" id="fantastic" name="fantastic" class="fancy" />',
//            $element->render()
//        );
//    }

    /**
     * Tests Phalcon\Forms\Element\* :: clear()
     *
     * @dataProvider getExamples
     *
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-12-05
     */
    public function formsElementRender(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Forms\Element\* - render() - ' . $example[0]);

        $name    = uniqid();
        $class   = $example[1];
        $factory = new TagFactory(new Escaper());
        $object  = new $class($name);
        $object->setTagFactory($factory);

        $expected = str_replace(":name:", $name, $example[2]);
        $actual   = $object->render();

var_dump($actual);
var_dump((string) $object);

        $I->assertSame($expected, $actual);

//        $actual = (string) $object;
//        $I->assertSame($expected, $actual);
    }

    /**
     * @return string[][]
     */
    private function getExamples(): array
    {
        return [
//            [
//                "Check",
//                Check::class,
//                '<input type="checkbox" id=":name:" name=":name:" />',
//            ],
            [
                "Date",
                Date::class,
                '<input type="date" id=":name:" name=":name:" />',
            ],
//            [
//                "Email",
//                Email::class,
//                "",
//            ],
//            [
//                "File",
//                File::class,
//                "",
//            ],
//            [
//                "Hidden",
//                Hidden::class,
//                "",
//            ],
//            [
//                "Numeric",
//                Numeric::class,
//                "",
//            ],
//            [
//                "Password",
//                Password::class,
//                "",
//            ],
//            [
//                "Radio",
//                Radio::class,
//                "",
//            ],
//            [
//                "Select",
//                Select::class,
//                "",
//            ],
//            [
//                "Submit",
//                Submit::class,
//                "",
//            ],
//            [
//                "Text",
//                Text::class,
//                "",
//            ],
//            [
//                "TextArea",
//                TextArea::class,
//                "",
//            ],
        ];
    }
}
