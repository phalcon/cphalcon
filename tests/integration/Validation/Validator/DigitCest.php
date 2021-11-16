<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Integration\Validation\Validator;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Digit;

class DigitCest
{
    /**
     * Tests digit validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorSingleField(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            'amount',
            new Digit()
        );


        $messages = $validation->validate(
            [
                'amount' => '123',
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'amount' => '123abc',
            ]
        );

        $I->assertEquals(
            1,
            $messages->count()
        );
    }

    /**
     * Tests digit validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorMultipleField(IntegrationTester $I)
    {
        $validation = new Validation();

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


        $messages = $validation->validate(
            [
                'amount' => '123',
                'price'  => '123',
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'amount' => '123abc',
                'price'  => '123',
            ]
        );

        $I->assertEquals(
            1,
            $messages->count()
        );

        $I->assertEquals(
            $validationMessages['amount'],
            $messages->offsetGet(0)->getMessage()
        );


        $messages = $validation->validate(
            [
                'amount' => '123abc',
                'price'  => '123abc',
            ]
        );

        $I->assertEquals(
            2,
            $messages->count()
        );

        $I->assertEquals(
            $validationMessages['amount'],
            $messages->offsetGet(0)->getMessage()
        );

        $I->assertEquals(
            $validationMessages['price'],
            $messages->offsetGet(1)->getMessage()
        );
    }

    /**
     * @dataProvider shouldValidateIntOrStringOfDigitsProvider
     */
    public function validationValidatorShouldValidateIntOrStringOfDigits(IntegrationTester $I, Example $example)
    {
        $digit = $example[0];

        $validation = new Validation();

        $validation->add(
            'amount',
            new Digit()
        );

        $messages = $validation->validate(
            [
                'amount' => $digit,
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );
    }

    private function shouldValidateIntOrStringOfDigitsProvider()
    {
        return [
            ['123'],
            [123],
            [PHP_INT_MAX],
            [0xFFFFFF],
            [100000],
            [-100000],
            [0],
            ['0'],
            ['00001233422003400'],
        ];
    }
}
