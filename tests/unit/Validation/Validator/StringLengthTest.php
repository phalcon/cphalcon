<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation;

/**
 * \Phalcon\Test\Unit\Validation\Validator\StringLengthTest
 * Tests the \Phalcon\Validation\Validator\StringLength component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Validation\Validator
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class StringLengthTest extends UnitTest
{
    /**
     * Tests string length validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testSingleField()
    {
        $this->specify('Test string length with single field.', function () {
            $validation = new Validation();
            $validation->add('name', new Validation\Validator\StringLength([
                'min' => 0,
                'max' => 9,
            ]));
            $messages = $validation->validate(['name' => 'SomeValue']);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['name' => 'SomeValue123']);
            expect($messages->count())->equals(1);
        });
    }

    /**
     * Tests string length validator with multiple field and single min, max
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleFieldSingleMinMax()
    {
        $this->specify('Test string length with multiple field and single min, max.', function () {
            $validation = new Validation();
            $validationMinimumMessages = [
                'name' => 'Name length must be minimum 0.',
                'type' => 'Type length must be minimum 0.',
            ];
            $validationMaximumMessages = [
                'name' => 'Name length must be maximum 9.',
                'type' => 'Type length must be maximum 9.',
            ];
            $validation->add(['name', 'type'], new Validation\Validator\StringLength([
                'min' => 0,
                'max' => 9,
                'messageMinimum' => $validationMinimumMessages,
                'messageMaximum' => $validationMaximumMessages
            ]));
            $messages = $validation->validate(['name' => 'SomeValue', 'type' => 'SomeValue']);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['name' => 'SomeValue123', 'type' => 'SomeValue']);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMaximumMessages['name']);
            $messages = $validation->validate(['name' => 'SomeValue123', 'type' => 'SomeValue123']);
            expect($messages->count())->equals(2);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMaximumMessages['name']);
            expect($messages->offsetGet(1)->getMessage())->equals($validationMaximumMessages['type']);
        });
    }

    /**
     * Tests string length validator with multiple field and min, max
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleFieldMultipleMinMax()
    {
        $this->specify('Test string length with multiple field and min, max.', function () {
            $validation = new Validation();
            $validationMinimumMessages = [
                'name' => 'Name length must be minimum 0.',
                'type' => 'Type length must be minimum 0.',
            ];
            $validationMaximumMessages = [
                'name' => 'Name length must be maximum 9.',
                'type' => 'Type length must be maximum 4.',
            ];
            $validation->add(['name', 'type'], new Validation\Validator\StringLength([
                'min' => [
                    'name' => 0,
                    'type' => 0,
                ],
                'max' => [
                    'name' => 9,
                    'type' => 4,
                ],
                'messageMinimum' => $validationMinimumMessages,
                'messageMaximum' => $validationMaximumMessages
            ]));
            $messages = $validation->validate(['name' => 'SomeValue', 'type' => 'Some']);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['name' => 'SomeValue123', 'type' => 'Some']);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMaximumMessages['name']);
            $messages = $validation->validate(['name' => 'SomeValue', 'type' => 'SomeValue']);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMaximumMessages['type']);
            $messages = $validation->validate(['name' => 'SomeValue123', 'type' => 'SomeValue']);
            expect($messages->count())->equals(2);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMaximumMessages['name']);
            expect($messages->offsetGet(1)->getMessage())->equals($validationMaximumMessages['type']);
        });
    }
}
