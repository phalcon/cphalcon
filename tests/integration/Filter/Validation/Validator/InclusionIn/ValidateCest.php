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

namespace Phalcon\Tests\Integration\Filter\Validation\Validator\InclusionIn;

use IntegrationTester;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\InclusionIn;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;

/**
 * Class ValidateCest
 */
class ValidateCest
{
    /**
     * Tests inclusion in validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorInclusioninSingleField(IntegrationTester $I)
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


        $messages = $validation->validate(
            []
        );

        $expected = new Messages(
            [
                new Message(
                    'Field status must be a part of list: A, I',
                    'status',
                    InclusionIn::class,
                    0
                ),
            ]
        );

        $I->assertEquals($expected, $messages);

        $messages = $validation->validate(
            [
                'status' => 'X',
            ]
        );

        $I->assertEquals($expected, $messages);

        $messages = $validation->validate(
            [
                'status' => 'A',
            ]
        );

        $I->assertSame(
            0,
            $messages->count()
        );
    }

    /**
     * Tests inclusion in validator with single multiple field and single domain
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorInclusioninMultipleFieldSingleDomain(IntegrationTester $I)
    {
        $validation = new Validation();

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


        $messages = $validation->validate(
            [
                'type'        => 'cyborg',
                'anotherType' => 'cyborg',
            ]
        );

        $I->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'type'        => 'hydraulic',
                'anotherType' => 'cyborg',
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
                'type'        => 'hydraulic',
                'anotherType' => 'hydraulic',
            ]
        );

        $I->assertSame(
            2,
            $messages->count()
        );

        $I->assertSame(
            $validationMessages['type'],
            $messages->offsetGet(0)->getMessage()
        );

        $I->assertSame(
            $validationMessages['anotherType'],
            $messages->offsetGet(1)->getMessage()
        );
    }

    /**
     * Tests inclusion in validator with single multiple field and domain
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorInclusioninMultipleFieldMultipleDomain(IntegrationTester $I)
    {
        $validation = new Validation();

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


        $messages = $validation->validate(
            [
                'type'        => 'cyborg',
                'anotherType' => 'mechanic',
            ]
        );

        $I->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'type'        => 'hydraulic',
                'anotherType' => 'mechanic',
            ]
        );

        $I->assertSame(
            1,
            $messages->count()
        );

        $expected = $validationMessages['type'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertSame($expected, $actual);


        $messages = $validation->validate(
            [
                'type'        => 'mechanic',
                'anotherType' => 'cyborg',
            ]
        );

        $I->assertSame(
            1,
            $messages->count()
        );

        $expected = $validationMessages['anotherType'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertSame($expected, $actual);


        $messages = $validation->validate(
            [
                'type'        => 'hydraulic',
                'anotherType' => 'cyborg',
            ]
        );

        $I->assertSame(
            2,
            $messages->count()
        );

        $I->assertSame(
            $validationMessages['type'],
            $messages->offsetGet(0)->getMessage()
        );

        $I->assertSame(
            $validationMessages['anotherType'],
            $messages->offsetGet(1)->getMessage()
        );
    }

    public function filterValidationValidatorInclusioninCustomMessage(IntegrationTester $I)
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


        $messages = $validation->validate(
            []
        );

        $expected = new Messages(
            [
                new Message(
                    'The status must be A=Active or I=Inactive',
                    'status',
                    InclusionIn::class,
                    0
                ),
            ]
        );

        $I->assertEquals($expected, $messages);


        $messages = $validation->validate(['status' => 'x=1']);

        $I->assertEquals($expected, $messages);

        $messages = $validation->validate(['status' => 'A']);

        $I->assertSame(
            0,
            $messages->count()
        );
    }
}
