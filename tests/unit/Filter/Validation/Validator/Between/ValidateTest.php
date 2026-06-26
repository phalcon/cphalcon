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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\Between;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exception;
use Phalcon\Filter\Validation\Validator\Between;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

final class ValidateTest extends AbstractUnitTestCase
{
    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorBetweenValidateCustomMessage(): void
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

        $this->assertEquals($expected, $messages);

        $this->assertEquals(
            $validation->validate([]),
            $messages
        );

        $messages = $validation->validate(
            [
                'price' => 2,
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-03
     */
    public function testFilterValidationValidatorBetweenValidateEmpty(): void
    {
        $validation = new Validation();
        $validator  = new Between(
            [
                'allowEmpty' => true,
                'minimum'    => 1,
                'maximum'    => 3,
            ]
        );
        $validation->add('price', $validator);
        $entity        = new stdClass();
        $entity->price = '';

        $validation->bind($entity, []);
        $result = $validator->validate($validation, 'price');
        $this->assertTrue($result);
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorBetweenValidateMultipleField(): void
    {
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

        $this->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'amount' => 1000,
                'price'  => 100,
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
                'amount' => 1000,
                'price'  => 1000,
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
    public function testFilterValidationValidatorBetweenValidateSingleField(): void
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

        $this->assertEquals($expected, $messages);

        $messages = $validation->validate(
            []
        );

        $this->assertEquals($expected, $messages);

        $messages = $validation->validate(
            [
                'price' => 2,
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );
    }
}
