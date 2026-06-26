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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\ExclusionIn;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exception;
use Phalcon\Filter\Validation\Validator\ExclusionIn;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

final class ValidateTest extends AbstractUnitTestCase
{
    public function testFilterValidationValidatorExclusionInCustomMessage(): void
    {
        $validation = new Validation();

        $validation->add(
            'status',
            new ExclusionIn(
                [
                    'message' => 'The status must not be A=Active or I=Inactive',
                    'domain'  => ['A', 'I'],
                ]
            )
        );


        $messages = $validation->validate(
            [
                'status' => 'A',
            ]
        );

        $expected = new Messages(
            [
                new Message(
                    'The status must not be A=Active or I=Inactive',
                    'status',
                    ExclusionIn::class,
                    0
                ),
            ]
        );

        $this->assertEquals($expected, $messages);


        $messages = $validation->validate(
            [
                'status' => 'A',
            ]
        );

        $this->assertEquals($expected, $messages);

        $messages = $validation->validate(
            [
                'status' => 'X',
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );
    }

    /**
     * @author Phalcon Team <tram@phalcon.io>
     * @since  2023-08-03
     */
    public function testFilterValidationValidatorExclusionInExceptionsDomain(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage("Option 'domain' must be an array");

        $validation = new Validation();
        $validator  = new ExclusionIn(
            [
                "message" => "The status must not be A or B",
                "domain"  => "A",
            ]
        );
        $validation->add('status', $validator);
        $entity         = new stdClass();
        $entity->status = '';

        $validation->bind($entity, []);
        $validator->validate($validation, 'status');
    }

    /**
     * @author Phalcon Team <tram@phalcon.io>
     * @since  2023-08-03
     */
    public function testFilterValidationValidatorExclusionInExceptionsStrict(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage("Option 'strict' must be a bool");

        $validation = new Validation();
        $validator  = new ExclusionIn(
            [
                "message" => "The status must not be A or B",
                "domain"  => [
                    "A",
                    "B",
                ],
                "strict"  => "x",
            ]
        );

        $validation->add('status', $validator);
        $entity         = new stdClass();
        $entity->status = '';

        $validation->bind($entity, []);
        $validator->validate($validation, 'status');
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorExclusionInMultipleFieldMultipleDomain(): void
    {
        $validation         = new Validation();
        $validationMessages = [
            'type'        => 'Type cant be mechanic or cyborg.',
            'anotherType' => 'AnotherType cant by mechanic or hydraulic.',
        ];
        $validation->add(
            [
                'type',
                'anotherType',
            ],
            new ExclusionIn(
                [
                    'domain'  => [
                        'type'        => ['mechanic', 'cyborg'],
                        'anotherType' => ['mechanic', 'hydraulic'],
                    ],
                    'message' => $validationMessages,
                ]
            )
        );
        $messages = $validation->validate(['type' => 'hydraulic', 'anotherType' => 'cyborg']);
        $expected = 0;
        $actual   = $messages->count();
        $this->assertSame($expected, $actual);

        $messages = $validation->validate(['type' => 'cyborg', 'anotherType' => 'cyborg']);
        $expected = 1;
        $actual   = $messages->count();
        $this->assertSame($expected, $actual);

        $expected = $validationMessages['type'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $this->assertSame($expected, $actual);

        $messages = $validation->validate(['type' => 'hydraulic', 'anotherType' => 'mechanic']);
        $expected = 1;
        $actual   = $messages->count();
        $this->assertSame($expected, $actual);

        $expected = $validationMessages['anotherType'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $this->assertSame($expected, $actual);

        $messages = $validation->validate(['type' => 'cyborg', 'anotherType' => 'mechanic']);
        $expected = 2;
        $actual   = $messages->count();
        $this->assertSame($expected, $actual);

        $expected = $validationMessages['type'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $this->assertSame($expected, $actual);

        $expected = $validationMessages['anotherType'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorExclusionInMultipleFieldSingleDomain(): void
    {
        $validation = new Validation();

        $validationMessages = [
            'type'        => 'Type cant be mechanic or cyborg.',
            'anotherType' => 'AnotherType cant by mechanic or cyborg.',
        ];

        $validation->add(
            [
                'type',
                'anotherType',
            ],
            new ExclusionIn(
                [
                    'domain'  => ['mechanic', 'cyborg'],
                    'message' => $validationMessages,
                ]
            )
        );
        $messages = $validation->validate(['type' => 'hydraulic', 'anotherType' => 'hydraulic']);
        $expected = 0;
        $actual   = $messages->count();
        $this->assertSame($expected, $actual);

        $messages = $validation->validate(['type' => 'cyborg', 'anotherType' => 'hydraulic']);
        $expected = 1;
        $actual   = $messages->count();
        $this->assertSame($expected, $actual);

        $expected = $validationMessages['type'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $this->assertSame($expected, $actual);

        $messages = $validation->validate(['type' => 'cyborg', 'anotherType' => 'mechanic']);
        $expected = 2;
        $actual   = $messages->count();
        $this->assertSame($expected, $actual);

        $expected = $validationMessages['type'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $this->assertSame($expected, $actual);

        $expected = $validationMessages['anotherType'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorExclusionInSingleField(): void
    {
        $validation = new Validation();

        $validation->add(
            'status',
            new ExclusionIn(
                [
                    'domain' => ['A', 'I'],
                ]
            )
        );

        $messages = $validation->validate(
            [
                'status' => 'A',
            ]
        );

        $expected = new Messages(
            [
                new Message(
                    'Field status must not be a part of list: A, I',
                    'status',
                    ExclusionIn::class,
                    0
                ),
            ]
        );
        $actual   = $messages;
        $this->assertEquals($expected, $actual);

        $messages = $validation->validate(['status' => 'A']);
        $actual   = $messages;
        $this->assertEquals($expected, $actual);

        $messages = $validation->validate(['status' => 'X']);
        $expected = 0;
        $actual   = $messages->count();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-03
     */
    public function testFilterValidationValidatorExclusionInValidateEmpty(): void
    {
        $validation = new Validation();
        $validator  = new ExclusionIn(['allowEmpty' => true,]);
        $validation->add('price', $validator);
        $entity        = new stdClass();
        $entity->price = '';

        $validation->bind($entity, []);
        $result = $validator->validate($validation, 'price');
        $this->assertTrue($result);
    }
}
