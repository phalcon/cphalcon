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

namespace Phalcon\Test\Integration\Validation\Validator\Alpha;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Alpha;

class ValidateCest
{
    /**
     * Tests Phalcon\Validation\Validator\Alpha :: validate() - single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorAlphaValidateSingleField(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Alpha - validate() - single field");

        $validation = new Validation();

        $validation->add(
            'name',
            new Alpha()
        );


        $messages = $validation->validate(
            [
                'name' => 'Asd',
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name' => 'Asd123',
            ]
        );

        $I->assertEquals(
            1,
            $messages->count()
        );
    }

    /**
     * Tests Phalcon\Validation\Validator\Alpha :: validate() - multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorAlphaValidateMultipleField(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Alpha - validate() - multiple field");

        $validation = new Validation();

        $validationMessages = [
            'name' => 'Name must be alpha.',
            'type' => 'Type must by alpha.',
        ];

        $validation->add(
            ['name', 'type'],
            new Alpha(
                [
                    'message' => $validationMessages,
                ]
            )
        );


        $messages = $validation->validate(
            [
                'name' => 'Asd',
                'type' => 'Asd',
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name' => 'Asd123',
                'type' => 'Asd',
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
                'name' => 'Asd123',
                'type' => 'Asd123',
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
     * Tests Phalcon\Validation\Validator\Alpha :: validate() - Non Alphabetic
     * Characters
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2016-06-10
     *
     * @dataProvider validationValidatorAlphaValidateNonAlphabeticCharactersProvider
     */
    public function validationValidatorAlphaValidateNonAlphabeticCharacters(IntegrationTester $I, Example $example)
    {
        $I->wantToTest("Validation\Validator\Alpha - validate() - non alphabetic characters");

        $input = $example[0];

        $validation = new Validation();

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
                    Alpha::class,
                    0
                ),
            ]
        );

        $actual = $validation->validate(
            [
                'name' => $input,
            ]
        );

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Validation\Validator\Alpha :: validate() - Alphabetic
     * Characters
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2016-06-10
     *
     * @dataProvider validationValidatorAlphaValidateAlphabeticCharactersProvider
     */
    public function validationValidatorAlphaValidateAlphabeticCharacters(IntegrationTester $I, Example $example)
    {
        $I->wantToTest("Validation\Validator\Alpha - validate() - alphabetic characters");

        $input = $example[0];

        $validation = new Validation();

        $validation->add(
            'name',
            new Alpha(
                [
                    'message' => ':field must contain only letters',
                ]
            )
        );

        $messages = $validation->validate(
            [
                'name' => $input,
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );
    }

    /**
     * Tests Phalcon\Validation\Validator\Alpha :: validate() - Non Latin
     * Characters
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2016-06-10
     *
     * @dataProvider nonLatinCharactersProvider
     */
    public function validationValidatorAlphaValidateNonLatinCharacters(IntegrationTester $I, Example $example)
    {
        $I->wantToTest("Validation\Validator\Alpha - validate() - non latin characters");

        $input = $example[0];

        $validation = new Validation();

        $validation->add(
            'name',
            new Alpha(
                [
                    'message' => ':field must contain only letters',
                ]
            )
        );

        $messages = $validation->validate(
            [
                'name' => $input,
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );
    }

    private function validationValidatorAlphaValidateNonAlphabeticCharactersProvider(): array
    {
        return [
            ['1'],
            [123],
            ['a-b-c-d'],
            ['a-1-c-2'],
            ['a1c2'],
            ['o0o0o0o0'],
        ];
    }

    private function validationValidatorAlphaValidateAlphabeticCharactersProvider(): array
    {
        return [
            ['a'],
            ['asdavafaiwnoabwiubafpowf'],
            ['QWERTYUIOPASDFGHJKL'],
            ['aSdFgHjKl'],
            [null],
        ];
    }

    private function nonLatinCharactersProvider(): array
    {
        return [
            ['йцукенг'],
            ['ждлорпа'],
            ['Señor'],
            ['cocoñùт'],
            ['COCOÑÙТ'],
            ['JÄGER'],
            ['šš'],
            ['あいうえお'],
            ['零一二三四五'],
        ];
    }
}
