<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Alpha;
use UnitTester;

class AlphaCest
{
    /**
     * Tests alpha validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testSingleField(UnitTester $I)
    {
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
     * Tests alpha validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleField(UnitTester $I)
    {
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
     * Tests Non Alphabetic Characters
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-06-10
     */
    public function testShouldDetectNonAlphabeticCharacters(UnitTester $I)
    {
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

            $expected = Messages::__set_state(
                [
                    '_messages' => [
                        Message::__set_state(
                            [
                                '_type'    => 'Alpha',
                                '_message' => 'name must contain only letters',
                                '_field'   => 'name',
                                '_code'    => '0',
                            ]
                        ),
                    ],
                ]
            );
            $actual   = $validation->validate(['name' => $input]);
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Alphabetic Characters
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-06-10
     */
    public function testShouldValidateAlphabeticCharacters(UnitTester $I)
    {
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
     * Tests Non Latin Characters
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-06-10
     */
    public function testShouldValidateNonLatinCharacters(UnitTester $I)
    {
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
