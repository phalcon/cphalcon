<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Between;

/**
 * \Phalcon\Test\Unit\Validation\Validator\BetweenTest
 * Tests the \Phalcon\Validation\Validator\Between component
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
class BetweenTest extends UnitTest
{
    /**
     * Tests between validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testSingleField()
    {
        $this->specify('Test between validator with single field.', function () {
            $validation = new Validation();

            $validation->add(
                'price',
                new Between(
                    [
                        'minimum' => 1,
                        'maximum' => 3
                    ]
                )
            );

            $messages = $validation->validate(['price' => 5]);

            $expectedMessages = Validation\Message\Group::__set_state(
                [
                    '_messages' => [
                        0 => Validation\Message::__set_state(
                            [
                                '_type'    => 'Between',
                                '_message' => 'Field price must be within the range of 1 to 3',
                                '_field'   => 'price',
                                '_code'    => '0',
                            ]
                        )
                    ]
                ]
            );

            expect($expectedMessages)->equals($messages);

            $messages = $validation->validate([]);
            expect($expectedMessages)->equals($messages);

            $messages = $validation->validate(['price' => 2]);
            expect($messages)->count(0);
        });
    }

    /**
     * Tests between validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleField()
    {
        $this->specify('Test between validator with multiple field.', function () {
            $validation = new Validation();
            $validationMessages = [
                'amount' => 'Amount must be between 0 and 999.',
                'price' => 'Price must be between 0 and 999.',
            ];
            $validation->add(['amount', 'price'], new Between([
                'minimum' => [
                    'amount' => 0,
                    'price' => 0,
                ],
                'maximum' => [
                    'amount' => 999,
                    'price' => 999,
                ],
                'message' => $validationMessages,
            ]));
            $messages = $validation->validate(['amount' => 100]);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['amount' => 1000, 'price' => 100]);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['amount']);
            $messages = $validation->validate(['amount' => 1000, 'price' => 1000]);
            expect($messages->count())->equals(2);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['amount']);
            expect($messages->offsetGet(1)->getMessage())->equals($validationMessages['price']);
        });
    }

    public function testCustomMessage()
    {
        $this->specify(
            'Test Between validator works with a custom message.',
            function () {
                $validation = new Validation();

                $validation->add(
                    'price',
                    new Between(
                        [
                            'minimum' => 1,
                            'maximum' => 3,
                            'message' => 'The price must be between 1 and 3'
                        ]
                    )
                );

                $messages = $validation->validate(['price' => 5]);

                $expectedMessages = Validation\Message\Group::__set_state(
                    [
                        '_messages' => [
                            0 => Validation\Message::__set_state(
                                [
                                    '_type'    => 'Between',
                                    '_message' => 'The price must be between 1 and 3',
                                    '_field'   => 'price',
                                    '_code'    => '0',
                                ]
                            )
                        ]
                    ]
                );

                $this->assertEquals($expectedMessages, $messages);

                $messages = $validation->validate([]);
                expect($expectedMessages)->equals($messages);

                $messages = $validation->validate(['price' => 2]);
                expect($messages)->count(0);
            }
        );
    }
}
