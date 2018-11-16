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
use Phalcon\Validation\Validator\StringLength;
use UnitTester;

class StringLengthCest
{
    /**
     * Tests string length validator with single field
     *
     * @test
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function shouldValidateSingleField(UnitTester $I)
    {
        $validation = new Validation();
        $validation->add(
            'name',
            new StringLength(
                [
                    'min' => 3,
                    'max' => 9,
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
    }

    /**
     * Tests too short string length
     *
     * @test
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2013-03-09
     */
    public function shouldValidateStringLengthMinimum(UnitTester $I)
    {
        $validation = new Validation();
        $validation->add('name', new StringLength(['min' => 3]));

        $messages = $validation->validate(['name' => 'Something']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = Messages::__set_state(
            [
                '_messages' => [
                    Message::__set_state(
                        [
                            '_type'    => 'TooShort',
                            '_message' => 'Field name must be at least 3 characters long',
                            '_field'   => 'name',
                            '_code'    => '0',
                        ]
                    ),
                ],
            ]
        );

        $messages = $validation->validate(['name' => 'So']);
        $actual   = $messages;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests too short string length with custom message
     *
     * @test
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2013-03-09
     */
    public function shouldValidateStringLengthMinimumWithCustomMessage(UnitTester $I)
    {
        $validation = new Validation();
        $validation->add(
            'message',
            new StringLength(['min' => 3, 'messageMinimum' => 'The message is too short'])
        );

        $messages = $validation->validate(['message' => 'Something']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = Messages::__set_state(
            [
                '_messages' => [
                    Message::__set_state(
                        [
                            '_type'    => 'TooShort',
                            '_message' => 'The message is too short',
                            '_field'   => 'message',
                            '_code'    => '0',
                        ]
                    ),
                ],
            ]
        );

        $messages = $validation->validate(['message' => 'So']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests too long string length
     *
     * @test
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2013-03-09
     */
    public function shouldValidateStringLengthMaximum(UnitTester $I)
    {
        $validation = new Validation();
        $validation->add('name', new StringLength(['max' => 4]));

        $messages = $validation->validate(['name' => 'John']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = Messages::__set_state(
            [
                '_messages' => [
                    Message::__set_state(
                        [
                            '_type'    => 'TooLong',
                            '_message' => 'Field name must not exceed 4 characters long',
                            '_field'   => 'name',
                            '_code'    => '0',
                        ]
                    ),
                ],
            ]
        );

        $messages = $validation->validate(['name' => 'Johannes']);
        $actual   = $messages;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests too long string length with custom message
     *
     * @test
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2013-03-09
     */
    public function shouldValidateStringLengthMaximumWithCustomMessage(UnitTester $I)
    {
        $validation = new Validation();
        $validation->add(
            'message',
            new StringLength(['max' => 4, 'messageMaximum' => 'The message is too long'])
        );

        $messages = $validation->validate(['message' => 'Pet']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = Messages::__set_state(
            [
                '_messages' => [
                    Message::__set_state(
                        [
                            '_type'    => 'TooLong',
                            '_message' => 'The message is too long',
                            '_field'   => 'message',
                            '_code'    => '0',
                        ]
                    ),
                ],
            ]
        );

        $messages = $validation->validate(['message' => 'Validation']);
        $actual   = $messages;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests string length validator with multiple field and single min, max
     *
     * @test
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function shouldValidateMultipleFieldSingleMinMax(UnitTester $I)
    {
        $validation                = new Validation();
        $validationMinimumMessages = [
            'name' => 'Name length must be minimum 0.',
            'type' => 'Type length must be minimum 0.',
        ];
        $validationMaximumMessages = [
            'name' => 'Name length must be maximum 9.',
            'type' => 'Type length must be maximum 9.',
        ];
        $validation->add(
            [
                'name',
                'type',
            ],
            new StringLength(
                [
                    'min'            => 0,
                    'max'            => 9,
                    'messageMinimum' => $validationMinimumMessages,
                    'messageMaximum' => $validationMaximumMessages,
                ]
            )
        );

        $messages = $validation->validate(['name' => 'SomeValue', 'type' => 'SomeValue']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['name' => 'SomeValue123', 'type' => 'SomeValue']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMaximumMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['name' => 'SomeValue123', 'type' => 'SomeValue123']);
        $expected = 2;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMaximumMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = $validationMaximumMessages['type'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests string length validator with multiple field and min, max
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleFieldMultipleMinMax(UnitTester $I)
    {
        $validation                = new Validation();
        $validationMinimumMessages = [
            'name' => 'Name length must be minimum 0.',
            'type' => 'Type length must be minimum 0.',
        ];
        $validationMaximumMessages = [
            'name' => 'Name length must be maximum 9.',
            'type' => 'Type length must be maximum 4.',
        ];
        $validation->add(
            [
                'name',
                'type',
            ],
            new StringLength(
                [
                    'min'            => [
                        'name' => 0,
                        'type' => 0,
                    ],
                    'max'            => [
                        'name' => 9,
                        'type' => 4,
                    ],
                    'messageMinimum' => $validationMinimumMessages,
                    'messageMaximum' => $validationMaximumMessages,
                ]
            )
        );

        $messages = $validation->validate(['name' => 'SomeValue', 'type' => 'Some']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['name' => 'SomeValue123', 'type' => 'Some']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMaximumMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['name' => 'SomeValue', 'type' => 'SomeValue']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMaximumMessages['type'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['name' => 'SomeValue123', 'type' => 'SomeValue']);
        $expected = 2;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMaximumMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = $validationMaximumMessages['type'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $I->assertEquals($expected, $actual);
    }
}
