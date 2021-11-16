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

use IntegrationTester;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Identical;

class IdenticalCest
{
    /**
     * Tests identical validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorSingleField(IntegrationTester $I)
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

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name' => 'SomeValue123',
            ]
        );

        $I->assertEquals(
            1,
            $messages->count()
        );


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
    public function validationValidatorMultipleFieldSingleAccepted(IntegrationTester $I)
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

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name'        => 'SomeValue123',
                'anotherName' => 'SomeValue',
            ]
        );

        $I->assertEquals(
            1,
            $messages->count()
        );

        $I->assertEquals(
            $validationMessages['name'],
            $messages->offsetGet(0)->getMessage()
        );


        $messages = $validation->validate(
            [
                'name'        => 'SomeValue123',
                'anotherName' => 'SomeValue123',
            ]
        );

        $I->assertEquals(
            2,
            $messages->count()
        );


        $I->assertEquals(
            $validationMessages['name'],
            $messages->offsetGet(0)->getMessage()
        );

        $I->assertEquals(
            $validationMessages['anotherName'],
            $messages->offsetGet(1)->getMessage()
        );
    }

    /**
     * Tests identical validator with multiple field and multiple accepted
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorMultipleFieldMultipleAccepted(IntegrationTester $I)
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

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name'        => 'SomeValue123',
                'anotherName' => 'SomeAnotherValue',
            ]
        );

        $I->assertEquals(
            1,
            $messages->count()
        );

        $I->assertEquals(
            $validationMessages['name'],
            $messages->offsetGet(0)->getMessage()
        );


        $messages = $validation->validate(
            [
                'name'        => 'SomeValue',
                'anotherName' => 'SomeAnotherValue123',
            ]
        );

        $I->assertEquals(
            1,
            $messages->count()
        );

        $I->assertEquals(
            $validationMessages['anotherName'],
            $messages->offsetGet(0)->getMessage()
        );


        $messages = $validation->validate(
            [
                'name'        => 'SomeValue123',
                'anotherName' => 'SomeAnotherValue123',
            ]
        );

        $I->assertEquals(
            2,
            $messages->count()
        );

        $I->assertEquals(
            $validationMessages['name'],
            $messages->offsetGet(0)->getMessage()
        );

        $I->assertEquals(
            $validationMessages['anotherName'],
            $messages->offsetGet(1)->getMessage()
        );
    }

    public function validationValidatorCustomMessage(IntegrationTester $I)
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

        $I->assertEquals(
            0,
            $messages->count()
        );
    }
}
