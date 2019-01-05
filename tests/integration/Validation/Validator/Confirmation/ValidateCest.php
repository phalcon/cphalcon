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
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorConfirmationValidateSingleField(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Confirmation - validate() - single field");
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

        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(
            [
                'name'     => 'SomeValue',
                'nameWith' => 'SomeValue123',
            ]
        );

        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Validation\Validator\Confirmation :: validate() - multiple
     * field
     *
     * @param IntegrationTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorConfirmationValidateMultipleField(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Confirmation - validate() - multiple field");
        $validation         = new Validation();
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

        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(
            [
                'name'     => 'SomeValue',
                'nameWith' => 'SomeValue123',
                'type'     => 'SomeValue',
                'typeWith' => 'SomeValue',
            ]
        );

        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(
            [
                'name'     => 'SomeValue',
                'nameWith' => 'SomeValue123',
                'type'     => 'SomeValue',
                'typeWith' => 'SomeValue123',
            ]
        );

        $expected = 2;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['type'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Validation\Validator\Confirmation :: validate() - empty
     * value
     *
     * @param IntegrationTester $I
     *
     * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
     * @since  2015-09-06
     */
    public function validationValidatorConfirmationValidateEmptyValues(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Confirmation - validate() - empty value");
        $expected = new Messages(
            [
                new Message(
                    'Field password must be the same as password2',
                    'password',
                    'Confirmation',
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

        $actual = $messages->count();
        $I->assertEquals(0, $actual);

        $messages = $validation->validate(
            [
                'password'  => null,
                'password2' => 'test123',
            ]
        );

        $actual = $messages->count();
        $I->assertEquals(0, $actual);

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

        $actual = $messages->count();
        $I->assertEquals(0, $actual);

        $messages = $validation->validate(
            [
                'password'  => null,
                'password2' => 'test123',
            ]
        );

        $actual = $messages->count();
        $I->assertEquals(1, $actual);
        $actual = $messages;
        $I->assertEquals($expected, $actual);

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

        $actual = $messages->count();
        $I->assertEquals(0, $actual);

        $messages = $validation->validate(
            [
                'password'  => null,
                'password2' => 'test123',
            ]
        );

        $actual = $messages->count();
        $I->assertEquals(1, $actual);
        $actual = $messages;
        $I->assertEquals($expected, $actual);
    }
}
