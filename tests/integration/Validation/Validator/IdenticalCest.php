<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Validation\Validator;

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

        $messages = $validation->validate(['name' => 'SomeValue']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['name' => 'SomeValue123']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = new Messages(
            [
                new Message(
                    'Field name does not have the expected value',
                    'name',
                    'Identical',
                    0
                ),
            ]
        );
        $actual   = $messages;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests identical validator with multiple field and single accepted
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorMultipleFieldSingleAccepted(IntegrationTester $I)
    {
        $validation         = new Validation();
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
        $messages = $validation->validate(['name' => 'SomeValue', 'anotherName' => 'SomeValue']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['name' => 'SomeValue123', 'anotherName' => 'SomeValue']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['name' => 'SomeValue123', 'anotherName' => 'SomeValue123']);
        $expected = 2;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['anotherName'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests identical validator with multiple field and multiple accepted
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorMultipleFieldMultipleAccepted(IntegrationTester $I)
    {
        $validation         = new Validation();
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

        $messages = $validation->validate(['name' => 'SomeValue', 'anotherName' => 'SomeAnotherValue']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['name' => 'SomeValue123', 'anotherName' => 'SomeAnotherValue']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['name' => 'SomeValue', 'anotherName' => 'SomeAnotherValue123']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['anotherName'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['name' => 'SomeValue123', 'anotherName' => 'SomeAnotherValue123']);
        $expected = 2;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['anotherName'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $I->assertEquals($expected, $actual);
    }

    public function validationValidatorCustomMessage(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            'name',
            new Validation\Validator\Identical(
                [
                    'accepted' => 'Peter',
                    'message'  => 'The name must be peter',
                ]
            )
        );

        $messages = $validation->validate([]);
        $expected = new Messages(
            [
                new Message(
                    'The name must be peter',
                    'name',
                    'Identical',
                    0
                ),
            ]
        );
        $actual   = $messages;
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['name' => 'Peter']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);
    }
}
