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
use Phalcon\Validation\Validator\Regex;

class RegexCest
{
    /**
     * Tests regex validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorSingleField(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            'car_plate',
            new Regex(
                [
                    'pattern' => '/[A-Z]{3}\-[0-9]{3}/',
                ]
            )
        );

        $messages = $validation->validate(
            []
        );

        $expected = new Messages(
            [
                new Message(
                    'Field car_plate does not match the required format',
                    'car_plate',
                    Regex::class,
                    0
                ),
            ]
        );

        $I->assertEquals($expected, $messages);

        $messages = $validation->validate(
            [
                'car_plate' => 'XYZ-123',
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );
    }

    /**
     * Tests regex validator with multiple field and single pattern
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorMultipleFieldSinglePattern(IntegrationTester $I)
    {
        $validation = new Validation();

        $validationMessages = [
            'name' => 'Name can be only lowercase letters.',
            'type' => 'Type can be only lowercase letters.',
        ];

        $validation->add(
            [
                'name',
                'type',
            ],
            new Regex(
                [
                    'pattern' => '/^[a-z]+$/',
                    'message' => $validationMessages,
                ]
            )
        );

        $messages = $validation->validate(
            [
                'name' => 'somevalue',
                'type' => 'somevalue',
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );

        $messages = $validation->validate(
            [
                'name' => 'SomeValue',
                'type' => 'somevalue',
            ]
        );

        $I->assertEquals(
            1,
            $messages->count()
        );

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(
            [
                'name' => 'SomeValue',
                'type' => 'SomeValue',
            ]
        );


        $I->assertEquals(
            2,
            $messages->count()
        );

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['type'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests regex validator with multiple field and pattern
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorMultipleFieldMultiplePattern(IntegrationTester $I)
    {
        $validation = new Validation();

        $validationMessages = [
            'name' => 'Name can be only lowercase letters.',
            'type' => 'Type can be only uppercase letters.',
        ];

        $validation->add(
            [
                'name',
                'type',
            ],
            new Regex(
                [
                    'pattern' => [
                        'name' => '/^[a-z]+$/',
                        'type' => '/^[A-Z]+$/',
                    ],
                    'message' => $validationMessages,
                ]
            )
        );


        $messages = $validation->validate(
            [
                'name' => 'somevalue',
                'type' => 'SOMEVALUE',
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name' => 'SomeValue',
                'type' => 'SOMEVALUE',
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
                'name' => 'somevalue',
                'type' => 'somevalue',
            ]
        );

        $I->assertEquals(
            1,
            $messages->count()
        );

        $I->assertEquals(
            $validationMessages['type'],
            $messages->offsetGet(0)->getMessage()
        );


        $messages = $validation->validate(
            [
                'name' => 'SomeValue',
                'type' => 'SomeValue',
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
            $validationMessages['type'],
            $messages->offsetGet(1)->getMessage()
        );
    }

    public function validationValidatorCustomMessage(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            'car_plate',
            new Regex(
                [
                    'pattern' => '/[A-Z]{3}\-[0-9]{3}/',
                    'message' => 'The car plate is not valid',
                ]
            )
        );


        $messages = $validation->validate(
            []
        );

        $expected = new Messages(
            [
                new Message(
                    'The car plate is not valid',
                    'car_plate',
                    Regex::class,
                    0
                ),
            ]
        );

        $I->assertEquals($expected, $messages);


        $messages = $validation->validate(
            [
                'car_plate' => 'XYZ-123',
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );
    }
}
