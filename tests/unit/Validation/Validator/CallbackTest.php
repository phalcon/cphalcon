<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation;
use Phalcon\Validation\Message;
use Phalcon\Validation\Message\Group;
use Phalcon\Validation\Validator\Callback;
use Phalcon\Validation\Validator\PresenceOf;
use Phalcon\Validation\Validator\StringLength;

/**
 * \Phalcon\Test\Unit\Validation\Validator\CallbackTest
 * Tests the \Phalcon\Validation\Validator\Callback component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Validation\Validator
 * @group     validation
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class CallbackTest extends UnitTest
{
    /**
     * Tests single field using boolean
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     */
    public function testSingleFieldBoolean()
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
        expect($messages)->count(0);
        $messages = $validation->validate(["user" => null, "admin" => "admin"]);
        expect($messages)->count(0);
        $messages = $validation->validate(["user" => "user", "admin" => "admin"]);
        expect($messages)->count(1);

        $expectedMessages = Group::__set_state(
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

        expect($messages)->equals($expectedMessages);
    }

    /**
     * Tests single field using validator
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     */
    public function testSingleFieldValidator()
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
        expect($messages)->count(0);
        $messages = $validation->validate(['user' => 'user', 'admin' => null]);
        expect($messages)->count(0);
        $messages = $validation->validate(['user' => 'u', 'admin' => null]);
        expect($messages)->count(1);
        $expectedMessages = Group::__set_state(
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
        expect($messages)->equals($expectedMessages);
    }

    /**
     * Tests multiple field returning boolean
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     */
    public function testMultipleFieldBoolean()
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
        expect($messages)->count(0);
        $messages = $validation->validate(['user' => 'user', 'admin' => null]);
        expect($messages)->count(0);
        $messages = $validation->validate(['user' => 'user', 'admin' => 'admin']);
        expect($messages)->count(2);
        $expectedMessages = Group::__set_state(
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
        expect($messages)->equals($expectedMessages);
    }

    /**
     * Tests multiple field validator using validator object
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     */
    public function testMultipleFieldValidator()
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
        expect($messages)->count(2);
        $expectedMessages = Group::__set_state(
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
        expect($messages)->equals($expectedMessages);
        $messages = $validation->validate(['admin' => 'admin', 'user' => null]);
        expect($messages)->count(0);
        $messages = $validation->validate(['admin' => null, 'user' => 'user']);
        expect($messages)->count(0);
        $messages = $validation->validate(['admin' => 'admin', 'user' => 'user']);
        expect($messages)->count(2);
        $expectedMessages = Group::__set_state(
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
        expect($messages)->equals($expectedMessages);
    }

    /**
     * Tests callback validator exception
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     * @expectedException \Phalcon\Validation\Validator\Exception
     * @expectedExceptionMessage Callback must return boolean or Phalcon\Validation\Validator object
     */
    public function testException()
    {
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
}
