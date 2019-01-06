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

namespace Phalcon\Test\Integration\Validation\Validator\Alnum;

use IntegrationTester;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Alnum;

/**
 * Class ValidateCest
 */
class ValidateCest
{
    /**
     * Tests Phalcon\Validation\Validator\Alnum :: validate() - single field
     *
     * @param IntegrationTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorAlnumValidateSingleField(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Alnum - validate() - single field");
        $validation = new Validation();
        $validation->add('name', new Alnum());
        $messages = $validation->validate(['name' => 'SomeValue123']);

        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['name' => 'SomeValue123!@#']);

        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Validation\Validator\Alnum :: validate() - multiple field
     *
     * @param IntegrationTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorAlnumValidateMultipleField(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Alnum - validate() - multiple field");
        $validation         = new Validation();
        $validationMessages = [
            'name' => 'Name must be alnum',
            'type' => 'Type must be alnum',
        ];
        $validation->add(
            [
                'name',
                'type',
            ],
            new Alnum(
                [
                    'message' => $validationMessages,
                ]
            )
        );
        $messages = $validation->validate(['name' => 'SomeValue123', 'type' => 'SomeValue123']);

        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['name' => 'SomeValue123!@#', 'type' => 'SomeValue123']);

        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['name' => 'SomeValue123!@#', 'type' => 'SomeValue123!@#']);

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
}
