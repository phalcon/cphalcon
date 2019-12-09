<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\Validation\Validator\Between;

use IntegrationTester;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Between;

/**
 * Class ValidateCest
 */
class ValidateCest
{
    /**
     * Tests Phalcon\Validation\Validator\Between :: validate() - single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorBetweenValidateSingleField(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Between - validate() - single field");

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


        $messages = $validation->validate(
            [
                'price' => 5,
            ]
        );

        $expected = new Messages(
            [
                new Message(
                    'Field price must be within the range of 1 to 3',
                    'price',
                    Between::class,
                    0
                ),
            ]
        );

        $I->assertEquals($expected, $messages);


        $messages = $validation->validate(
            []
        );

        $I->assertEquals($expected, $messages);


        $messages = $validation->validate(
            [
                'price' => 2,
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );
    }

    /**
     * Tests Phalcon\Validation\Validator\Between :: validate() - multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorBetweenValidateMultipleField(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Between - validate() - multiple field");

        $validation = new Validation();

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


        $messages = $validation->validate(
            [
                'amount' => 100,
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'amount' => 1000,
                'price'  => 100,
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
                'amount' => 1000,
                'price'  => 1000,
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
     * Tests Phalcon\Validation\Validator\Between :: validate() - custom message
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorBetweenValidateCustomMessage(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Between - validate() - custom message");

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


        $messages = $validation->validate(
            [
                'price' => 5,
            ]
        );

        $expected = new Messages(
            [
                new Message(
                    'The price must be between 1 and 3',
                    'price',
                    Between::class,
                    0
                ),
            ]
        );

        $I->assertEquals($expected, $messages);


        $I->assertEquals(
            $validation->validate([]),
            $messages
        );


        $messages = $validation->validate(
            [
                'price' => 2,
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );
    }
}
