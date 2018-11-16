<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Between;
use Phalcon\Validation\Validator\Callback;
use Phalcon\Validation\Validator\Exception;
use Phalcon\Validation\Validator\PresenceOf;
use Phalcon\Validation\Validator\StringLength;
use UnitTester;

class CallbackCest
{
    /**
     * Tests single field using boolean
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     */
    public function testSingleFieldBoolean(UnitTester $I)
    {
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

        $expected = Messages::__set_state(
            [
                '_messages' => [
                    Message::__set_state(
                        [
                            '_type'    => 'Callback',
                            '_message' => 'You cant provide both admin and user.',
                            '_field'   => 'user',
                            '_code'    => '0',
                        ]
                    ),
                ],
            ]
        );
        $actual   = $messages;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests single field using validator
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     */
    public function testSingleFieldValidator(UnitTester $I)
    {
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

        $expected = Messages::__set_state(
            [
                '_messages' => [
                    Message::__set_state(
                        [
                            '_type'    => 'TooShort',
                            '_message' => 'User name should be minimum 4 characters.',
                            '_field'   => 'user',
                            '_code'    => '0',
                        ]
                    ),
                ],
            ]
        );
        $actual   = $messages;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests multiple field returning boolean
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     */
    public function testMultipleFieldBoolean(UnitTester $I)
    {
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

        $expected = Messages::__set_state(
            [
                '_messages' => [
                    Message::__set_state(
                        [
                            '_type'    => 'Callback',
                            '_message' => 'There must be only an user or admin set',
                            '_field'   => 'user',
                            '_code'    => '0',
                        ]
                    ),
                    Message::__set_state(
                        [
                            '_type'    => 'Callback',
                            '_message' => 'There must be only an user or admin set',
                            '_field'   => 'admin',
                            '_code'    => '0',
                        ]
                    ),
                ],
            ]
        );
        $actual   = $messages;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests multiple field validator using validator object
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     */
    public function testMultipleFieldValidator(UnitTester $I)
    {
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

        $expected = Messages::__set_state(
            [
                '_messages' => [
                    Message::__set_state(
                        [
                            '_type'    => 'PresenceOf',
                            '_message' => 'You must provide admin or user',
                            '_field'   => 'user',
                            '_code'    => '0',
                        ]
                    ),
                    Message::__set_state(
                        [
                            '_type'    => 'PresenceOf',
                            '_message' => 'You must provide admin or user',
                            '_field'   => 'admin',
                            '_code'    => '0',
                        ]
                    ),
                ],
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

        $expected = Messages::__set_state(
            [
                '_messages' => [
                    Message::__set_state(
                        [
                            '_type'    => 'Callback',
                            '_message' => 'There must be only an user or admin set',
                            '_field'   => 'user',
                            '_code'    => '0',
                        ]
                    ),
                    Message::__set_state(
                        [
                            '_type'    => 'Callback',
                            '_message' => 'There must be only an user or admin set',
                            '_field'   => 'admin',
                            '_code'    => '0',
                        ]
                    ),
                ],
            ]
        );
        $actual   = $messages;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests callback validator exception
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     */
    public function testException(UnitTester $I)
    {
        $I->expectThrowable(
            new Exception('Callback must return boolean or Phalcon\Validation\Validator object'),
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
