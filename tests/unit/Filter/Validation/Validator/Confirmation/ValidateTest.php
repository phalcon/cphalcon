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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\Confirmation;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\Confirmation;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tests\AbstractUnitTestCase;

final class ValidateTest extends AbstractUnitTestCase
{
    /**
     * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
     * @since  2015-09-06
     */
    public function testFilterValidationValidatorConfirmationValidateEmptyValues(): void
    {
        $expected = new Messages(
            [
                new Message(
                    'Field password must be the same as password2',
                    'password',
                    Confirmation::class,
                    0
                ),
            ]
        );

        $validation = new Validation();

        $validation->add(
            'password',
            new Confirmation(
                [
                    'allowEmpty' => true,
                    'ignoreCase' => true,
                    'with'       => 'password2',
                ]
            )
        );


        $messages = $validation->validate(
            [
                'password'  => 'TEST123',
                'password2' => 'test123',
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'password'  => null,
                'password2' => 'test123',
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );


        $validation = new Validation();

        $validation->add(
            'password',
            new Confirmation(
                [
                    'allowEmpty' => false,
                    'with'       => 'password2',
                ]
            )
        );


        $messages = $validation->validate(
            [
                'password'  => 'test123',
                'password2' => 'test123',
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );

        $validation = new Validation();

        $validation->add(
            'password',
            new Confirmation(
                [
                    'with' => 'password2',
                ]
            )
        );


        $messages = $validation->validate(
            [
                'password'  => 'test123',
                'password2' => 'test123',
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorConfirmationValidateMultipleField(): void
    {
        $validation = new Validation();

        $validationMessages = [
            'name' => 'Name must be same as nameWith.',
            'type' => 'Type must be same as typeWith.',
        ];

        $validation->add(
            ['name', 'type'],
            new Confirmation(
                [
                    'with'    => [
                        'name' => 'nameWith',
                        'type' => 'typeWith',
                    ],
                    'message' => $validationMessages,
                ]
            )
        );


        $messages = $validation->validate(
            [
                'name'     => 'SomeValue',
                'nameWith' => 'SomeValue',
                'type'     => 'SomeValue',
                'typeWith' => 'SomeValue',
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name'     => 'SomeValue',
                'nameWith' => 'SomeValue123',
                'type'     => 'SomeValue',
                'typeWith' => 'SomeValue',
            ]
        );

        $this->assertSame(
            1,
            $messages->count()
        );

        $this->assertSame(
            $validationMessages['name'],
            $messages->offsetGet(0)->getMessage()
        );


        $messages = $validation->validate(
            [
                'name'     => 'SomeValue',
                'nameWith' => 'SomeValue123',
                'type'     => 'SomeValue',
                'typeWith' => 'SomeValue123',
            ]
        );

        $this->assertSame(
            2,
            $messages->count()
        );

        $this->assertSame(
            $validationMessages['name'],
            $messages->offsetGet(0)->getMessage()
        );

        $this->assertSame(
            $validationMessages['type'],
            $messages->offsetGet(1)->getMessage()
        );
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorConfirmationValidateSingleField(): void
    {
        $validation = new Validation();

        $validation->add(
            'name',
            new Confirmation(
                [
                    'with' => 'nameWith',
                ]
            )
        );

        $messages = $validation->validate(
            [
                'name'     => 'SomeValue',
                'nameWith' => 'SomeValue',
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name'     => 'SomeValue',
                'nameWith' => 'SomeValue123',
            ]
        );

        $this->assertSame(
            1,
            $messages->count()
        );


        // https://github.com/phalcon/cphalcon/issues/15252
        $messages = $validation->validate(
            [
                'name'     => '000012345',
                'nameWith' => '12345',
            ]
        );

        $this->assertSame(
            1,
            $messages->count(),
            "Phalcon\Filter\Validation\Validator\Confirmation failed to compare 000012345=12345"
        );

        $messages = $validation->validate(
            [
                'name'     => 'asd',
                'nameWith' => 'asdß',
            ]
        );

        $this->assertSame(
            1,
            $messages->count(),
            "Phalcon\Filter\Validation\Validator\Confirmation failed to compare asd=asdß"
        );
    }
}
