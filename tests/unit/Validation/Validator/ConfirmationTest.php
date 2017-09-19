<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Validation;
use Phalcon\Validation\Message;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation\Message\Group;
use Phalcon\Validation\Validator\Confirmation;

/**
 * \Phalcon\Test\Unit\Validation\Validator\ConfirmationTest
 * Tests the \Phalcon\Validation\Validator\Confirmation component
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
class ConfirmationTest extends UnitTest
{
    /**
     * Tests confirmation validator with single field
     *
     * @test
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function shouldValidateSingleField()
    {
        $this->specify('Test confirmation validator with single field.', function () {
            $validation = new Validation();
            $validation->add('name', new Confirmation([
                'with' => 'nameWith',
            ]));

            $messages = $validation->validate(
                [
                    'name'     => 'SomeValue',
                    'nameWith' => 'SomeValue',
                ]
            );

            expect($messages->count())->equals(0);

            $messages = $validation->validate(
                [
                    'name'     => 'SomeValue',
                    'nameWith' => 'SomeValue123',
                ]
            );

            expect($messages->count())->equals(1);
        });
    }

    /**
     * Tests confirmation validator with multiple field
     *
     * @test
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function shouldValidateMultipleField()
    {
        $this->specify('Test confirmation validator with multiple field.', function () {
            $validation = new Validation();
            $validationMessages = [
                'name' => 'Name must be same as nameWith.',
                'type' => 'Type must be same as typeWith.',
            ];
            $validation->add(['name', 'type'], new Confirmation([
                'with' => [
                    'name' => 'nameWith',
                    'type' => 'typeWith',
                ],
                'message' => $validationMessages,
            ]));

            $messages = $validation->validate(
                [
                    'name'     => 'SomeValue',
                    'nameWith' => 'SomeValue',
                    'type'     => 'SomeValue',
                    'typeWith' => 'SomeValue',
                ]
            );

            expect($messages->count())->equals(0);

            $messages = $validation->validate(
                [
                    'name'     => 'SomeValue',
                    'nameWith' => 'SomeValue123',
                    'type'     => 'SomeValue',
                    'typeWith' => 'SomeValue',
                ]
            );

            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['name']);

            $messages = $validation->validate(
                [
                    'name'     => 'SomeValue',
                    'nameWith' => 'SomeValue123',
                    'type'     => 'SomeValue',
                    'typeWith' => 'SomeValue123',
                ]
            );

            expect($messages->count())->equals(2);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['name']);
            expect($messages->offsetGet(1)->getMessage())->equals($validationMessages['type']);
        });
    }

    /**
     * Tests allowing empty value
     *
     * @test
     * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
     * @since  2015-09-06
     */
    public function shouldAllowEmptyValues()
    {
        $this->specify(
            'The Confirmation validator should allow empty value',
            function () {
                $expected = Group::__set_state([
                    '_messages' => [
                        Message::__set_state([
                            '_type' => 'Confirmation',
                            '_message' => 'Field password must be the same as password2',
                            '_field' => 'password',
                            '_code' => '0',
                        ]),
                    ]
                ]);

                $validation = new Validation();
                $validation->add('password', new Confirmation([
                    'allowEmpty' => true,
                    'with'       => 'password2'
                ]));

                $actual = $validation->validate([
                    'password'  => 'test123',
                    'password2' => 'test123'
                ]);

                expect($actual)->count(0);

                $actual = $validation->validate([
                    'password'  => null,
                    'password2' => 'test123'
                ]);

                expect($actual)->count(0);

                $validation = new Validation();
                $validation->add('password', new Confirmation([
                    'allowEmpty' => false,
                    'with'       => 'password2'
                ]));

                $actual = $validation->validate([
                    'password'  => 'test123',
                    'password2' => 'test123'
                ]);

                expect($actual)->count(0);

                $actual = $validation->validate([
                    'password'  => null,
                    'password2' => 'test123'
                ]);

                expect($actual)->count(1);
                expect($actual)->equals($expected);

                $validation = new Validation();
                $validation->add('password', new Confirmation(['with' => 'password2']));

                $actual = $validation->validate([
                    'password'  => 'test123',
                    'password2' => 'test123'
                ]);

                expect($actual)->count(0);

                $actual = $validation->validate([
                    'password'  => null,
                    'password2' => 'test123'
                ]);

                expect($actual)->count(1);
                expect($actual)->equals($expected);
            }
        );
    }
}
