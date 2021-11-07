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

namespace Phalcon\Tests\Integration\Validation\Validator\Callback;

use IntegrationTester;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Callback;
use Phalcon\Validation\Validator\Exception;
use Phalcon\Validation\Validator\PresenceOf;
use Phalcon\Validation\Validator\StringLength;
use Phalcon\Validation\Validator\StringLength\Min;

class ValidateCest
{
    /**
     * Tests Phalcon\Validation\Validator\Callback :: validate() - single field
     * using boolean
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     */
    public function validationValidatorCallbackValidateSingleFieldBoolean(IntegrationTester $I)
    {
        $I->wantToTest(
            "Validation\Validator\Callback - validate() - single field using boolean"
        );

        $validation = new Validation();

        $validation->add(
            'user',
            new Callback(
                [
                    'callback'   => function ($data) {
                        return empty($data['admin']);
                    },
                    'message'    => 'You cant provide both admin and user.',
                ]
            )
        );


        $messages = $validation->validate(
            [
                'user'  => 'user',
                'admin' => null,
            ]
        );

        $I->assertCount(0, $messages);


        $messages = $validation->validate(
            [
                'user'  => null,
                'admin' => 'admin',
            ]
        );

        $I->assertCount(0, $messages);


        $messages = $validation->validate(
            [
                'user'  => 'user',
                'admin' => 'admin',
            ]
        );

        $I->assertCount(1, $messages);


        $expected = new Messages(
            [
                new Message(
                    'You cant provide both admin and user.',
                    'user',
                    Callback::class,
                    0
                ),
            ]
        );

        $I->assertEquals($expected, $messages);
    }

    /**
     * Tests Phalcon\Validation\Validator\Callback :: validate() - single field
     * using validator
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     */
    public function validationValidatorCallbackValidateSingleFieldValidator(IntegrationTester $I)
    {
        $I->wantToTest(
            "Validation\Validator\Callback - validate() - single field using validator"
        );

        $validation = new Validation();

        $validation->add(
            'user',
            new Callback(
                [
                    'callback' => function ($data) {
                        if (empty($data['admin'])) {
                            return new StringLength(
                                [
                                    'min'            => 4,
                                    'messageMinimum' => 'User name should be minimum 4 characters.',
                                ]
                            );
                        }

                        return true;
                    },
                ]
            )
        );


        $messages = $validation->validate(
            [
                'user'  => 'u',
                'admin' => 'admin',
            ]
        );

        $I->assertCount(0, $messages);


        $messages = $validation->validate(
            [
                'user'  => 'user',
                'admin' => null,
            ]
        );

        $I->assertCount(0, $messages);


        $messages = $validation->validate(
            [
                'user'  => 'u',
                'admin' => null,
            ]
        );

        $I->assertCount(1, $messages);


        $expected = new Messages(
            [
                new Message(
                    'User name should be minimum 4 characters.',
                    'user',
                    Min::class,
                    0
                ),
            ]
        );

        $I->assertEquals($expected, $messages);
    }

    /**
     * Tests Phalcon\Validation\Validator\Callback :: validate() - multiple
     * field returning boolean
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     */
    public function validationValidatorCallbackValidateMultipleFieldBoolean(IntegrationTester $I)
    {
        $I->wantToTest(
            "Validation\Validator\Callback - validate() - multiple field returning boolean"
        );

        $validation = new Validation();

        $validation->add(
            ['user', 'admin'],
            new Callback(
                [
                    'message'  => 'There must be only an user or admin set',
                    'callback' => function ($data) {
                        if (!empty($data['user']) && !empty($data['admin'])) {
                            return false;
                        }

                        return true;
                    },
                ]
            )
        );


        $messages = $validation->validate(
            [
                'user'  => null,
                'admin' => 'admin',
            ]
        );

        $I->assertCount(0, $messages);


        $messages = $validation->validate(
            [
                'user'  => 'user',
                'admin' => null,
            ]
        );

        $I->assertCount(0, $messages);


        $messages = $validation->validate(
            [
                'user'  => 'user',
                'admin' => 'admin',
            ]
        );

        $I->assertCount(2, $messages);


        $expected = new Messages(
            [
                new Message(
                    'There must be only an user or admin set',
                    'user',
                    Callback::class,
                    0
                ),
                new Message(
                    'There must be only an user or admin set',
                    'admin',
                    Callback::class,
                    0
                ),
            ]
        );

        $I->assertEquals($expected, $messages);
    }

    /**
     * Tests Phalcon\Validation\Validator\Callback :: validate() - multiple
     * field validator
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     */
    public function validationValidatorCallbackValidateMultipleFieldValidator(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Callback - validate() - multiple field validator");

        $validation = new Validation();

        $validation->add(
            ['user', 'admin'],
            new Callback(
                [
                    'message'  => 'There must be only an user or admin set',
                    'callback' => function ($data) {
                        if (empty($data['user']) && empty($data['admin'])) {
                            return new PresenceOf(
                                [
                                    'message' => 'You must provide admin or user',
                                ]
                            );
                        }

                        if (!empty($data['user']) && !empty($data['admin'])) {
                            return false;
                        }

                        return true;
                    },
                ]
            )
        );


        $messages = $validation->validate(
            [
                'admin' => null,
                'user'  => null,
            ]
        );

        $I->assertCount(2, $messages);


        $expected = new Messages(
            [
                new Message(
                    'You must provide admin or user',
                    'user',
                    PresenceOf::class,
                    0
                ),
                new Message(
                    'You must provide admin or user',
                    'admin',
                    PresenceOf::class,
                    0
                ),
            ]
        );

        $I->assertEquals($expected, $messages);


        $messages = $validation->validate(
            [
                'admin' => 'admin',
                'user'  => null,
            ]
        );

        $I->assertCount(0, $messages);


        $messages = $validation->validate(
            [
                'admin' => null,
                'user'  => 'user',
            ]
        );

        $I->assertCount(0, $messages);


        $messages = $validation->validate(
            [
                'admin' => 'admin',
                'user'  => 'user',
            ]
        );

        $I->assertCount(2, $messages);


        $expected = new Messages(
            [
                new Message(
                    'There must be only an user or admin set',
                    'user',
                    Callback::class,
                    0
                ),
                new Message(
                    'There must be only an user or admin set',
                    'admin',
                    Callback::class,
                    0
                ),
            ]
        );

        $I->assertEquals($expected, $messages);
    }

    /**
     * Tests Phalcon\Validation\Validator\Callback :: validate() - exception
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     */
    public function validationValidatorCallbackValidateException(IntegrationTester $I)
    {
        $I->wantToTest(
            "Validation\Validator\Callback - validate() - exception"
        );

        $I->expectThrowable(
            new Exception('Callback must return bool or Phalcon\Validation\Validator object'),
            function () {
                $validation = new Validation();

                $validation->add(
                    'user',
                    new Callback(
                        [
                            'callback' => function ($data) {
                                return new Validation();
                            },
                        ]
                    )
                );

                $validation->validate(
                    [
                        'user' => 'user',
                    ]
                );
            }
        );
    }
}
