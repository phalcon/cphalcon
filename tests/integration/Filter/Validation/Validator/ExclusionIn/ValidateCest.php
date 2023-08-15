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

namespace Phalcon\Tests\Integration\Filter\Validation\Validator\ExclusionIn;

use IntegrationTester;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exception;
use Phalcon\Filter\Validation\Validator\ExclusionIn;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use stdClass;

/**
 * Class ValidateCest
 */
class ValidateCest
{
    /**
     * Tests Phalcon\Filter\Validation\Validator\ExclusionIn :: validate() - empty
     *
     * @param IntegrationTester $I
     *
     * @return void
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-03
     */
    public function filterValidationValidatorExclusionInValidateEmpty(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\ExclusionIn - validate() - empty");

        $validation = new Validation();
        $validator  = new ExclusionIn(['allowEmpty' => true,]);
        $validation->add('price', $validator);
        $entity = new stdClass();
        $entity->price = '';

        $validation->bind($entity, []);
        $result = $validator->validate($validation, 'price');
        $I->assertTrue($result);
    }

    /**
     * Tests Phalcon\Filter\Validation\Validator\ExclusionIn :: validate() - single field
     *
     * @param IntegrationTester $I
     *
     * @return void
     * @throws Exception
     *
     * @author Phalcon Team <tram@phalcon.io>
     * @since  2023-08-03
     */
    public function filterValidationValidatorExclusionInExceptions(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\ExclusionIn - validate() - exceptions");

        $I->expectThrowable(
            new Exception("Option 'domain' must be an array"),
            function () {
                $validation = new Validation();
                $validator  = new ExclusionIn(
                    [
                        "message" => "The status must not be A or B",
                        "domain"  => "A",
                    ]
                );
                $validation->add('status', $validator);
                $entity = new stdClass();
                $entity->status = '';

                $validation->bind($entity, []);
                $validator->validate($validation, 'status');
            }
        );

        $I->expectThrowable(
            new Exception("Option 'strict' must be a bool"),
            function () {
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
                $entity = new stdClass();
                $entity->status = '';

                $validation->bind($entity, []);
                $validator->validate($validation, 'status');
            }
        );
    }
    /**
     * Tests exclusion in validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorExclusionInSingleField(IntegrationTester $I)
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
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['status' => 'A']);
        $actual   = $messages;
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['status' => 'X']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests exclusion in validator with multiple field and single domain
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorExclusionInMultipleFieldSingleDomain(IntegrationTester $I)
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
        $I->assertSame($expected, $actual);

        $messages = $validation->validate(['type' => 'cyborg', 'anotherType' => 'hydraulic']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertSame($expected, $actual);

        $expected = $validationMessages['type'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertSame($expected, $actual);

        $messages = $validation->validate(['type' => 'cyborg', 'anotherType' => 'mechanic']);
        $expected = 2;
        $actual   = $messages->count();
        $I->assertSame($expected, $actual);

        $expected = $validationMessages['type'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertSame($expected, $actual);

        $expected = $validationMessages['anotherType'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests exclusion in validator with multiple field and multiple domain
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorExclusionInMultipleFieldMultipleDomain(IntegrationTester $I)
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
        $I->assertSame($expected, $actual);

        $messages = $validation->validate(['type' => 'cyborg', 'anotherType' => 'cyborg']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertSame($expected, $actual);

        $expected = $validationMessages['type'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertSame($expected, $actual);

        $messages = $validation->validate(['type' => 'hydraulic', 'anotherType' => 'mechanic']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertSame($expected, $actual);

        $expected = $validationMessages['anotherType'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertSame($expected, $actual);

        $messages = $validation->validate(['type' => 'cyborg', 'anotherType' => 'mechanic']);
        $expected = 2;
        $actual   = $messages->count();
        $I->assertSame($expected, $actual);

        $expected = $validationMessages['type'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertSame($expected, $actual);

        $expected = $validationMessages['anotherType'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $I->assertSame($expected, $actual);
    }

    public function filterValidationValidatorExclusionInCustomMessage(IntegrationTester $I)
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

        $I->assertEquals($expected, $messages);


        $messages = $validation->validate(
            [
                'status' => 'A',
            ]
        );

        $I->assertEquals($expected, $messages);

        $messages = $validation->validate(
            [
                'status' => 'X',
            ]
        );

        $I->assertSame(
            0,
            $messages->count()
        );
    }
}
