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

namespace Phalcon\Test\Integration\Validation\Validator\Confirmation;

use IntegrationTester;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Confirmation;

/**
 * Class ValidateCest
 */
class ValidateCest
{

    /**
     * Tests Phalcon\Validation\Validator\Confirmation :: validate() - single
     * field
     *
     * @param IntegrationTester $I
     *
     * @since  2016-06-05
     * @author Wojciech Ślawski <jurigag@gmail.com>
     */
    public function validationValidatorConfirmationValidateSingleField(IntegrationTester $I)
    {
        $I->wantToTest(
            "Validation\Validator\Confirmation - validate() - single field"
        );

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

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name'     => 'SomeValue',
                'nameWith' => 'SomeValue123',
            ]
        );

        $I->assertEquals(
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

        $I->assertEquals(
            1,
            $messages->count(),
            "Phalcon\Validation\Validator\Confirmation failed to compare 000012345=12345"
        );

        $messages = $validation->validate(
            [
                'name'     => 'asd',
                'nameWith' => 'asdß',
            ]
        );

        $I->assertEquals(
            1,
            $messages->count(),
            "Phalcon\Validation\Validator\Confirmation failed to compare asd=asdß"
        );
    }

    /**
     * Tests Phalcon\Validation\Validator\Confirmation :: validate() - multiple
     * field
     *
     * @param IntegrationTester $I
     *
     * @since  2016-06-05
     * @author Wojciech Ślawski <jurigag@gmail.com>
     */
    public function validationValidatorConfirmationValidateMultipleField(IntegrationTester $I)
    {
        $I->wantToTest(
            "Validation\Validator\Confirmation - validate() - multiple field"
        );

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

        $I->assertEquals(
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

        $I->assertEquals(
            1,
            $messages->count()
        );

        $I->assertEquals(
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

        $I->assertEquals(
            2,
            $messages->count()
        );

        $I->assertEquals(
            $validationMessages['name'],
            $messages->offsetGet(0)->getMessage()
        );

        $I->assertEquals(
            $validationMessages['type'],
            $messages->offsetGet(1)->getMessage()
        );
    }

    /**
     * Tests Phalcon\Validation\Validator\Confirmation :: validate() - empty
     * value
     *
     * @param IntegrationTester $I
     *
     * @since  2015-09-06
     * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
     */
    public function validationValidatorConfirmationValidateEmptyValues(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Confirmation - validate() - empty value");

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

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'password'  => null,
                'password2' => 'test123',
            ]
        );

        $I->assertEquals(
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

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'password'  => null,
                'password2' => 'test123',
            ]
        );

        $I->assertEquals(
            1,
            $messages->count()
        );

        $I->assertEquals($expected, $messages);


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

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'password'  => null,
                'password2' => 'test123',
            ]
        );

        $I->assertEquals(
            1,
            $messages->count()
        );

        $I->assertEquals($expected, $messages);
    }
}
