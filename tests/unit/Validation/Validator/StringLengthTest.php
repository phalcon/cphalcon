<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Validation;
use Phalcon\Validation\Message;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation\Message\Group;
use Phalcon\Validation\Validator\StringLength;

/**
 * \Phalcon\Test\Unit\Validation\Validator\StringLengthTest
 * Tests the \Phalcon\Validation\Validator\StringLength component
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
class StringLengthTest extends UnitTest
{
    /**
     * Tests string length validator with single field
     *
     * @test
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function shouldValidateSingleField()
    {
        $this->specify('Test string length with single field.', function () {
            $validation = new Validation();
            $validation->add('name', new StringLength([
                'min' => 3,
                'max' => 9,
            ]));

            expect($validation->validate(['name' => 'SomeValue']))->count(0);
            expect($validation->validate(['name' => 'SomeValue123']))->count(1);
        });
    }

    /**
     * Tests too short string length
     *
     * @test
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2013-03-09
     */
    public function shouldValidateStringLengthMinimum()
    {
        $this->specify(
            'The StringLength validator does not validate too short string length correctly.',
            function () {
                $validation = new Validation();
                $validation->add('name', new StringLength(['min' => 3]));

                expect($validation->validate(['name' => 'Something']))->count(0);

                $expected = Group::__set_state([
                    '_messages' => [
                        Message::__set_state([
                            '_type'    => 'TooShort',
                            '_message' => 'Field name must be at least 3 characters long',
                            '_field'   => 'name',
                            '_code'    => '0',
                        ])
                    ]
                ]);

                expect($validation->validate(['name' => 'So']))->equals($expected);
            }
        );
    }

    /**
     * Tests too short string length with custom message
     *
     * @test
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2013-03-09
     */
    public function shouldValidateStringLengthMinimumWithCustomMessage()
    {
        $this->specify(
            'The StringLength validator does not validate too short string length with custom message correctly.',
            function () {
                $validation = new Validation();
                $validation->add(
                    'message',
                    new StringLength(['min' => 3, 'messageMinimum' => 'The message is too short'])
                );

                expect($validation->validate(['message' => 'Something']))->count(0);

                $expected = Group::__set_state([
                    '_messages' => [
                        Message::__set_state([
                            '_type'    => 'TooShort',
                            '_message' => 'The message is too short',
                            '_field'   => 'message',
                            '_code'    => '0',
                        ])
                    ]
                ]);

                expect($validation->validate(['message' => 'So']))->equals($expected);
            }
        );
    }

    /**
     * Tests too long string length
     *
     * @test
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2013-03-09
     */
    public function shouldValidateStringLengthMaximum()
    {
        $this->specify(
            'The StringLength validator does not validate too long string length correctly.',
            function () {
                $validation = new Validation();
                $validation->add('name', new StringLength(['max' => 4]));

                expect($validation->validate(['name' => 'John']))->count(0);

                $expected = Group::__set_state([
                    '_messages' => [
                        Message::__set_state([
                            '_type'    => 'TooLong',
                            '_message' => 'Field name must not exceed 4 characters long',
                            '_field'   => 'name',
                            '_code'    => '0',
                        ])
                    ]
                ]);

                expect($validation->validate(['name' => 'Johannes']))->equals($expected);
            }
        );
    }

    /**
     * Tests too long string length with custom message
     *
     * @test
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2013-03-09
     */
    public function shouldValidateStringLengthMaximumWithCustomMessage()
    {
        $this->specify(
            'The StringLength validator does not validate too long string length with custom message correctly.',
            function () {
                $validation = new Validation();
                $validation->add(
                    'message',
                    new StringLength(['max' => 4, 'messageMaximum' => 'The message is too long'])
                );

                expect($validation->validate(['message' => 'Pet']))->count(0);

                $expected = Group::__set_state([
                    '_messages' => [
                        Message::__set_state([
                            '_type'    => 'TooLong',
                            '_message' => 'The message is too long',
                            '_field'   => 'message',
                            '_code'    => '0',
                        ])
                    ]
                ]);

                expect($validation->validate(['message' => 'Validation']))->equals($expected);
            }
        );
    }

    /**
     * Tests string length validator with multiple field and single min, max
     *
     * @test
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function shouldValidateMultipleFieldSingleMinMax()
    {
        $this->specify('Test string length with multiple field and single min, max.', function () {
            $validation = new Validation();
            $validationMinimumMessages = [
                'name' => 'Name length must be minimum 0.',
                'type' => 'Type length must be minimum 0.',
            ];
            $validationMaximumMessages = [
                'name' => 'Name length must be maximum 9.',
                'type' => 'Type length must be maximum 9.',
            ];
            $validation->add(['name', 'type'], new StringLength([
                'min' => 0,
                'max' => 9,
                'messageMinimum' => $validationMinimumMessages,
                'messageMaximum' => $validationMaximumMessages
            ]));
            $messages = $validation->validate(['name' => 'SomeValue', 'type' => 'SomeValue']);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['name' => 'SomeValue123', 'type' => 'SomeValue']);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMaximumMessages['name']);
            $messages = $validation->validate(['name' => 'SomeValue123', 'type' => 'SomeValue123']);
            expect($messages->count())->equals(2);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMaximumMessages['name']);
            expect($messages->offsetGet(1)->getMessage())->equals($validationMaximumMessages['type']);
        });
    }

    /**
     * Tests string length validator with multiple field and min, max
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleFieldMultipleMinMax()
    {
        $this->specify('Test string length with multiple field and min, max.', function () {
            $validation = new Validation();
            $validationMinimumMessages = [
                'name' => 'Name length must be minimum 0.',
                'type' => 'Type length must be minimum 0.',
            ];
            $validationMaximumMessages = [
                'name' => 'Name length must be maximum 9.',
                'type' => 'Type length must be maximum 4.',
            ];
            $validation->add(['name', 'type'], new StringLength([
                'min' => [
                    'name' => 0,
                    'type' => 0,
                ],
                'max' => [
                    'name' => 9,
                    'type' => 4,
                ],
                'messageMinimum' => $validationMinimumMessages,
                'messageMaximum' => $validationMaximumMessages
            ]));
            $messages = $validation->validate(['name' => 'SomeValue', 'type' => 'Some']);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['name' => 'SomeValue123', 'type' => 'Some']);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMaximumMessages['name']);
            $messages = $validation->validate(['name' => 'SomeValue', 'type' => 'SomeValue']);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMaximumMessages['type']);
            $messages = $validation->validate(['name' => 'SomeValue123', 'type' => 'SomeValue']);
            expect($messages->count())->equals(2);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMaximumMessages['name']);
            expect($messages->offsetGet(1)->getMessage())->equals($validationMaximumMessages['type']);
        });
    }
}
