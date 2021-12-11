<?php

/*
    +------------------------------------------------------------------------+
    | Phalcon Framework                                                      |
    +------------------------------------------------------------------------+
    | Copyright (c) 2011-2015 Phalcon Team (http://www.phalcon.io)       |
    +------------------------------------------------------------------------+
    | This source file is subject to the New BSD License that is bundled     |
    | with this package in the file LICENSE.txt.                             |
    |                                                                        |
    | If you did not receive a copy of the license and are unable to         |
    | obtain it through the world-wide-web, please send an email             |
    | to license@phalcon.io so we can send you a copy immediately.       |
    +------------------------------------------------------------------------+
    | Authors: Andres Gutierrez <andres@phalcon.io>                      |
    |          Eduar Carvajal <eduar@phalcon.io>                         |
    +------------------------------------------------------------------------+
*/

namespace Phalcon\Tests\Integration\Forms;

use IntegrationTester;
use Phalcon\Forms\Element\Radio;
use Phalcon\Forms\Element\Select;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Messages\Message;
use Phalcon\Tag;
use Phalcon\Tests\Fixtures\Forms\ContactFormPublicProperties;
use Phalcon\Tests\Fixtures\Forms\ContactFormSettersGetters;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Validation\Validator\PresenceOf;

class FormsCest
{

    public function testFormElementRender(IntegrationTester $I)
    {
        $element1 = new Text('name');

        $element1->setAttributes(
            [
                'class' => 'big-input',
            ]
        );


        $element2 = new Radio('radio');

        $element2->setAttributes(
            [
                'value' => 0,
            ]
        );


        $I->assertEquals(
            '<input type="text" id="name" name="name" class="big-input">',
            $element1->render()
        );

        $I->assertEquals(
            '<input type="text" id="name" name="name" class="big-input">',
            (string) $element1
        );

        $I->assertEquals(
            '<input type="radio" id="radio" name="radio" value="0">',
            (string) $element2
        );
    }

    public function testFormRenderEntity(IntegrationTester $I)
    {
        //Second element
        $address = new Text('address');

        $address->addValidator(
            new PresenceOf(
                [
                    'message' => 'The address is required',
                ]
            )
        );

        $telephone = new Text('telephone');

        $telephone->addValidator(
            new PresenceOf(
                [
                    'message' => 'The telephone is required',
                ]
            )
        );

        $form = new Form(
            new ContactFormPublicProperties()
        );

        $form->add($address);
        $form->add($telephone);

        $I->assertEquals(
            $form->render('address'),
            '<input type="text" id="address" name="address" value="Cr. 12 #12-82">'
        );

        $I->assertEquals(
            $form->render('telephone'),
            '<input type="text" id="telephone" name="telephone" value="+44 124 82122">'
        );
    }

    public function testFormRenderEntityGetters(IntegrationTester $I)
    {
        //Second element
        $address = new Text('address');

        $address->addValidator(
            new PresenceOf(
                [
                    'message' => 'The address is required',
                ]
            )
        );

        $telephone = new Text('telephone');

        $telephone->addValidator(
            new PresenceOf(
                [
                    'message' => 'The telephone is required',
                ]
            )
        );

        $form = new Form(
            new ContactFormSettersGetters()
        );

        $form->add($address);
        $form->add($telephone);

        $I->assertEquals(
            $form->render('address'),
            '<input type="text" id="address" name="address" value="Cr. 12 #12-82">'
        );

        $I->assertEquals(
            $form->render('telephone'),
            '<input type="text" id="telephone" name="telephone" value="+44 124 82122">'
        );
    }

    public function testFormValidatorEntity(IntegrationTester $I)
    {
        //Second element
        $address = new Text('address');

        $address->addValidator(
            new PresenceOf(
                [
                    'message' => 'The address is required',
                ]
            )
        );

        $telephone = new Text('telephone');

        $telephone->addValidator(
            new PresenceOf(
                [
                    'message' => 'The telephone is required',
                ]
            )
        );

        $form = new Form(
            new ContactFormPublicProperties()
        );

        $form->add($address);
        $form->add($telephone);

        $I->assertTrue(
            $form->isValid(
                [
                    'telephone' => '+44 124 82122',
                    'address'   => 'hello',
                ]
            )
        );
    }

    public function testFormValidatorEntityBind(IntegrationTester $I)
    {
        //Second element
        $address = new Text('address');

        $address->addValidator(
            new PresenceOf(
                [
                    'message' => 'The address is required',
                ]
            )
        );

        $telephone = new Text('telephone');

        $telephone->addValidator(
            new PresenceOf(
                [
                    'message' => 'The telephone is required',
                ]
            )
        );

        $entity = new ContactFormPublicProperties();

        $form = new Form();

        $form->add($address);
        $form->add($telephone);

        $form->bind(
            [
                'telephone' => '+44 123 45678',
                'address'   => 'hello',
            ],
            $entity
        );

        $I->assertTrue(
            $form->isValid()
        );

        $I->assertEquals(
            '+44 123 45678',
            $entity->telephone
        );

        $I->assertEquals(
            'hello',
            $entity->address
        );
    }

    public function testFormValidatorEntityBindSetters(IntegrationTester $I)
    {
        //Second element
        $address = new Text('address');

        $address->addValidator(
            new PresenceOf(
                [
                    'message' => 'The address is required',
                ]
            )
        );

        $telephone = new Text('telephone');

        $telephone->addValidator(
            new PresenceOf(
                [
                    'message' => 'The telephone is required',
                ]
            )
        );

        $entity = new ContactFormSettersGetters();

        $form = new Form();

        $form->add($address);
        $form->add($telephone);

        $form->bind(
            [
                'telephone' => '+44 123 45678',
                'address'   => 'hello',
            ],
            $entity
        );


        $I->assertTrue(
            $form->isValid()
        );

        $I->assertEquals(
            '+44 123 45678',
            $entity->getTelephone()
        );

        $I->assertEquals(
            'hello',
            $entity->getAddress()
        );
    }

    public function testElementAppendMessage(IntegrationTester $I)
    {
        $element = new Select('test-select');

        $element->appendMessage(
            new Message('')
        );
    }
}
