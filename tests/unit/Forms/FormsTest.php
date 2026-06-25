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

namespace Phalcon\Tests\Unit\Forms;

use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Forms\Element\Radio;
use Phalcon\Forms\Element\Select;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Messages\Message;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Forms\ContactFormPublicProperties;
use Phalcon\Tests\Support\Forms\ContactFormSettersGetters;

final class FormsTest extends AbstractUnitTestCase
{
    public function testElementAppendMessage(): void
    {
        $element = new Select('test-select');

        $element->appendMessage(
            new Message('')
        );

        $this->assertCount(1, $element->getMessages());
    }
    public function testFormElementRender(): void
    {
        $factory = new TagFactory(new Escaper());

        $element1 = new Text('name');
        $element1->setTagFactory($factory);
        $element1->setAttributes(
            [
                'class' => 'big-input',
            ]
        );

        $element2 = new Radio('radio');
        $element2->setTagFactory($factory);
        $element2->setAttributes(
            [
                'value' => 0,
            ]
        );

        $this->assertEquals(
            '<input type="text" id="name" name="name" class="big-input">',
            $element1->render()
        );

        $this->assertEquals(
            '<input type="text" id="name" name="name" class="big-input">',
            (string) $element1
        );

        $this->assertEquals(
            '<input type="radio" id="radio" name="radio" value="0">',
            (string) $element2
        );
    }

    public function testFormRenderEntity(): void
    {
        $factory = new TagFactory(new Escaper());

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
        $form->setTagFactory($factory);

        $form->add($address);
        $form->add($telephone);

        $this->assertEquals(
            $form->render('address'),
            '<input type="text" id="address" name="address" value="Cr. 12 #12-82">'
        );

        $this->assertEquals(
            $form->render('telephone'),
            '<input type="text" id="telephone" name="telephone" value="+44 124 82122">'
        );
    }

    public function testFormRenderEntityGetters(): void
    {
        $factory = new TagFactory(new Escaper());

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
        $form->setTagFactory($factory);

        $form->add($address);
        $form->add($telephone);

        $this->assertEquals(
            $form->render('address'),
            '<input type="text" id="address" name="address" value="Cr. 12 #12-82">'
        );

        $this->assertEquals(
            $form->render('telephone'),
            '<input type="text" id="telephone" name="telephone" value="+44 124 82122">'
        );
    }

    public function testFormValidatorEntity(): void
    {
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

        $this->assertTrue(
            $form->isValid(
                [
                    'telephone' => '+44 124 82122',
                    'address'   => 'hello',
                ]
            )
        );
    }

    public function testFormValidatorEntityBind(): void
    {
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

        $this->assertTrue(
            $form->isValid()
        );

        $this->assertEquals(
            '+44 123 45678',
            $entity->telephone
        );

        $this->assertEquals(
            'hello',
            $entity->address
        );
    }

    public function testFormValidatorEntityBindSetters(): void
    {
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

        $this->assertTrue(
            $form->isValid()
        );

        $this->assertEquals(
            '+44 123 45678',
            $entity->getTelephone()
        );

        $this->assertEquals(
            'hello',
            $entity->getAddress()
        );
    }
}
