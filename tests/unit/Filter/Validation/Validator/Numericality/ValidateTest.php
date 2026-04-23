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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\Numericality;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exception;
use Phalcon\Filter\Validation\Validator\Numericality;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

final class ValidateTest extends AbstractUnitTestCase
{
    /**
     * @return array
     */
    public static function getExamples(): array
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

    /**
     * @return array[]
     */
    public static function getMixedExamples(): array
    {
        return [
            [1, true],
            [123, true],
            [123.45, true],
            ['1 234.56', false],
            ['1,234.56', true],
            ['1.23', true],
            ['1.123,56', true],
            ['1 234.56aa', false],
            ['1,234.56aa', false],
            ['1.23aa', false],
            ['1.123,56aa', false],
            [-1, true],
            [-123, true],
            [-123.45, true],
            ['-1 234.56', false],
            ['-1,234.56', true],
            ['-1.23', true],
            ['-1.123,56', true],
            ['-1 234.56aa', false],
            ['-1,234.56aa', false],
            ['-1.23aa', false],
            ['-1.123,56aa', false],
            ['-12,000', true],
            ['-12,0@0', false],
            ['-12,0@@0', false],
            [' 1', false],
            ['1 ', false],
            ['1 1', false],
        ];
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorNumericalityMultipleField(): void
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
        $this->assertSame($expected, $actual);

        $messages = $validation->validate(
            [
                'amount' => '123abc',
                'price'  => 123,
            ]
        );

        $expected = 1;
        $actual   = $messages->count();
        $this->assertSame($expected, $actual);

        $expected = $validationMessages['amount'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $this->assertSame($expected, $actual);

        $messages = $validation->validate(
            [
                'amount' => '123abc',
                'price'  => '123abc',
            ]
        );

        $expected = 2;
        $actual   = $messages->count();
        $this->assertSame($expected, $actual);

        $expected = $validationMessages['amount'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $this->assertSame($expected, $actual);

        $expected = $validationMessages['price'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $this->assertSame($expected, $actual);
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Wojciech Ślawski <jurigag@gmail.com>
     * @author       Andrey Izman <izmanw@gmail.com>
     * @since        2016-06-05
     */
    public function testFilterValidationValidatorNumericalitySingleField(
        mixed $amount,
        int $expected
    ): void {
        $validation = new Validation();
        $validation->add('amount', new Numericality());

        $messages = $validation->validate(
            [
                'amount' => $amount,
            ]
        );

        $actual = $messages->count();
        $this->assertSame($expected, $actual);
    }

    /**
     * @dataProvider getMixedExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function testFilterValidationValidatorNumericalityValidate(
        mixed $price,
        bool $expected
    ): void {
        $entity        = new stdClass();
        $entity->price = $price;

        $validation = new Validation();
        $validation->setEntity($entity);
        $validator = new Numericality();

        $actual = $validator->validate($validation, 'price');
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-03
     */
    public function testFilterValidationValidatorNumericalityValidateEmpty(): void
    {
        $validation = new Validation();
        $validator  = new Numericality(['allowEmpty' => true,]);
        $validation->add('price', $validator);
        $entity        = new stdClass();
        $entity->price = '';

        $validation->bind($entity, []);
        $result = $validator->validate($validation, 'price');
        $this->assertTrue($result);
    }
}
