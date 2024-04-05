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

namespace Phalcon\Tests\Integration\Filter\Validation\Validator\StringLength\Max;

use IntegrationTester;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exception;
use Phalcon\Filter\Validation\Validator\StringLength\Max;
use stdClass;

class ValidateCest
{
    /**
     * Tests Phalcon\Filter\Validation\Validator\Min :: validate() - empty
     *
     * @param IntegrationTester $I
     *
     * @return void
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-03
     */
    public function filterValidationValidatorMaxValidateEmpty(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Max - validate() - empty");

        $validation = new Validation();
        $validator  = new Max(['allowEmpty' => true,]);
        $validation->add('name', $validator);
        $entity       = new stdClass();
        $entity->name = '';

        $validation->bind($entity, []);
        $result = $validator->validate($validation, 'name');
        $I->assertTrue($result);
    }

    /**
     * Tests Phalcon\Filter\Validation\Validator\StringLength :: validate() - single
     * field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorMaxStringLengthValidateSingleField(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength :: validate() - single field');

        $validation = new Validation();

        $validation->add(
            'name',
            new Max(
                [
                    'max' => 9,
                ]
            )
        );


        $messages = $validation->validate(
            [
                'name' => 'SomeValue',
            ]
        );

        $I->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name' => 'SomeValue123',
            ]
        );

        $I->assertSame(
            1,
            $messages->count()
        );
    }

    /**
     * Tests Phalcon\Filter\Validation\Validator\StringLength :: validate() - single
     * field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorMaxOrEqualStringLengthValidateSingleField(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength :: validate() - single field');

        $validation = new Validation();

        $validation->add(
            'name',
            new Max(
                [
                    'max'      => 9,
                    'included' => true,
                ]
            )
        );


        $messages = $validation->validate(
            [
                'name' => 'short',
            ]
        );

        $I->assertSame(
            0,
            $messages->count()
        );

        $messages = $validation->validate(
            [
                'name' => 'SomeValue',
            ]
        );

        $I->assertSame(
            1,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name' => 'SomeValue123',
            ]
        );

        $I->assertSame(
            1,
            $messages->count()
        );
    }
}
