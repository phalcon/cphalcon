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

namespace Phalcon\Tests\Integration\Filter\Validation\Validator\Alnum;

use IntegrationTester;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exception;
use Phalcon\Filter\Validation\Validator\Alnum;
use stdClass;

class ValidateCest
{
    /**
     * Tests Phalcon\Filter\Validation\Validator\Alnum :: validate() - empty
     *
     * @param IntegrationTester $I
     *
     * @return void
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-03
     */
    public function filterValidationValidatorAlnumValidateEmpty(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Alnum - validate() - empty");

        $validation = new Validation();
        $validator  = new Alnum(['allowEmpty' => true,]);
        $validation->add('name', $validator);
        $entity       = new stdClass();
        $entity->name = '';

        $validation->bind($entity, []);
        $result = $validator->validate($validation, 'name');
        $I->assertTrue($result);
    }

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
        $validation->add('name', new Alnum());

        $messages = $validation->validate(
            [
                'name' => 'SomeValue123',
            ]
        );

        $expected = 0;
        $actual   = $messages->count();
        $I->assertSame($expected, $actual);

        $messages = $validation->validate(
            [
                'name' => 'SomeValue123!@#',
            ]
        );

        $expected = 1;
        $actual   = $messages->count();
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Filter\Validation\Validator\Alnum :: validate() - multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorAlnumValidateMultipleField(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Alnum - validate() - multiple fields");

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

        $messages = $validation->validate(
            [
                'name' => 'SomeValue123',
                'type' => 'SomeValue123',
            ]
        );

        $expected = 0;
        $actual   = $messages->count();
        $I->assertSame($expected, $actual);

        $messages = $validation->validate(
            [
                'name' => 'SomeValue123!@#',
                'type' => 'SomeValue123',
            ]
        );

        $expected = 1;
        $actual   = $messages->count();
        $I->assertSame($expected, $actual);

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertSame($expected, $actual);

        $messages = $validation->validate(
            [
                'name' => 'SomeValue123!@#',
                'type' => 'SomeValue123!@#',
            ]
        );

        $expected = 2;
        $actual   = $messages->count();
        $I->assertSame($expected, $actual);

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertSame($expected, $actual);

        $expected = $validationMessages['type'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $I->assertSame($expected, $actual);
    }
}
