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

namespace Phalcon\Test\Integration\Forms\Form;

use IntegrationTester;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Tag;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class RenderCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiEscaper();
        $this->setDiUrl();

        Tag::setDocType(
            Tag::XHTML5
        );
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
     * Tests Form::render
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10398
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-07-17
     */
    public function testCreatingElementsWithNameSimilarToTheFormMethods(IntegrationTester $I)
    {
        $names = [
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

        foreach ($names as $name) {
            $form    = new Form();
            $element = new Text($name);


            $expected = $name;
            $actual   = $element->getName();

            $I->assertEquals($expected, $actual);


            $form->add($element);


            $expected = sprintf(
                '<input type="text" id="%s" name="%s" />',
                $name,
                $name
            );

            $actual = $form->render($name);

            $I->assertEquals($expected, $actual);


            $actual = $form->getValue($name);

            $I->assertNull($actual);
        }
    }

    public function testFormIndirectElementRender(IntegrationTester $I)
    {
        $form = new Form();

        $form->add(
            new Text('name')
        );

        $expected = '<input type="text" id="name" name="name" />';
        $actual   = $form->render('name');

        $I->assertEquals($expected, $actual);


        $expected = '<input type="text" id="name" name="name" class="big-input" />';

        $actual = $form->render(
            'name',
            [
                'class' => 'big-input',
            ]
        );

        $I->assertEquals($expected, $actual);
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/1190
     */
    public function testIssue1190(IntegrationTester $I)
    {
        $object = new \stdClass();

        $object->title = 'Hello "world!"';

        $form = new Form($object);

        $form->add(
            new Text('title')
        );

        $I->assertEquals(
            '<input type="text" id="title" name="title" value="Hello &quot;world!&quot;" />',
            $form->render('title')
        );
    }
}
