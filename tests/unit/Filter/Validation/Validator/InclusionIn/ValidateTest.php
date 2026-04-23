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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\InclusionIn;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\InclusionIn;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tests\AbstractUnitTestCase;

final class ValidateTest extends AbstractUnitTestCase
{
    public function testFilterValidationValidatorInclusioninCustomMessage(): void
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

        $this->assertEquals($expected, $messages);


        $messages = $validation->validate(['status' => 'x=1']);

        $this->assertEquals($expected, $messages);

        $messages = $validation->validate(['status' => 'A']);

        $this->assertSame(
            0,
            $messages->count()
        );
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorInclusioninMultipleFieldMultipleDomain(): void
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

        $this->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'type'        => 'hydraulic',
                'anotherType' => 'mechanic',
            ]
        );

        $this->assertSame(
            1,
            $messages->count()
        );

        $expected = $validationMessages['type'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $this->assertSame($expected, $actual);


        $messages = $validation->validate(
            [
                'type'        => 'mechanic',
                'anotherType' => 'cyborg',
            ]
        );

        $this->assertSame(
            1,
            $messages->count()
        );

        $expected = $validationMessages['anotherType'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $this->assertSame($expected, $actual);


        $messages = $validation->validate(
            [
                'type'        => 'hydraulic',
                'anotherType' => 'cyborg',
            ]
        );

        $this->assertSame(
            2,
            $messages->count()
        );

        $this->assertSame(
            $validationMessages['type'],
            $messages->offsetGet(0)->getMessage()
        );

        $this->assertSame(
            $validationMessages['anotherType'],
            $messages->offsetGet(1)->getMessage()
        );
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorInclusioninMultipleFieldSingleDomain(): void
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

        $this->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'type'        => 'hydraulic',
                'anotherType' => 'cyborg',
            ]
        );

        $this->assertSame(
            1,
            $messages->count()
        );

        $this->assertSame(
            $validationMessages['type'],
            $messages->offsetGet(0)->getMessage()
        );


        $messages = $validation->validate(
            [
                'type'        => 'hydraulic',
                'anotherType' => 'hydraulic',
            ]
        );

        $this->assertSame(
            2,
            $messages->count()
        );

        $this->assertSame(
            $validationMessages['type'],
            $messages->offsetGet(0)->getMessage()
        );

        $this->assertSame(
            $validationMessages['anotherType'],
            $messages->offsetGet(1)->getMessage()
        );
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorInclusioninSingleField(): void
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

        $this->assertEquals($expected, $messages);

        $messages = $validation->validate(
            [
                'status' => 'X',
            ]
        );

        $this->assertEquals($expected, $messages);

        $messages = $validation->validate(
            [
                'status' => 'A',
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );
    }
}
