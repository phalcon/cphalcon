<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation;

/**
 * \Phalcon\Test\Unit\Validation\Validator\PresenceOfTest
 * Tests the \Phalcon\Validation\Validator\PresenceOf component
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
class PresenceOfTest extends UnitTest
{
    /**
     * Tests presence of validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testSingleField()
    {
        $this->specify('Test presence of validator with single field.', function () {
            $validation = new Validation();
            $validation->add('name', new Validation\Validator\PresenceOf());
            $messages = $validation->validate(['name' => 'SomeValue']);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['name' => '']);
            expect($messages->count())->equals(1);
        });
    }

    /**
     * Tests presence of validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleField()
    {
        $this->specify('Test presence of validator with multiple field.', function () {
            $validation = new Validation();
            $validationMessages = [
                'name' => 'Name cant be empty.',
                'type' => 'Type cant be empty.',
            ];
            $validation->add(['name', 'type'], new Validation\Validator\PresenceOf([
                'message' => $validationMessages,
            ]));
            $messages = $validation->validate(['name' => 'SomeValue', 'type' => 'SomeValue']);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['name' => '', 'type' => 'SomeValue']);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['name']);
            $messages = $validation->validate(['name' => '', 'type' => '']);
            expect($messages->count())->equals(2);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['name']);
            expect($messages->offsetGet(1)->getMessage())->equals($validationMessages['type']);
        });
    }
}
