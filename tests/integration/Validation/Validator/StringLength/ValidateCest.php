<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Validation\Validator\StringLength;

use IntegrationTester;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Validation;
use Phalcon\Validation\Validator\StringLength;

/**
 * Class ValidateCest
 */
class ValidateCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength :: validate() - single
     * field
     *
     * @param IntegrationTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorStringLengthValidateSingleField(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength :: validate() - single field');
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
     * Tests Phalcon\Validation\Validator\StringLength :: validate() - minimum
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2013-03-09
     */
    public function validationValidatorStringLengthValidateMinimum(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength :: validate() - minimum');
        $validation = new Validation();
        $validation->add('name', new StringLength(['min' => 3]));

        $messages = $validation->validate(['name' => 'Something']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = new Messages(
            [
                new Message(
                    'Field name must be at least 3 characters long',
                    'name',
                    'TooShort',
                    0
                ),
            ]
        );
        $messages = $validation->validate(['name' => 'So']);
        $actual   = $messages;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Validation\Validator\StringLength :: validate() - minimum
     * custom message
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2013-03-09
     */
    public function validationValidatorStringLengthValidateMinimumWithCustomMessage(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength :: validate() - minimum custom message');
        $validation = new Validation();
        $validation->add(
            'message',
            new StringLength(['min' => 3, 'messageMinimum' => 'The message is too short'])
        );

        $messages = $validation->validate(['message' => 'Something']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = new Messages(
            [
                new Message(
                    'The message is too short',
                    'message',
                    'TooShort',
                    0
                ),
            ]
        );
        $messages = $validation->validate(['message' => 'So']);
        $actual   = $messages;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Validation\Validator\StringLength :: validate() - maximum
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2013-03-09
     */
    public function validationValidatorStringLengthValidateMaximum(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength :: validate() - maximum');
        $validation = new Validation();
        $validation->add('name', new StringLength(['max' => 4]));

        $messages = $validation->validate(['name' => 'John']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = new Messages(
            [
                new Message(
                    'Field name must not exceed 4 characters long',
                    'name',
                    'TooLong',
                    0
                ),
            ]
        );
        $messages = $validation->validate(['name' => 'Johannes']);
        $actual   = $messages;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Validation\Validator\StringLength :: validate() - maximum
     * custom message
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2013-03-09
     */
    public function validationValidatorStringLengthValidateMaximumWithCustomMessage(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength :: validate() - maximum custom message');
        $validation = new Validation();
        $validation->add(
            'message',
            new StringLength(['max' => 4, 'messageMaximum' => 'The message is too long'])
        );

        $messages = $validation->validate(['message' => 'Pet']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = new Messages(
            [
                new Message(
                    'The message is too long',
                    'message',
                    'TooLong',
                    0
                ),
            ]
        );
        $messages = $validation->validate(['message' => 'Validation']);
        $actual   = $messages;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Validation\Validator\StringLength :: validate()
     * multiple field and single min, max
     *
     * @param IntegrationTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorStringLengthValidateMultipleFieldSingleMinMax(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength :: validate() - multiple field and single min, max');
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
     * Tests Phalcon\Validation\Validator\StringLength :: validate()
     * multiple field and min, max
     *
     * @param IntegrationTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorStringLengthValidateMultipleFieldMultipleMinMax(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength :: validate() - multiple field and min, max');
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
