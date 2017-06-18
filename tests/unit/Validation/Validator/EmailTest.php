<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Email;

/**
 * \Phalcon\Test\Unit\Validation\Validator\EmailTest
 * Tests the \Phalcon\Validation\Validator\Email component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Validation\Validator
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class EmailTest extends UnitTest
{
    /**
     * Tests email validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testSingleField()
    {
        $this->specify(
            'Test email validator with single field.',
            function () {
                $validation = new Validation();

                $validation->add('email', new Email());

                $messages = $validation->validate(['email' => 'test@somemail.com']);
                expect($messages->count())->equals(0);

                $messages = $validation->validate(['email' => 'rootlocalhost']);
                expect($messages->count())->equals(1);

                $expectedMessages = Validation\Message\Group::__set_state(
                    [
                        '_messages' => [
                            0 => Validation\Message::__set_state(
                                [
                                    '_type'    => 'Email',
                                    '_message' => 'Field email must be an email address',
                                    '_field'   => 'email',
                                    '_code'    => 0,
                                ]
                            )
                        ]
                    ]
                );

                expect($expectedMessages)->equals($messages);
            }
        );
    }

    /**
     * Tests email validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleField()
    {
        $this->specify('Test email validator with multiple field.', function () {
            $validation = new Validation();
            $validationMessages = [
                'email' => 'Email must be correct email.',
                'anotherEmail' => 'AnotherEmail must be correct email.',
            ];
            $validation->add(['email', 'anotherEmail'], new Email([
                'message' => $validationMessages,
            ]));
            $messages = $validation->validate(['email' => 'test@somemail.com', 'anotherEmail' => 'test@somemail.com']);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['email' => 'rootlocalhost', 'anotherEmail' => 'test@somemail.com']);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['email']);
            $messages = $validation->validate(['email' => 'rootlocalhost', 'anotherEmail' => 'rootlocalhost']);
            expect($messages->count())->equals(2);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['email']);
            expect($messages->offsetGet(1)->getMessage())->equals($validationMessages['anotherEmail']);
        });
    }

    public function testCustomMessage()
    {
        $this->specify(
            'Test Email validator works with a custom message.',
            function () {
                $validation = new Validation();

                $validation->add(
                    'email',
                    new Email(
                        [
                           'message' => 'The email is not valid'
                        ]
                    )
                );

                $messages = $validation->validate([]);

                $expectedMessages = Validation\Message\Group::__set_state(
                    [
                        '_messages' => [
                            0 => Validation\Message::__set_state(
                                [
                                    '_type' => 'Email',
                                    '_message' => 'The email is not valid',
                                    '_field' => 'email',
                                    '_code' => '0',
                                ]
                            )
                        ]
                    ]
                );

                $this->assertEquals($expectedMessages, $messages);

                $messages = $validation->validate(['email' => 'x=1']);
                expect($expectedMessages)->equals($messages);

                $messages = $validation->validate(['email' => 'x.x@hotmail.com']);
                expect($messages)->count(0);
            }
        );
    }
}
