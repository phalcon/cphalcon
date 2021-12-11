<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Integration\Forms;

use IntegrationTester;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tag;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Validation\Validator\PresenceOf;
use Phalcon\Validation\Validator\Regex;
use Phalcon\Validation\Validator\StringLength;
use Phalcon\Validation\Validator\StringLength\Min;

class FormCest
{
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
                    PresenceOf::class,
                    0
                ),
                new Message(
                    'The telephone is too short',
                    'telephone',
                    Min::class,
                    0
                ),
                new Message(
                    'The telephone has an invalid format',
                    'telephone',
                    Regex::class,
                    0
                ),
                new Message(
                    'The address is required',
                    'address',
                    PresenceOf::class,
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
                    Regex::class,
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
                    Regex::class,
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
