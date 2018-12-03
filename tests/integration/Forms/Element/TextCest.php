<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Forms\Element;

use IntegrationTester;
use Phalcon\Forms\Element\Text;
use Phalcon\Tag;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class TextCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiEscaper();
        $this->setDiUrl();
    }

    /**
     * executed after each test
     */
    public function _after(IntegrationTester $I)
    {
        // Setting the doctype to XHTML5 for other tests to run smoothly
        Tag::setDocType(Tag::XHTML5);
    }

    /**
     * Tests Text::render
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10398
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-07-17
     */
    public function testCreatingTextElementWithNameSimilarToTheFormMethods(IntegrationTester $I)
    {
        $examples = [
            'validation',
            'action',
            'useroption',
            'useroptions',
            'entity',
            'elements',
            'messages',
            'messagesfor',
            'label',
            'value',
            'di',
            'eventsmanager',
        ];

        foreach ($examples as $name) {
            $element = new Text($name);

            $expected = $name;
            $actual   = $element->getName();
            $I->assertEquals($expected, $actual);

            $expected = sprintf('<input type="text" id="%s" name="%s" />', $name, $name);
            $actual   = $element->render();
            $I->assertEquals($expected, $actual);

            $actual = $element->getValue();
            $I->assertNull($actual);
        };
    }

    public function testIssue1210(IntegrationTester $I)
    {
        $element = new Text("test");
        $element->setLabel("Test");

        $actual   = $element->label();
        $expected = '<label for="test">Test</label>';
        $I->assertEquals($expected, $actual);
    }

    public function testIssue2045(IntegrationTester $I)
    {
        $element = new Text("name");
        $element->setAttributes(
            [
                "class" => "big-input",
            ]
        );

        $element->setAttribute("id", null);

        $expected = '<input type="text" name="name" class="big-input" />';
        $actual   = $element->render();
        $I->assertEquals($expected, $actual);
    }

    public function testPrepareAttributesNoDefault(IntegrationTester $I)
    {
        $element1 = new Text("name");
        $element1->setLabel("name");

        $actual   = $element1->prepareAttributes(
            [
                "class" => "big-input",
            ]
        );
        $expected = [
            "name",
            "class" => "big-input",
        ];
        $I->assertEquals($expected, $actual);
    }

    public function testFormElementEmpty(IntegrationTester $I)
    {
        $element = new Text("name");

        $actual = $element->getLabel();
        $I->assertNull($actual);

        $expected = [];
        $actual   = $element->getAttributes();
        $I->assertEquals($expected, $actual);
    }

    public function testFormElement(IntegrationTester $I)
    {
        $element = new Text("name");

        $element->setLabel('name');
        $element->setAttributes(['class' => 'big-input']);
        $element->setAttribute('placeholder', 'Type the name');

        $expected = 'name';
        $actual   = $element->getLabel();
        $I->assertEquals($expected, $actual);

        $expected = [
            'class'       => 'big-input',
            'placeholder' => 'Type the name',
        ];
        $actual   = $element->getAttributes();
        $I->assertEquals($expected, $actual);

        $expected = 'big-input';
        $actual   = $element->getAttribute('class');
        $I->assertEquals($expected, $actual);

        $expected = 'Type the name';
        $actual   = $element->getAttribute('placeholder', 'the name');
        $I->assertEquals($expected, $actual);

        $expected = 'en';
        $actual   = $element->getAttribute('lang', 'en');
        $I->assertEquals($expected, $actual);

        $element->setLabel(0);
        $expected = '<label for="name">0</label>';
        $actual   = $element->label();
        $I->assertEquals($expected, $actual);
    }

    public function testFormPrepareAttributes(IntegrationTester $I)
    {
        $element1 = new Text("name");

        $element1->setLabel('name');

        $expected = ['name'];
        $actual   = $element1->prepareAttributes();
        $I->assertEquals($expected, $actual);
    }

    public function testFormPrepareAttributesDefault(IntegrationTester $I)
    {
        $element1 = new Text("name");

        $element1->setLabel('name');
        $element1->setAttributes(['class' => 'big-input']);

        $expected = ['name', 'class' => 'big-input'];
        $actual   = $element1->prepareAttributes();
        $I->assertEquals($expected, $actual);
    }

    public function testFormOptions(IntegrationTester $I)
    {
        $element1 = new Text("name");

        $element1->setAttributes(['class' => 'big-input']);
        $element1->setUserOptions(['some' => 'value']);

        $expected = ['some' => 'value'];
        $actual   = $element1->getUserOptions();
        $I->assertEquals($expected, $actual);

        $expected = 'value';
        $actual   = $element1->getUserOption('some');
        $I->assertEquals($expected, $actual);

        $actual = $element1->getUserOption('some-non');
        $I->assertNull($actual);

        $expected = 'default';
        $actual   = $element1->getUserOption('some-non', 'default');
        $I->assertEquals($expected, $actual);
    }
}
