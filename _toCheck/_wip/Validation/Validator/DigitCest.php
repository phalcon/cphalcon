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
use Phalcon\Validation\Validator\Digit;
use UnitTester;

class DigitCest
{
    /**
     * Tests digit validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testSingleField(UnitTester $I)
    {
        $validation = new Validation();
        $validation->add('amount', new Digit());

        $messages = $validation->validate(['amount' => '123']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['amount' => '123abc']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests digit validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleField(UnitTester $I)
    {
        $validation         = new Validation();
        $validationMessages = [
            'amount' => 'Amount must be digit.',
            'price'  => 'Price must be digit.',
        ];
        $validation->add(
            ['amount', 'price'],
            new Digit(
                [
                    'message' => $validationMessages,
                ]
            )
        );

        $messages = $validation->validate(['amount' => '123', 'price' => '123']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['amount' => '123abc', 'price' => '123']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['amount'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['amount' => '123abc', 'price' => '123abc']);
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

    public function testShouldValidateIntOrStringOfDigits(UnitTester $I)
    {
        $examples = [
            '123',
            123,
            PHP_INT_MAX,
            0xFFFFFF,
            100000,
            -100000,
            0,
            "0",
            "00001233422003400",
        ];

        foreach ($examples as $digit) {
            $validation = new Validation();
            $validation->add('amount', new Digit());

            $messages = $validation->validate(['amount' => $digit]);
            $expected = 0;
            $actual   = $messages->count();
            $I->assertEquals($expected, $actual);
        }
    }
}
