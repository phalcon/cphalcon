<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Forms;

use IntegrationTester;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Html\Interfaces\AttributesInterface;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Validation\Validator\PresenceOf;
use Phalcon\Validation\Validator\Regex;
use Phalcon\Validation\Validator\StringLength;

class FormCest
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
        Tag::setDocType(
            Tag::XHTML5
        );
    }

    /**
     * Test form attributes
     */
    public function testAttributes(IntegrationTester $I)
    {
        $form = new Form();

        // Form implements AttributeInterface
        $I->assertInstanceOf(AttributesInterface::class, $form);

        // Empty attributes
        $I->assertCount(0, $form->getAttributes());

        // Set an attribute
        $form->getAttributes()->set('attr', 'value');
        $I->assertCount(1, $form->getAttributes());

        // Check has attribute
        $I->assertTrue($form->getAttributes()->has('attr'));
        $I->assertFalse($form->getAttributes()->has('fake-attr'));
        $I->assertFalse($form->getAttributes()->has('non exists attr'));

        // Render an attribute
        $result   = $form->getAttributes()->render();
        $expected = ' attr="value"';
        $I->assertEquals($expected, $result);

        // Reset attributes
        $form->getAttributes()->clear();
        $I->assertCount(0, $form->getAttributes());

        // Set multi attributes
        $form->getAttributes()->init([
            'attr1' => 'value1',
            'attr2' => 'value2',
            'attr3' => 'value3',
        ]);

        $I->assertCount(3, $form->getAttributes());

        // Render multi attributes
        $result   = $form->getAttributes()->render();
        $expected = ' attr1="value1" attr2="value2" attr3="value3"';
        $I->assertEquals($expected, $result);

        // Get an attribute
        $result   = $form->getAttributes()->get('attr2');
        $expected = 'value2';
        $I->assertEquals($expected, $result);

        // Test action attribute
        $form->setAction('/some-url');
        $actual   = $form->getAction();
        $expected = '/some-url';
        $I->assertEquals($expected, $actual);

        $actual   = $form->getAttributes()->get('action');
        $expected = '/some-url';
        $I->assertEquals($expected, $actual);

        $result   = $form->getAttributes()->render();
        $expected = ' action="/some-url" attr1="value1" attr2="value2" attr3="value3"';
        $I->assertEquals($expected, $result);

        // Remove an attribute
        $form->getAttributes()->remove('attr2');
        $actual = $form->getAttributes()->has('attr2');
        $I->assertFalse($actual, 'Remove an attribute');
        $I->assertCount(3, $form->getAttributes());

        // Delete a nonexistent attribute
        $form->getAttributes()->remove('attr2');

        $actual = $form->getAttributes()->has('attr2');
        $I->assertFalse($actual);

        // Render multi attributes again
        $result   = $form->getAttributes()->render();
        $expected = ' action="/some-url" attr1="value1" attr3="value3"';
        $I->assertEquals($expected, $result);

        // Reset attributes
        $form->getAttributes()->clear();
        $I->assertCount(0, $form->getAttributes());

        // Exception on non exists attribute
        $I->assertNull($form->getAttributes()->get('non exists'));
    }


    public function testIterator(IntegrationTester $I)
    {
        $form = new Form();
        $data = [];

        foreach ($form as $key => $value) {
            $data[$key] = $value->getName();
        }


        $expected = [];
        $actual   = $data;

        $I->assertEquals($expected, $actual);


        $form->add(
            new Text('name')
        );

        $form->add(
            new Text('telephone')
        );

        foreach ($form as $key => $value) {
            $data[$key] = $value->getName();
        }


        $expected = [
            0 => 'name',
            1 => 'telephone',
        ];

        $actual = $data;

        $I->assertEquals($expected, $actual);
    }

    public function testLabels(IntegrationTester $I)
    {
        $form = new Form();

        $form->add(
            new Text('name')
        );

        $telephone = new Text('telephone');

        $telephone->setLabel('The Telephone');

        $form->add($telephone);


        $expected = 'name';
        $actual   = $form->getLabel('name');

        $I->assertEquals($expected, $actual);


        $expected = 'The Telephone';
        $actual   = $form->getLabel('telephone');

        $I->assertEquals($expected, $actual);


        $expected = '<label for="name">name</label>';
        $actual   = $form->label('name');

        $I->assertEquals($expected, $actual);


        $expected = '<label for="telephone">The Telephone</label>';
        $actual   = $form->label('telephone');

        $I->assertEquals($expected, $actual);


        // https://github.com/phalcon/cphalcon/issues/1029
        $expected = '<label for="name" class="form-control">name</label>';

        $actual = $form->label(
            'name',
            [
                'class' => 'form-control',
            ]
        );

        $I->assertEquals($expected, $actual);


        $expected = '<label for="telephone" class="form-control">The Telephone</label>';

        $actual = $form->label(
            'telephone',
            [
                'class' => 'form-control',
            ]
        );

        $I->assertEquals($expected, $actual);
    }

    public function testFormValidator(IntegrationTester $I)
    {
        //First element
        $telephone = new Text('telephone');

        $telephone->addValidator(
            new PresenceOf(
                [
                    'message' => 'The telephone is required',
                ]
            )
        );


        $I->assertCount(
            1,
            $telephone->getValidators()
        );


        $telephone->addValidators(
            [
                new StringLength(
                    [
                        'min'            => 5,
                        'messageMinimum' => 'The telephone is too short',
                    ]
                ),
                new Regex(
                    [
                        'pattern' => '/\+44 [0-9]+ [0-9]+/',
                        'message' => 'The telephone has an invalid format',
                    ]
                ),
            ]
        );


        $I->assertCount(
            3,
            $telephone->getValidators()
        );


        //Second element
        $address = new Text('address');

        $address->addValidator(
            new PresenceOf(
                [
                    'message' => 'The address is required',
                ]
            )
        );


        $I->assertCount(
            3,
            $telephone->getValidators()
        );


        $form = new Form();

        $form->add($telephone);
        $form->add($address);


        $actual = $form->isValid(
            []
        );

        $I->assertFalse($actual);


        $expected = new Messages(
            [
                new Message(
                    'The telephone is required',
                    'telephone',
                    'PresenceOf',
                    0
                ),
                new Message(
                    'The telephone is too short',
                    'telephone',
                    'TooShort',
                    0
                ),
                new Message(
                    'The telephone has an invalid format',
                    'telephone',
                    'Regex',
                    0
                ),
                new Message(
                    'The address is required',
                    'address',
                    'PresenceOf',
                    0
                ),
            ]
        );

        $I->assertEquals(
            $expected,
            $form->getMessages()
        );


        $actual = $form->isValid(
            [
                'telephone' => '12345',
                'address'   => 'hello',
            ]
        );

        $I->assertFalse($actual);


        $expected = new Messages(
            [
                new Message(
                    'The telephone has an invalid format',
                    'telephone',
                    'Regex',
                    0
                ),
            ]
        );

        $I->assertEquals(
            $expected,
            $form->getMessages()
        );


        $actual = $form->isValid(
            [
                'telephone' => '+44 124 82122',
                'address'   => 'hello',
            ]
        );

        $I->assertTrue($actual);
    }

    /**
     * Tests Element::hasMessages() Element::getMessages()
     *
     * @author Mohamad Rostami <rostami@outlook.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/11135
     * @issue  https://github.com/phalcon/cphalcon/issues/3167
     */
    public function testElementMessages(IntegrationTester $I)
    {
        // First element
        $telephone = new Text('telephone');

        $telephone->addValidators(
            [
                new Regex(
                    [
                        'pattern' => '/\+44 [0-9]+ [0-9]+/',
                        'message' => 'The telephone has an invalid format',
                    ]
                ),
            ]
        );

        // Second element
        $address = new Text('address');
        $form    = new Form();

        $form->add($telephone);
        $form->add($address);


        $I->assertFalse(
            $form->isValid(
                [
                    'telephone' => '12345',
                    'address'   => 'hello',
                ]
            )
        );


        $I->assertTrue(
            $form->get('telephone')->hasMessages()
        );

        $I->assertFalse(
            $form->get('address')->hasMessages()
        );


        $expected = new Messages(
            [
                new Message(
                    'The telephone has an invalid format',
                    'telephone',
                    'Regex',
                    0
                ),
            ]
        );

        $I->assertEquals(
            $expected,
            $form->get('telephone')->getMessages()
        );

        $I->assertEquals(
            $form->getMessages(),
            $form->get('telephone')->getMessages()
        );


        $expected = new Messages();

        $I->assertEquals(
            $expected,
            $form->get('address')->getMessages()
        );


        $expected = new Messages();

        $I->assertEquals(
            $expected,
            $form->getMessagesFor('notelement')
        );
    }
}
