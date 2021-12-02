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
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\Numericality;

class NumericalityCest
{
    /**
     * Tests numericality validator with single field
     *
     * @author       Wojciech Ślawski <jurigag@gmail.com>
     * @author       Andrey Izman <izmanw@gmail.com>
     * @since        2016-06-05
     *
     * @dataProvider validationValidatorSingleFieldProvider
     */
    public function filterValidationValidatorSingleField(IntegrationTester $I, Example $example)
    {
        $validation = new Validation();

        $validation->add(
            'amount',
            new Numericality()
        );

        $messages = $validation->validate(
            [
                'amount' => $example['amount'],
            ]
        );

        $I->assertEquals(
            $example['expected'],
            $messages->count()
        );
    }

    /**
     * Tests numericality validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorMultipleField(IntegrationTester $I)
    {
        $validation = new Validation();

        $validationMessages = [
            'amount' => 'Amount must be digit.',
            'price'  => 'Price must be digit.',
        ];

        $validation->add(
            [
                'amount',
                'price',
            ],
            new Numericality(
                [
                    'message' => $validationMessages,
                ]
            )
        );

        $messages = $validation->validate(
            [
                'amount' => 123,
                'price'  => 123,
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );

        $messages = $validation->validate(
            [
                'amount' => '123abc',
                'price'  => 123,
            ]
        );

        $I->assertEquals(
            1,
            $messages->count()
        );

        $expected = $validationMessages['amount'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

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

        $expected = $validationMessages['amount'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['price'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $I->assertEquals($expected, $actual);
    }

    private function validationValidatorSingleFieldProvider(): array
    {
        return [
            [
                'amount'   => 123,
                'expected' => 0,
            ],

            [
                'amount'   => 123.12,
                'expected' => 0,
            ],

            [
                'amount'   => '123abc',
                'expected' => 1,
            ],

            [
                'amount'   => '123.12e3',
                'expected' => 1,
            ],
        ];
    }
}
