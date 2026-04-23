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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\Identical;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exception;
use Phalcon\Filter\Validation\Validator\Identical;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

final class ValidateTest extends AbstractUnitTestCase
{
    public function testFilterValidationValidatorIdenticalCustomMessage(): void
    {
        $validation = new Validation();

        $validation->add(
            'name',
            new Identical(
                [
                    'accepted' => 'Peter',
                    'message'  => 'The name must be peter',
                ]
            )
        );


        $messages = $validation->validate(
            []
        );

        $expected = new Messages(
            [
                new Message(
                    'The name must be peter',
                    'name',
                    Identical::class,
                    0
                ),
            ]
        );

        $this->assertEquals($expected, $messages);

        $messages = $validation->validate(
            [
                'name' => 'Peter',
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
    public function testFilterValidationValidatorIdenticalMultipleFieldMultipleAccepted(): void
    {
        $validation = new Validation();

        $validationMessages = [
            'name'        => 'Name must be SomeValue.',
            'anotherName' => 'AnotherName must be SomeAnotherValue.',
        ];

        $validation->add(
            [
                'name',
                'anotherName',
            ],
            new Identical(
                [
                    'accepted' => [
                        'name'        => 'SomeValue',
                        'anotherName' => 'SomeAnotherValue',
                    ],
                    'message'  => $validationMessages,
                ]
            )
        );


        $messages = $validation->validate(
            [
                'name'        => 'SomeValue',
                'anotherName' => 'SomeAnotherValue',
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name'        => 'SomeValue123',
                'anotherName' => 'SomeAnotherValue',
            ]
        );

        $this->assertSame(
            1,
            $messages->count()
        );

        $this->assertSame(
            $validationMessages['name'],
            $messages->offsetGet(0)->getMessage()
        );


        $messages = $validation->validate(
            [
                'name'        => 'SomeValue',
                'anotherName' => 'SomeAnotherValue123',
            ]
        );

        $this->assertSame(
            1,
            $messages->count()
        );

        $this->assertSame(
            $validationMessages['anotherName'],
            $messages->offsetGet(0)->getMessage()
        );


        $messages = $validation->validate(
            [
                'name'        => 'SomeValue123',
                'anotherName' => 'SomeAnotherValue123',
            ]
        );

        $this->assertSame(
            2,
            $messages->count()
        );

        $this->assertSame(
            $validationMessages['name'],
            $messages->offsetGet(0)->getMessage()
        );

        $this->assertSame(
            $validationMessages['anotherName'],
            $messages->offsetGet(1)->getMessage()
        );
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorIdenticalMultipleFieldSingleAccepted(): void
    {
        $validation = new Validation();

        $validationMessages = [
            'name'        => 'Name must be SomeValue.',
            'anotherName' => 'AnotherName must be SomeValue.',
        ];

        $validation->add(
            [
                'name',
                'anotherName',
            ],
            new Identical(
                [
                    'accepted' => 'SomeValue',
                    'message'  => $validationMessages,
                ]
            )
        );

        $messages = $validation->validate(
            [
                'name'        => 'SomeValue',
                'anotherName' => 'SomeValue',
            ]
        );

        $expected = 0;
        $actual   = $messages->count();
        $this->assertSame($expected, $actual);

        $messages = $validation->validate(
            [
                'name'        => 'SomeValue123',
                'anotherName' => 'SomeValue',
            ]
        );

        $expected = 1;
        $actual   = $messages->count();
        $this->assertSame($expected, $actual);

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $this->assertSame($expected, $actual);

        $messages = $validation->validate(
            [
                'name'        => 'SomeValue123',
                'anotherName' => 'SomeValue123',
            ]
        );

        $expected = 2;
        $actual   = $messages->count();
        $this->assertSame($expected, $actual);

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $this->assertSame($expected, $actual);

        $expected = $validationMessages['anotherName'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorIdenticalMultipleFieldSingleValue(): void
    {
        $validation = new Validation();

        $validationMessages = [
            'name'        => 'Name must be SomeValue.',
            'anotherName' => 'AnotherName must be SomeValue.',
        ];

        $validation->add(
            [
                'name',
                'anotherName',
            ],
            new Identical(
                [
                    'value'   => 'SomeValue',
                    'message' => $validationMessages,
                ]
            )
        );

        $messages = $validation->validate(
            [
                'name'        => 'SomeValue',
                'anotherName' => 'SomeValue',
            ]
        );

        $expected = 0;
        $actual   = $messages->count();
        $this->assertSame($expected, $actual);

        $messages = $validation->validate(
            [
                'name'        => 'SomeValue123',
                'anotherName' => 'SomeValue',
            ]
        );

        $expected = 1;
        $actual   = $messages->count();
        $this->assertSame($expected, $actual);

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $this->assertSame($expected, $actual);

        $messages = $validation->validate(
            [
                'name'        => 'SomeValue123',
                'anotherName' => 'SomeValue123',
            ]
        );

        $expected = 2;
        $actual   = $messages->count();
        $this->assertSame($expected, $actual);

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $this->assertSame($expected, $actual);

        $expected = $validationMessages['anotherName'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorIdenticalSingleField(): void
    {
        $validation = new Validation();

        $validation->add(
            'name',
            new Identical(
                [
                    'accepted' => 'SomeValue',
                ]
            )
        );


        $messages = $validation->validate(
            [
                'name' => 'SomeValue',
            ]
        );

        $expected = 0;
        $actual   = $messages->count();
        $this->assertSame($expected, $actual);

        $messages = $validation->validate(
            [
                'name' => 'SomeValue123',
            ]
        );

        $expected = 1;
        $actual   = $messages->count();
        $this->assertSame($expected, $actual);


        $expected = new Messages(
            [
                new Message(
                    'Field name does not have the expected value',
                    'name',
                    Identical::class,
                    0
                ),
            ]
        );

        $this->assertEquals($expected, $messages);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-03
     */
    public function testFilterValidationValidatorIdenticalValidateEmpty(): void
    {
        $validation = new Validation();
        $validator  = new Identical(['allowEmpty' => true,]);
        $validation->add('price', $validator);
        $entity        = new stdClass();
        $entity->price = '';

        $validation->bind($entity, []);
        $result = $validator->validate($validation, 'price');
        $this->assertTrue($result);
    }
}
