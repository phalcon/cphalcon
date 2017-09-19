<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation;

/**
 * \Phalcon\Test\Unit\Validation\Validator\RegexTest
 * Tests the \Phalcon\Validation\Validator\Regex component
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
class RegexTest extends UnitTest
{
    /**
     * Tests regex validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testSingleField()
    {
        $this->specify(
            'Test regex validator with single field.',
            function () {
                $validation = new Validation();

                $validation->add(
                    'car_plate',
                    new Validation\Validator\Regex(
                        [
                            'pattern' => '/[A-Z]{3}\-[0-9]{3}/'
                        ]
                    )
                );

                $messages = $validation->validate([]);

                $expectedMessages = Validation\Message\Group::__set_state(
                    [
                        '_messages' => [
                            0 => Validation\Message::__set_state(
                                [
                                    '_type'    => 'Regex',
                                    '_message' => 'Field car_plate does not match the required format',
                                    '_field'   => 'car_plate',
                                    '_code'    => '0',
                                ]
                            )
                        ]
                    ]
                );

                expect($expectedMessages)->equals($messages);

                $messages = $validation->validate(['car_plate' => 'XYZ-123']);
                expect($messages)->count(0);
            }
        );
    }

    /**
     * Tests regex validator with multiple field and single pattern
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleFieldSinglePattern()
    {
        $this->specify('Test regex validator with multiple field and single pattern.', function () {
            $validation = new Validation();
            $validationMessages = [
                'name' => 'Name can be only lowercase letters.',
                'type' => 'Type can be only lowercase letters.',
            ];
            $validation->add(['name', 'type'], new Validation\Validator\Regex([
                'pattern' => '/^[a-z]+$/',
                'message' => $validationMessages,
            ]));
            $messages = $validation->validate(['name' => 'somevalue', 'type' => 'somevalue']);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['name' => 'SomeValue', 'type' => 'somevalue']);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['name']);
            $messages = $validation->validate(['name' => 'SomeValue', 'type' => 'SomeValue']);
            expect($messages->count())->equals(2);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['name']);
            expect($messages->offsetGet(1)->getMessage())->equals($validationMessages['type']);
        });
    }

    /**
     * Tests regex validator with multiple field and pattern
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleFieldMultiplePattern()
    {
        $this->specify('Test regex validator with multiple field and pattern.', function () {
            $validation = new Validation();
            $validationMessages = [
                'name' => 'Name can be only lowercase letters.',
                'type' => 'Type can be only uppercase letters.',
            ];
            $validation->add(['name', 'type'], new Validation\Validator\Regex([
                'pattern' => [
                    'name' => '/^[a-z]+$/',
                    'type' => '/^[A-Z]+$/',
                ],
                'message' => $validationMessages,
            ]));
            $messages = $validation->validate(['name' => 'somevalue', 'type' => 'SOMEVALUE']);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['name' => 'SomeValue', 'type' => 'SOMEVALUE']);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['name']);
            $messages = $validation->validate(['name' => 'somevalue', 'type' => 'somevalue']);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['type']);
            $messages = $validation->validate(['name' => 'SomeValue', 'type' => 'SomeValue']);
            expect($messages->count())->equals(2);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['name']);
            expect($messages->offsetGet(1)->getMessage())->equals($validationMessages['type']);
        });
    }

    public function testCustomMessage()
    {
        $this->specify(
            'Test Regex validator works with a custom message.',
            function () {
                $validation = new Validation();

                $validation->add(
                    'car_plate',
                    new Validation\Validator\Regex(
                        [
                            'pattern' => '/[A-Z]{3}\-[0-9]{3}/',
                            'message' => 'The car plate is not valid'
                        ]
                    )
                );

                $messages = $validation->validate([]);

                $expectedMessages = Validation\Message\Group::__set_state(
                    [
                        '_messages' => [
                            0 => Validation\Message::__set_state(
                                [
                                    '_type'    => 'Regex',
                                    '_message' => 'The car plate is not valid',
                                    '_field'   => 'car_plate',
                                    '_code'    => '0',
                                ]
                            )
                        ]
                    ]
                );

                expect($expectedMessages)->equals($messages);

                $messages = $validation->validate(['car_plate' => 'XYZ-123']);
                expect($messages)->count(0);
            }
        );
    }
}
