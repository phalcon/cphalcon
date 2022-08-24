<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Integration\Filter\Validation\Validator;

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
     * @dataProvider getExamples
     */
    public function filterValidationValidatorSingleField(IntegrationTester $I, Example $example)
    {
        $validation = new Validation();
        $validation->add('amount', new Numericality());

        $amount   = $example['amount'];
        $expected = $example['expected'];
        $messages = $validation->validate(
            [
                'amount' => $amount,
            ]
        );

        $actual = $messages->count();
        $I->assertEquals($expected, $actual);
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

        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(
            [
                'amount' => '123abc',
                'price'  => 123,
            ]
        );

        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['amount'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(
            [
                'amount' => '123abc',
                'price'  => '123abc',
            ]
        );

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

    /**
     * @return array
     */
    private function getExamples(): array
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
                'amount'   => '-12,000',
                'expected' => 0,
            ],
            [
                'amount'   => '-12,0@0',
                'expected' => 1,
            ],
            [
                'amount'   => '-12,0@@0',
                'expected' => 1,
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
