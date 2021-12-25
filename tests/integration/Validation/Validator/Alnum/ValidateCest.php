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

namespace Phalcon\Tests\Integration\Validation\Validator\Alnum;

use IntegrationTester;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\Alnum;

class ValidateCest
{
    /**
     * Tests Phalcon\Filter\Validation\Validator\Alnum :: validate() - single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorAlnumValidateSingleField(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Alnum - validate() - single field");

        $validation = new Validation();

        $validation->add(
            'name',
            new Alnum()
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

        $messages = $validation->validate(
            [
                'name' => 'SomeValue123!@#',
            ]
        );

        $I->assertEquals(
            1,
            $messages->count()
        );
    }

    /**
     * Tests Phalcon\Filter\Validation\Validator\Alnum :: validate() - multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorAlnumValidateMultipleField(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Alnum - validate() - multiple field");

        $validation = new Validation();

        $validationMessages = [
            'name' => 'Name must be alnum',
            'type' => 'Type must be alnum',
        ];

        $al = new Alnum(
            [
                'message' => $validationMessages,
            ]
        );

        $validation->add(
            [
                'name',
                'type',
            ],
            $al
        );

        codecept_debug($validation);
        codecept_debug($al);


        $messages = $validation->validate(
            [
                'name' => 'SomeValue123',
                'type' => 'SomeValue123',
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name' => 'SomeValue123!@#',
                'type' => 'SomeValue123',
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
                'name' => 'SomeValue123!@#',
                'type' => 'SomeValue123!@#',
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
}
