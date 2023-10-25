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

namespace Phalcon\Tests\Integration\Filter\Validation\Validator\Digit;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exception;
use Phalcon\Filter\Validation\Validator\Digit;
use stdClass;

use const PHP_INT_MAX;

/**
 * Class ValidateCest
 */
class ValidateCest
{
    /**
     * Tests Phalcon\Filter\Validation\Validator\Digit :: validate() - empty
     *
     * @param IntegrationTester $I
     *
     * @return void
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-03
     */
    public function filterValidationValidatorDigitValidateEmpty(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Digit - validate() - empty");

        $validation = new Validation();
        $validator  = new Digit(['allowEmpty' => true,]);
        $validation->add('price', $validator);
        $entity        = new stdClass();
        $entity->price = '';

        $validation->bind($entity, []);
        $result = $validator->validate($validation, 'price');
        $I->assertTrue($result);
    }

    /**
     * Tests digit validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorDigitSingleField(IntegrationTester $I)
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

        $I->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'amount' => '123abc',
            ]
        );

        $I->assertSame(
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
    public function filterValidationValidatorDigitMultipleField(IntegrationTester $I)
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

        $I->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'amount' => '123abc',
                'price'  => '123',
            ]
        );

        $I->assertSame(
            1,
            $messages->count()
        );

        $I->assertSame(
            $validationMessages['amount'],
            $messages->offsetGet(0)->getMessage()
        );


        $messages = $validation->validate(
            [
                'amount' => '123abc',
                'price'  => '123abc',
            ]
        );

        $I->assertSame(
            2,
            $messages->count()
        );

        $I->assertSame(
            $validationMessages['amount'],
            $messages->offsetGet(0)->getMessage()
        );

        $I->assertSame(
            $validationMessages['price'],
            $messages->offsetGet(1)->getMessage()
        );
    }

    /**
     * @dataProvider getExamplesIntOrStringOfDigits
     *
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @return void
     * @throws Exception
     */
    public function filterValidationValidatorDigitIntOrStringOfDigits(IntegrationTester $I, Example $example)
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

        $I->assertSame(
            0,
            $messages->count()
        );
    }

    /**
     * @return array
     */
    private function getExamplesIntOrStringOfDigits()
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
