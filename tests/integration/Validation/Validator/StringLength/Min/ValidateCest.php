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

namespace Phalcon\Test\Integration\Validation\Validator\StringLength\Min;

use IntegrationTester;
use Phalcon\Validation;
use Phalcon\Validation\Validator\StringLength\Min;

class ValidateCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength :: validate() - single
     * field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorMinStringLengthValidateSingleField(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength :: validate() - single field');

        $validation = new Validation();

        $validation->add(
            'name',
            new Min(
                [
                    'min' => 9,
                ]
            )
        );


        $messages = $validation->validate(
            [
                'name' => 'SomeValue',
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name' => 'SomeValue123',
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );
    }

    /**
     * Tests Phalcon\Validation\Validator\StringLength :: validate() - single
     * field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorMinOrEqualStringLengthValidateSingleField(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength :: validate() - single field');

        $validation = new Validation();

        $validation->add(
            'name',
            new Min(
                [
                    'min'      => 9,
                    'included' => true,
                ]
            )
        );


        $messages = $validation->validate(
            [
                'name' => 'SomeValue',
            ]
        );

        $I->assertEquals(
            1,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name' => 'SomeValue123',
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );
    }
}
