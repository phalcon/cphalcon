<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Validation\Validator\Callback;

use IntegrationTester;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Callback;
use Phalcon\Validation\Validator\Exception;
use Phalcon\Validation\Validator\PresenceOf;
use Phalcon\Validation\Validator\StringLength;

/**
 * Class ValidateCest
 */
class ValidateCest
{
    /**
     * Tests Phalcon\Validation\Validator\Callback :: validate() - single field
     * using boolean
     *
     * @param IntegrationTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     */
    public function validationValidatorCallbackValidateSingleFieldBoolean(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Callback - validate() - single field using boolean");
        $validation = new Validation();
        $validation->add(
            'user',
            new Callback(
                [
                    "callback"   => function ($data) {
                        return empty($data['admin']);
                    },
                    "message"    => "You cant provide both admin and user.",
                    "allowEmpty" => true,
                ]
            )
        );

        $messages = $validation->validate(["user" => "user", "admin" => null]);

        $expected = 0;
        $actual   = count($messages);
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(["user" => null, "admin" => "admin"]);
        $expected = 0;
        $actual   = count($messages);
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(["user" => "user", "admin" => "admin"]);
        $expected = 1;
        $actual   = count($messages);
        $I->assertEquals($expected, $actual);

        $expected = new Messages(
            [
                new Message(
                    'You cant provide both admin and user.',
                    'user',
                    'Callback',
                    0
                ),
            ]
        );
        $actual   = $messages;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Validation\Validator\Callback :: validate() - single field
     * using validator
     *
     * @param IntegrationTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     */
    public function validationValidatorCallbackValidateSingleFieldValidator(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Callback - validate() - single field using validator");
        $validation = new Validation();
        $validation->add(
            'user',
            new Callback(
                [
                    "callback" => function ($data) {
                        if (empty($data['admin'])) {
                            return new StringLength(
                                [
                                    "min"            => 4,
                                    "messageMinimum" => "User name should be minimum 4 characters.",
                                ]
                            );
                        }

                        return true;
                    },
                ]
            )
        );
        $messages = $validation->validate(['user' => 'u', 'admin' => 'admin']);

        $expected = 0;
        $actual   = count($messages);
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['user' => 'user', 'admin' => null]);

        $expected = 0;
        $actual   = count($messages);
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['user' => 'u', 'admin' => null]);

        $expected = 1;
        $actual   = count($messages);
        $I->assertEquals($expected, $actual);

        $expected = new Messages(
            [
                new Message(
                    'User name should be minimum 4 characters.',
                    'user',
                    'TooShort',
                    0
                ),
            ]
        );
        $actual   = $messages;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Validation\Validator\Callback :: validate() - multiple
     * field returning boolean
     *
     * @param IntegrationTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     */
    public function validationValidatorCallbackValidateMultipleFieldBoolean(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Callback - validate() - multiple field returning boolean");
        $validation = new Validation();
        $validation->add(
            ['user', 'admin'],
            new Callback(
                [
                    "message"  => "There must be only an user or admin set",
                    "callback" => function ($data) {
                        if (!empty($data['user']) && !empty($data['admin'])) {
                            return false;
                        }

                        return true;
                    },
                ]
            )
        );

        $messages = $validation->validate(['user' => null, 'admin' => 'admin']);

        $expected = 0;
        $actual   = count($messages);
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['user' => 'user', 'admin' => null]);

        $expected = 0;
        $actual   = count($messages);
        $I->assertEquals($expected, $actual);
        $messages = $validation->validate(['user' => 'user', 'admin' => 'admin']);

        $expected = 2;
        $actual   = count($messages);
        $I->assertEquals($expected, $actual);

        $expected = new Messages(
            [
                new Message(
                    'There must be only an user or admin set',
                    'user',
                    'Callback',
                    0
                ),
                new Message(
                    'There must be only an user or admin set',
                    'admin',
                    'Callback',
                    0
                ),
            ]
        );
        $actual   = $messages;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Validation\Validator\Callback :: validate() - multiple
     * field validator
     *
     * @param IntegrationTester $I
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
                    "message"  => "There must be only an user or admin set",
                    "callback" => function ($data) {
                        if (empty($data['user']) && empty($data['admin'])) {
                            return new PresenceOf(
                                [
                                    "message" => "You must provide admin or user",
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

        $messages = $validation->validate(['admin' => null, 'user' => null]);

        $expected = 2;
        $actual   = count($messages);
        $I->assertEquals($expected, $actual);

        $expected = new Messages(
            [
                new Message(
                    'You must provide admin or user',
                    'user',
                    'PresenceOf',
                    0
                ),
                new Message(
                    'You must provide admin or user',
                    'admin',
                    'PresenceOf',
                    0
                ),
            ]
        );
        $actual   = $messages;
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['admin' => 'admin', 'user' => null]);
        $expected = 0;
        $actual   = count($messages);
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['admin' => null, 'user' => 'user']);
        $expected = 0;
        $actual   = count($messages);
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['admin' => 'admin', 'user' => 'user']);
        $expected = 2;
        $actual   = count($messages);
        $I->assertEquals($expected, $actual);

        $expected = new Messages(
            [
                new Message(
                    'There must be only an user or admin set',
                    'user',
                    'Callback',
                    0
                ),
                new Message(
                    'There must be only an user or admin set',
                    'admin',
                    'Callback',
                    0
                ),
            ]
        );
        $actual   = $messages;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Validation\Validator\Callback :: validate() - exception
     *
     * @param IntegrationTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     */
    public function validationValidatorCallbackValidateException(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Callback - validate() - exception");
        $I->expectThrowable(
            new Exception('Callback must return bool or Phalcon\Validation\Validator object'),
            function () {
                $validation = new Validation();
                $validation->add(
                    'user',
                    new Callback(
                        [
                            "callback" => function ($data) {
                                return new Validation();
                            },
                        ]
                    )
                );

                $validation->validate(['user' => 'user']);
            }
        );
    }
}
