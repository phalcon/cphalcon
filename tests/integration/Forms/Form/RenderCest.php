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

namespace Phalcon\Tests\Integration\Forms\Form;

use IntegrationTester;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\Doctype;
use Phalcon\Html\TagFactory;
use stdClass;

class RenderCest
{
    /**
     * Tests Form::render
     *
     * @param IntegrationTester $I
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10398
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-07-17
     */
    public function formsFormRenderMethods(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - render() - similar method names');

        /**
         * Make them all XHTML
         */
        $factory = new TagFactory(new Escaper());
        $doctype = $factory->newInstance('doctype');
        $doctype(Doctype::XHTML5);

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
            /**
             * Make them all XHTML
             */
            $factory = new TagFactory(new Escaper());
            $doctype = $factory->newInstance('doctype');
            $doctype(Doctype::XHTML5);

            $form->setTagFactory($factory);

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
            $I->assertSame($expected, $actual);

            $actual = $form->getValue($name);
            $I->assertNull($actual);
        }
    }

    /**
     * Tests Form::render
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-07-17
     */
    public function formsFormRenderIndirect(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - render() - indirect element');

        $form = new Form();
        $factory = new TagFactory(new Escaper());
        $doctype = $factory->newInstance('doctype');
        $doctype(Doctype::XHTML5);

        $form->setTagFactory($factory);

        $element = new Text("name");

        $form->add($element);

        $expected = '<input type="text" id="name" name="name" />';
        $actual   = $form->render('name');
        $I->assertSame($expected, $actual);


        $expected = '<input type="text" id="name" name="name" class="big-input" />';
        $actual = $form->render(
            'name',
            [
                'class' => 'big-input',
            ]
        );
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Form::render
     *
     * @param IntegrationTester $I
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1190
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-07-17
     */
    public function formsFormRenderEscaped(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - render() - escaped');

        $object = new stdClass();
        $object->title = 'Hello "world!"';

        $form = new Form($object);
        $form->setTagFactory(new TagFactory(new Escaper()));

        $element = new Text("title");

        $form->add($element);

        $expected = '<input type="text" id="title" name="title" value="Hello &quot;world!&quot;" />';
        $actual   = $form->render('title');
        $I->assertSame($expected, $actual);
    }
}
