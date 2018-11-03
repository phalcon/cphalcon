<?php

namespace Phalcon\Test\Unit\Forms\Element;

use Phalcon\Forms\Element\Text;
use Phalcon\Tag;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Forms\Element\TextTest
 * Tests the \Phalcon\Test\Unit\Forms\Element\Text component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Forms\Element
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class TextTest extends UnitTest
{
    /**
     * executed after each test
     */
    protected function _after()
    {
        // Setting the doctype to XHTML5 for other tests to run smoothly
        Tag::setDocType(Tag::XHTML5);
    }

    /**
     * Tests Text::render
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10398
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-07-17
     */
    public function testCreatingTextElementWithNameSimilarToTheFormMethods()
    {
        $this->specify('Text::render does not return expected result', function ($name) {
            $element = new Text($name);

            expect($element->getName())->equals($name);
            expect($element->render())->equals(sprintf('<input type="text" id="%s" name="%s" />', $name, $name));
            expect($element->getValue())->null();
        }, ['examples' => $this->nameLikeFormMethodsProvider()]);
    }

    protected function nameLikeFormMethodsProvider()
    {
        return [
            ['validation'],
            ['action'],
            ['useroption'],
            ['useroptions'],
            ['entity'],
            ['elements'],
            ['messages'],
            ['messagesfor'],
            ['label'],
            ['value'],
            ['di'],
            ['eventsmanager'],
        ];
    }

    public function testIssue1210()
    {
        $this->specify(
            "Labels are not properly rendered",
            function () {
                $element = new Text("test");

                $element->setLabel("Test");

                $actual   = $element->label();
                $expected = '<label for="test">Test</label>';

                expect($actual)->equals($expected);
            }
        );
    }

    public function testIssue2045()
    {
        $this->specify(
            "Attributes are not properly rendered",
            function () {
                $element = new Text("name");

                $element->setAttributes(
                    [
                        "class" => "big-input",
                    ]
                );

                $element->setAttribute("id", null);

                $expected = '<input type="text" name="name" class="big-input" />';

                expect($element->render())->equals($expected);
            }
        );
    }

    public function testPrepareAttributesNoDefault()
    {
        $this->specify(
            "Prepared attributes are not properly rendered",
            function () {
                $element1 = new Text("name");

                $element1->setLabel("name");

                $actual = $element1->prepareAttributes(
                    [
                        "class" => "big-input",
                    ]
                );

                $expected = [
                    "name",
                    "class" => "big-input",
                ];

                expect($actual)->equals($expected);
            }
        );
    }

    public function testFormElementEmpty()
    {
        $this->specify(
            "Default/empty values are not set properly",
            function () {
                $element = new Text("name");

                expect($element->getLabel())->null();
                expect($element->getAttributes())->equals([]);
            }
        );
    }

    public function testFormElement()
    {
        $this->specify(
            "Form elements do not store attributes/labels properly",
            function () {
                $element = new Text("name");

                $element->setLabel('name');
                $element->setAttributes(array('class' => 'big-input'));
                $element->setAttribute('placeholder', 'Type the name');

                expect($element->getLabel())->equals('name');
                expect($element->getAttributes())->equals(array(
                    'class' => 'big-input',
                    'placeholder' => 'Type the name'
                ));

                expect($element->getAttribute('class'))->equals('big-input');
                expect($element->getAttribute('placeholder', 'the name'))->equals('Type the name');
                expect($element->getAttribute('lang', 'en'))->equals('en');

                $element->setLabel(0);
                expect($element->label())->equals('<label for="name">0</label>');
            }
        );
    }

    public function testFormPrepareAttributes()
    {
        $this->specify(
            "Attributes are not prepared properly",
            function () {
                $element1 = new Text("name");

                $element1->setLabel('name');

                expect($element1->prepareAttributes())->equals(['name']);
            }
        );
    }

    public function testFormPrepareAttributesDefault()
    {
        $this->specify(
            "Attributes are not prepared properly (2)",
            function () {
                $element1 = new Text("name");

                $element1->setLabel('name');
                $element1->setAttributes(['class' => 'big-input']);

                expect($element1->prepareAttributes())->equals(['name', 'class' => 'big-input']);
            }
        );
    }

    public function testFormOptions()
    {
        $this->specify(
            "Text elements don't properly store user options or attributes",
            function () {
                $element1 = new Text("name");

                $element1->setAttributes(array('class' => 'big-input'));
                $element1->setUserOptions(array('some' => 'value'));

                expect($element1->getUserOptions())->equals(array('some' => 'value'));

                expect($element1->getUserOption('some'))->equals('value');

                expect($element1->getUserOption('some-non'))->null();

                expect($element1->getUserOption('some-non', 'default'))->equals('default');
            }
        );
    }
}
