<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation;

/**
 * \Phalcon\Test\Unit\Validation\Validator\IdenticalTest
 * Tests the \Phalcon\Validation\Validator\Identical component
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
class IdenticalTest extends UnitTest
{
    /**
     * Tests identical validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testSingleField()
    {
        $this->specify(
            'Test identical validator with single field.',
            function () {
                $validation = new Validation();

                $validation->add(
                    'name',
                    new Validation\Validator\Identical(
                        [
                            'accepted' => 'SomeValue',
                        ]
                    )
                );

                $messages = $validation->validate(['name' => 'SomeValue']);
                expect($messages->count())->equals(0);

                $messages = $validation->validate(['name' => 'SomeValue123']);
                expect($messages->count())->equals(1);

                $expectedMessages = Validation\Message\Group::__set_state(
                    [
                        '_messages' => [
                            0 => Validation\Message::__set_state(
                                [
                                    '_type'    => 'Identical',
                                    '_message' => 'Field name does not have the expected value',
                                    '_field'   => 'name',
                                    '_code'    => '0',
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
     * Tests identical validator with multiple field and single accepted
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleFieldSingleAccepted()
    {
        $this->specify('Test identical validator with multiple field and single accepted.', function () {
            $validation = new Validation();
            $validationMessages = [
                'name' => 'Name must be SomeValue.',
                'anotherName' => 'AnotherName must be SomeValue.',
            ];
            $validation->add(['name', 'anotherName'], new Validation\Validator\Identical([
                'accepted' => 'SomeValue',
                'message' => $validationMessages,
            ]));
            $messages = $validation->validate(['name' => 'SomeValue', 'anotherName' => 'SomeValue']);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['name' => 'SomeValue123', 'anotherName' => 'SomeValue']);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['name']);
            $messages = $validation->validate(['name' => 'SomeValue123', 'anotherName' => 'SomeValue123']);
            expect($messages->count())->equals(2);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['name']);
            expect($messages->offsetGet(1)->getMessage())->equals($validationMessages['anotherName']);
        });
    }

    /**
     * Tests identical validator with multiple field and multiple accepted
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleFieldMultipleAccepted()
    {
        $this->specify('Test identical with multiple field and accepted.', function () {
            $validation = new Validation();
            $validationMessages = [
                'name' => 'Name must be SomeValue.',
                'anotherName' => 'AnotherName must be SomeAnotherValue.',
            ];
            $validation->add(['name', 'anotherName'], new Validation\Validator\Identical([
                'accepted' => [
                    'name' => 'SomeValue',
                    'anotherName' => 'SomeAnotherValue',
                ],
                'message' => $validationMessages,
            ]));
            $messages = $validation->validate(['name' => 'SomeValue', 'anotherName' => 'SomeAnotherValue']);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['name' => 'SomeValue123', 'anotherName' => 'SomeAnotherValue']);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['name']);
            $messages = $validation->validate(['name' => 'SomeValue', 'anotherName' => 'SomeAnotherValue123']);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['anotherName']);
            $messages = $validation->validate(['name' => 'SomeValue123', 'anotherName' => 'SomeAnotherValue123']);
            expect($messages->count())->equals(2);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['name']);
            expect($messages->offsetGet(1)->getMessage())->equals($validationMessages['anotherName']);
        });
    }

    public function testCustomMessage()
    {
        $this->specify(
            'Test Identical validator works with a custom message.',
            function () {
                $validation = new Validation();

                $validation->add(
                    'name',
                    new Validation\Validator\Identical(
                        [
                            'accepted' => 'Peter',
                            'message'  => 'The name must be peter',
                        ]
                    )
                );

                $messages = $validation->validate([]);

                $expectedMessages = Validation\Message\Group::__set_state(
                    [
                        '_messages' => [
                            0 => Validation\Message::__set_state(
                                [
                                    '_type'    => 'Identical',
                                    '_message' => 'The name must be peter',
                                    '_field'   => 'name',
                                    '_code'    => '0',
                                ]
                            )
                        ]
                    ]
                );

                expect($expectedMessages)->equals($messages);

                $messages = $validation->validate(['name' => 'Peter']);

                expect($messages)->count(0);
            }
        );
    }
}
