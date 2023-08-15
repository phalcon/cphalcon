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

namespace Phalcon\Tests\Integration\Filter\Validation\Validator\Identical;

use IntegrationTester;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exception;
use Phalcon\Filter\Validation\Validator\Identical;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use stdClass;

/**
 * Class ValidateCest
 */
class ValidateCest
{
    /**
     * Tests Phalcon\Filter\Validation\Validator\Identical :: validate() - empty
     *
     * @param IntegrationTester $I
     *
     * @return void
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-03
     */
    public function filterValidationValidatorIdenticalValidateEmpty(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Identical - validate() - empty");

        $validation = new Validation();
        $validator  = new Identical(['allowEmpty' => true,]);
        $validation->add('price', $validator);
        $entity = new stdClass();
        $entity->price = '';

        $validation->bind($entity, []);
        $result = $validator->validate($validation, 'price');
        $I->assertTrue($result);
    }

    /**
     * Tests identical validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorIdenticalSingleField(IntegrationTester $I)
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
        $I->assertSame($expected, $actual);

        $messages = $validation->validate(
            [
                'name' => 'SomeValue123',
            ]
        );

        $expected = 1;
        $actual   = $messages->count();
        $I->assertSame($expected, $actual);


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

        $I->assertEquals($expected, $messages);
    }

    /**
     * Tests identical validator with multiple field and single accepted
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorIdenticalMultipleFieldSingleAccepted(IntegrationTester $I)
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
        $I->assertSame($expected, $actual);

        $messages = $validation->validate(
            [
                'name'        => 'SomeValue123',
                'anotherName' => 'SomeValue',
            ]
        );

        $expected = 1;
        $actual   = $messages->count();
        $I->assertSame($expected, $actual);

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertSame($expected, $actual);

        $messages = $validation->validate(
            [
                'name'        => 'SomeValue123',
                'anotherName' => 'SomeValue123',
            ]
        );

        $expected = 2;
        $actual   = $messages->count();
        $I->assertSame($expected, $actual);

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertSame($expected, $actual);

        $expected = $validationMessages['anotherName'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests identical validator with multiple field and single accepted
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorIdenticalMultipleFieldSingleValue(IntegrationTester $I)
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
        $I->assertSame($expected, $actual);

        $messages = $validation->validate(
            [
                'name'        => 'SomeValue123',
                'anotherName' => 'SomeValue',
            ]
        );

        $expected = 1;
        $actual   = $messages->count();
        $I->assertSame($expected, $actual);

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertSame($expected, $actual);

        $messages = $validation->validate(
            [
                'name'        => 'SomeValue123',
                'anotherName' => 'SomeValue123',
            ]
        );

        $expected = 2;
        $actual   = $messages->count();
        $I->assertSame($expected, $actual);

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertSame($expected, $actual);

        $expected = $validationMessages['anotherName'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests identical validator with multiple field and multiple accepted
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorIdenticalMultipleFieldMultipleAccepted(IntegrationTester $I)
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

        $I->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name'        => 'SomeValue123',
                'anotherName' => 'SomeAnotherValue',
            ]
        );

        $I->assertSame(
            1,
            $messages->count()
        );

        $I->assertSame(
            $validationMessages['name'],
            $messages->offsetGet(0)->getMessage()
        );


        $messages = $validation->validate(
            [
                'name'        => 'SomeValue',
                'anotherName' => 'SomeAnotherValue123',
            ]
        );

        $I->assertSame(
            1,
            $messages->count()
        );

        $I->assertSame(
            $validationMessages['anotherName'],
            $messages->offsetGet(0)->getMessage()
        );


        $messages = $validation->validate(
            [
                'name'        => 'SomeValue123',
                'anotherName' => 'SomeAnotherValue123',
            ]
        );

        $I->assertSame(
            2,
            $messages->count()
        );

        $I->assertSame(
            $validationMessages['name'],
            $messages->offsetGet(0)->getMessage()
        );

        $I->assertSame(
            $validationMessages['anotherName'],
            $messages->offsetGet(1)->getMessage()
        );
    }

    public function filterValidationValidatorIdenticalCustomMessage(IntegrationTester $I)
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

        $I->assertEquals($expected, $messages);

        $messages = $validation->validate(
            [
                'name' => 'Peter',
            ]
        );

        $I->assertSame(
            0,
            $messages->count()
        );
    }
}
