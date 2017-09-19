<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Validation;
use Phalcon\Validation\Message;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation\Message\Group;
use Phalcon\Validation\Validator\Alpha;

/**
 * \Phalcon\Test\Unit\Validation\Validator\AlphaTest
 * Tests the \Phalcon\Validation\Validator\Alpha component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Validation\Validator
 * @group     validation
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class AlphaTest extends UnitTest
{
    /**
     * Tests alpha validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testSingleField()
    {
        $validation = new Validation();
        $validation->add('name', new Alpha());
        $messages = $validation->validate(['name' => 'Asd']);
        expect($messages->count())->equals(0);
        $messages = $validation->validate(['name' => 'Asd123']);
        expect($messages->count())->equals(1);
    }

    /**
     * Tests alpha validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleField()
    {
        $validation = new Validation();
        $validationMessages = [
            'name' => 'Name must be alpha.',
            'type' => 'Type must by alpha.',
        ];
        $validation->add(['name', 'type'], new Alpha([
            'message' => $validationMessages,
        ]));

        $messages = $validation->validate(['name' => 'Asd', 'type' => 'Asd']);
        expect($messages->count())->equals(0);
        $messages = $validation->validate(['name' => 'Asd123', 'type' => 'Asd']);
        expect($messages->count())->equals(1);
        expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['name']);
        $messages = $validation->validate(['name' => 'Asd123', 'type' => 'Asd123']);
        expect($messages->count())->equals(2);
        expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['name']);
        expect($messages->offsetGet(1)->getMessage())->equals($validationMessages['type']);
    }

    /**
     * Tests Non Alphabetic Characters
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-06-10
     */
    public function testShouldDetectNonAlphabeticCharacters()
    {
        $this->specify(
            "The Alpha Validator does not detect non alphabetic characters",
            function ($input) {
                $validation = new Validation;
                $validation->add('name', new Alpha([
                    'message' => ':field must contain only letters'
                ]));

                $messages = $validation->validate(['name' => $input]);

                $expectedMessages = Group::__set_state([
                    '_messages' => [
                        Message::__set_state([
                            '_type' => 'Alpha',
                            '_message' => 'name must contain only letters',
                            '_field' => 'name',
                            '_code' => '0',
                        ])
                    ],
                ]);

                expect($messages)->equals($expectedMessages);
            },
            [
                'examples' => [
                    ['1'],
                    [123],
                    ['a-b-c-d'],
                    ['a-1-c-2'],
                    ['a1c2'],
                    ['o0o0o0o0'],
                ]
            ]
        );
    }

    /**
     * Tests Alphabetic Characters
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-06-10
     */
    public function testShouldValidateAlphabeticCharacters()
    {
        $this->specify(
            "The Alpha Validator does not validate alphabetic characters",
            function ($input) {
                $validation = new Validation;
                $validation->add('name', new Alpha([
                    'message' => ':field must contain only letters'
                ]));

                $messages = $validation->validate(['name' => $input]);

                expect($messages)->count(0);
            },
            [
                'examples' => [
                    ['a'],
                    ['asdavafaiwnoabwiubafpowf'],
                    ['QWERTYUIOPASDFGHJKL'],
                    ['aSdFgHjKl'],
                    [null],
                ]
            ]
        );
    }

    /**
     * Tests Non Latin Characters
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-06-10
     */
    public function testShouldValidateNonLatinCharacters()
    {
        $this->specify(
            "The Alpha Validator does not validate alphabetic characters",
            function ($input) {
                $validation = new Validation;
                $validation->add('name', new Alpha([
                    'message' => ':field must contain only letters'
                ]));

                $messages = $validation->validate(['name' => $input]);

                expect($messages)->count(0);
            },
            [
                'examples' => [
                    ['йцукенг'],
                    ['ждлорпа'],
                    ['Señor'],
                    ['cocoñùт'],
                    ['COCOÑÙТ'],
                    ['JÄGER'],
                    ['šš'],
                    ['あいうえお'],
                    ['零一二三四五'],
                ]
            ]
        );
    }
}
