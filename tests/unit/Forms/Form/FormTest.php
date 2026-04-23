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

namespace Phalcon\Tests\Unit\Forms\Form;

use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Filter\Validation\Validator\Regex;
use Phalcon\Filter\Validation\Validator\StringLength;
use Phalcon\Filter\Validation\Validator\StringLength\Min;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tests\AbstractUnitTestCase;

final class FormTest extends AbstractUnitTestCase
{
    public function testLabels(): void
    {
        $factory = new TagFactory(new Escaper());

        $form = new Form();
        $form->setTagFactory($factory);

        $form->add(
            new Text('name')
        );

        $telephone = new Text('telephone');
        $telephone->setLabel('The Telephone');

        $form->add($telephone);

        $expected = 'name';
        $actual   = $form->getLabel('name');
        $this->assertEquals($expected, $actual);

        $expected = 'The Telephone';
        $actual   = $form->getLabel('telephone');
        $this->assertEquals($expected, $actual);

        $expected = '<label for="name">name</label>';
        $actual   = $form->label('name');
        $this->assertEquals($expected, $actual);

        $expected = '<label for="telephone">The Telephone</label>';
        $actual   = $form->label('telephone');
        $this->assertEquals($expected, $actual);

        // https://github.com/phalcon/cphalcon/issues/1029
        $expected = '<label for="name" class="form-control">name</label>';
        $actual   = $form->label(
            'name',
            [
                'class' => 'form-control',
            ]
        );
        $this->assertEquals($expected, $actual);

        $expected = '<label for="telephone" class="form-control">The Telephone</label>';
        $actual   = $form->label(
            'telephone',
            [
                'class' => 'form-control',
            ]
        );
        $this->assertEquals($expected, $actual);
    }

    public function testFormValidator(): void
    {
        $telephone = new Text('telephone');

        $telephone->addValidator(
            new PresenceOf(
                [
                    'message' => 'The telephone is required',
                ]
            )
        );

        $this->assertCount(
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

        $this->assertCount(
            3,
            $telephone->getValidators()
        );

        $address = new Text('address');
        $address->addValidator(
            new PresenceOf(
                [
                    'message' => 'The address is required',
                ]
            )
        );

        $this->assertCount(
            3,
            $telephone->getValidators()
        );

        $form = new Form();
        $form->add($telephone);
        $form->add($address);

        $actual = $form->isValid(
            []
        );
        $this->assertFalse($actual);

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
        $this->assertEquals(
            $expected,
            $form->getMessages()
        );

        $actual = $form->isValid(
            [
                'telephone' => '123456',
                'address'   => 'hello',
            ]
        );
        $this->assertFalse($actual);

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
        $this->assertEquals(
            $expected,
            $form->getMessages()
        );

        $actual = $form->isValid(
            [
                'telephone' => '+44 124 82122',
                'address'   => 'hello',
            ]
        );
        $this->assertTrue($actual);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/11135
     * @issue  https://github.com/phalcon/cphalcon/issues/3167
     * @author Mohamad Rostami <rostami@outlook.com>
     */
    public function testElementMessages(): void
    {
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

        $address = new Text('address');
        $form    = new Form();

        $form->add($telephone);
        $form->add($address);

        $this->assertFalse(
            $form->isValid(
                [
                    'telephone' => '12345',
                    'address'   => 'hello',
                ]
            )
        );

        $this->assertTrue(
            $form->get('telephone')->hasMessages()
        );

        $this->assertFalse(
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
        $this->assertEquals(
            $expected,
            $form->get('telephone')->getMessages()
        );

        $this->assertEquals(
            $form->getMessages(),
            $form->get('telephone')->getMessages()
        );

        $expected = new Messages();
        $this->assertEquals(
            $expected,
            $form->get('address')->getMessages()
        );

        $expected = new Messages();
        $this->assertEquals(
            $expected,
            $form->getMessagesFor('notelement')
        );
    }
}
