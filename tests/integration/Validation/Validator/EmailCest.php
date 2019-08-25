<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Validation\Validator;

use IntegrationTester;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Email;

class EmailCest
{
    /**
     * Tests email validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorSingleField(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            'email',
            new Email()
        );


        $messages = $validation->validate(
            [
                'email' => 'test@somemail.com',
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'email' => 'rootlocalhost',
            ]
        );

        $I->assertEquals(
            1,
            $messages->count()
        );

        $expected = new Messages(
            [
                new Message(
                    'Field email must be an email address',
                    'email',
                    Email::class,
                    0
                ),
            ]
        );

        $I->assertEquals($expected, $messages);
    }

    /**
     * Tests email validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorMultipleField(IntegrationTester $I)
    {
        $validation = new Validation();

        $validationMessages = [
            'email'        => 'Email must be correct email.',
            'anotherEmail' => 'AnotherEmail must be correct email.',
        ];

        $validation->add(
            [
                'email',
                'anotherEmail',
            ],
            new Email(
                [
                    'message' => $validationMessages,
                ]
            )
        );


        $messages = $validation->validate(
            [
                'email'        => 'test@somemail.com',
                'anotherEmail' => 'test@somemail.com',
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'email'        => 'rootlocalhost',
                'anotherEmail' => 'test@somemail.com',
            ]
        );

        $I->assertEquals(
            1,
            $messages->count()
        );

        $I->assertEquals(
            $validationMessages['email'],
            $messages->offsetGet(0)->getMessage()
        );


        $messages = $validation->validate(
            [
                'email'        => 'rootlocalhost',
                'anotherEmail' => 'rootlocalhost',
            ]
        );

        $I->assertEquals(
            2,
            $messages->count()
        );

        $I->assertEquals(
            $validationMessages['email'],
            $messages->offsetGet(0)->getMessage()
        );

        $I->assertEquals(
            $validationMessages['anotherEmail'],
            $messages->offsetGet(1)->getMessage()
        );
    }

    public function validationValidatorCustomMessage(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            'email',
            new Email(
                [
                    'message' => 'The email is not valid',
                ]
            )
        );

        $actual   = $validation->validate([]);
        $expected = new Messages(
            [
                new Message(
                    'The email is not valid',
                    'email',
                    Email::class,
                    0
                ),
            ]
        );
        $I->assertEquals($expected, $actual);

        $actual = $validation->validate(['email' => 'x=1']);
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['email' => 'x.x@hotmail.com']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);
    }
}
