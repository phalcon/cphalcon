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

namespace Phalcon\Tests\Integration\Filter\Validation\Validator\Regex;

use IntegrationTester;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exception;
use Phalcon\Filter\Validation\Validator\Regex;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use stdClass;

/**
 * Class ValidateCest
 */
class ValidateCest
{
    /**
     * Tests Phalcon\Filter\Validation\Validator\Regex :: validate() - empty
     *
     * @param IntegrationTester $I
     *
     * @return void
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-03
     */
    public function filterValidationValidatorRegexValidateEmpty(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Regex - validate() - empty");

        $validation = new Validation();
        $validator  = new Regex(['allowEmpty' => true,]);
        $validation->add('price', $validator);
        $entity = new stdClass();
        $entity->price = '';

        $validation->bind($entity, []);
        $result = $validator->validate($validation, 'price');
        $I->assertTrue($result);
    }

    /**
     * Tests regex validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorRegexSingleField(IntegrationTester $I)
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

        $I->assertSame(
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
    public function filterValidationValidatorRegexMultipleFieldSinglePattern(IntegrationTester $I)
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

        $I->assertSame(
            0,
            $messages->count()
        );

        $messages = $validation->validate(
            [
                'name' => 'SomeValue',
                'type' => 'somevalue',
            ]
        );

        $I->assertSame(
            1,
            $messages->count()
        );

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertSame($expected, $actual);

        $messages = $validation->validate(
            [
                'name' => 'SomeValue',
                'type' => 'SomeValue',
            ]
        );


        $I->assertSame(
            2,
            $messages->count()
        );

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertSame($expected, $actual);

        $expected = $validationMessages['type'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests regex validator with multiple field and pattern
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorRegexMultipleFieldMultiplePattern(IntegrationTester $I)
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

        $I->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name' => 'SomeValue',
                'type' => 'SOMEVALUE',
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
                'name' => 'somevalue',
                'type' => 'somevalue',
            ]
        );

        $I->assertSame(
            1,
            $messages->count()
        );

        $I->assertSame(
            $validationMessages['type'],
            $messages->offsetGet(0)->getMessage()
        );


        $messages = $validation->validate(
            [
                'name' => 'SomeValue',
                'type' => 'SomeValue',
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
            $validationMessages['type'],
            $messages->offsetGet(1)->getMessage()
        );
    }

    public function filterValidationValidatorRegexCustomMessage(IntegrationTester $I)
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

        $I->assertSame(
            0,
            $messages->count()
        );
    }
}
