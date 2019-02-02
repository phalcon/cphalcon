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
use Phalcon\Validation\Validator\InclusionIn;

class InclusionInCest
{
    /**
     * Tests inclusion in validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorSingleField(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            'status',
            new InclusionIn(
                [
                    'domain' => ['A', 'I'],
                ]
            )
        );

        $messages = $validation->validate([]);
        $expected = new Messages(
            [
                new Message(
                    'Field status must be a part of list: A, I',
                    'status',
                    'InclusionIn',
                    0
                ),
            ]
        );
        $actual   = $messages;
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['status' => 'X']);
        $actual   = $messages;
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['status' => 'A']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests inclusion in validator with single multiple field and single domain
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorMultipleFieldSingleDomain(IntegrationTester $I)
    {
        $validation         = new Validation();
        $validationMessages = [
            'type'        => 'Type must be mechanical or cyborg.',
            'anotherType' => 'AnotherType must be mechanical or cyborg.',
        ];
        $validation->add(
            [
                'type',
                'anotherType',
            ],
            new InclusionIn(
                [
                    'domain'  => ['mechanical', 'cyborg'],
                    'message' => $validationMessages,
                ]
            )
        );
        $messages = $validation->validate(['type' => 'cyborg', 'anotherType' => 'cyborg']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['type' => 'hydraulic', 'anotherType' => 'cyborg']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['type'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['type' => 'hydraulic', 'anotherType' => 'hydraulic']);
        $expected = 2;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['type'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['anotherType'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests inclusion in validator with single multiple field and domain
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorMultipleFieldMultipleDomain(IntegrationTester $I)
    {
        $validation         = new Validation();
        $validationMessages = [
            'type'        => 'Type must be mechanic or cyborg.',
            'anotherType' => 'AnotherType must be mechanic or hydraulic.',
        ];
        $validation->add(
            [
                'type',
                'anotherType',
            ],
            new InclusionIn(
                [
                    'domain'  => [
                        'type'        => ['cyborg', 'mechanic'],
                        'anotherType' => ['mechanic', 'hydraulic'],
                    ],
                    'message' => $validationMessages,
                ]
            )
        );

        $messages = $validation->validate(['type' => 'cyborg', 'anotherType' => 'mechanic']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['type' => 'hydraulic', 'anotherType' => 'mechanic']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['type'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['type' => 'mechanic', 'anotherType' => 'cyborg']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['anotherType'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['type' => 'hydraulic', 'anotherType' => 'cyborg']);
        $expected = 2;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['type'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['anotherType'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $I->assertEquals($expected, $actual);
    }

    public function validationValidatorCustomMessage(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            'status',
            new InclusionIn(
                [
                    'message' => 'The status must be A=Active or I=Inactive',
                    'domain'  => ['A', 'I'],
                ]
            )
        );

        $messages = $validation->validate([]);
        $expected = new Messages(
            [
                new Message(
                    'The status must be A=Active or I=Inactive',
                    'status',
                    'InclusionIn',
                    0
                ),
            ]
        );
        $actual   = $messages;
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['status' => 'x=1']);
        $actual   = $messages;
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['status' => 'A']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);
    }
}
