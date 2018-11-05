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
use UnitTester;

class BetweenCest
{
    /**
     * Tests between validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testSingleField(UnitTester $I)
    {
        $validation = new Validation();
        $validation->add(
            'price',
            new Between(
                [
                    'minimum' => 1,
                    'maximum' => 3,
                ]
            )
        );

        $messages = $validation->validate(['price' => 5]);

        $expected = Messages::__set_state(
            [
                '_messages' => [
                    0 => Message::__set_state(
                        [
                            '_type'    => 'Between',
                            '_message' => 'Field price must be within the range of 1 to 3',
                            '_field'   => 'price',
                            '_code'    => '0',
                        ]
                    ),
                ],
            ]
        );
        $actual   = $messages;
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate([]);
        $actual   = $messages;
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['price' => 2]);

        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests between validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleField(UnitTester $I)
    {
        $validation         = new Validation();
        $validationMessages = [
            'amount' => 'Amount must be between 0 and 999.',
            'price'  => 'Price must be between 0 and 999.',
        ];
        $validation->add(
            [
                'amount',
                'price',
            ],
            new Between(
                [
                    'minimum' => [
                        'amount' => 0,
                        'price'  => 0,
                    ],
                    'maximum' => [
                        'amount' => 999,
                        'price'  => 999,
                    ],
                    'message' => $validationMessages,
                ]
            )
        );

        $messages = $validation->validate(['amount' => 100]);

        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['amount' => 1000, 'price' => 100]);

        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['amount'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['amount' => 1000, 'price' => 1000]);

        $expected = 2;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['amount'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['price'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $I->assertEquals($expected, $actual);
    }

    public function testCustomMessage(UnitTester $I)
    {
        $validation = new Validation();

        $validation->add(
            'price',
            new Between(
                [
                    'minimum' => 1,
                    'maximum' => 3,
                    'message' => 'The price must be between 1 and 3',
                ]
            )
        );

        $messages = $validation->validate(['price' => 5]);

        $expected = Messages::__set_state(
            [
                '_messages' => [
                    0 => Message::__set_state(
                        [
                            '_type'    => 'Between',
                            '_message' => 'The price must be between 1 and 3',
                            '_field'   => 'price',
                            '_code'    => '0',
                        ]
                    ),
                ],
            ]
        );
        $actual   = $messages;
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate([]);
        $actual   = $messages;
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['price' => 2]);

        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);
    }
}
