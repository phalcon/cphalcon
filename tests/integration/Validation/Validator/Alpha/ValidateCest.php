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

namespace Phalcon\Test\Integration\Validation\Validator\Alpha;

use IntegrationTester;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Alpha;

/**
 * Class ValidateCest
 */
class ValidateCest
{
    /**
     * Tests Phalcon\Validation\Validator\Alpha :: validate() - single field
     *
     * @param IntegrationTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorAlphaValidateSingleField(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Alpha - validate() - single field");
        $validation = new Validation();
        $validation->add('name', new Alpha());
        $messages = $validation->validate(['name' => 'Asd']);

        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['name' => 'Asd123']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Validation\Validator\Alpha :: validate() - multiple field
     *
     * @param IntegrationTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorAlphaValidateMultipleField(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Alpha - validate() - multiple field");
        $validation         = new Validation();
        $validationMessages = [
            'name' => 'Name must be alpha.',
            'type' => 'Type must by alpha.',
        ];
        $validation->add(['name', 'type'], new Alpha([
            'message' => $validationMessages,
        ]));

        $messages = $validation->validate(['name' => 'Asd', 'type' => 'Asd']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);
        $messages = $validation->validate(['name' => 'Asd123', 'type' => 'Asd']);

        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['name' => 'Asd123', 'type' => 'Asd123']);
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
     * Tests Phalcon\Validation\Validator\Alpha :: validate() - Non Alphabetic
     * Characters
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-06-10
     */
    public function validationValidatorAlphaValidateNonAlphabeticCharacters(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Alpha - validate() - non alphabetic characters");
        $examples = [
            '1',
            123,
            'a-b-c-d',
            'a-1-c-2',
            'a1c2',
            'o0o0o0o0',
        ];

        foreach ($examples as $input) {
            $validation = new Validation;
            $validation->add(
                'name',
                new Alpha(
                    [
                        'message' => ':field must contain only letters',
                    ]
                )
            );

            $expected = new Messages(
                [
                    new Message(
                        'name must contain only letters',
                        'name',
                        'Alpha',
                        0
                    ),
                ]
            );
            $actual   = $validation->validate(['name' => $input]);
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Phalcon\Validation\Validator\Alpha :: validate() - Alphabetic
     * Characters
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-06-10
     */
    public function validationValidatorAlphaValidateAlphabeticCharacters(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Alpha - validate() - alphabetic characters");
        $examples = [
            'a',
            'asdavafaiwnoabwiubafpowf',
            'QWERTYUIOPASDFGHJKL',
            'aSdFgHjKl',
            null,
        ];

        foreach ($examples as $input) {
            $validation = new Validation;
            $validation->add(
                'name',
                new Alpha(
                    [
                        'message' => ':field must contain only letters',
                    ]
                )
            );

            $messages = $validation->validate(['name' => $input]);

            $expected = 0;
            $actual   = $messages->count();
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Phalcon\Validation\Validator\Alpha :: validate() - Non Latin
     * Characters
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-06-10
     */
    public function validationValidatorAlphaValidateNonLatinCharacters(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Alpha - validate() - non latin characters");
        $examples = [
            'йцукенг',
            'ждлорпа',
            'Señor',
            'cocoñùт',
            'COCOÑÙТ',
            'JÄGER',
            'šš',
            'あいうえお',
            '零一二三四五',
        ];

        foreach ($examples as $input) {
            $validation = new Validation;
            $validation->add(
                'name',
                new Alpha(
                    [
                        'message' => ':field must contain only letters',
                    ]
                )
            );

            $messages = $validation->validate(['name' => $input]);

            $expected = 0;
            $actual   = $messages->count();
            $I->assertEquals($expected, $actual);
        }
    }
}
