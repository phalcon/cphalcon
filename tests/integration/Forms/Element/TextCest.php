<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Integration\Forms\Element;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Forms\Element\Text;
use Phalcon\Tag;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class TextCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiService('escaper');
        $this->setDiService('url');
    }

    /**
     * executed after each test
     */
    public function _after(IntegrationTester $I)
    {
        // Setting the doctype to XHTML5 for other tests to run smoothly
        Tag::setDocType(
            Tag::XHTML5
        );
    }

    /**
     * Tests Text::render
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10398
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2016-07-17
     *
     * @dataProvider testCreatingTextElementWithNameSimilarToTheFormMethodsProvider
     */
    public function testCreatingTextElementWithNameSimilarToTheFormMethods(IntegrationTester $I, Example $example)
    {
        $name = $example[0];

        $element = new Text($name);


        $I->assertEquals(
            $name,
            $element->getName()
        );


        $expected = sprintf(
            '<input type="text" id="%s" name="%s" />',
            $name,
            $name
        );

        $I->assertEquals(
            $expected,
            $element->render()
        );

        $I->assertNull(
            $element->getValue()
        );
    }

    public function testIssue2045(IntegrationTester $I)
    {
        $element = new Text('name');

        $element->setAttributes(
            [
                'class' => 'big-input',
            ]
        );

        $element->setAttribute('id', null);

        $I->assertEquals(
            '<input type="text" name="name" class="big-input" />',
            $element->render()
        );
    }

    public function testPrepareAttributesNoDefault(IntegrationTester $I)
    {
        $element1 = new Text('name');

        $element1->setLabel('name');

        $expected = [
            'name',
            'class' => 'big-input',
        ];

        $actual = $element1->prepareAttributes(
            [
                'class' => 'big-input',
            ]
        );

        $I->assertEquals($expected, $actual);
    }

    public function testFormElementEmpty(IntegrationTester $I)
    {
        $element = new Text('name');

        $I->assertEquals(
            [],
            $element->getAttributes()
        );
    }

    public function testFormElement(IntegrationTester $I)
    {
        $element = new Text('name');

        $element->setLabel('name');

        $element->setAttributes(
            [
                'class' => 'big-input',
            ]
        );

        $element->setAttribute('placeholder', 'Type the name');


        $I->assertEquals(
            'name',
            $element->getLabel()
        );


        $expected = [
            'class'       => 'big-input',
            'placeholder' => 'Type the name',
        ];

        $I->assertEquals(
            $expected,
            $element->getAttributes()
        );


        $I->assertEquals(
            'big-input',
            $element->getAttribute('class')
        );

        $I->assertEquals(
            'Type the name',
            $element->getAttribute('placeholder', 'the name')
        );

        $I->assertEquals(
            'en',
            $element->getAttribute('lang', 'en')
        );


        $element->setLabel(0);

        $I->assertEquals(
            '<label for="name">0</label>',
            $element->label()
        );
    }

    public function testFormPrepareAttributes(IntegrationTester $I)
    {
        $element1 = new Text('name');

        $element1->setLabel('name');

        $expected = ['name'];

        $I->assertEquals(
            $expected,
            $element1->prepareAttributes()
        );
    }

    public function testFormPrepareAttributesDefault(IntegrationTester $I)
    {
        $element1 = new Text('name');

        $element1->setLabel('name');

        $element1->setAttributes(
            [
                'class' => 'big-input',
            ]
        );

        $expected = [
            'name',
            'class' => 'big-input',
        ];

        $I->assertEquals(
            $expected,
            $element1->prepareAttributes()
        );
    }

    public function testFormOptions(IntegrationTester $I)
    {
        $element1 = new Text('name');

        $element1->setAttributes(
            [
                'class' => 'big-input',
            ]
        );

        $options = [
            'some' => 'value',
        ];

        $element1->setUserOptions($options);

        $I->assertEquals(
            $options,
            $element1->getUserOptions()
        );


        $I->assertEquals(
            'value',
            $element1->getUserOption('some')
        );

        $I->assertNull(
            $element1->getUserOption('some-non')
        );

        $I->assertEquals(
            'default',
            $element1->getUserOption('some-non', 'default')
        );
    }

    private function testCreatingTextElementWithNameSimilarToTheFormMethodsProvider(): array
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
}
