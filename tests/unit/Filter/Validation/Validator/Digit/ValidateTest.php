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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\Digit;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exception;
use Phalcon\Filter\Validation\Validator\Digit;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

use const PHP_INT_MAX;

final class ValidateTest extends AbstractUnitTestCase
{
    /**
     * @return array
     */
    public static function getExamplesIntOrStringOfDigits()
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

    /**
     * @dataProvider getExamplesIntOrStringOfDigits
     *
     */
    public function testFilterValidationValidatorDigitIntOrStringOfDigits(
        mixed $digit
    ): void {
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

        $this->assertSame(
            0,
            $messages->count()
        );
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorDigitMultipleField(): void
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

        $this->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'amount' => '123abc',
                'price'  => '123',
            ]
        );

        $this->assertSame(
            1,
            $messages->count()
        );

        $this->assertSame(
            $validationMessages['amount'],
            $messages->offsetGet(0)->getMessage()
        );


        $messages = $validation->validate(
            [
                'amount' => '123abc',
                'price'  => '123abc',
            ]
        );

        $this->assertSame(
            2,
            $messages->count()
        );

        $this->assertSame(
            $validationMessages['amount'],
            $messages->offsetGet(0)->getMessage()
        );

        $this->assertSame(
            $validationMessages['price'],
            $messages->offsetGet(1)->getMessage()
        );
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorDigitSingleField(): void
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

        $this->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'amount' => '123abc',
            ]
        );

        $this->assertSame(
            1,
            $messages->count()
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-03
     */
    public function testFilterValidationValidatorDigitValidateEmpty(): void
    {
        $validation = new Validation();
        $validator  = new Digit(['allowEmpty' => true,]);
        $validation->add('price', $validator);
        $entity        = new stdClass();
        $entity->price = '';

        $validation->bind($entity, []);
        $result = $validator->validate($validation, 'price');
        $this->assertTrue($result);
    }
}
