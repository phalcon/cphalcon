<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Alnum;

/**
 * \Phalcon\Test\Unit\Validation\Validator\AlnumTest
 * Tests the \Phalcon\Validation\Validator\Alnum component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Validation\Validator
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class AlnumTest extends UnitTest
{
    /**
     * Tests alnum validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testSingleField()
    {
        $this->specify('Test alnum validator with single field.', function () {
            $validation = new Validation();
            $validation->add('name', new Alnum());
            $messages = $validation->validate(['name' => 'SomeValue123']);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['name' => 'SomeValue123!@#']);
            expect($messages->count())->equals(1);
        });
    }

    /**
     * Tests alnum validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleField()
    {
        $this->specify('Test alnum validator with multiple field.', function () {
            $validation = new Validation();
            $validationMessages = [
                'name' => 'Name must be alnum',
                'type' => 'Type must be alnum',
            ];
            $validation->add(['name', 'type'], new Alnum([
                'message' => $validationMessages,
            ]));
            $messages = $validation->validate(['name' => 'SomeValue123', 'type' => 'SomeValue123']);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['name' => 'SomeValue123!@#', 'type' => 'SomeValue123']);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['name']);
            $messages = $validation->validate(['name' => 'SomeValue123!@#', 'type' => 'SomeValue123!@#']);
            expect($messages->count())->equals(2);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['name']);
            expect($messages->offsetGet(1)->getMessage())->equals($validationMessages['type']);
        });
    }
}
