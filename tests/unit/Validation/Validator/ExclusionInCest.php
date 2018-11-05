<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Validation;
use Phalcon\Validation\Validator\ExclusionIn;
use UnitTester;

class ExclusionInCest
{
    /**
     * Tests exclusion in validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testSingleField(UnitTester $I)
    {
        $validation = new Validation();

        $validation->add(
            'status',
            new ExclusionIn(
                [
                    'domain' => ['A', 'I']
                ]
            )
        );

        $messages = $validation->validate(['status' => 'A']);
        $expected = Messages::__set_state(
            [
                '_messages' => [
                    0 => Message::__set_state(
                        [
                            '_type'    => 'ExclusionIn',
                            '_message' => 'Field status must not be a part of list: A, I',
                            '_field'   => 'status',
                            '_code'    => 0,
                        ]
                    )
                ]
            ]
        );
        $actual = $messages;
        $I->assertEquals($expected, $actual);

        $messages =  $validation->validate(['status' => 'A']);
        $actual   = $messages;
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['status' => 'X']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests exclusion in validator with multiple field and single domain
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleFieldSingleDomain(UnitTester $I)
    {
        $validation = new Validation();
        $validationMessages = [
            'type' => 'Type cant be mechanic or cyborg.',
            'anotherType' => 'AnotherType cant by mechanic or cyborg.',
        ];
        $validation->add(
            [
                'type',
                'anotherType',
                ],
            new ExclusionIn(
                [
                    'domain' => ['mechanic', 'cyborg'],
                    'message' => $validationMessages,
                ]
            )
        );
        $messages = $validation->validate(['type' => 'hydraulic', 'anotherType' => 'hydraulic']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['type' => 'cyborg', 'anotherType' => 'hydraulic']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['type'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['type' => 'cyborg', 'anotherType' => 'mechanic']);
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
     * Tests exclusion in validator with multiple field and multiple domain
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleFieldMultipleDomain(UnitTester $I)
    {
        $validation = new Validation();
        $validationMessages = [
            'type' => 'Type cant be mechanic or cyborg.',
            'anotherType' => 'AnotherType cant by mechanic or hydraulic.',
        ];
        $validation->add(
            [
                'type',
                'anotherType',
            ],
            new ExclusionIn(
                [
                'domain' => [
                    'type' => ['mechanic', 'cyborg'],
                    'anotherType' => ['mechanic', 'hydraulic'],
                ],
                'message' => $validationMessages,
                ]
            )
        );
        $messages = $validation->validate(['type' => 'hydraulic', 'anotherType' => 'cyborg']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['type' => 'cyborg', 'anotherType' => 'cyborg']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['type'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['type' => 'hydraulic', 'anotherType' => 'mechanic']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['anotherType'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['type' => 'cyborg', 'anotherType' => 'mechanic']);
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

    public function testCustomMessage(UnitTester $I)
    {
        $validation = new Validation();

        $validation->add(
            'status',
            new ExclusionIn(
                [
                    'message' => 'The status must not be A=Active or I=Inactive',
                    'domain' => ['A', 'I']
                ]
            )
        );

        $messages = $validation->validate(['status' => 'A']);
        $expected = Messages::__set_state(
            [
                '_messages' => [
                    0 => Message::__set_state(
                        [
                            '_type'    => 'ExclusionIn',
                            '_message' => 'The status must not be A=Active or I=Inactive',
                            '_field'   => 'status',
                            '_code'    => '0',
                        ]
                    )
                ]
            ]
        );
        $actual   = $messages;
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['status' => 'A']);
        $actual   = $messages;
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['status' => 'X']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);
    }
}
