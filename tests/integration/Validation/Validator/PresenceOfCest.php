<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Validation\Validator;

use IntegrationTester;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Validation;
use Phalcon\Validation\Validator\PresenceOf;

class PresenceOfCest
{
    /**
     * Tests presence of validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function shouldValidateSingleField(IntegrationTester $I)
    {
        $validation = new Validation();
        $validation->add('name', new PresenceOf());

        $messages = $validation->validate(['name' => 'SomeValue']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['name' => '']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests presence of validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function shouldValidateMultipleField(IntegrationTester $I)
    {
        $validation         = new Validation();
        $validationMessages = [
            'name' => 'Name cant be empty.',
            'type' => 'Type cant be empty.',
        ];
        $validation->add(
            ['name', 'type'],
            new PresenceOf(
                [
                    'message' => $validationMessages,
                ]
            )
        );

        $messages = $validation->validate(['name' => 'SomeValue', 'type' => 'SomeValue']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['name' => '', 'type' => 'SomeValue']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = new Messages(
            [
                new Message(
                    'Name cant be empty.',
                    'name',
                    'PresenceOf',
                    0
                ),
            ]
        );
        $actual   = $messages;
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['name' => '', 'type' => '']);
        $expected = 2;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['type'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = new Messages(
            [
                new Message(
                    'Name cant be empty.',
                    'name',
                    'PresenceOf',
                    0
                ),
                new Message(
                    'Type cant be empty.',
                    'type',
                    'PresenceOf',
                    0
                ),
            ]
        );
        $actual   = $messages;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests mixed fields
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2013-03-01
     */
    public function shouldValidateMixedFields(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation
            ->add('name', new PresenceOf(['message' => 'The name is required']))
            ->add('email', new PresenceOf(['message' => 'The email is required']))
            ->add('login', new PresenceOf(['message' => 'The login is required']))
        ;

        $actual = $validation->validate([]);

        $expected = new Messages(
            [
                new Message(
                    'The name is required',
                    'name',
                    'PresenceOf',
                    0
                ),
                new Message(
                    'The email is required',
                    'email',
                    'PresenceOf',
                    0
                ),
                new Message(
                    'The login is required',
                    'login',
                    'PresenceOf',
                    0
                ),
            ]
        );
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests cancel validation on first fail
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2013-03-01
     */
    public function shouldCancelOnFail(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation
            ->add('name', new PresenceOf(['message' => 'The name is required']))
            ->add('email', new PresenceOf([
                'message'      => 'The email is required',
                'cancelOnFail' => true,
            ]))
            ->add('login', new PresenceOf(['message' => 'The login is required']))
        ;

        $actual = $validation->validate([]);

        $expected = new Messages(
            [
                new Message(
                    'The name is required',
                    'name',
                    'PresenceOf',
                    0
                ),
                new Message(
                    'The email is required',
                    'email',
                    'PresenceOf',
                    0
                ),
            ]
        );
        $I->assertEquals($expected, $actual);
    }
}
